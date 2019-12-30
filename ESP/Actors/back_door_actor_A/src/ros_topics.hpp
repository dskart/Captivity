#ifndef ROS_TOPICS_HPP
#define ROS_TOPICS_HPP

#include "ros_subscriber_callbacks.hpp"

#include <ros.h>
#include <captivity/GameState.h>
#include <std_msgs/Int32.h>
#include <std_msgs/UInt8.h>

enum PublisherTopics {
};
//front_actor_A_state
class RosTopics {
 public:
  RosTopics() : game_state_sub("game_state", &GameStateCB),
                front_door_actor_state_sub("back_actor_A_state", &FrontDoorActorCB){}


  ros::Subscriber<captivity::GameState> game_state_sub;

  ros::Subscriber<std_msgs::UInt8> front_door_actor_state_sub;

  ros::Publisher* GetTopicPublisher(const PublisherTopics& topic);

 private:
  // DEFINE YOUR MESSAGES HERE
};

#endif  // ROS_TOPICS_HPP