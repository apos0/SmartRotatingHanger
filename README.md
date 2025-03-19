# Smart Rotating Hanger  

**NOTE:** This project was designed within a few days and is not fully operational. There will be no updates on this repository. However, you are free to study, improve, and fork it.  

This project is licensed under **GPL3**, allowing you to use it within the extent permitted by the license.  

## Overview  
Smart Rotating Hanger is an Arduino-based system that automates the rotation of a circular dress hanger. Users can adjust the rotation speed using an encoder, and an OLED screen displays the current RPM.  

## Features  
- Adjustable rotation speed using a rotary encoder  
- Real-time RPM display on an OLED screen  
- Controlled by an **Arduino Nano**  
- Stepper motor-driven rotation for smooth operation  

## Basic Components  
- **Arduino Nano**  
- **Stepper Motor** (42BYGHW804)  
- **Stepper Motor Controller** (DRV8825)  
- **Rotary Encoder**  
- **OLED Display** (GME12864)  
- **12V 6A Power Supply**  

## Extended Components  

### Mechanical Parts  
- [Gantry Plate](https://grobotronics.com/v-slot-gantry-plate-20mmoem.html) x1  
- [Shaft Hub 5mm](https://grobotronics.com/shaft-hub-5mm.html) x1  
- [Bolt M3 L50](https://grobotronics.com/m3-l50mm-cheese-head-philips.html) x4  
- [Bolt M3 L10](https://grobotronics.com/bolt-m3-din-912.html?variation_id=11809) x4  
- [Bolt M3 L5](https://grobotronics.com/bolt-m3-din7985-black-100pcs.html) x4  
- [Nut M3](https://grobotronics.com/nut-safety-m3-metal.html) x4  
- [Bolt M5 L15](https://grobotronics.com/bolt-m5-low-profile-black.html?variation_id=15208) x4  
- [Washer M5](https://grobotronics.com/washer-m5mm.html) x4  

### Electronics  
- [Stepper Motor](https://grobotronics.com/stepper-motor-42byghw804.html)  
- [DRV8825 Driver](https://grobotronics.com/drv8825-stepper-motor-driver.html)  
- [Arduino Nano](https://grobotronics.com/nano-compatible-ch340-with-headers.html)  
- [PCB Board](https://grobotronics.com/72x47mm.html)  
- [OLED Display](https://grobotronics.com/oled-module-1.3-128x64-i2c-white.html)  
- [Rotary Encoder](https://grobotronics.com/rotary-encoder-module-for-arduino-rectangle-pcb.html)  
- [Encoder Knob](https://grobotronics.com/potentiometer-knob-17x14mm-grey-d-shaft.html)  
- [Power Supply](https://grobotronics.com/rotary-encoder-module-for-arduino-rectangle-pcb.html)  
- [Rocker Switch](https://grobotronics.com/rocker-switch-on-off-blackdaier.html)  

## Problems & Notes  
- Unfortunately, the project did not work as intended. The stepper motor was not strong enough to handle the dress's weight.  
- The **DRV8825 driver** overheated after a few minutes. This was patched by adding an **80mm 12V fan** on top of the enclosure box.  
- The stepper motor overheated, likely due to the dress’s inertia on each rotation change.  
- The motor overheating caused the **M5 bolts** on the motor mount to loosen, leading to the mount falling.  

### Conclusion  
A **larger stepper motor** or switching to a **more powerful DC motor** would be required for better performance.  

