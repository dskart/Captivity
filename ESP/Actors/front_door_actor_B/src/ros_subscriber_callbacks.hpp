#ifndef ROS_SUBSCRIBER_CALLBACKS
#define ROS_SUBSCRIBER_CALLBACKS

#include <ros.h>
#include <captivity/GameState.h>
#include <std_msgs/UInt8.h>

void GameStateCB(const captivity::GameState& incoming_msg);
void FrontDoorActorCB(const std_msgs::UInt8& incoming_msg);

#endif  // ROS_SUBSCRIBER_CALLBACKS