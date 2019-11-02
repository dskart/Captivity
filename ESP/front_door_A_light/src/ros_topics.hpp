#ifndef ROS_TOPICS_HPP
#define ROS_TOPICS_HPP

#include "ros_subscriber_callbacks.hpp"

#include <ros.h>
#include <captivity/GameState.h>
#include <std_msgs/Int32.h>
#include <std_msgs/UInt8.h>

enum PublisherTopics {
  UPDATE_LIFE,
  LIGHT_STATE
};

class RosTopics {
 public:
  RosTopics() : game_state_sub("game_state", &GameStateCB),
                update_life_pub("update_life", &update_life_msg),
                front_door_A_light_pub("front_door_A_light", &front_door_A_light_msg){};

  ros::Subscriber<captivity::GameState> game_state_sub;

  ros::Publisher update_life_pub;
  ros::Publisher front_door_A_light_pub;

  ros::Publisher* GetTopicPublisher(const PublisherTopics& topic);

 private:
  // DEFINE YOUR MESSAGES HERE
  std_msgs::Int32 update_life_msg;
  std_msgs::UInt8 front_door_A_light_msg;
};

#endif  // ROS_TOPICS_HPP