cmake_minimum_required(VERSION 3.3)
project(cardInterlacer)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES main.cpp model/CardNode.cpp model/CardNode.h model/CardCollection.cpp model/CardCollection.h controller/CardController.cpp controller/CardController.h view/CardDisplay.cpp view/CardDisplay.h)
add_executable(cardInterlacer ${SOURCE_FILES})