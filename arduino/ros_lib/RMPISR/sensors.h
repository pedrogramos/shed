#ifndef _ROS_RMPISR_sensors_h
#define _ROS_RMPISR_sensors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace RMPISR
{

  class sensors : public ros::Msg
  {
    public:
      typedef uint8_t _ir1_type;
      _ir1_type ir1;
      typedef uint8_t _ir2_type;
      _ir2_type ir2;
      typedef uint8_t _ir3_type;
      _ir3_type ir3;
      typedef uint8_t _ir4_type;
      _ir4_type ir4;
      typedef uint8_t _s1_type;
      _s1_type s1;
      typedef uint8_t _s2_type;
      _s2_type s2;
      typedef uint8_t _s5_type;
      _s5_type s5;

    sensors():
      ir1(0),
      ir2(0),
      ir3(0),
      ir4(0),
      s1(0),
      s2(0),
      s5(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ir1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ir1);
      *(outbuffer + offset + 0) = (this->ir2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ir2);
      *(outbuffer + offset + 0) = (this->ir3 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ir3);
      *(outbuffer + offset + 0) = (this->ir4 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ir4);
      *(outbuffer + offset + 0) = (this->s1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->s1);
      *(outbuffer + offset + 0) = (this->s2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->s2);
      *(outbuffer + offset + 0) = (this->s5 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->s5);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->ir1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ir1);
      this->ir2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ir2);
      this->ir3 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ir3);
      this->ir4 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ir4);
      this->s1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->s1);
      this->s2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->s2);
      this->s5 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->s5);
     return offset;
    }

    const char * getType(){ return "RMPISR/sensors"; };
    const char * getMD5(){ return "9eedb779141fc8e42c127e038f10520e"; };

  };

}
#endif