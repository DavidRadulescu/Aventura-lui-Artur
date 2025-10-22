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

if (WIN32)
    set(EXEC_FILE_NAME "Aventura_lui_Artur.exe")
else()
    set(EXEC_FILE_NAME "Aventura_lui_Artur")
endif()

add_custom_command(TARGET Aventura_lui_Artur POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:Aventura_lui_Artur>/artifacts/bin

        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Aventura_lui_Artur>
        $<TARGET_FILE_DIR:Aventura_lui_Artur>/artifacts/bin/${EXEC_FILE_NAME}
        COMMENT "Copiere executabila artifacts"
)


