#ifndef ROS_TOPICS_HPP
#define ROS_TOPICS_HPP

#include "ros_subscriber_callbacks.hpp"

#include <ros.h>
#include <captivity/GameState.h>
#include <std_msgs/Int32.h>
#include <std_msgs/UInt8.h>

enum PublisherTopics {
  UPDATE_LIFE,
  IRIS_SWITCH 
};

class RosTopics {
 public:
  RosTopics() : game_state_sub("game_state", &GameStateCB),
                update_life_pub("update_life", &update_life_msg),
                iris_state_pub("iris_B_state", &iris_state_msg){};

  ros::Subscriber<captivity::GameState> game_state_sub;
  ros::Publisher iris_state_pub;
  ros::Publisher update_life_pub;

  ros::Publisher* GetTopicPublisher(const PublisherTopics& topic);

 private:
  // DEFINE YOUR MESSAGES HERE
  std_msgs::Int32 update_life_msg;
  std_msgs::UInt8 iris_state_msg;
};

#endif  // ROS_TOPICS_HPP