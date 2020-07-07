find_package(Threads REQUIRED)


add_executable(test_embed
        catch.cpp
        test_interpreter.cpp
)

target_include_directories(test_embed PRIVATE ${CATCH_INCLUDE_DIR})
target_compile_options(test_embed PRIVATE -Wall -Wextra -Wconversion -Wcast-qual -Wdeprecated  -Werror)
target_link_libraries(test_embed PRIVATE   ${CONAN_LIBS} dl)

target_link_libraries(test_embed PUBLIC ${CMAKE_THREAD_LIBS_INIT})

add_custom_target(cpptest COMMAND $<TARGET_FILE:test_embed> WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
