#set(Qt5::Test)
project(CTestActionsBug)
cmake_minimum_required(VERSION 3.00)

find_package(Qt5Test REQUIRED)
set(CMAKE_AUTOMOC ON)
enable_testing()

add_executable(test_demo test_demo.cpp)
target_link_libraries(test_demo Qt5::Test)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
add_test(NAME test_demo COMMAND test_demo -tap)
add_dependencies(check test_demo)
