// Generated by gencpp from file captivity/GameState.msg
// DO NOT EDIT!


#ifndef CAPTIVITY_MESSAGE_GAMESTATE_H
#define CAPTIVITY_MESSAGE_GAMESTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace captivity
{
template <class ContainerAllocator>
struct GameState_
{
  typedef GameState_<ContainerAllocator> Type;

  GameState_()
    : player1(false)
    , player2(false)
    , game_state(0)  {
    }
  GameState_(const ContainerAllocator& _alloc)
    : player1(false)
    , player2(false)
    , game_state(0)  {
  (void)_alloc;
    }



   typedef uint8_t _player1_type;
  _player1_type player1;

   typedef uint8_t _player2_type;
  _player2_type player2;

   typedef uint8_t _game_state_type;
  _game_state_type game_state;





  typedef boost::shared_ptr< ::captivity::GameState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::captivity::GameState_<ContainerAllocator> const> ConstPtr;

}; // struct GameState_

typedef ::captivity::GameState_<std::allocator<void> > GameState;

typedef boost::shared_ptr< ::captivity::GameState > GameStatePtr;
typedef boost::shared_ptr< ::captivity::GameState const> GameStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::captivity::GameState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::captivity::GameState_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace captivity

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/home/raphael/ros_catkin_ws/install_isolated/share/std_msgs/cmake/../msg'], 'captivity': ['/home/raphael/Documents/Captivity/captivity_catkin_ws/src/captivity/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::captivity::GameState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::captivity::GameState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::captivity::GameState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::captivity::GameState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::captivity::GameState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::captivity::GameState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::captivity::GameState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e5ed06714a7a82b0c32a7be321a7202a";
  }

  static const char* value(const ::captivity::GameState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe5ed06714a7a82b0ULL;
  static const uint64_t static_value2 = 0xc32a7be321a7202aULL;
};

template<class ContainerAllocator>
struct DataType< ::captivity::GameState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "captivity/GameState";
  }

  static const char* value(const ::captivity::GameState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::captivity::GameState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool player1\n"
"bool player2\n"
"uint8 game_state\n"
;
  }

  static const char* value(const ::captivity::GameState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::captivity::GameState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.player1);
      stream.next(m.player2);
      stream.next(m.game_state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GameState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::captivity::GameState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::captivity::GameState_<ContainerAllocator>& v)
  {
    s << indent << "player1: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.player1);
    s << indent << "player2: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.player2);
    s << indent << "game_state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.game_state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAPTIVITY_MESSAGE_GAMESTATE_H
