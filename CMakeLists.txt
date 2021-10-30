cmake_minimum_required(VERSION 3.20)
project(engine)

set(CMAKE_CXX_STANDARD 23)
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
add_executable(engine
        main.cpp
        Game.hpp
        Game.cpp
        Raycaster.hpp
        Raycaster.cpp
        GameObject.hpp
        GameObject.cpp
        PlayerInputComponent.hpp
        PlayerInputComponent.cpp
        World.hpp
        World.cpp
        ResourceHolder.h
        Textures.h
        Textures.cpp
        Player.h
        )
target_link_libraries(engine sfml-graphics sfml-audio sfml-window sfml-system)
