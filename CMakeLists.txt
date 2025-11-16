cmake_minimum_required(VERSION 3.16)
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
        Enemy.h
        Enemy.cpp
        Goblin.h
        Goblin.cpp
        Orc.h
        Orc.cpp
        Dragon.cpp
        Dragon.h
        GameExceps.h
        Skeleton.cpp
        Skeleton.h
)

install(TARGETS Aventura_lui_Artur
        RUNTIME DESTINATION "bin"
)

install(FILES "launcher.command"
        DESTINATION "bin"
)


