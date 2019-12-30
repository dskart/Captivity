#ifndef ESP_ROS_NODE_HPP
#define ESP_ROS_NODE_HPP

#include "ros_topics.hpp"

#include <ros.h>

// #include <WiFi.h> // FOR ESP32
#include <ESP8266WiFi.h>  // FOR ESP8266

struct RosLogInfo {
  String debug;
  String info_msg;
  String warn;
  String error;
  String fatal;
};

class EspRosNode {
 public:
  // EspRosNode() : server_ip_(IPAddress(10, 9, 9, 137)){};
  EspRosNode() : server_ip_(IPAddress(192, 168, 0, 121)){};
  ~EspRosNode(){};

  void Init();

  void SpinOnce(const uint16_t& spin_frequency);

  ros::Publisher* GetTopicPublisher(const PublisherTopics& topic);

 private:
  const String ssid_ = "it-hurts-when-ip";
  const char* password_ = "SendNudesOn259S";

  ros::NodeHandle ros_node_handle_;
  const uint16_t server_port_ = 11411;
  IPAddress server_ip_;

  RosTopics topics_;

  RosLogInfo log_;

  void SetupWifi();
  void AdvertiseTopics();
  void SubscribeToTopics();
};

#endif  //ESP_ROS_NODE_HPP
