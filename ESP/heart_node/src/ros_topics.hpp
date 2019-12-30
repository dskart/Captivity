#ifndef ROS_TOPICS_HPP
#define ROS_TOPICS_HPP

#include "ros_subscriber_callbacks.hpp"

#include <captivity/GameState.h>
#include <ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/UInt8.h>

enum PublisherTopics {
  PLAYER_A_CURRENT_LIFE,
  PLAYER_B_CURRENT_LIFE
};

class RosTopics {
 public:
  RosTopics() : game_state_sub("game_state", &GameStateCB),
                player_A_current_life_pub("player_A_health", &player_A_current_life_msg_),
                player_B_current_life_pub("player_B_health", &player_B_current_life_msg_),
                update_life_sub("update_life", &UpdateLifeCB),
                life_switch_state_sub("life_switch_state", &LifeSwitchCB){};

  ros::Publisher player_A_current_life_pub;
  ros::Publisher player_B_current_life_pub;

  ros::Subscriber<std_msgs::Int32> update_life_sub;
  ros::Subscriber<captivity::GameState> game_state_sub;

  ros::Subscriber<std_msgs::UInt8> life_switch_state_sub;

  ros::Publisher* GetTopicPublisher(const PublisherTopics& topic);

 private:
  // DEFINE YOUR MESSAGES HERE
  std_msgs::Int32 player_A_current_life_msg_;
  std_msgs::Int32 player_B_current_life_msg_;
};

#endif  // ROS_TOPICS_HPP