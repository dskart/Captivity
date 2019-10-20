#include "ros_topics.hpp"

ros::Publisher* RosTopics::GetTopicPublisher(const PublisherTopics& topic) {
  switch (topic) {
    case PublisherTopics::CHATTER1:
      return &chatter1_pub;
  }
  return NULL;
}
