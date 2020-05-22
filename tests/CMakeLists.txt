

file(GLOB SRC  ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
find_package(GTest REQUIRED)
add_executable(Tests ${SRC})
target_include_directories(Tests PUBLIC ${INCLUDE_DIR})
target_link_libraries(Tests  gtest_main gtest pthread)