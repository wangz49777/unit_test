cmake_minimum_required(VERSION 3.5)
 
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# Set the project name
project (google_test_example)
#############################################
# Unit tests
# enable CTest testing
enable_testing()
# include_directories("/home/wzy/app/googletest-build-release-1.10/include")
# get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
# message("include_dirs: ${dir}")
# Add a testing executable
add_executable(unit_tests src/unit_tests.cpp)
#compiler with the -I flag eg. -I/directory/path
#\home\project\googletest\googletest\include
# target_include_directories(unit_tests PUBLIC "/home/project/googletest/googletest/include")
# 打印指定的头文件搜索路径
get_property(public_private_dirs TARGET unit_tests PROPERTY INCLUDE_DIRECTORIES)
message("public_private_dirs: ${public_private_dirs}")
#find libgtest.so library
find_library(GTEST 
    gtest) 
#     "/home/project/googletest/googletest/lib" )
find_library(GTEST_MAIN 
    gtest_main) 
#     "/home/project/googletest/googletest/lib" )    
IF (NOT GTEST)
    MESSGAGE(FATAL_ERROR "libgtest.so not found")
ENDIF(NOT GTEST)
IF (NOT GTEST_MAIN)
    MESSGAGE(FATAL_ERROR "libgtest_main.so not found")
ENDIF(NOT GTEST_MAIN)
message(STATUS " gtest path : " ${GTEST})
message(STATUS " gtest_main path : " ${GTEST_MAIN})
target_link_libraries(unit_tests
    ${GTEST} 
    ${GTEST_MAIN}
)
#To add a test you call the add_test() function. This will create a named test which will run the supplied command.
add_test(test_all unit_tests)