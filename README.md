# Bluetooth Controlled Car

A smartphone-controlled robotic car built using **Arduino Nano, HC-05 Bluetooth module, L293D motor driver, and DC motors**.

The car receives movement commands wirelessly from a smartphone through Bluetooth. The Arduino Nano processes the received command and controls the motor driver to move the car in the required direction.

## Features

- Wireless smartphone control
- Bluetooth-based communication
- Forward movement
- Backward movement
- Left movement
- Right movement
- Stop control
- Arduino-based motor control
- Simple embedded C/C++ implementation


## Working Principle

The smartphone sends a character through the Bluetooth module.

The HC-05 receives the command and passes it to the Arduino Nano through serial communication.

The Arduino checks the received character and generates the required motor-control signals.

The L293D motor driver receives these signals and controls the direction of the DC motors.

### Command Mapping

| Command | Function |
|---|---|
| `F` | Forward |
| `B` | Backward |
| `L` | Left |
| `R` | Right |
| `S` | Stop |

## Hardware Components

- Arduino Nano
- HC-05 Bluetooth module
- L293D motor driver
- DC geared motors × 2
- Robotic car chassis
- Wheels
- Battery
- Jumper wires

## Software

- Arduino IDE
- Arduino C/C++
- SoftwareSerial library

## Pin Configuration

### Arduino Nano → L293D

| Arduino Nano | L293D | Function |
|---|---|---|
| D2 | IN1 | Motor 1 control |
| D3 | IN2 | Motor 1 control |
| D4 | IN3 | Motor 2 control |
| D5 | IN4 | Motor 2 control |
| D9 | ENA | Motor 1 enable/PWM |
| D10 | ENB | Motor 2 enable/PWM |

### Arduino Nano → HC-05

| HC-05 | Arduino Nano |
|---|---|
| TX | RX |
| RX | TX |
| VCC | 5V |
| GND | GND |

> Check the voltage requirements of your specific HC-05 breakout before connecting its RX pin directly to a 5 V Arduino TX signal.

## Motor Control Logic

### Forward

```text
Motor 1 → Forward
Motor 2 → Forward
```

### Backward

```text
Motor 1 → Reverse
Motor 2 → Reverse
```

### Left

```text
Left Motor  → Stop/Reverse
Right Motor → Forward
```

### Right

```text
Left Motor  → Forward
Right Motor → Stop/Reverse
```

### Stop

```text
Left Motor  → Stop
Right Motor → Stop
```



## Source Code

The main Arduino program is available here:

```text
src/
└── bluetooth_controlled_car.ino
```

## How to Use

1. Connect the HC-05 Bluetooth module to the Arduino Nano.
2. Connect the Arduino Nano to the L293D motor driver.
3. Connect the DC motors to the L293D.
4. Upload the Arduino program.
5. Pair the smartphone with the HC-05.
6. Open a Bluetooth terminal/controller application.
7. Send the required command.
8. The robotic car responds to the command.

## Applications

- Bluetooth-controlled robotics
- Wireless vehicle control
- Educational robotics
- Embedded systems learning
- Human-machine interface experiments
- Remote-controlled robotic platforms

## Embedded Concepts Demonstrated

- UART/serial communication
- Bluetooth communication
- Digital I/O
- Motor control
- Motor driver interfacing
- Conditional programming
- Embedded C/C++
- Hardware-software integration

## Future Improvements

- Add PWM-based speed control
- Add obstacle detection
- Add ultrasonic sensor
- Add autonomous mode
- Add battery voltage monitoring
- Add multiple speed levels
- Replace Bluetooth with Wi-Fi/BLE
- Add an Android application with a custom control interface

