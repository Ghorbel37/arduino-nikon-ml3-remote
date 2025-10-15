# Arduino Nikon ML-3 IR Remote

An Arduino-based infrared remote control that emulates the Nikon ML-3 remote shutter release for Nikon DSLR cameras. This project is based on reverse-engineered IR protocol timing specifications.

## Description

This project allows you to trigger your Nikon camera's shutter using an Arduino and an infrared LED. It replicates the IR signal protocol used by the Nikon ML-3 remote control, providing a low-cost alternative to the commercial remote.

## Features

- **Push-button trigger**: Simple button press to activate the camera shutter
- **ML-3 protocol emulation**: Accurate timing and burst sequences matching Nikon's IR protocol
- **Serial debugging**: Monitor button presses and IR signal transmission via Serial Monitor
- **Low-cost solution**: Build your own camera remote with minimal components

## Hardware Requirements

- Arduino board (Uno, Nano, or compatible)
- IR LED (infrared LED, typically 940nm)
- Push button
- 100Ω - 220Ω resistor (for IR LED current limiting)
- Breadboard and jumper wires (for prototyping)

## Circuit Diagram

### Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| IR LED (+) | Pin 3 (through resistor) |
| IR LED (-) | GND |
| Push Button | Pin 2 (with internal pull-up) |
| Push Button | GND |

### Wiring Instructions

1. Connect the IR LED anode (longer leg) to Pin 3 through a 100-220Ω resistor
2. Connect the IR LED cathode (shorter leg) to GND
3. Connect one side of the push button to Pin 2
4. Connect the other side of the push button to GND
5. The internal pull-up resistor is enabled in code for Pin 2

## Installation

1. Clone or download this repository
2. Open `Nikon_Remote_ML-3.ino` in the Arduino IDE
3. Connect your Arduino board via USB
4. Select the correct board type and port in the Arduino IDE
5. Upload the sketch to your Arduino

## Usage

1. Power on your Arduino (via USB or battery)
2. Set your Nikon camera to remote control mode
3. Point the IR LED at the camera's IR receiver (usually on the front of the camera)
4. Press the button to trigger the shutter
5. The camera should take a photo

**Note**: Keep the IR LED within a few meters of the camera and ensure there are no obstructions between the LED and the camera's IR sensor.

## How It Works

The code sends a specific IR signal sequence that Nikon cameras recognize as the ML-3 remote command:

1. **Carrier frequency**: ~38 kHz (achieved by toggling the IR LED every 7 microseconds)
2. **Signal sequence**:
   - Initial burst: 76 pulses
   - First delay: 27ms + 810μs
   - Second burst: 16 pulses
   - Second delay: 1540μs
   - Third burst: 16 pulses
   - Third delay: 3545μs
   - Final burst: 16 pulses

This timing pattern matches the Nikon ML-3 protocol for immediate shutter release.

## Compatible Cameras

This remote should work with Nikon DSLR cameras that support the ML-3 remote, including:

- Nikon D40, D40x, D50, D60, D70, D70s, D80, D90
- Nikon D3000, D3100, D3200, D3300, D3400, D3500
- Nikon D5000, D5100, D5200, D5300, D5500, D5600
- Nikon D7000, D7100, D7200, D7500
- And many other models with IR remote capability

**Check your camera's manual** to confirm it supports infrared remote control.

## Customization

### Modify the Delay

If you need a delayed shutter release, you can add a delay before calling `doTheSequence()` in the `loop()` function:

```cpp
if (digitalRead(2) == LOW) {
    Serial.println("Button pressed. Waiting 2 seconds...");
    delay(2000); // 2-second delay
    Serial.println("Sending IR signal...");
    doTheSequence();
    delay(50);
}
```

### Change the Button Pin

To use a different pin for the button, change the pin number in both `setup()` and `loop()`:

```cpp
pinMode(YOUR_PIN, INPUT_PULLUP);
// and
if (digitalRead(YOUR_PIN) == LOW) { ... }
```

## Troubleshooting

- **Camera not responding**: Ensure the IR LED is pointing at the camera's IR sensor and is within range (typically 1-5 meters)
- **Intermittent operation**: Check your IR LED wiring and resistor connections
- **No response at all**: Verify your camera supports IR remote control and is set to the correct mode
- **LED not visible**: IR light is invisible to the human eye; use a smartphone camera to verify the LED is emitting (it will appear purple/white on camera)

## License

This project is open-source and available for personal and educational use.

---

*Built with passion for photography and embedded systems. Happy shooting! 📷*
