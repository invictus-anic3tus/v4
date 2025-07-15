This is the directory containing the files for the controllers and the drone-side receiver. To install the code, first download and install the [Arduino IDE](https://arduino.cc/en/software) app. This will flash the code to your microcontroller. Launch it once installed, and go to File -> Preferences. Add this URL at the end of the "Additional Boards Manager URLs" input: https://jihulab.com/esp-mirror/espressif/arduino-esp32.git and hit OK to exit. Go to Tools -> Board -> Boards Manager... and type ESP32. Find the latest version by Espressif Systems and install it. Now to go Tools -> Board -> ESP32 Arduino and scroll down to select XIAO_ESP32C3.

After completely powering off the drone, plug in the USB port on the back of the drone to your computer, and then open Tools -> Port. If you know which port is your USB for the XIAO, select it. If you're not sure which one it is, close the Port interface, unplug the USB, open it again, and see which one is missing. The one that's now missing is the USB port for the XIAO. Plug the USB back in, and if the port selection doesn't automatically refresh, open and close it and select the correct port.

If unplugging and plugging the USB doesn't make a difference, try using multiple different cables to see if the cable is the issue.

Now you need the SBUS library for the receiver. Open a terminal window and navigate to `C:\Users\{username}\Documents\Arduino` on Windows, `/Users/{username}/Documents/Arduino` on Mac, or `/home/{username}/Arduino/libraries` on Linux. Now run `git clone https://github.com/bolderflight/sbus.git`.

Finally, paste the receiver code text from above into the code window in Arduino IDE and hit the forward arrow button in the top left. Once the code is completely uploaded, you can unplug the USB.

Now you can plug in the controllers and paste the code in for each one, uploading like before.
