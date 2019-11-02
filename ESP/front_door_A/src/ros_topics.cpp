#include "ros_topics.hpp"

ros::Publisher* RosTopics::GetTopicPublisher(const PublisherTopics& topic) {
  switch (topic) {
    case PublisherTopics::FRONT_DOOR:
      return &front_door_state_pub;
    case PublisherTopics::UPDATE_LIFE:
      return &update_life_pub;
  }
  return NULL;
}
