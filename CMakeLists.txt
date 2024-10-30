cmake_minimum_required(VERSION 3.30.5)
project(rockPaperScissors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # C++20 is required
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(rockPaperScissors src/main.cpp)