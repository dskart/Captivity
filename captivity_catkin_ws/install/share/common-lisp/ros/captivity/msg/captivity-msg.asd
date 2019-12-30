
(cl:in-package :asdf)

(defsystem "captivity-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "GameState" :depends-on ("_package_GameState"))
    (:file "_package_GameState" :depends-on ("_package"))
    (:file "Num" :depends-on ("_package_Num"))
    (:file "_package_Num" :depends-on ("_package"))
    (:file "StringAndNum" :depends-on ("_package_StringAndNum"))
    (:file "_package_StringAndNum" :depends-on ("_package"))
  ))