#ifndef ROS_SUBSCRIBER_CALLBACKS
#define ROS_SUBSCRIBER_CALLBACKS

#include <ros.h>
#include <captivity/GameState.h>

void GameStateCB(const captivity::GameState& incoming_msg);

#endif  // ROS_SUBSCRIBER_CALLBACKS