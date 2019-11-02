#ifndef ROS_TOPICS_HPP
#define ROS_TOPICS_HPP

#include "ros_subscriber_callbacks.hpp"

#include <ros.h>
#include <captivity/GameState.h>
#include <captivity/Num.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Int32.h>

enum PublisherTopics {
  FRONT_DOOR,
  UPDATE_LIFE
};

class RosTopics {
 public:
  RosTopics() : front_door_state_pub("front_door_B_state", &lock_msg_),
                update_life_pub("update_life", &update_life_msg_),
                game_state_sub("game_state", &GameStateCB){};

  ros::Publisher front_door_state_pub;
  ros::Publisher update_life_pub;
  ros::Subscriber<captivity::GameState> game_state_sub;

  ros::Publisher* GetTopicPublisher(const PublisherTopics& topic);

 private:
  // DEFINE YOUR MESSAGES HERE
  captivity::Num num_msg_;
  std_msgs::UInt8 lock_msg_;
  std_msgs::Int32 update_life_msg_;
};

#endif  // ROS_TOPICS_HPP