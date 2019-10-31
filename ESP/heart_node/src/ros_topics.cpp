#include "ros_topics.hpp"

ros::Publisher* RosTopics::GetTopicPublisher(const PublisherTopics& topic) {
  switch (topic) {
    case PublisherTopics::PLAYER_A_CURRENT_LIFE:
      return &player_A_current_life_pub;
    case PublisherTopics::PLAYER_B_CURRENT_LIFE:
      return &player_B_current_life_pub;
  }
  return NULL;
}
