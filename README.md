# Speech Laboratory Switching Module

This project provides an Arduino-based switching mechanism for a speech laboratory, allowing control of up to 8 cubicle relays using push buttons and preset broadcast/reset buttons.

## Features

- Toggle individual cubicle relays ON/OFF with dedicated push buttons
- Broadcast button: Activate all relays simultaneously
- Reset button: Deactivate all relays simultaneously
- Serial output for debugging

## Hardware Setup

- **Relays (Outputs):** Pins 13, 12, 14, 27, 26, 25, 33, 32
- **Push Buttons (Inputs):** Pins 4, 16, 17, 5, 18, 19, 21, 22
- **Broadcast Button:** Pin 23
- **Reset Button:** Pin 15

## Usage

1. Upload `speech_switching.ino` to your Arduino board.
2. Connect relays and push buttons as described above.
3. Use individual buttons to toggle cubicle relays.
4. Use preset buttons for quick broadcast/reset actions.

## Repository

[GitHub Repository](https://github.com/Yosores04/Speech-Laboratory-Switching-Module)

---

For wiring diagrams and further instructions, see the code comments in `speech_switching.ino`.
