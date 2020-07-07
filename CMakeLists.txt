cmake_minimum_required(VERSION 3.16)
project(dynamic-load-python)

#############################################################################################
#conan

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.15/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

if (CONAN_EXPERIMENTAL_INCLUDE)
    set(CONAN_SYSTEM_INCLUDES "On")
endif ()

conan_cmake_run(
        CONANFILE conanfile.txt
        BASIC_SETUP
        BUILD missing
        NO_OUTPUT_DIRS
)

# conan
#############################################################################################

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests)