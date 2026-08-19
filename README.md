# 7-Segment-Display-Counter
Part of the #30DayIoTArduinoSeries — Display Integration theme.


## What it does
A push button increments a counter (0–9) shown on a single 7-segment display.
Each press-and-release registers as exactly one count, using edge detection
and a millis()-based debounce to avoid double-counting from button bounce.

## Components
- Arduino Uno
- 7-segment display (common cathode)
- Push button
- 10kΩ resistor (pull-down)
- 7× 220Ω resistors (segment current limiting)

## Circuit
| Segment | Arduino Pin |
|---------|-------------|
| a       | 2           |
| b       | 3           |
| c       | 4           |
| d       | 5           |
| e       | 6           |
| f       | 7           |
| g       | 8           |
| COM     | GND         |

Button: one leg → pin 9, other leg → 5V, with a 10kΩ pull-down resistor
from pin 9 to GND.

## How it works
- Digit patterns are stored as a lookup table (`digits[10][7]`), where each
  row lists which segments must be ON to display that number.
- Button state is checked for a LOW→HIGH transition (edge detection) so a
  held-down button doesn't rapid-fire counts.
- A `millis()`-based debounce (200ms) filters out mechanical/simulated
  button bounce.

## Simulate it
Open in [Wokwi](https://wokwi.com) using the included `diagram.json`, or
run locally via PlatformIO (`platformio.ini` included).

## Part of
[#30DayIoTArduinoSeries](https://linkedin.com/in/YOUR-PROFILE) — daily
Arduino/ESP32 projects, Day 5 of 30.
