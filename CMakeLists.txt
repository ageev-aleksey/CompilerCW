cmake_minimum_required(VERSION 3.15)
project(dummy_parser)

set(CMAKE_CXX_STANDARD 14)

option(TESTS_COMPILE "" ON)
set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

file(GLOB SRC ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp ${CMAKE_CURRENT_LIST_DIR}/src/*.c)
file(GLOB SRC_parser  ${CMAKE_CURRENT_LIST_DIR}/src/parser/*.cpp)
FIND_PACKAGE(BISON REQUIRED)
FIND_PACKAGE(FLEX REQUIRED)

set(BISON_OUTPUT ${CMAKE_CURRENT_LIST_DIR}/src/bison.cpp)
set(FLEX_OUTPUT lex.yy.c)

add_custom_target(bison)

ADD_CUSTOM_COMMAND(
        OUTPUT  ${BISON_OUTPUT}
        COMMAND ${BISON_EXECUTABLE}  -d ${CMAKE_CURRENT_LIST_DIR}/bison-dev.y -o ${BISON_OUTPUT}
)

ADD_CUSTOM_COMMAND(
        OUTPUT ${FLEX_OUTPUT}
        PRE-BUILD
        COMMAND ${FLEX_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/flex.l
)


add_executable(parser ${SRC}  ${SRC_parser} ${FLEX_OUTPUT} ${BISON_OUTPUT})
target_include_directories(parser PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/parser)
target_link_libraries(parser fl)

if(${TESTS_COMPILE})
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tests)
endif()