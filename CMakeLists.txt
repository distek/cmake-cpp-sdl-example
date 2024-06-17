cmake_minimum_required(VERSION 3.0)
project(something)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

# Set up vcpkg and Emscripten toolchain files
set(CMAKE_TOOLCHAIN_FILE "~/git-clones/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(sdl2-gfx CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)

add_executable(something "")

target_sources(something
    PRIVATE
    src/Main.cpp
)

# Copy the game assets to the build directory, so that we can debug the game easily
# file(COPY assets/ DESTINATION assets/)

# if (APPLE)
    # This is for macOS
    # TODO: Handle iOS.
    target_link_libraries(something PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_ttf::SDL2_ttf-static SDL2::SDL2_gfx SDL2_image::SDL2_image-static SDL2_mixer::SDL2_mixer-static "-framework CoreFoundation")
    set_target_properties(something PROPERTIES LINK_FLAGS "-Wl,-F/Library/Frameworks")
    # elseif (WIN32)
    #     target_link_libraries(something PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_ttf::SDL2_ttf SDL2::SDL2_gfx SDL2::SDL2_image SDL2_mixer::SDL2_mixer "Shlwapi.lib")
    # elseif (LINUX)
    #     target_link_libraries(something PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_ttf::SDL2_ttf-static SDL2::SDL2_gfx SDL2::SDL2_image SDL2_mixer::SDL2_mixer-static)
    # endif ()
