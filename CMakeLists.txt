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

set(CI_ARTIFACT_DIR "${CMAKE_BINARY_DIR}/artifacts/bin")

if (WIN32)
    set(EXEC_FILE_NAME "Aventura_lui_Artur.exe")
else()
    set(EXEC_FILE_NAME "Aventura_lui_Artur")
endif()

add_custom_command(TARGET Aventura_lui_Artur POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CI_ARTIFACT_DIR}"

        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Aventura_lui_Artur>
        "${CI_ARTIFACT_DIR}/${EXEC_FILE_NAME}"
        COMMENT "Copiere executabila"
)


