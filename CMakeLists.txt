cmake_minimum_required(VERSION 3.30)
project(Aventura_lui_Artur)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/artifacts/bin")

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


