#ifndef ROS_TOPICS_HPP
#define ROS_TOPICS_HPP

#include "ros_subscriber_callbacks.hpp"

#include <ros.h>
#include <captivity/GameState.h>
#include <std_msgs/Int32.h>
#include <std_msgs/UInt8.h>

// /music_box_A_stat

enum PublisherTopics {
  MONSTER_OUT
};

class RosTopics {
 public:
  RosTopics() : game_state_sub("game_state", &GameStateCB),
                music_state_sub("music_box_A_state", &MusicBoxStateCB),
                monster_out_pub("monster_A_out", &monster_out_msg_){}


  ros::Subscriber<captivity::GameState> game_state_sub;
  ros::Subscriber<std_msgs::UInt8> music_state_sub;

  ros::Publisher monster_out_pub;

  ros::Publisher* GetTopicPublisher(const PublisherTopics& topic);

 private:
  // DEFINE YOUR MESSAGES HERE
  std_msgs::UInt8 monster_out_msg_;
};

#endif  // ROS_TOPICS_HPP