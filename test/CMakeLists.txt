cmake_minimum_required(VERSION 3.24)
project(Test)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED 14)

file(GLOB SRC
     "../src/*.cpp"
)

FOREACH(item ${SRC})
  IF(${item} MATCHES "main.cpp")
    LIST(REMOVE_ITEM SRC ${item})
  ENDIF(${item} MATCHES "main.cpp")
ENDFOREACH(item)

add_executable(Test ${SRC} BookManager_test.cpp)
target_include_directories(Test PUBLIC ../include)
find_package(nlohmann_json REQUIRED)
find_package(GTest REQUIRED)
target_link_libraries(Test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
