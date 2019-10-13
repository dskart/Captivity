# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "go_birds: 1 messages, 1 services")

set(MSG_I_FLAGS "-Igo_birds:/home/raphael/go_birds_catkin_ws/src/go_birds/msg;-Istd_msgs:/home/raphael/ros_catkin_ws/install_isolated/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(go_birds_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv" NAME_WE)
add_custom_target(_go_birds_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "go_birds" "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv" ""
)

get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg" NAME_WE)
add_custom_target(_go_birds_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "go_birds" "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(go_birds
  "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/go_birds
)

### Generating Services
_generate_srv_cpp(go_birds
  "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/go_birds
)

### Generating Module File
_generate_module_cpp(go_birds
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/go_birds
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(go_birds_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(go_birds_generate_messages go_birds_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(go_birds_generate_messages_cpp _go_birds_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg" NAME_WE)
add_dependencies(go_birds_generate_messages_cpp _go_birds_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(go_birds_gencpp)
add_dependencies(go_birds_gencpp go_birds_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS go_birds_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(go_birds
  "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/go_birds
)

### Generating Services
_generate_srv_eus(go_birds
  "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/go_birds
)

### Generating Module File
_generate_module_eus(go_birds
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/go_birds
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(go_birds_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(go_birds_generate_messages go_birds_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(go_birds_generate_messages_eus _go_birds_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg" NAME_WE)
add_dependencies(go_birds_generate_messages_eus _go_birds_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(go_birds_geneus)
add_dependencies(go_birds_geneus go_birds_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS go_birds_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(go_birds
  "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/go_birds
)

### Generating Services
_generate_srv_lisp(go_birds
  "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/go_birds
)

### Generating Module File
_generate_module_lisp(go_birds
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/go_birds
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(go_birds_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(go_birds_generate_messages go_birds_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(go_birds_generate_messages_lisp _go_birds_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg" NAME_WE)
add_dependencies(go_birds_generate_messages_lisp _go_birds_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(go_birds_genlisp)
add_dependencies(go_birds_genlisp go_birds_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS go_birds_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(go_birds
  "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/go_birds
)

### Generating Services
_generate_srv_nodejs(go_birds
  "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/go_birds
)

### Generating Module File
_generate_module_nodejs(go_birds
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/go_birds
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(go_birds_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(go_birds_generate_messages go_birds_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(go_birds_generate_messages_nodejs _go_birds_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg" NAME_WE)
add_dependencies(go_birds_generate_messages_nodejs _go_birds_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(go_birds_gennodejs)
add_dependencies(go_birds_gennodejs go_birds_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS go_birds_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(go_birds
  "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/go_birds
)

### Generating Services
_generate_srv_py(go_birds
  "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/go_birds
)

### Generating Module File
_generate_module_py(go_birds
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/go_birds
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(go_birds_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(go_birds_generate_messages go_birds_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(go_birds_generate_messages_py _go_birds_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/raphael/go_birds_catkin_ws/src/go_birds/msg/Num.msg" NAME_WE)
add_dependencies(go_birds_generate_messages_py _go_birds_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(go_birds_genpy)
add_dependencies(go_birds_genpy go_birds_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS go_birds_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/go_birds)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/go_birds
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(go_birds_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/go_birds)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/go_birds
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(go_birds_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/go_birds)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/go_birds
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(go_birds_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/go_birds)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/go_birds
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(go_birds_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/go_birds)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/go_birds\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/go_birds
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(go_birds_generate_messages_py std_msgs_generate_messages_py)
endif()
