#include "ros_topics.hpp"

ros::Publisher* RosTopics::GetTopicPublisher(const PublisherTopics& topic) {
  switch (topic) {
    case PublisherTopics::UPDATE_LIFE:
      return &update_life_pub;
    case PublisherTopics::LIGHT_STATE:
      return &front_door_A_light_pub;
  }
  return NULL;
}
