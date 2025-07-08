<div align="center">
  <h1>v4</h1>

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
- [Setup](#setup)
- [Bill of Materials](#bill-of-materials)
- [Contributing](#contributing)


# About
I've been trying to make a drone for a _long_ time. It was my 10th birthday, and my grandparents bought me a toy drone--you know, the kind with the tiny hobby motors and dinky little cameras. I liked flying with it, but it had some drawbacks. For one, it was slow and weak. Flying it in any amount of wind was impossible; it would simply get carried away. It couldn't go fast at all, and speed is really the most fun part of flying a drone. The camera was small and the transmitter slow, so attempting to fly via the mobile camera app was impossible because of the latency. However I will say that it had a 40 min total battery life, between the two 1S 1800mAh batteries it used.

In February of 2024, that all started to change.

It was rough at first. I'd started to get fed up with the silly drone, and I wanted to make one of my own. However, it wasn't _really_ my own at all. I was planning to use the same motors in the old drone, and even the same camera if I was able. (I wasn't.) I thought that by giving it an ESP32 as a brain and an ultrasonic distance sensor as eyes, I could turn the drone into something really neat. The flaw with this idea was that I wasn't really changing anything. Sure, using an ESP32 would let me give it custom programming and stuff, but by trying to use the same motors as the old drone, I was essentially creating a new shell for an old drone.

Besides that, by adding all the extra components, I was making the drone too heavy for the motors to lift. The ESP32s would limit the drone's range (not like it was great to begin with), and all in all it was a fairly silly drone. I blew through three revisions of the thing, each hoping that it would work. Needless to say, none of them did.

It was extremely frustrating. I was more than ready to scrap the entire project and move on to something else.

When Highway came along. [Highway](https://highway.hackclub.com/) is a [Hack Club](https://hackclub.com/)-run You Ship, We Ship (YSWS) event where anybody and everybody who makes a hardware project and journals it along the way gets a grant to build it! From the very start (hehe I got leeks early >:D) I knew I wanted to finish the drone using this program. So I scrapped all my earlier ideas
