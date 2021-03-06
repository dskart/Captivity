// Generated by gencpp from file captivity/AddTwoIntsRequest.msg
// DO NOT EDIT!


#ifndef CAPTIVITY_MESSAGE_ADDTWOINTSREQUEST_H
#define CAPTIVITY_MESSAGE_ADDTWOINTSREQUEST_H


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
struct AddTwoIntsRequest_
{
  typedef AddTwoIntsRequest_<ContainerAllocator> Type;

  AddTwoIntsRequest_()
    : a(0)
    , b(0)  {
    }
  AddTwoIntsRequest_(const ContainerAllocator& _alloc)
    : a(0)
    , b(0)  {
  (void)_alloc;
    }



   typedef int64_t _a_type;
  _a_type a;

   typedef int64_t _b_type;
  _b_type b;





  typedef boost::shared_ptr< ::captivity::AddTwoIntsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::captivity::AddTwoIntsRequest_<ContainerAllocator> const> ConstPtr;

}; // struct AddTwoIntsRequest_

typedef ::captivity::AddTwoIntsRequest_<std::allocator<void> > AddTwoIntsRequest;

typedef boost::shared_ptr< ::captivity::AddTwoIntsRequest > AddTwoIntsRequestPtr;
typedef boost::shared_ptr< ::captivity::AddTwoIntsRequest const> AddTwoIntsRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::captivity::AddTwoIntsRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::captivity::AddTwoIntsRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::captivity::AddTwoIntsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::captivity::AddTwoIntsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::captivity::AddTwoIntsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::captivity::AddTwoIntsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::captivity::AddTwoIntsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::captivity::AddTwoIntsRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::captivity::AddTwoIntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "36d09b846be0b371c5f190354dd3153e";
  }

  static const char* value(const ::captivity::AddTwoIntsRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x36d09b846be0b371ULL;
  static const uint64_t static_value2 = 0xc5f190354dd3153eULL;
};

template<class ContainerAllocator>
struct DataType< ::captivity::AddTwoIntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "captivity/AddTwoIntsRequest";
  }

  static const char* value(const ::captivity::AddTwoIntsRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::captivity::AddTwoIntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 a\n"
"int64 b\n"
;
  }

  static const char* value(const ::captivity::AddTwoIntsRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::captivity::AddTwoIntsRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.a);
      stream.next(m.b);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AddTwoIntsRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::captivity::AddTwoIntsRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::captivity::AddTwoIntsRequest_<ContainerAllocator>& v)
  {
    s << indent << "a: ";
    Printer<int64_t>::stream(s, indent + "  ", v.a);
    s << indent << "b: ";
    Printer<int64_t>::stream(s, indent + "  ", v.b);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAPTIVITY_MESSAGE_ADDTWOINTSREQUEST_H
