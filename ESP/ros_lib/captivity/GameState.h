#ifndef _ROS_captivity_GameState_h
#define _ROS_captivity_GameState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace captivity
{

  class GameState : public ros::Msg
  {
    public:
      typedef bool _player1_type;
      _player1_type player1;
      typedef bool _player2_type;
      _player2_type player2;
      typedef uint8_t _game_state_type;
      _game_state_type game_state;

    GameState():
      player1(0),
      player2(0),
      game_state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_player1;
      u_player1.real = this->player1;
      *(outbuffer + offset + 0) = (u_player1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->player1);
      union {
        bool real;
        uint8_t base;
      } u_player2;
      u_player2.real = this->player2;
      *(outbuffer + offset + 0) = (u_player2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->player2);
      *(outbuffer + offset + 0) = (this->game_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->game_state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_player1;
      u_player1.base = 0;
      u_player1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->player1 = u_player1.real;
      offset += sizeof(this->player1);
      union {
        bool real;
        uint8_t base;
      } u_player2;
      u_player2.base = 0;
      u_player2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->player2 = u_player2.real;
      offset += sizeof(this->player2);
      this->game_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->game_state);
     return offset;
    }

    const char * getType(){ return "captivity/GameState"; };
    const char * getMD5(){ return "e5ed06714a7a82b0c32a7be321a7202a"; };

  };

}
#endif
