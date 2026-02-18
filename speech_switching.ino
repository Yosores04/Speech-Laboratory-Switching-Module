// Relay Pins (Outputs)
const int relays[] = {13, 12, 14, 27, 26, 25, 33, 32}; 
// Push Button Pins (Inputs)
const int switches[] = {4, 16, 17, 5, 18, 19, 21, 22}; 
const int numRelays = 8;

// --- PRESET BUTTONS ---
const int BROADCAST_BTN = 23; 
const int RESET_BTN = 15;

// Arrays to track the state of each cubicle
bool relayLockedStates[numRelays] = {false}; 
bool lastButtonStates[numRelays] = {LOW}; 

// Track states for preset buttons
bool lastBroadcastState = HIGH;
bool lastResetState = HIGH;

void setup() {
  Serial.begin(115200);
  Serial.println("Speech Lab Toggle Mode Initialized...");

  for (int i = 0; i < numRelays; i++) {
    pinMode(relays[i], OUTPUT);
    // Standardizing to HIGH (OFF) at start so relays don't click on boot
    digitalWrite(relays[i], HIGH); 
    
    pinMode(switches[i], INPUT_PULLUP); 
    // Reverted to your initialization style
    lastButtonStates[i] = relayLockedStates[i]; 
  }

  pinMode(BROADCAST_BTN, INPUT_PULLUP);
  pinMode(RESET_BTN, INPUT_PULLUP);
}

void loop() {
  // --- PRESET: ALL ON ---
  bool broadcastReading = digitalRead(BROADCAST_BTN);
  if (lastBroadcastState == HIGH && broadcastReading == LOW) {
    for (int i = 0; i < numRelays; i++) {
      relayLockedStates[i] = true;
      digitalWrite(relays[i], LOW); 
    }
    //Serial.println("PRESET: ALL CHANNELS ACTIVE");
    delay(200); 
  }
  lastBroadcastState = broadcastReading;

  // --- PRESET: ALL OFF ---
  bool resetReading = digitalRead(RESET_BTN);
  if (lastResetState == HIGH && resetReading == LOW) {
    for (int i = 0; i < numRelays; i++) {
      relayLockedStates[i] = false;
      digitalWrite(relays[i], HIGH); 
    }
    //Serial.println("PRESET: ALL CHANNELS CLEAR");
    delay(200);
  }
  lastResetState = resetReading;

  // --- YOUR ORIGINAL LOOP ---
  for (int i = 0; i < numRelays; i++) {
    bool currentReading = digitalRead(switches[i]);

    if (lastButtonStates[i] == HIGH && currentReading == LOW) {
      relayLockedStates[i] = !relayLockedStates[i]; 
      digitalWrite(relays[i], relayLockedStates[i] ? LOW : HIGH);

     // Serial.print("Cubicle ");
     // Serial.print(i + 1);
      //Serial.println(relayLockedStates[i] ? " LOCKED ON" : " LOCKED OFF");

      delay(150); 
    }
    lastButtonStates[i] = currentReading;
  }
}