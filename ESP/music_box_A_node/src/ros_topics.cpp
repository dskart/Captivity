#include "ros_topics.hpp"

ros::Publisher* RosTopics::GetTopicPublisher(const PublisherTopics& topic) {
  switch (topic) {
    case PublisherTopics::MONSTER_OUT:
      return &monster_out_pub;
      break;
    case PublisherTopics::MUSIC_STATE:
      return &music_state_pub;
  }
  return NULL;
}
