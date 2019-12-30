#include "ros_topics.hpp"

ros::Publisher* RosTopics::GetTopicPublisher(const PublisherTopics& topic) {
  switch (topic) {
    case PublisherTopics::LIFE_SWITCH:
      return &life_switch_state_pub;
  }
  return NULL;
}
