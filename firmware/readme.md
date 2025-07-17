# How to use firmware

This is the directory containing the files for the controllers and the drone-side receiver. To install the code, first download and install the [Arduino IDE](https://arduino.cc/en/software) app. This will flash the code to your microcontroller. Launch it once installed, and go to File -> Preferences. Add this URL at the end of the "Additional Boards Manager URLs" input: <https://jihulab.com/esp-mirror/espressif/arduino-esp32.git> and hit OK to exit. Go to Tools -> Board -> Boards Manager... and type ESP32. Find the latest version by Espressif Systems and install it. Now to go Tools -> Board -> ESP32 Arduino and scroll down to select XIAO_ESP32C3.

## Uploading to the drone receiver

After completely powering off the drone, plug in the USB port on the back of the drone to your computer, and then open Tools -> Port. If you know which port is your USB for the XIAO, select it. If you're not sure which one it is, close the Port interface, unplug the USB, open it again, and see which one is missing. The one that's now missing is the USB port for the XIAO. Plug the USB back in, and if the port selection doesn't automatically refresh, open and close it and select the correct port.

If unplugging and plugging the USB doesn't make a difference, try using multiple different cables to see if the cable is the issue.

Now you need the SBUS library for the receiver. Open a terminal window and navigate to `C:\Users\{username}\Documents\Arduino` on Windows, `/Users/{username}/Documents/Arduino` on Mac, or `/home/{username}/Arduino/libraries` on Linux. Now run `git clone https://github.com/bolderflight/sbus.git`.

Finally, paste the receiver code text from above into the code window in Arduino IDE and hit the forward arrow button in the top left. Once the code is completely uploaded, you can unplug the USB.

## Uploading to the controllers

Now you can plug in the controllers and paste the code in for each one, uploading like before. For the left controller and right controller code files, you'll need to change the MAC address at the top of the code as specified. You can find it by copying the get-mac-address file and uploading it to the ESP32's, then unplugging and re-plugging them back in. See the output in Arduino IDE for the MAC address.

Now replace the placeholder address at the top of the right-controller and left-controller files and upload them like you did with the receiver code. Everything _should_ work now, granted you wired everything correctly!

## Auto-hover

After uploading all the code to their respective ESP32s, you need to tune the hover value. After configuring everything else in firmware, and after you can safely move the drone around a bit, you may notice that when you let go of the left joystick, instead of the drone staying in place, it most likely will either fall or rise slowly. Don't worry--this is normal! Go to the SpeedyBee app and watch the receiver tab while moving the drone up and down. Try to find the point that the drone hovers in place (by moving the left joystick up/down) and note what value (from 1000 to 2000) is displayed for "throttle," the fourth line from the top. Simply subtract 1000 from this number and replace it in the receiver code. Re-upload the code with the updated value. Repeat if you'd like to fine-tune further.

For example, if the drone slowly sinks with the base code, you may find that it steadily hovers at around a value of 1450. Subtract 1000 to get 450, and replace it in the code. But maybe then you see that the drone rises ever so slowly now. Now you can very slowly bring down the left joystick, until maybe you get a value of 1435. Subtract 1000, get 435, add it to the code, and re-upload. Keep doing this until you're satisfied with the drone's hovering.
