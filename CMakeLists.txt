cmake_minimum_required(VERSION 3.22) # 최소 요구 버전을 낮춤
project(LunaTerminal C)

set(CMAKE_C_STANDARD 11)

# CMake 3.29 이상에서만 사용할 명령어들
if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.29")
    message(STATUS "CMake 3.29 or higher detected.")
    # CMake 3.29 전용 명령어 및 기능 추가
else()
    message(WARNING "CMake version is below 3.29. Some features might not be available.")
endif()

if (WIN32)
    add_definitions(-D_WINDOWS)
else()
    include_directories(/path/to/dirent)
endif()

add_executable(LunaTerminal src/main.c
        src/commands.c
        src/commands.h)

