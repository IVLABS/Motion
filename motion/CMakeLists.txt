cmake_minimum_required(VERSION 2.8.3)
project(motion)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)


 add_message_files(
   FILES
   angles_in.msg
   angles_out.msg
    )

 generate_messages(
   DEPENDENCIES
   std_msgs
 )
include_directories(include ${catkin_INCLUDE_DIRS})



add_executable(parser src/parser.cpp)
target_link_libraries(parser  ${catkin_LIBRARIES})
add_dependencies(parser  motion_generate_messages_cpp)



add_executable(conveyor src/conveyor.cpp)
target_link_libraries(conveyor ${catkin_LIBRARIES})
add_dependencies(conveyor motion_generate_messages_cpp)



# link the libraries to the executable
link_directories(/usr/lib)
#target_link_libraries (conveyor_one_motor serial)

target_link_libraries(conveyor serial)


#add_dependencies(conveyor ${catkin_EXPORTED_TARGETS})






