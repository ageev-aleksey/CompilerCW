cmake_minimum_required(VERSION 3.15)
project(dummy_parser)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SRC ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp ${CMAKE_CURRENT_LIST_DIR}/src/*.c)
FIND_PACKAGE(BISON REQUIRED)
FIND_PACKAGE(FLEX REQUIRED)

set(BISON_OUTPUT ${CMAKE_CURRENT_LIST_DIR}/src/bison.cpp)
set(FLEX_OUTPUT lex.yy.c)

ADD_CUSTOM_COMMAND(
        OUTPUT ${BISON_OUTPUT}
        PRE-BUILD
       COMMAND ${BISON_EXECUTABLE}  -d ${CMAKE_CURRENT_LIST_DIR}/bison.y -o ${BISON_OUTPUT}
)

ADD_CUSTOM_COMMAND(
        OUTPUT ${FLEX_OUTPUT}
        PRE-BUILD
        COMMAND ${FLEX_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/flex.l
)


add_executable(dummy_parser ${SRC} ${FLEX_OUTPUT} ${BISON_OUTPUT})
target_include_directories(dummy_parser PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(dummy_parser fl)