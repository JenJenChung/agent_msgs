cmake_minimum_required(VERSION 2.8.3)
project(agent_msgs)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  std_msgs
)

## Generate messages in the 'msg' folder
add_message_files(
  DIRECTORY
  FILES
  AgentMembership.msg
  UtmGraph.msg
  BoolLog.msg
  WallUpdate.msg
  AgentCosts.msg
)

# Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES agent_msgs
  CATKIN_DEPENDS message_runtime std_msgs
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(membership_publisher src/membership_publisher.cpp)
target_link_libraries(membership_publisher ${catkin_LIBRARIES})
add_dependencies(membership_publisher ${catkin_EXPORTED_TARGETS})

add_executable(membership_subscriber src/membership_subscriber.cpp)
target_link_libraries(membership_subscriber ${catkin_LIBRARIES})
add_dependencies(membership_subscriber ${catkin_EXPORTED_TARGETS})


add_executable(graph_publisher src/graph_publisher.cpp)
target_link_libraries(graph_publisher ${catkin_LIBRARIES})
add_dependencies(graph_publisher ${catkin_EXPORTED_TARGETS})

add_executable(graph_subscriber src/graph_subscriber.cpp)
target_link_libraries(graph_subscriber ${catkin_LIBRARIES})
add_dependencies(graph_subscriber ${catkin_EXPORTED_TARGETS})
