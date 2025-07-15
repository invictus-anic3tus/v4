<div align="center">
  <h1>v4</h1>
  <p>by anicetus</p>

  <img src="https://github.com/user-attachments/assets/801288e2-b164-47a1-a751-db6bcc992d8a" alt="title image" />

  <p display="inline">
  
  <a href="https://creativecommons.org/licenses/by-nc/4.0/">
    <img src="https://licensebuttons.net/l/by-nc/4.0/88x31.png" alt="Creative Commons Attribution-NonCommercial 4.0 International License"></a> <a href="https://hackclub.com/highway">
    <img alt="Funded by Hack Club" src="https://img.shields.io/badge/Hack_Club-Funded-ec3750?style=for-the-badge&logo=hackclub&logoColor=ec3750"></img>
  </a>

  </p>

  <h1></h1>

  <p>
    A powerful, budget, open source 5" FPV quadcopter--perfect for freestyling, casual flying, and even short races!
  </p>
</div>


<sub>This work is licensed under a
[Creative Commons Attribution-NonCommercial 4.0 International License](https://creativecommons.org/licenses/by-nc/4.0/).
</sub>

## Table of Contents
- [About](#about)
- [Features](#features)
- [Specifications](#specifications)
- [Controllers](#controllers)
- [Setup](#setup)
  - [Assembly](#assembly)
  - [Firmware](#firmware) 
- [Bill of Materials](#bill-of-materials)
- [Contributing](#contributing)


# About
I've been trying to make a drone for a _long_ time. It was my 10th birthday, and my grandparents bought me a toy drone--you know, the kind with the tiny hobby motors and dinky little cameras. I liked flying with it, but it had some drawbacks. For one, it was slow and weak. Flying it in any amount of wind was impossible; it would simply get carried away. It couldn't go fast at all, and speed is really the most fun part of flying a drone. The camera was small and the transmitter slow, so attempting to fly via the mobile camera app was impossible because of the latency. However I will say that it had a 40 min total battery life, between the two 1S 1800mAh batteries it used.

In February of 2024, that all started to change.

It was rough at first. I'd started to get fed up with the silly drone, and I wanted to make one of my own. However, it wasn't _really_ my own at all. I was planning to use the same motors in the old drone, and even the same camera if I was able. (I wasn't.) I thought that by giving it an ESP32 as a brain and an ultrasonic distance sensor as eyes, I could turn the drone into something really neat. The flaw with this idea was that I wasn't really changing anything. Sure, using an ESP32 would let me give it custom programming and stuff, but by trying to use the same motors as the old drone, I was essentially creating a new shell for an old drone.

Besides that, by adding all the extra components, I was making the drone too heavy for the motors to lift. The ESP32s would limit the drone's range (not like it was great to begin with), and all in all it was a fairly silly drone. I blew through three revisions of the thing, each hoping that it would work. Needless to say, none of them did.

It was extremely frustrating. I was more than ready to scrap the entire project and move on to something else.

When Highway came along. [Highway](https://highway.hackclub.com/) is a [Hack Club](https://hackclub.com/)-run You Ship, We Ship (YSWS) event where anybody and everybody who makes a hardware project and journals it along the way gets a grant to build it! From the very start (hehe I got leeks early >:D) I knew I wanted to finish the drone using this program. So I scrapped all my earlier ideas (ESP32 brain, tiny motors) and started the fourth version of my drone! You can read all about my journey [here](https://github.com/invictus-anic3tus/v4/blob/main/JOURNAL.md).

# Features
- An analog video system, utilizing the Caddx Ratel Pro camera with the HGLRC Zeus Nano 350mW VTX
- 110° rotating camera
- 5-minute flight time per battery
- An ESP32C3 XIAO receiver
- ESP32C3 XIAO dual controllers
- A drone finder buzzer for crashes
- A leading GPS module, the HGLRC M100-5883
- The Speedybee F405 Mini FC-ESC stack
- Powerful iFlight XING E-Pro 2207 2450kV motors
- 5045 propellers
- 3D-printed case for both drone and controllers
- Only uses M3 screws

## Specifications

|          Specification           |  Value  |
|----------------------------------|---------|
| Battery Voltage                  | 14.8V   |
| Battery Life                     | 1550mAh |
| Total Weight                     | ~650g   |
| Weight (Minus Battery)           | ~460g   |
| Average Total Power Consumption* | 200W    |
| Average Flight Time Per Battery* | 6 min   |
| Flight Range (Untested)          | 400m    |

*When flying in normal weather at low to mid-range speeds

# Controllers

The v4 is designed to be controlled by an ESP-NOW-based controller. The drone has a slot for an ESP32C3 XIAO to fit, which can communicate to the ground controller which also has an ESP32. This ESP32 controller can be any shape and size you wish, but there are 3D-printable dual handheld controllers already made. You can see the code for the controllers and drone in the firmware folder above.

# Setup

## 3D Printing Instructions
| Part             | Details                                     |
|------------------|---------------------------------------------|
| Main body        | 30-50% infill, 6 walls, PETG-CF or similar  |
| Top              | 30-50% infill, 6 walls, PETG-CF or similar  |
| Servo casing top | 30-50% infill, Any stiff filament           |
| Camera pivot     | 30-50% infill, Any stiff filament           |
| Legs             | 3 walls, TPU or similar                     |
| GPS mount        | 50% infill, TPU or similar                  |
| ESP32 cover      | Any stiff filament                          |

## ⚠️ PETG-CF Warning ⚠️
The way carbon fiber filaments work is by adding little... you guessed it... fibers of carbon to the plastic to make it more strong and durable. This is great for parts that undergo a lot of stress, such as drones, but the downside is that small fiber shards have all the tendencies of splinters. They can get deep into your skin. They're too small to pick out with tweezers, and only dig deeper when washing your hands. You should wear gloves when assembling PETG-CF parts, and even when transporting the drone. If you do get carbon fibers in your skin, however, try using duct tape to rip them out. Leaving them in can cause permanent itchiness and irritation.

## Assembly

### Camera
First, install an M3 4mm depth brass heatset insert into the large hole on the camera pivot. Next, take the 9g servo and attach the pivot to it. Make sure that the servo is at the 90° position first! Also ensure that the pivot is a tight fit. If the tolerances are too small, the camera could slip and point downwards throughout the entire flight. Note that the camera pivot piece does not have tolerances already. Try printing it multiple times with mulitple tolerances (using the tolerance settings in your 3D printer slicer of choice) to try to find the minimal tolerances you can get while it fits. After attaching the pivot, screw the camera into the slot using the screws it includes. Make sure that it can't wiggle while in the mount. Place the setup in the drone body as seen in the CAD design.

### Body
Assembling the drone body is very easy. First, take the large baseplate piece, and insert M3 brass heatset inserts into every 4.7mm hole, as seen in the CAD design. Next, insert the FC-ESC stack using the M3 screws included with it, with the FC on top! Make sure that the screw heads are at the bottom of the drone. Place spacers on the tops of two diagonally opposite screws, and put the VTX on. Fasten the VTX down with the nuts included with the FC-ESC. Now insert M3 brass heatset inserts into the legs and screw them into the base. Screw in all four motors using the screws they came with, making sure to route the three wires through the tunnels in the base.

Place the battery at the back of the drone, and route a velcro strap through the base to secure it in place. Take the TPU GPS mount and screw it onto the tail of the drone with two M3 screws. Press the GPS into it. Place the ESP32 into its slot, and screw in its panel. Attach the antenna which came with the ESP32 and secure it to the bottom of the drone, using extra tape if needed.

Add a heatset insert to the large hole of the servo top piece. Screw it in place to the main body piece. This is when you'll wire everything. Make sure to route the wires through the top piece for the buzzer before soldering them, since the pins of the buzzer stick through the top piece.

<img width="2400" height="1800" alt="FC Wiring" src="https://github.com/user-attachments/assets/3daa0e85-d86a-4c2b-a572-caad2b970fdd" />

<img width="1116" height="1837" alt="ESC wiring" src="https://github.com/user-attachments/assets/5aefe95c-96e9-4418-8326-385645bf32c9" />

Now add heatset inserts to the top piece. It needs four to secure the FC-ESC stack, as well as eight along the sides to connect to the arms. Screw in the M3 standoffs as shown in the CAD design, and place the top piece on top of them. Screw it to the standoffs and the plastic piece on the front as well as from the arms and to the servo top piece.

All done!

### Controllers
Instructions coming soon, for now see the CAD design

Wiring diagram: (For left controller; the right one simply omits the standalone potentiometer)

![Controller Wiring](https://github.com/user-attachments/assets/d50aeb38-5a00-43ba-86bf-0838346216b4)

## Firmware
See the [Speedybee F405 Mini manual](https://store-fhxxhuiq8q.mybigcommerce.com/product_images/img_SpeedyBee_F405_Mini_BLS_35A/SpeedyBee-f405-mini-stack-Manual-en.pdf) for firmware and FC-ESC setup.

# Bill of Materials

|Part                      |Quantity|Unit Price|Total Price|Amazon Link                                                                             |AliExpress Link                                     |eBay Link (can change)               |Manufacturer                                                                            |Weight on Drone (g)|Alt. Product                                 |Notes                                                                                                    |Cheapest                                                  |
|--------------------------|--------|----------|-----------|----------------------------------------------------------------------------------------|----------------------------------------------------|-------------------------------------|----------------------------------------------------------------------------------------|-------------------|---------------------------------------------|---------------------------------------------------------------------------------------------------------|----------------------------------------------------------|
|analog camera             |1       |$31.23    |$31.23     |https://www.amazon.com/Caddx-Ratel-Micro-Camera-Switchable/dp/B0DDBW1D5F/               |https://www.aliexpress.us/item/3256807158842523.html|https://www.ebay.com/itm/157155289889|https://caddxfpv.com/products/ratel-2-1-1-8inch-starlight-sensor-freestyle-fpv-camera   |5                  |                                             |                                                                                                         |amazon, but aliexpress is just a bit more for more reviews|
|FC-ESC Stack              |1       |$75.15    |$75.15     |F405 Mini Stack                                                                         |https://www.aliexpress.us/item/3256806779866237.html|https://www.ebay.com/itm/145520506360|https://www.speedybee.com/speedybee-f405-mini-bls-35a-20x20-stack/                      |13.5               |                                             |speedybee f405 mini stack                                                                                |aliexpress                                                |
|ESP32C3 XIAOs (3 pack)    |1       |$19.99    |$0.00      |https://www.amazon.com/Seeed-Studio-XIAO-ESP32C3-Microcontroller/dp/B0DGX3LSC7          |https://www.aliexpress.us/item/3256805195972424.html|https://www.ebay.com/itm/256334636719|https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C3-3PCS-p-5920.html                  |4                  |                                             |One for drone-side receiver, two for controllers                                                         |amazon (or manufacturer depending on shipping cost)       |
|Headset                   |1       |$54.19    |$54.19     |(none found)                                                                            |(none found)                                        |(any pre-owned set you can find)     |https://emax-usa.com                                                                    |                   |                                             |I used the Emax Transporter, feel free to use whatever analog goggles you'd like                         |manufacturer                                              |
|Buzzer                    |1       |$2.12     |$2.12      |https://www.amazon.com/Cylewet-Electronic-Magnetic-Continuous-Arduino/dp/B01N7NHSY6/    |https://www.aliexpress.us/item/2255800643239740.html|https://www.ebay.com/itm/324358979243|(none)                                                                                  |2                  |                                             |get the 12x9.5 5V kind                                                                                   |aliexpress                                                |
|VTX                       |1       |$24.99    |$24.99     |https://www.amazon.com/HGLRC-Microphone-Switchable-Transmitter-Betaflight/dp/B08MQ4ZDVF/|Likely not a good seller                            |https://www.ebay.com/itm/236115710085|https://www.hglrc.com/products/hglrc-zeus-nano-vtx-350mw-for-fpv-racing-drone           |2.4                |rush tank ultimate plus - $40                |                                                                                                         |amazon                                                    |
|drone batteries           |1       |$50.63    |$50.63     |https://www.amazon.com/Ovonic-Packs-1550mAh-Battery-Racing/dp/B0821YX6JB/               |$2 cheaper but less buys                            |4-pack but cheaper per battery       |https://us.ovonicshop.com/products/ovonic-100c-14-8v-1550mah-4s1p-xt60-lipo-battery-4pcs|190                |                                             |                                                                                                         |ebay (can change)                                         |
|battery straps            |1       |$2.67     |$2.67      |https://www.amazon.com/Apex-RC-Products-Non-Slip-Battery/dp/B01MRJ7BUY/                 |https://www.aliexpress.us/item/3256806939437749.html|https://www.ebay.com/itm/267163799860|(none)                                                                                  |5                  |                                             |Length 250+ mm, width ≤20mm                                                                              |aliexpress                                                |
|18mm M3 standoffs         |2       |$2.30     |$4.60      |(none found)                                                                            |https://www.aliexpress.us/item/3256808051105851.html|https://www.ebay.com/itm/394867520163|(none)                                                                                  |9                  |                                             |M3x18+6, make sure they're threaded, need 6 total                                                        |aliexpress                                                |
|Body (filament)           |1       |$19.99    |$19.99     |                                                                                        |                                                    |                                     |                                                                                        |250                |                                             |any reliable PETG-CF brand is good: Atomic Filament's is the best, but really expensive                  |amazon (most likely)                                      |
|gps                       |1       |$18.99    |$18.99     |https://www.amazon.com/HGLRC-M100-5883-GPS-Generation-Compatible/dp/B0CB5N8RQ8          |Very sketchy seller                                 |https://www.ebay.com/itm/365491316265|https://www.hglrc.com/collections/gps-module/products/m100-5883-gps                     |7.8                |                                             |                                                                                                         |aliexpress, but amazon is $0.4 more for better seller     |
|diodes                    |1       |$0.98     |$0.98      |https://www.amazon.com/BOJACK-Rectifier-IN4007-Electronic-Silicon/dp/B07Q6J9TNW/        |https://www.aliexpress.us/item/3256801365779334.html|https://www.ebay.com/itm/233978474455|(none)                                                                                  |                   |                                             |for the controller battery charging                                                                      |aliexpress                                                |
|joysticks                 |1       |$1.81     |$1.81      |https://www.amazon.com/Teyleten-Robot-Dual-axis-Controller-Raspberry/dp/B0CPFDKWZF/     |https://www.aliexpress.us/item/3256806299955871.html|https://www.ebay.com/itm/116398486698|(none)                                                                                  |                   |                                             |haz buttons!!!!                                                                                          |aliexpress                                                |
|buttons                   |1       |$1.82     |$1.82      |https://www.amazon.com/QTEATAK-Momentary-Tactile-Button-Switch/dp/B07VSNN9S2            |https://www.aliexpress.us/item/3256802301084670.html|https://www.ebay.com/itm/115663380319|(none)                                                                                  |                   |                                             |6mm tactile switch, height ≤5mm                                                                          |aliexpress                                                |
|small lipo batteries      |2       |$6.74     |$13.48     |https://www.amazon.com/EEMB-Battery-Rechargeable-Connector-Certified/dp/B095VN3JHW/     |(none found)                                        |https://www.ebay.com/itm/357122701041|(none)                                                                                  |                   |                                             |for powering the controllers - get any size smaller than in the CAD design                               |amazon (I wouldn't trust aliexpress with batteries)       |
|controller on/off switches|1       |$3.20     |$3.20      |https://www.amazon.com/Tnuocke-Vertical-Position-Latching-SS12F44-G5/dp/B099MN9JFP      |https://www.aliexpress.us/item/3256803752541650.html|https://www.ebay.com/itm/296516034736|(none)                                                                                  |                   |                                             |get the ss12f44 model                                                                                    |aliexpress                                                |
|Drone battery charger     |1       |$24.99    |$24.99     |https://www.amazon.com/SKYRC-B6Neo-Balance-Battery-Discharger/dp/B0CCT2WGNS/            |https://www.aliexpress.us/item/3256805953719537.html|https://www.ebay.com/itm/286231446903|https://www.skyrc.com/b6neo+                                                            |                   |https://www.amazon.com/gp/product/B0CYBXM3JV/|the skyrc b6 neo is great, but the alt linked amazon one seems good too                                  |amazon                                                    |
|Motors                    |1       |$63.00    |$63.00     |https://www.amazon.com/SPARKHOBBY-Brushless-5-6inch-Propeller-Freestyle/dp/B0D791QQ64/  |https://www.aliexpress.us/item/3256807565015473.html|https://www.ebay.com/itm/364104658026|https://shop.iflight.com/xing-e-pro-2207-2-6s-fpv-nextgen-motor-pro874                  |136                |                                             |these are the ones I got, but please please please research your own 2207 models (16x16 mounting pattern)|amazon                                                    |
|Props                     |2       |$2.24     |$4.48      |https://www.amazon.com/PHJKCRWXUL-6x4-5-3-Blade-Propeller-Quadcopter/dp/B0FB7VC2BD      |https://www.aliexpress.us/item/3256804148539664.html|https://www.ebay.com/itm/285665860636|(none)                                                                                  |20                 |                                             |please research these yourself (but get 5045 size)                                                       |aliexpress                                                |
|Tax                       |        |          |$23.48     |                                                                                        |                                                    |                                     |                                                                                        |                   |                                             |                                                                                                         |                                                          |
|Total                     |        |          |$421.80    |                                                                                        |                                                    |                                     |                                                                                        |644.7              |                                             |                                                                                                         |                                                          |

# Contributing

If you'd like to request something, give feedback, or wish to make your own changes, simply open an issue on this repository or email me! (My email is in my profile.)
