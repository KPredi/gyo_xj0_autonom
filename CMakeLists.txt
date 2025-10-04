cmake_minimum_required(VERSION 3.8)
project(gyo_xj0_autonom)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

set(ament_dependencies
  rclcpp
  std_msgs
  geometry_msgs
)

add_executable(generator src/generator.cpp)
ament_target_dependencies(generator rclcpp std_msgs)

add_executable(atlagolo src/atlagolo.cpp)
ament_target_dependencies(atlagolo rclcpp std_msgs)

add_executable(generator_minusz src/generator_minusz.cpp)
ament_target_dependencies(generator_minusz rclcpp std_msgs)

add_executable(atlagolo_minusz src/atlagolo_minusz.cpp)
ament_target_dependencies(atlagolo_minusz rclcpp std_msgs)

add_executable(atlag_ossz src/atlag_ossz.cpp)
ament_target_dependencies(atlag_ossz rclcpp std_msgs)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

install(TARGETS
  generator
  atlagolo
  generator_minusz
  atlagolo_minusz  
  atlag_ossz
  DESTINATION lib/${PROJECT_NAME})

  install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)


  ament_package()
