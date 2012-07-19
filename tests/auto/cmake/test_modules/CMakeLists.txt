
cmake_minimum_required(VERSION 2.8)

project(test_modules)

find_package(Qt5Network REQUIRED)

find_package(Qt5XmlPatterns REQUIRED)

include_directories(
  ${Qt5XmlPatterns_INCLUDE_DIRS}
)

add_definitions(
  ${Qt5XmlPatterns_DEFINITIONS}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Core_EXECUTABLE_COMPILE_FLAGS}")

add_executable(mainapp main.cpp)
target_link_libraries(mainapp
  ${Qt5XmlPatterns_LIBRARIES}
)
