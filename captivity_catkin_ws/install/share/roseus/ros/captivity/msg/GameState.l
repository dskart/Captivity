;; Auto-generated. Do not edit!


(when (boundp 'captivity::GameState)
  (if (not (find-package "CAPTIVITY"))
    (make-package "CAPTIVITY"))
  (shadow 'GameState (find-package "CAPTIVITY")))
(unless (find-package "CAPTIVITY::GAMESTATE")
  (make-package "CAPTIVITY::GAMESTATE"))

(in-package "ROS")
;;//! \htmlinclude GameState.msg.html


(defclass captivity::GameState
  :super ros::object
  :slots (_player1 _player2 _game_state ))

(defmethod captivity::GameState
  (:init
   (&key
    ((:player1 __player1) nil)
    ((:player2 __player2) nil)
    ((:game_state __game_state) 0)
    )
   (send-super :init)
   (setq _player1 __player1)
   (setq _player2 __player2)
   (setq _game_state (round __game_state))
   self)
  (:player1
   (&optional __player1)
   (if __player1 (setq _player1 __player1)) _player1)
  (:player2
   (&optional __player2)
   (if __player2 (setq _player2 __player2)) _player2)
  (:game_state
   (&optional __game_state)
   (if __game_state (setq _game_state __game_state)) _game_state)
  (:serialization-length
   ()
   (+
    ;; bool _player1
    1
    ;; bool _player2
    1
    ;; uint8 _game_state
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _player1
       (if _player1 (write-byte -1 s) (write-byte 0 s))
     ;; bool _player2
       (if _player2 (write-byte -1 s) (write-byte 0 s))
     ;; uint8 _game_state
       (write-byte _game_state s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _player1
     (setq _player1 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _player2
     (setq _player2 (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint8 _game_state
     (setq _game_state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get captivity::GameState :md5sum-) "e5ed06714a7a82b0c32a7be321a7202a")
(setf (get captivity::GameState :datatype-) "captivity/GameState")
(setf (get captivity::GameState :definition-)
      "bool player1
bool player2
uint8 game_state
")



(provide :captivity/GameState "e5ed06714a7a82b0c32a7be321a7202a")


