#ifndef _ROS_SERVICE_add_obstacle_h
#define _ROS_SERVICE_add_obstacle_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace perception_pkg
{

static const char ADD_OBSTACLE[] = "perception_pkg/add_obstacle";

  class add_obstacleRequest : public ros::Msg
  {
    public:
      typedef float _xobj_type;
      _xobj_type xobj;
      typedef float _yobj_type;
      _yobj_type yobj;

    add_obstacleRequest():
      xobj(0),
      yobj(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_xobj;
      u_xobj.real = this->xobj;
      *(outbuffer + offset + 0) = (u_xobj.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xobj.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xobj.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xobj.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xobj);
      union {
        float real;
        uint32_t base;
      } u_yobj;
      u_yobj.real = this->yobj;
      *(outbuffer + offset + 0) = (u_yobj.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yobj.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yobj.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yobj.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yobj);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_xobj;
      u_xobj.base = 0;
      u_xobj.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xobj.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xobj.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xobj.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xobj = u_xobj.real;
      offset += sizeof(this->xobj);
      union {
        float real;
        uint32_t base;
      } u_yobj;
      u_yobj.base = 0;
      u_yobj.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yobj.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yobj.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yobj.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yobj = u_yobj.real;
      offset += sizeof(this->yobj);
     return offset;
    }

    const char * getType(){ return ADD_OBSTACLE; };
    const char * getMD5(){ return "f8fb8420bfa4e803c844225154ef8e5f"; };

  };

  class add_obstacleResponse : public ros::Msg
  {
    public:

    add_obstacleResponse()
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

    const char * getType(){ return ADD_OBSTACLE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class add_obstacle {
    public:
    typedef add_obstacleRequest Request;
    typedef add_obstacleResponse Response;
  };

}
#endif
