cmake_minimum_required(VERSION 3.10)
project(stmath C)


set(CMAKE_C_STANDARD 11)

include_directories(include)

add_library(stmath STATIC src/stmath.c)

add_executable(example examples/base.c)
target_link_libraries(example stmath)

install(TARGETS stmath ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
