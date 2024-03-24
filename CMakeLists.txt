cmake_minimum_required(VERSION 3.5)
project(cpp_example)

include_directories(
  include
  /usr/local/include/coin-or
)
link_directories(/usr/local/lib)

add_library(MyNLP src/MyNLP.cpp)
target_link_libraries(MyNLP ipopt)

add_executable(cpp_example src/cpp_example.cpp)
target_link_libraries(cpp_example MyNLP ipopt)
