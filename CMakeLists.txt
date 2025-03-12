cmake_minimum_required(VERSION 3.30)
project(Game_Engine)

set(CMAKE_CXX_STANDARD 20)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add library directory
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Find all static and dynamic libraries in lib/
file(GLOB LIBS "${CMAKE_SOURCE_DIR}/lib/*.a" "${CMAKE_SOURCE_DIR}/lib/*.so")

# Add executable
add_executable(Game_Engine main.cpp
        src/IComponent.h
        src/Components/PositionComponent.cpp
        src/Components/PositionComponent.h
        src/Components/RenderComponent.h
        src/Components/CircleRenderComponent.cpp
        src/Components/CircleRenderComponent.h
        src/GameObject.cpp
        src/GameObject.h
        src/GameObjectManager.cpp
        src/GameObjectManager.h
        src/StateManager.cpp
        src/StateManager.h
        src/States/BaseState.h
        src/States/IdleState.h
        src/States/IdleState.cpp
        src/States/WalkingState.cpp
        src/States/WalkingState.h
        src/States/JumpingState.cpp
        src/States/JumpingState.h
)

# Link libraries
if (LIBS)
    target_link_libraries(Game_Engine PRIVATE ${LIBS})
else()
    message(WARNING "No libraries found in lib/ folder!")
endif()

# Fix: Link macOS system frameworks (CoreFoundation, IOKit, CoreGraphics, AppKit)
if(APPLE)
    target_link_libraries(Game_Engine PRIVATE
            "-framework CoreFoundation"
            "-framework IOKit"
            "-framework CoreGraphics"
            "-framework AppKit"  # Required for `_NSApp` symbol
    )
endif()