#ifndef ROS_SUBSCRIBER_CALLBACKS
#define ROS_SUBSCRIBER_CALLBACKS

#include "captivity.hpp"

#include <ros.h>
#include <captivity/GameState.h>
#include <captivity/Num.h>

void Chatter2Cb(const captivity::Num& incoming_msg);

void GameStateCB(const captivity::GameState& incoming_msg);

#endif  // ROS_SUBSCRIBER_CALLBACKS