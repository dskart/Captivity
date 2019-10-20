# ESP NODES 
This is where all the code for the Esp nodes is. They are all build on top of the template that lives in ./template.

## Getting Started

These instructions will get you ready to use the code for each esp node. 

### Prerequisites

Before compiling and flashing the code you will need some software:  
- [Arduino IDE](https://www.arduino.cc/en/main/software)
- [Esp8266 and Esp32](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/) board on the Arduino IDE
- [rosserial](http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup) on your Arduino IDE.

There are unfortunatly custom messages that we use in the ros_lib for arduino. It can be as simple as moving the ros_lib folder to your Arduino Library directory, but you might want to ask Raph. 

### Flashing

Choose the NodeMCU 1.0 board or the ESP32 devkit V1 board on the IDE.  
Then click compile and upload on your Arduino IDE



### Coding Style 

We "try" to follow the [google c++ standards](https://google.github.io/styleguide/cppguide.html).  
There should be a .clang-format file in the top directory to help you.

## Implementing the Low Level

Go the the [template README]() To see how you can write/add a node to this project
