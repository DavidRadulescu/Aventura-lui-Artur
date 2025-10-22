cmake_minimum_required(VERSION 3.30)
project(Aventura_lui_Artur)

set(CMAKE_CXX_STANDARD 26)

add_executable(Aventura_lui_Artur main.cpp
        HP.h
        Item.cpp
        Item.h
        Inventory.cpp
        Inventory.h
        Player.h
        HP.cpp
        Player.cpp
)

set(EXECUTABLE_NAME Aventura_lui_Artur)

add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/artifacts/bin
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${EXECUTABLE_NAME}> $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/artifacts/bin/
)


