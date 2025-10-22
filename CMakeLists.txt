cmake_minimum_required(VERSION 3.1)
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

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/artifacts/bin")
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/artifacts/bin")


