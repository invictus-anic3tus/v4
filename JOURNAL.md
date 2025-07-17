---
title: "v4"
author: "Anicetus"
description: "My custom FPV drone and controllers!"
created_at: "2025-05-27"
---

## total time: 64+1/3 hrs

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
    * Vert: Up/down
    * Button: arm/disarm  
2. Right joystick (right thumb):  
    * Horiz: Roll (strafe left or right)  
    * Vert: Pitch (forwards or backwards)  
    * Button: mode switch (manual, auto, idk)  
3. Potentiometer (left thumb): throttle/camera angle
4. Button 1 (left index): land  
5. Button 2 (right index): emergency poweroff  
6. Button 3 (left middle): beep buzzer  
7. Button 4 (right middle): programmable macro  
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

1.5 hrs

### day seventeen - june 24
today i started the fc-esc stack mount, and i was looking for the included screw sizes. so i opened up my BOM and klicked on my amazon link that i was gonna buy from and... it's out of stock. NOOOOOOO!! It was an amazing price too!!! hopefully it gets back in stock... the ebay link also expired. the aliexpress link is still up, but it's selling for $77, which is a lot more than the amazon one was. I looked around, and the only good ebay links i found were $70 plus shipping. for reference, the original amazon product was $65.99. I looked at the official manufacturer website and was shocked to see it selling for only $60! I put it in the checkout to see what shipping was, and it was free!

You know what wasn't free?

Tariffs.

If you don't know it already about me, I'm politically right and I support President Trump and what he's doing. But $27 tariffs?????? COME ON! It was 45% tariffs. Yep, u heard me right, 45%. That put it at $90. Not ideal.

I'll do more looking around... also cadded the drone legs and made a slot for the esp32 receiver. i edited the gps mount a bit, and positioned it to look nice.

3 hrs

### day eighteen - june 25
today i worked a lot on CAD! i fixed some messed up geometry (drag components aaaahhhhh) and edited the legs to be more flexible and printable. i widened the holes for the battery velcro straps. here's some pics

