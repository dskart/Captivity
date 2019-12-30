#ifndef ROS_TOPICS_HPP
#define ROS_TOPICS_HPP

#include "ros_subscriber_callbacks.hpp"

#include <ros.h>
#include <captivity/GameState.h>
#include <std_msgs/Int32.h>
#include <std_msgs/UInt8.h>

enum PublisherTopics {
  LIFE_SWITCH
};

class RosTopics {
 public:
  RosTopics() : game_state_sub("game_state", &GameStateCB),
                life_switch_state_pub("life_switch_state", &life_switch_state_msg){};

  ros::Subscriber<captivity::GameState> game_state_sub;
  ros::Publisher life_switch_state_pub;

  ros::Publisher* GetTopicPublisher(const PublisherTopics& topic);

 private:
  // DEFINE YOUR MESSAGES HERE

  std_msgs::UInt8 life_switch_state_msg;
};

#endif  // ROS_TOPICS_HPP