#ifndef _ROS_SERVICE_markerdetected_h
#define _ROS_SERVICE_markerdetected_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace RMPISR
{

static const char MARKERDETECTED[] = "RMPISR/markerdetected";

  class markerdetectedRequest : public ros::Msg
  {
    public:

    markerdetectedRequest()
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

    const char * getType(){ return MARKERDETECTED; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class markerdetectedResponse : public ros::Msg
  {
    public:

    markerdetectedResponse()
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

    const char * getType(){ return MARKERDETECTED; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class markerdetected {
    public:
    typedef markerdetectedRequest Request;
    typedef markerdetectedResponse Response;
  };

}
#endif