![image](https://github.com/user-attachments/assets/ad514c70-6fa3-4592-b46e-76fc9dd95bd6)

![image](https://github.com/user-attachments/assets/fa5b48e2-9578-486e-bf5e-d762441c12b1)

![image](https://github.com/user-attachments/assets/51331c3d-ca5e-4ffc-98ed-4e8f3d055d73)

![image](https://github.com/user-attachments/assets/8f8e0cd9-9fe7-4a58-9a5f-3115df9a73c3)

![image](https://github.com/user-attachments/assets/cd30d99d-88b2-4640-89a2-548e02e487b9)

![image](https://github.com/user-attachments/assets/8d03450b-98f6-4248-a919-223ac37a8fe2)

![image](https://github.com/user-attachments/assets/22216c64-cb39-4bf1-8d96-0c73bc4da20d)

![image](https://github.com/user-attachments/assets/39a979ce-dcd5-4fee-8cf5-7be51cb39ce7)

![image](https://github.com/user-attachments/assets/ce1a2de2-e50a-4db6-87cd-9fafee48cb77)

![image](https://github.com/user-attachments/assets/19f1e75a-41af-426d-8bdf-4009eb3cbc9a)

2 hrs

![image](https://github.com/user-attachments/assets/311b81d3-92fa-4aba-97b7-5efe645390c0)

### day nineteen - june ??
so I'm writing this on july 3rd, and for the life of me i cant remember what day i actually did this work. i did a ton of work on whichever day it was, and got the top plate probably 75% done! this drone is actually a lot easier than I thought it'd be. Maybe I just got more skilled at CAD since the 3D printer? Idk.

but what I do know is that the end of CAD is actually drawing near. as of writing this, I just bought everything for the printer pi pro, a side-quest I've been taking these past few days. it's a little mod that I'd like to have before continuing work on my 3D printer. more about it on the [github](https://github.com/invictus-anic3tus/Printer-Pi-Pro)!

2.5 hrs

### day twenty - july 3
wow! got a bunch more done today. i connected the two plates via hex standoffs so that they're easy to assemble, sturdy, and not complicated. I colored the components to make them more distinguishable and to make the thing look better. This thing is looking about done!

<img width="708" alt="image" src="https://github.com/user-attachments/assets/5a070070-9145-4116-8797-34c00158d2c5" />

2 hrs

### day twenty one - july 5
yesterday was the 4th of july (AMERICA DAY!), so i didn't do any work. I got a few responses concerning my design, and I was told that the "wings" which hold the motors were likely to bend and make flying difficult. I started to work on it some, thickening them up. I'm just glad I learned this _before_ assembling!

2 hrs

### day twenty two - july 6
today i pretty much finished the drone body! It's looking really smooth, and the arms are definitely much more sturdy. it looks quite clean, even though it's super bloated (lay off the doritos!) it was a bit complicated getting the geometry to work, but it's way worth it.

Will send pics tmrw.

2 hrs
### day twenty three - july 7
wow! it's already july 7th.... crazy. anyways, I think I've actually finally finished the drone body! I've been working a bunch on the controllers as well. right now, they just look like ugly boxes, but i intend to give them nice curvy shapes and whatnot.

Here's some pics!

![image](https://github.com/user-attachments/assets/d5d0785c-1a41-42df-9a42-b67c3cfa92cb)

![image](https://github.com/user-attachments/assets/9df8e3eb-8f35-4f22-a39c-59e7fc87e8e5)

![image](https://github.com/user-attachments/assets/b5275ea1-4d3d-4845-8ff4-410dcf5ef43b)

![image](https://github.com/user-attachments/assets/e7b45083-06a8-42ad-b18a-efd1bd423089)

![image](https://github.com/user-attachments/assets/8a9e86af-5291-43c7-ac44-00c19515d88a)

![image](https://github.com/user-attachments/assets/0171f1f2-f4c1-44cc-b2ef-3b71c64663fb)

3 hrs

### day twenty four - july 8
today was quite productive! I did a ton of work on the controllers and got them half-finished. They're super complex and assembly will be really fun (both sarcastic and not lol).

![image](https://github.com/user-attachments/assets/5b3d88b1-ea6b-4586-85e4-091dc83568cd)

![image](https://github.com/user-attachments/assets/840fd6ed-71af-4338-afd0-7919140ab032)

![image](https://github.com/user-attachments/assets/ca0528ff-2e2b-4f51-83d0-c0c3b8f209e6)

![image](https://github.com/user-attachments/assets/50a62f9a-2b12-4e75-8e5e-5b2cc921d7e1)

3 hrs

### day twenty five - july 9
dang I was fire today

finished the controllers! They each have a joystick w/ button for the up/down, forwards/backwards, pitch/yaw, and strafe, as well as two extra buttons on each for more features. The left joystick has a potentiometer for throttle control and camera pitch when a button is pressed. They're kinda ugly and boxy, but for what I had to work with, I'm quite proud of them.

![image](https://github.com/user-attachments/assets/33f252d8-33b9-48f3-9a11-9279bfad95ed)

![image](https://github.com/user-attachments/assets/931e280e-aa5a-405f-9829-757e1fa48eeb)

![image](https://github.com/user-attachments/assets/2a8bdec6-8ddb-4e72-af88-63a8516662e2)

![image](https://github.com/user-attachments/assets/9d8d1669-9881-4887-b638-8b93104291eb)

2.3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333 hrs

### day twenty six - july 10
today i made some minor changes and did a big ol github overhaul. I researched a bunch on using ESP-Now for the receiver and stuff, and found out it's a bit easier than i thought. i also made a lil hole for the esp32's antenna to route through on the drone. unfortunatley, I realized my drone batteries dont fit, so i need to rework those. also need to add switches for on/off

2.5 hrs

### day twenty seven - july 11
today I did more work on the drone controllers, trying to get the batteries to fit. not a whole lot of time tho because my MOM'S BRITHDAY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

2 hrs

### day twenty eight - july 13
today i finished the controllers 100% finally! Assembly is definitely going to be a challenge because of how intricate they are, but I'm prepared to make revisions to them if needs be. I also incorporated power switches finally! the most difficult part of assembly is hands down going to be the power wiring. the battery has to go positive to the switch, then to the esp32, and negative straight to the esp32, but all the while, the esp32 will have to be wired to the switches, pot, and joystick. I'm frankly not sure I've allotted enough space for wires to go... I'll see.

<img width="434" height="530" alt="image" src="https://github.com/user-attachments/assets/2ddd64c0-a5bc-4356-9c4d-009299c0d1b7" />

<img width="289" height="412" alt="image" src="https://github.com/user-attachments/assets/4d378d84-fa77-4f19-bde7-726dd55b0c8a" />

<img width="366" height="516" alt="image" src="https://github.com/user-attachments/assets/56430824-9964-4345-9273-bd3aec110b5a" />

<img width="476" height="574" alt="image" src="https://github.com/user-attachments/assets/835d215c-8fa2-4777-ad80-f047b8538eb0" />

Oh poo. I went over my BOM to try to optimize it, you know, review parts that were overkill or unnecessary. I did take out the Caddx Ratel Pro camera in favor of the Ratel 2, which is cheaper and which many claim to be better. That brought the cost down $5, which I was pleased about! I went through, changing stuff and finding cheaper versions on AliExpress, until I got to the VTX. I never inputted the price on it. It's $25. That means that my entire BOM was $25 more than I thought! That brought it to a staggering $373, even after optimizing the other parts. I didn't know what to do, so I just kept optimizing, hoping to be able to find cheaper parts. I was concerned that I might have to get rid of buying carbon fiber filament, which I'd planned on in order to keep the body from flexing. I cut $5 from overpriced joysticks on Amazon, $5 from my battery charger, in favor of a cheaper model, and a cheaper seller of my FC-ESC stack. In the end, I brought it down to $349.93! Ouch.

3 hrs

### day twenty nine - july 15
today i basically cleaned up the BOM some more and started working on the controllers/receiver firmware. I've kinda found an issue though... most drone controllers' throttle control doesn't snap to center, but the joystick modules I'm getting do, and the spring can't be removed without affecting the other direction, which for the the throttle joystick would be yaw. removing the spring would cause the drone to never stop rotating in place! I tried to do a bunch of research on this, but it's hard to figure out what to do. The firmware is a bit more complicated than I'd expected, but I got a bunch done after getting the general idea of it.

3 hrs

### day thirty - july 16
figured out the throttle! I decided to leave it with the spring in... here's how I explained it to ChatGPT when I was brainstorming:


So the "throttle" control is just the percentage of motor power, not distinctly up/down or speed. I had thought that throttle meant motor power while moving, aka speed, and that there was a separate control for up/down that controlled motor power while stationary. However, the former is really just how far I push the forwards/backwards/left/right joystick, while the latter is more of what throttle is.

So the drone is always in either one of two states while flying: no X/Y plane movement or moving in the X or Y direction. If I control throttle in the first state, it simply causes the drone to move upwards the entire time the throttle percentage is above hover, and downwards if the throttle percentage is below hover. If I change throttle in the second state, while the drone is tilted in a direction, it will move faster in that direction but also start to move upwards.

If I leave the spring in, then in the software I can configure the midpoint to be exactly at the hover percentage (likely much lower than 50% in my scenario, somewhere around 25%). This means that in the first state, with no throttle control, the drone will always be at hover. I can specifically control it and pull down to make the drone go down, up to go up, and when releasing, it will hover at that position. In the second state, with no throttle control, the drone will be moving along the X/Y axes at a speed relative to how far I'm pushing the X/Y movement joysticks. When I increase throttle in the second state, the drone will begin to move in the X/Y plane a bit faster, while going upwards as well. The opposite for decreasing throttle. When taking off with the spring, The drone starts up and immediately goes to the hover percentage, meaning it only lifts a small bit above the ground, if at all. If I want the drone not to shake or lift immediately, I can hold the throttle joystick down when arming.

If I somehow take out the spring for throttle but not yaw, in the first state the drone will only be at hover if I specifically set it there, and otherwise will drift up or down. In the second state, the drone will either steadily climb a bit or lower a bit when throttle is the least bit off center, and when deliberately controlling, will stay at that level and continue to rise/fall at that rate until I manually bring it back to center. Taking off would be easier, however, as the motors would be idle until I manually lift the joystick to have the drone rise.


I did a bunch more work on firmware! I am very pleased :3

3.5 hrs

