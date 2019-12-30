#include "ros_topics.hpp"

ros::Publisher* RosTopics::GetTopicPublisher(const PublisherTopics& topic) {
  switch (topic) {
    case PublisherTopics::UPDATE_LIFE:
      return &update_life_pub;
    case PublisherTopics::IRIS_SWITCH:
      return &iris_state_pub;
  }
  return NULL;
}
