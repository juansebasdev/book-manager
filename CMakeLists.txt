cmake_minimum_required(VERSION 3.24)
project(BookManager)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED 14)

file(GLOB SRC
     "./src/*.cpp"
)

add_executable(BookManager ${SRC})
target_include_directories(BookManager PUBLIC ./include)
find_package(nlohmann_json REQUIRED)
