; Auto-generated. Do not edit!


(cl:in-package captivity-msg)


;//! \htmlinclude GameState.msg.html

(cl:defclass <GameState> (roslisp-msg-protocol:ros-message)
  ((player1
    :reader player1
    :initarg :player1
    :type cl:boolean
    :initform cl:nil)
   (player2
    :reader player2
    :initarg :player2
    :type cl:boolean
    :initform cl:nil)
   (game_state
    :reader game_state
    :initarg :game_state
    :type cl:fixnum
    :initform 0))
)

(cl:defclass GameState (<GameState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GameState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GameState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name captivity-msg:<GameState> is deprecated: use captivity-msg:GameState instead.")))

(cl:ensure-generic-function 'player1-val :lambda-list '(m))
(cl:defmethod player1-val ((m <GameState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader captivity-msg:player1-val is deprecated.  Use captivity-msg:player1 instead.")
  (player1 m))

(cl:ensure-generic-function 'player2-val :lambda-list '(m))
(cl:defmethod player2-val ((m <GameState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader captivity-msg:player2-val is deprecated.  Use captivity-msg:player2 instead.")
  (player2 m))

(cl:ensure-generic-function 'game_state-val :lambda-list '(m))
(cl:defmethod game_state-val ((m <GameState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader captivity-msg:game_state-val is deprecated.  Use captivity-msg:game_state instead.")
  (game_state m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GameState>) ostream)
  "Serializes a message object of type '<GameState>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'player1) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'player2) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'game_state)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GameState>) istream)
  "Deserializes a message object of type '<GameState>"
    (cl:setf (cl:slot-value msg 'player1) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'player2) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'game_state)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GameState>)))
  "Returns string type for a message object of type '<GameState>"
  "captivity/GameState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GameState)))
  "Returns string type for a message object of type 'GameState"
  "captivity/GameState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GameState>)))
  "Returns md5sum for a message object of type '<GameState>"
  "e5ed06714a7a82b0c32a7be321a7202a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GameState)))
  "Returns md5sum for a message object of type 'GameState"
  "e5ed06714a7a82b0c32a7be321a7202a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GameState>)))
  "Returns full string definition for message of type '<GameState>"
  (cl:format cl:nil "bool player1~%bool player2~%uint8 game_state~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GameState)))
  "Returns full string definition for message of type 'GameState"
  (cl:format cl:nil "bool player1~%bool player2~%uint8 game_state~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GameState>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GameState>))
  "Converts a ROS message object to a list"
  (cl:list 'GameState
    (cl:cons ':player1 (player1 msg))
    (cl:cons ':player2 (player2 msg))
    (cl:cons ':game_state (game_state msg))
))
