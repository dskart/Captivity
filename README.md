# CAPTIVITY
Captivity is a project to create an interactive room/gaming environment. The idea came from the popular horor game ["5 nights at freddy's"](https://en.wikipedia.org/wiki/Five_Nights_at_Freddy%27s). We wanted to recreate a similar gameplay but in real life. Doing so we had to create a multitude of real life "modules" such as switchs, automatic doors, locks, control panels etc... 
  
This meant that all this modules had to be controlled/sensed and then processed by a microntroller (esp8266/ esp32). All the data was then gathered by a main server that controlled the game logic for the entirety of the game. We had around 20 esp "nodes" all talking together over wifi by running ROS with its pub/sub pattern. The main server was also running a GUI that enabled the "game master" to see everything happening in the rooms as well as control any actuator remotly. The server was also made in a way that it is easy to implement a .json file with instruction to automated the whole game. 
  
If you look at the code, please remind yourself that all the code was done in the span of 3 w.e with no sleep literally in a dark basement. So there are so shortcuts I had to take that made sense on the moment. It was still reliable enought to run the game over 2 w.e with around 200 people playing it and nothing breaking.

## Getting Started

These instructions will show you how to get the game running on your esp/computer if you wish to copy some of it

### Prerequisites

- ROS
- ROS serial
- Esp32 /8266
- TkInter

## Repository format

The repository is divided into 2 directories, the "captivity_catkin_ws" folder and the "ESP" folder. As the name indicates it, "captivity_catkin_ws" is a catkin workspace that has all the code for the main server, this should run on a laptop with ROS installed. The second folder "ESP" contains a bunch of directories, these are all the code for the inidividual nodes (esp) as well as templates to create new nodes that will connect to the network easily and the ros_lib needed in your arduino library to implement ros on a ESP.

## Captivity_catkin_ws

This works as a normal catkin workspace that is used by ROS. If you have never used ROS or catkin before, I recommend following these [tutorials](http://wiki.ros.org/ROS/Tutorials).  

The source code is located in "scripts" and is seperated into 2 packags: Visualizer and Controls. The Visualizer package is used to see all the sensor info in real time of the game/nodes and the Controls package is used to control any node that has an actuator/controllabillity.
  
You can run each package with the following commands:
```
rosrun captivity nexus_controls.py
rosrun captivity nexus_visualizer.py
```

## ESP

This directory contains all the ESP code. The only special directories that are not for an ESP are:
- ros_examples
- ros_lib
- template

the names of these directories are pretty explanitory by themselves and the ESP folder has its own [README](https://github.com/dskart/Captivity/blob/master/ESP/README.md). Look there for any information you want.


### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Raphael Van Hoffelen** - *Initial work*  - [github](https://github.com/dskart), [website](www.raphaelvanhoffelen.com)

## License

TODO

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc

