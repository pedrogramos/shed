#ifndef _ROS_SERVICE_addpoint_h
#define _ROS_SERVICE_addpoint_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace RMPISR
{

static const char ADDPOINT[] = "RMPISR/addpoint";

  class addpointRequest : public ros::Msg
  {
    public:
      uint32_t pointArray_length;
      typedef geometry_msgs::Point _pointArray_type;
      _pointArray_type st_pointArray;
      _pointArray_type * pointArray;
      typedef bool _type_type;
      _type_type type;
      typedef int32_t _size_type;
      _size_type size;

    addpointRequest():
      pointArray_length(0), pointArray(NULL),
      type(0),
      size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pointArray_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pointArray_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pointArray_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pointArray_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pointArray_length);
      for( uint32_t i = 0; i < pointArray_length; i++){
      offset += this->pointArray[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_size;
      u_size.real = this->size;
      *(outbuffer + offset + 0) = (u_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t pointArray_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pointArray_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pointArray_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pointArray_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pointArray_length);
      if(pointArray_lengthT > pointArray_length)
        this->pointArray = (geometry_msgs::Point*)realloc(this->pointArray, pointArray_lengthT * sizeof(geometry_msgs::Point));
      pointArray_length = pointArray_lengthT;
      for( uint32_t i = 0; i < pointArray_length; i++){
      offset += this->st_pointArray.deserialize(inbuffer + offset);
        memcpy( &(this->pointArray[i]), &(this->st_pointArray), sizeof(geometry_msgs::Point));
      }
      union {
        bool real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_size;
      u_size.base = 0;
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->size = u_size.real;
      offset += sizeof(this->size);
     return offset;
    }

    const char * getType(){ return ADDPOINT; };
    const char * getMD5(){ return "7da3ac5df9a593780eabd65b2f6b4ceb"; };

  };

  class addpointResponse : public ros::Msg
  {
    public:

    addpointResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return ADDPOINT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class addpoint {
    public:
    typedef addpointRequest Request;
    typedef addpointResponse Response;
  };

}
#endif
