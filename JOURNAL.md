---
title: "v4"
author: "Anicetus"
description: "My custom FPV drone plus headset!"
created_at: "2025-05-27"
---

## total time: 5 hrs

# firstly
i want to thank everybody at hack club who's making this possible. if you don't know, hack club is a 100% 501(c)(3) nonprofit run by zach latta + friends made for coders and electronics peoples 18 and under. this project is made possible through their highway to undercity program, where teens are empowered to build their dreams with up to $350 in funding!

so a big thank you out to acon, alex ren, and everybody else who pulled this together.

hello!

# i'm anicetus
if you're reading this on hack club, you may very well already know me. but if you dont, here's a bit of info:
1. I live in the usa
2. i'm ok at coding
3. but i think im pretty good at electronics and stuff!
4. i've designed a custom keyboard
5. and a custom 3d printer

so yeah i've got a bit to put on my resume! but anyways let's get down to business.

# bom
| Part                | Quantity | Unit Price | Total Price | Link                                                                                                                                                                               | Alt. Link                                                                                                         | Alt. Alt. Link                                                                               | Notes                                                |
| ------------------- | -------- | ---------- | ----------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------- | ---------------------------------------------------- |
| RPi Camera 3        | 1        | $25.00     | $25.00      | [https://www.amazon.com/Arducam-Raspberry-Camera-Autofocus-15-22pin/dp/B0C9PYCV9S](https://www.amazon.com/Arducam-Raspberry-Camera-Autofocus-15-22pin/dp/B0C9PYCV9S)               |                                                                                                                   |                                                                                              | maybe skip rpis and just get an analog cam           |
| FC-ESC Stack        | 1        | $55.99     | $55.99      | [F405 Mini - $70 - little amperage](https://www.amazon.com/SpeedyBee-Controller-20x20mm-Bluetooth-BLHeli_S-Wireless/dp/B0CF1X3N5V)                                                 | [F405 - $100](https://www.amazon.com/SpeedyBee-Flight-Control-30x30mm-Aircraft/dp/B0CKMKTLDW)                     | [F405 AIO - $65](https://www.amazon.com/SpeedyBee-F405-AIO-Flight-Controller/dp/B0DLKT9DS4/) | speedybee f405 v4 mini or f405 v4 or f405 aio?       |
| 7" Screen           | 1        | $45.99     | $45.99      | [https://www.amazon.com/Hosyond-Display-1024%C3%97600-Capacitive-Raspberry/dp/B09XKC53NH](https://www.amazon.com/Hosyond-Display-1024%C3%97600-Capacitive-Raspberry/dp/B09XKC53NH) |                                                                                                                   |                                                                                              |                                                      |
| Rpi 5?              | 1        | $0.00      | $0.00       |                                                                                                                                                                                    |                                                                                                                   |                                                                                              | $70 if needed                                        |
| Drone-side receiver | 1        | $18.99     | $18.99      | [https://www.amazon.com/BETAFPV-ExpressLRS-Receiver-Refresh-Performance/dp/B09B28HSVB](https://www.amazon.com/BETAFPV-ExpressLRS-Receiver-Refresh-Performance/dp/B09B28HSVB)       |                                                                                                                   |                                                                                              |                                                      |
| Rpi Zero 2 W        | 1        | $0.00      | $0.00       | owned                                                                                                                                                                              |                                                                                                                   |                                                                                              |                                                      |
| VRX                 | 1        | $70.00     | $70.00      |                                                                                                                                                                                    |                                                                                                                   |                                                                                              |                                                      |
| Buzzer              | 1        | $5.49      | $5.49       | [https://www.amazon.com/WEICHUANG-Active-Electronic-Buzzer-Continous/dp/B08SL2HH65/](https://www.amazon.com/WEICHUANG-Active-Electronic-Buzzer-Continous/dp/B08SL2HH65/)           |                                                                                                                   |                                                                                              |                                                      |
| VTX                 | 1        | $24.99     | $24.99      | [rush tank ultimate plus - $40](https://www.getfpv.com/rush-tank-ultimate-plus-5-8ghz-vtx-w-smart-audio.html)                                                                      | [hglrc Zeus350mW - $25](https://www.amazon.com/HGLRC-Microphone-Switchable-Transmitter-Betaflight/dp/B08MQ4ZDVF/) |                                                                                              | rush tank ultimate plus or zeus?                     |
| drone battery       | 1        | $21.99     | $21.99      | [https://www.amazon.com/OVONIC-2200mAh-Battery-Airplane-Helicopter/dp/B08R71SWJ3/](https://www.amazon.com/OVONIC-2200mAh-Battery-Airplane-Helicopter/dp/B08R71SWJ3/)               |                                                                                                                   |                                                                                              |                                                      |
| headset battery     | 1        | $0.00      | $0.00       | owned                                                                                                                                                                              |                                                                                                                   |                                                                                              |                                                      |
| filament            | 1        | $24.28     | $24.28      | [https://www.amazon.com/ELEGOO-Filament-30-600mm-Dimensional-Cardboard/dp/B0CJ32W7QL](https://www.amazon.com/ELEGOO-Filament-30-600mm-Dimensional-Cardboard/dp/B0CJ32W7QL)         |                                                                                                                   |                                                                                              |                                                      |
| gps                 | 1        | $19.99     | $19.99      | [https://www.amazon.com/HGLRC-M100-5883-GPS-Generation-Compatible/dp/B0CB5N8RQ8](https://www.amazon.com/HGLRC-M100-5883-GPS-Generation-Compatible/dp/B0CB5N8RQ8)                   |                                                                                                                   |                                                                                              | hglrc m100-5883                                      |
| mini magnets        | 1        | $5.99      | $5.99       | [https://www.amazon.com/VSKIZ-Refrigerator-Multi-use-Neodymium-Whiteboard/dp/B0BW91ZTKZ/](https://www.amazon.com/VSKIZ-Refrigerator-Multi-use-Neodymium-Whiteboard/dp/B0BW91ZTKZ/) |                                                                                                                   |                                                                                              | 6x3mm - for drone docking and maybe battery docking? |
| joysticks           | 1        | $8.99      | $8.99       | [https://www.amazon.com/Teyleten-Robot-Dual-axis-Controller-Raspberry/dp/B0CPFDKWZF/](https://www.amazon.com/Teyleten-Robot-Dual-axis-Controller-Raspberry/dp/B0CPFDKWZF/)         |                                                                                                                   |                                                                                              |                                                      |
| buttons             | 4        | $0.00      | $0.00       | owned?                                                                                                                                                                             |                                                                                                                   |                                                                                              |                                                      |
| gyros (optional)    | 1        | $10.99     | $10.99      | [https://www.amazon.com/HiLetgo-MPU-6050-Accelerometer-Gyroscope-Converter/](https://www.amazon.com/HiLetgo-MPU-6050-Accelerometer-Gyroscope-Converter/)                           |                                                                                                                   |                                                                                              |                                                      |
| wire sleeves        |          |            | $0.00       |                                                                                                                                                                                    |                                                                                                                   |                                                                                              |                                                      |
| Tax                 |          |            | $25.80      |                                                                                                                                                                                    |                                                                                                                   |                                                                                              |                                                      |
| Total               |          |            | $364.48     |                                                                                                                                                                                    |                                                                                                                   |                                                                                              |                                                      |

# captain's log
yes i stinking know high seas ended in january shut up

## research
### day one - 5/23/25
so today was a long haul of researching tons of different parts. mostly i researched the flight controller and different ways to make it work. i know i have a ton of parts to think about, and idk how im going to get the camera footage from the drone to a rpi for the headset.

anyways lots of progress. i'll give it 2 hrs

### day two - 5/25/25
today i was able to do a ton of research on transmitting video from drone to headset. i learned a bunch about VTX's and VRX's, analog and digital cameras. i posted an essay (lol) in #highway-pitstop asking for opinions and stuff (which I never received by the way,) but it explains a bunch. Here:

so i'd like some opinions on something:
I'm thinking about making an FPV drone plus DIY headset, and I already have the motors and some smaller parts. In the beginning I was planning to make it entirely Raspberry Pi-based, but as I've researched more and more I've uncovered the dire truth: raspberry pi drone == more expensive, more complicated, and less powerful than a standard fpv setup (fc, dedicated drone parts, etc.)

#### (begin post)
The headset is about the same thing: I'd planned to power it with a pi but after researching I've figured out that a simple VRX receiver plus HDMI display could do the job more efficiently. I'm still going to do some sort of DIY controller, probably incorporated into the headset somehow (thinking about handheld joysticks wired to a pi zero in the headset, transmitted with some sort of radio transmitter) but after coming across these hurdles, the project is looking a lot less DIY and more "everybody's already done this, it's nothing new and can't be built on."
My current setup is looking like a pretty normal drone, with a dedicated flight controller and some sort of analog video system. (Digital is way too expensive.) The headset will probably be an HDMI screen paired with a VRX receiver with an HDMI output. I'll either make a standard handheld controller or the split keeb of controllers, with a Raspberry Pi and some sort of radio transmitter (haven't researched this yet.) This is the part I can get really creative with, both with design and with autonomous drone control.
I'd really, really need the whole $350 to pull this off, but here's why I think it's worth it: (I know we don't need approval at the beginning, but similarly to the post above I'd like some opinions.)

1. Researching. I've been researching a bit already, and have been overwhelmed by the varieties and complexities of the most abstruse parts. Most of what I peruse is predominately illegible to me, and every answer just reveals more questions. Also, I can't use AliExpress cuz I hate it.
2. Designing. Creating all the parts will probably be challenging. Drone designs aren't a walk in the park; I know that from my previous few months of trying to make a simple one. This will be the vast majority of the project, as like explained above, drone parts today are largely very plug-and-play.
3. The controller programming. The controller is where I really think my creativity can come into play, and where I can experiment with different functionalities and whatnot. I will likely use a Pi Zero 2 W for it, with simple buttons and joysticks.

Unfortunately, even with my rough BOM, I'm already over the $350. I'll have to do quite a bit more researching and poking around, but if there's anything I've learned with the Anicept Vex, one should never make sacrifices to save money.
Sorry for the essay. Thoughts?
#### (end post)

today i was able to focus harder than yesterday, and got a lot done in ~3hrs

### day three - 5/26/25
today i started composing a rough bom. i researched stuff like batteries, better flight controllers, GPS, etc.

however there was a giant storm and the power went off sooooo

1.5 hrs

p.s. bom at the top :3

### day four - 5/27/25
today i researched more peripherals, like the buzzer and docking magnets (might not use these) as well as controller parts like the joysticks and buttons.
