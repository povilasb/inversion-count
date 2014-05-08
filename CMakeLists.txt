cmake_minimum_required (VERSION 2.6)
project (inversion-count CXX)


# Configurable.

set (PROJECT_LIB "libinversions")
set (PROJECT_EXEC "main")


message (STATUS "Build type: ${CMAKE_BUILD_TYPE}.")

set (CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
set (CMAKE_CXX_FLAGS_RELEASE "-O3")
set (CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Werror -pedantic")


set (SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file (GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")
set (MAIN_SRC "${SRC_DIR}/main.cpp")
list (REMOVE_ITEM SRC_FILES "${MAIN_SRC}")

add_library ("${PROJECT_LIB}" STATIC ${SRC_FILES})

add_executable ("${PROJECT_EXEC}" "${MAIN_SRC}")
target_link_libraries ("${PROJECT_EXEC}" "${PROJECT_LIB}")


#
# Testing rules.
#

enable_testing()


set (TEST_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test")
file (GLOB_RECURSE TEST_SRC_FILES "${TEST_SRC_DIR}/*.cpp")

set (GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest")
add_subdirectory (${GTEST_DIR})
include_directories ("${GTEST_DIR}/include" "${SRC_DIR}")


add_custom_target (build_test COMMAND "")

foreach (TEST_SRC ${TEST_SRC_FILES})
	get_filename_component (TEST_NAME "${TEST_SRC}" NAME_WE)

	add_executable ("${TEST_NAME}" EXCLUDE_FROM_ALL ${TEST_SRC})
	add_dependencies ("${TEST_NAME}" "${PROJECT_LIB}")
	target_link_libraries (${TEST_NAME} "gtest" "gtest_main"
		"${PROJECT_LIB}")

	set (TEST_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/Testing/bin")
	set_target_properties("${TEST_NAME}" PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${TEST_OUTPUT_DIR}")

	add_test ("${TEST_NAME}" "${TEST_OUTPUT_DIR}/${TEST_NAME}")

	add_dependencies (build_test "${TEST_NAME}")
endforeach()
