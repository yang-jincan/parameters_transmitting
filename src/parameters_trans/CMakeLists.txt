cmake_minimum_required(VERSION 3.0.2)
project(parameters_trans)



find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  

)
find_package(PkgConfig REQUIRED)
pkg_check_modules(YAML_CPP REQUIRED yaml-cpp)
include_directories(${YAML_CPP_INCLUDEDIR})


set(WORK_SPACE_PATH ${PROJECT_SOURCE_DIR})
configure_file (
  ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/global_defination/global_defination.h.in
  ${PROJECT_BINARY_DIR}/include/${PROJECT_NAME}/global_defination/global_defination.h)
include_directories(${PROJECT_BINARY_DIR}/include)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES parameters_trans
#  CATKIN_DEPENDS roscpp rospy
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(test1 src/test1.cpp)
target_link_libraries(test1 ${catkin_LIBRARIES} ${YAML_CPP_LIBRARIES})



