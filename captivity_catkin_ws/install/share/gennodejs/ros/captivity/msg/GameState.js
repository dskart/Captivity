// Auto-generated. Do not edit!

// (in-package captivity.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class GameState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.player1 = null;
      this.player2 = null;
      this.game_state = null;
    }
    else {
      if (initObj.hasOwnProperty('player1')) {
        this.player1 = initObj.player1
      }
      else {
        this.player1 = false;
      }
      if (initObj.hasOwnProperty('player2')) {
        this.player2 = initObj.player2
      }
      else {
        this.player2 = false;
      }
      if (initObj.hasOwnProperty('game_state')) {
        this.game_state = initObj.game_state
      }
      else {
        this.game_state = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GameState
    // Serialize message field [player1]
    bufferOffset = _serializer.bool(obj.player1, buffer, bufferOffset);
    // Serialize message field [player2]
    bufferOffset = _serializer.bool(obj.player2, buffer, bufferOffset);
    // Serialize message field [game_state]
    bufferOffset = _serializer.uint8(obj.game_state, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GameState
    let len;
    let data = new GameState(null);
    // Deserialize message field [player1]
    data.player1 = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [player2]
    data.player2 = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [game_state]
    data.game_state = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 3;
  }

  static datatype() {
    // Returns string type for a message object
    return 'captivity/GameState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e5ed06714a7a82b0c32a7be321a7202a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool player1
    bool player2
    uint8 game_state
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GameState(null);
    if (msg.player1 !== undefined) {
      resolved.player1 = msg.player1;
    }
    else {
      resolved.player1 = false
    }

    if (msg.player2 !== undefined) {
      resolved.player2 = msg.player2;
    }
    else {
      resolved.player2 = false
    }

    if (msg.game_state !== undefined) {
      resolved.game_state = msg.game_state;
    }
    else {
      resolved.game_state = 0
    }

    return resolved;
    }
};

module.exports = GameState;
