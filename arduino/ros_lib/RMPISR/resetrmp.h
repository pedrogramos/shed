#ifndef _ROS_SERVICE_resetrmp_h
#define _ROS_SERVICE_resetrmp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace RMPISR
{

static const char RESETRMP[] = "RMPISR/resetrmp";

  class resetrmpRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _pose_type;
      _pose_type pose;

    resetrmpRequest():
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return RESETRMP; };
    const char * getMD5(){ return "271cb12677c4cd9bccbc642cd9258d1f"; };

  };

  class resetrmpResponse : public ros::Msg
  {
    public:

    resetrmpResponse()
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

    const char * getType(){ return RESETRMP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class resetrmp {
    public:
    typedef resetrmpRequest Request;
    typedef resetrmpResponse Response;
  };

}
#endif
