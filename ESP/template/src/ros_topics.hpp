#ifndef ROS_TOPICS_HPP
#define ROS_TOPICS_HPP

#include "ros_subscriber_callbacks.hpp"

#include <ros.h>
#include <captivity/GameState.h>
#include <captivity/Num.h>

enum PublisherTopics {
  CHATTER1
};

class RosTopics {
 public:
  RosTopics() : chatter1_pub("chatter1", &num_msg_),
                chatter2_sub("chatter2", &Chatter2Cb),
                game_state_sub("game_state", &GameStateCB){};

  ros::Publisher chatter1_pub;
  ros::Subscriber<captivity::Num> chatter2_sub;
  ros::Subscriber<captivity::GameState> game_state_sub;

  ros::Publisher* GetTopicPublisher(const PublisherTopics& topic);

 private:
  // DEFINE YOUR MESSAGES HERE
  captivity::Num num_msg_;
};

#endif  // ROS_TOPICS_HPP