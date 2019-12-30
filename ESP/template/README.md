# ESP NODE TEMPLATE
This is where the framework for each node is, you should copy this template and build on top of it if you want to create a new node

## Getting Started

These instructions will help you understand how the framework works in order to create a new node or contribute to one 

### Directory Layout
```
The general structure is
├── Node Name
   ├── main.ino    # main esp code, where the main loop lives
   ├── src
   │   ├── captivity.cpp    # where most of your implementation will be
   │   ├── captivity.hpp
   │   ├── esp_ros_node.cpp    # where the ros node is handled 
   │   ├── esp_ros_node.hpp 
   │   ├── ros_subscriber_callbacks.cpp    # where callbacks are define for subscribers
   │   ├── ros_subscriber_callbacks.hpp
   │   ├── ros_topics.cpp    # where publishers and subscribers are define
   │   └── ros_topics.hpp
   └── README
```

### Main Loop
Structure of the main loop
``` cpp
void loop() {
  switch (Captivity::current_state) {
    case GameStates::IDLE:
      captivity_game.Idle();
      break;

    case GameStates::RESET:
      captivity_game.Reset();
      break;

    case GameStates::START:
      captivity_game.Start();
      break;

    case GameStates::END:
      captivity_game.End();
      break;

    default:
      Serial.println("ERROR: GAME STATE IS WRONG");
      break;
  }
  node.SpinOnce(kSpinFrequency);
}

```

### Implementing a Node
FIRST RULE: DO NOT ADD A DELAY APART IF RAPH SAYS YES.  
SECOND RULE: DO NOT ADD A DELAY APART IF RAPH SAYS YES.  

If you are just trying to implement a node (meaning the node already exists), You will probably only have to touch the captivity.cpp/hpp file.

You don't have to worry how the esp knows what state, you just need to implement the right behavior for each game states existing in captivity.cpp

#### Callbacks
If you need to set variables/do stuff when a topic you subscribed to has a new message, go to ros_subscriber_callback.cpp. Be carefull, if you need to set a varibale to use somewhere else, create a class (you should be implementing your behaviors in classes anyway) and create a public static variable inside the class. This is the variable you can change/set inside the callback, this way every instance of that class will get the new change.

#### Publishing

This is how Publishing code works:
``` cpp
  captivity::MyMsg my_msg;
  my_msg.some_data = SOMETHINGNGNNGN;

  ros::Publisher* pub = node.GetTopicPublisher(PublisherTopics::CHATTER);
  pub->publish(&my_msg);
```
Make sure to #include the right message type. Example:
```cpp
#include "src/captivity.hpp"
```

There is an enum that lives in "esp_topics.hpp" called "PublisherTopics" that contains all the topics ou are allowed to publish on this node. Use that enum (as shown in the example) to retrieve the ros::Publisher* that you want so that yo ucan publish your message to that topic.

## Coding Style 

We "try" to follow the [google c++ standards](https://google.github.io/styleguide/cppguide.html).  
There should be a .clang-format file in the top directory to help you.