---
title: "v4"
author: "Anicetus"
description: "My custom FPV drone and controllers!"
created_at: "2025-05-27"
---

## total time: 27 hrs

# firstly
i want to thank everybody at hack club who's making this possible. if you don't know, hack club is a 100% 501(c)(3) nonprofit run by zach latta + friends made for coders and electronics peoples 18 and under. this project is made possible through their highway to undercity program, where teens are empowered to build their dreams with up to $350 in funding!

so a big thank you out to acon, alex ren, cyao, ducc, bunnyguy, phthallo, paolo, kareem, rhys, kl, ian, tongyu, manitej, cinders, and m0hid!!

## i'm anicetus
if you're reading this on hack club, you may very well already know me. but if you dont, here's a bit of info:  
1. I live in the usa  
2. i'm ok at coding  
3. but i think im pretty good at electronics and stuff!  
4. i've designed a custom keyboard  
5. and a custom 3d printer  

so yeah i've got a bit to put on my resume! but anyways let's get down to business.


# what the project currently looks like

Right now I'm looking at an FPV drone using a standard FC-ESC stack and analog video system. It transmits to Emax Transporter goggles that display it in real-time to my eyeballs! The controller is fully DIY, and instead of being a single controller you hold with both hands, it's sort of like Nintendo joy-cons, with a joystick and two tactile switches on each one:
1. Left joystick (left thumb):  
    * Horiz: Yaw (spin in place)  
    * Vert: camera angle  
    * Button: arm/disarm  
2. Right joystick (right thumb):  
    * Horiz: Roll (strafe left or right)  
    * Vert: Pitch (forwards or backwards)  
    * Button: mode switch (manual, auto, idk)  
3. Button 1 (left index): land  
4. Button 2 (right index): quick press for headless/headed mode, hold for emergency poweroff  
5. Button 3 (left middle): programmable macro  
6. Button 4 (right middle): programmable macro  
I may also add holding functions for the rest of the buttons, where holding a button makes it do something different than normal. Each controller has an ESP32C3 XIAO and a 1800mAh lipo battery in it. The left controller acts as the master in the ESP-Now communication, getting data from the right controller. It then sends its data as well as the right controller's data to the drone's ESP32, also an ESP32C3 XIAO. I'm using XIAOs because they have external antenna ports, which provide better signals than the onboard antennas of other boards. Additionally, I may use a stronger antenna on the left controller and the drone than what comes with the XIAOs.
## bom
[here](https://docs.google.com/spreadsheets/d/e/2PACX-1vSraEE6H8Cx8CHQLCQyQCyDCrQoR9ur6-9fPs5dZ3vY1AYaFjepRuHVCa8LgQ7bhq75_Z4WIajNvxX1/pubhtml)

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

p.s. bom at [this link](https://docs.google.com/spreadsheets/d/e/2PACX-1vSraEE6H8Cx8CHQLCQyQCyDCrQoR9ur6-9fPs5dZ3vY1AYaFjepRuHVCa8LgQ7bhq75_Z4WIajNvxX1/pubhtml)

### day four - 5/27/25
today i researched more peripherals, like the buzzer and docking magnets (might not use these) as well as controller parts like the joysticks and buttons. i got a pretty good idea of how I want the joysticks to work:

each controller has an esp32, a buzzer (for power indication), a joystick, two tactile switches, and a small lipo battery
the headset has an esp32 and a rpi zero 2 w
the esp32s on the controllers connect via esp-now (basically a wifi hotspot for esp32 microcontrollers) to the headset, and relay button presses and joystick movement to the headset esp32. that esp32 connects with i2c to the rpi, which processes the data and conveys it to the drone accordingly

i dont really know how im supposed to do this, but ig i'll figure it out :D

today i started teaching my friend javascript :)
2.5 hrs

### day five - 5/28/25
crudcrudcrudcrudcrudcrudcrudcrudcrudcrudcrudcrudcrudcrudcrudcrudcrudcrudcrud

the motors i got in like december or smth are 2450kv cuz i didnt know what it meant and thought well more powerful the better right?

wrong  
so wrong  
really really wrong  
like, kill this project wrong  
because i didnt stop to think "huh more powerful = more power used" and realize that i need a MASSIVE battery to power these motors. thing is, massive batteries cost massive dollars. and this project doesnt have massive dollars. i'd really hate to waste those motors, but idk what else to do. will do more research on this.

2.5 hrs

### day six - 5/29/25
ok i think i figured it out  
so the motors spec page said max amp draw 35A and i was freaking out cuz that's a LOT. but what i didn't realize (but should have) is that the motors wont be drawing 35A 100% of the time... or even 1% of the time. If I can aim for my drone to be 800g or less, including the battery, then I'll only have to use 40%-50% throttle to get it flying well. The spec sheet also says that 50% throttle using 5045 props (what I have) provides 476g thrust at only 100W of power. Four of those are over 1900g of thrust for only 400W of power! That's way plenty for really any drone.

With that in mind, i looked over different sizes of batteries and eventually landed on 4S's, either 1550mAh ($60 for a four pack on eBay) or 2200mAh ($40 for a two pack on amazon.) The 1550's are looking best rn, since it's more for my money.

All that considered, that's around 3 minutes of flight time per 1550mAh battery/4 min for the 2200mAh's, which isn't very good but not as bad as I thought it would be.

Crisis avoided :D

3 hrs

### day seven - 5/30/25
today i spent some time helping other people! it was really gratifying and made me feel good :)  
i didn't do a ton of research tho except for some headset lenses and other smol things. today is the AMA with Strange Parts!!

1 hr

### day eight - 6/2/25
the past few days ive been hanging out with my friend irl so havent got much done. however today i did a bunch of research on cameras and stuff, and found a $55 headset... cheaper than literally just my VRX. makes me wonder if i would be able to just get that instead, seeing as how it does the exact same stuff, better, and cheaper.

2 hrs

### day nine - 6/5/25
ok so yesterday and the day before i was focusing mainly on making a corexy guide writeup thingy so i did basically 0 drone work. however today I think I've got the last little bit of research done! I researched how to get the controller commands to the drone, and I think I've settled on ESP-Now.

For those of you who don't know, ESP-Now is a protocol that transfers data quickly between two ESP32 boards. On each handheld controller is an ESP32, and the right controller will send data to the left. The left combines the received data with its own and sends both to the drone. All ESP32s will be ESP32C3 XIAO boards, preferable due to their external antenna ports rather than the PCB antennae. The ESP32 on the drone receives the data and poops it out of its UART channel, which the FC receives grudgingly.

ESP-Now doesn't have a super great range, but I think that if I can optimize it I'll get good results. I don't need hardly any bandwidth, meaning I can get good range instead. Right now I'm looking at a max of close to 0.2 mi (0.3 km) in good weather and in a fairly open area. I've looked at tests, both using onboard and external antennae, and I've gathered that 500 ft (150 m) is when it begins to drop off a bit. That's pretty good in my opinion, especially since I'm not gonna be flying this thing around the city or whatever.

I also did a bit more headset research. So the headset I was looking at is the Emax Transporter (not 2 lol im not that fancy) headset, and from videos ive seen online it's pretty decent--especially for less than $60 😭 Anyways, I asked if it would be fair if I could get it instead of making my own.

Research for this thing has been actually fairly light. I don't think I'm actually quite done yet, there's always something I forget about.

2.5 hrs

### days ten thru twelve - june 6-12
i've been doing a bunch on the 3d printer and less on the drone from the 6th to the 12th, but for two days I worked on some CAD! I cadded the flight controller when i realized that there wasn't one, and also a few other small things. i found some 3d models online and that's pretty much it. on the 12th i left for church camp! cya soon :D

3 hrs

### day thirteen - june 18
back from church camp! I made a model for the switches im using in the DIY controller, and re-analysed the bom for anything I could get rid of. i popped all the components into one design, and started organizing it and seeing what would go where.

1.5 hrs

### day fourteen - june 20
im multitasking between this and 3d printer so im sorry im doing so little :sob:

anyways i worked on a bunch of cad and started the frame! it's looking quite nice if i do say so myself. I made a lil mount for the GPS at the back. im not super proud of it but i think its ok. does what it's supposed to lol.

![image](https://github.com/user-attachments/assets/8c5634c8-6c9e-4cad-a011-c4a478e75673)

2 hrs

### day fifteen - june 22
today I just focused on the drone, and did more frame! I got the servo + camera mounts done, so that the camera can go up and down :D

![image](https://github.com/user-attachments/assets/b6791086-e8e6-4012-ab29-bac96c41c1de)

2 hrs

### day sixteen - june 23
today I fixed a bunch of stuff with the camera mount, and colorized the camera itself, just to make it look nice. I should've done more today, but I got sidetracked by some stuff. However, it's looking quite nice so far!
