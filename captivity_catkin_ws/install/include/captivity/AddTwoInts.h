// Generated by gencpp from file captivity/AddTwoInts.msg
// DO NOT EDIT!


#ifndef CAPTIVITY_MESSAGE_ADDTWOINTS_H
#define CAPTIVITY_MESSAGE_ADDTWOINTS_H

#include <ros/service_traits.h>


#include <captivity/AddTwoIntsRequest.h>
#include <captivity/AddTwoIntsResponse.h>


namespace captivity
{

struct AddTwoInts
{

typedef AddTwoIntsRequest Request;
typedef AddTwoIntsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct AddTwoInts
} // namespace captivity


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::captivity::AddTwoInts > {
  static const char* value()
  {
    return "6a2e34150c00229791cc89ff309fff21";
  }

  static const char* value(const ::captivity::AddTwoInts&) { return value(); }
};

template<>
struct DataType< ::captivity::AddTwoInts > {
  static const char* value()
  {
    return "captivity/AddTwoInts";
  }

  static const char* value(const ::captivity::AddTwoInts&) { return value(); }
};


// service_traits::MD5Sum< ::captivity::AddTwoIntsRequest> should match 
// service_traits::MD5Sum< ::captivity::AddTwoInts > 
template<>
struct MD5Sum< ::captivity::AddTwoIntsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::captivity::AddTwoInts >::value();
  }
  static const char* value(const ::captivity::AddTwoIntsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::captivity::AddTwoIntsRequest> should match 
// service_traits::DataType< ::captivity::AddTwoInts > 
template<>
struct DataType< ::captivity::AddTwoIntsRequest>
{
  static const char* value()
  {
    return DataType< ::captivity::AddTwoInts >::value();
  }
  static const char* value(const ::captivity::AddTwoIntsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::captivity::AddTwoIntsResponse> should match 
// service_traits::MD5Sum< ::captivity::AddTwoInts > 
template<>
struct MD5Sum< ::captivity::AddTwoIntsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::captivity::AddTwoInts >::value();
  }
  static const char* value(const ::captivity::AddTwoIntsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::captivity::AddTwoIntsResponse> should match 
// service_traits::DataType< ::captivity::AddTwoInts > 
template<>
struct DataType< ::captivity::AddTwoIntsResponse>
{
  static const char* value()
  {
    return DataType< ::captivity::AddTwoInts >::value();
  }
  static const char* value(const ::captivity::AddTwoIntsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CAPTIVITY_MESSAGE_ADDTWOINTS_H
