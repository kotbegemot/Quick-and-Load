find_package(Threads REQUIRED)

find_package(Python3 COMPONENTS Development)
include_directories(${Python3_INCLUDE_DIRS})

add_executable(test_embed
        catch.cpp
        test_interpreter.cpp
        fake_python.cpp
        fake_python_1.cpp
        dl_python.hpp
)

set_property(TARGET test_embed PROPERTY POSITION_INDEPENDENT_CODE ON)
target_include_directories(test_embed PRIVATE ${CATCH_INCLUDE_DIR})
target_link_libraries(test_embed PRIVATE   ${CONAN_LIBS} ${CMAKE_DL_LIBS})

target_link_libraries(test_embed PUBLIC ${CMAKE_THREAD_LIBS_INIT})

add_custom_target(cpptest COMMAND $<TARGET_FILE:test_embed> WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
