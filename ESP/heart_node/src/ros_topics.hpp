#ifndef ROS_TOPICS_HPP
#define ROS_TOPICS_HPP

#include "ros_subscriber_callbacks.hpp"

#include <ros.h>
#include <captivity/GameState.h>
#include <std_msgs/Int32.h>

enum PublisherTopics {
  CURRENT_LIFE
};

class RosTopics {
 public:
  RosTopics() : game_state_sub("game_state", &GameStateCB),
                current_life_pub("current_life", &current_life_msg_),
                update_life_sub("update_life", &UpdateLifeCB){};


  ros::Publisher current_life_pub;
  
  ros::Subscriber<std_msgs::Int32> update_life_sub;
  ros::Subscriber<captivity::GameState> game_state_sub;

  ros::Publisher* GetTopicPublisher(const PublisherTopics& topic);

 private:
  // DEFINE YOUR MESSAGES HERE
  std_msgs::Int32 current_life_msg_;
};

#endif  // ROS_TOPICS_HPP