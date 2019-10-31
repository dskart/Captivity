#include "esp_ros_node.hpp"

void EspRosNode::Init() {
  SetupWifi();

  ros_node_handle_.getHardware()->setConnection(server_ip_, server_port_);
  ros_node_handle_.initNode();

  AdvertiseTopics();
  SubscribeToTopics();

  return;
}

void EspRosNode::SetupWifi() {
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid_);

  WiFi.begin(ssid_, password_);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // let esp breathe
  delay(1000);

  return;
}

void EspRosNode::AdvertiseTopics() {
  return;
}

void EspRosNode::SubscribeToTopics() {
  ros_node_handle_.subscribe(topics_.game_state_sub);
  ros_node_handle_.subscribe(topics_.front_door_actor_state_sub);

  return;
}

void EspRosNode::SpinOnce(const uint16_t& spin_frequency) {
  ros_node_handle_.spinOnce();
  delay(spin_frequency);

  return;
}

ros::Publisher* EspRosNode::GetTopicPublisher(const PublisherTopics& topic) {
  return topics_.GetTopicPublisher(topic);
}
