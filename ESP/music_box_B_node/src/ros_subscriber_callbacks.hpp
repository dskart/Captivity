#ifndef ROS_SUBSCRIBER_CALLBACKS
#define ROS_SUBSCRIBER_CALLBACKS

#include <ros.h>
#include <captivity/GameState.h>
#include <std_msgs/Int32.h>
#include <std_msgs/UInt8.h>

void GameStateCB(const captivity::GameState& incoming_msg);
void MusicBoxStateCB(const std_msgs::UInt8& incoming_msg);

#endif  // ROS_SUBSCRIBER_CALLBACKS