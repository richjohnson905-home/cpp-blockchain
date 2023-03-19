cmake_minimum_required(VERSION 3.20)
project(MyCoin)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)  # Includes the contents of the conanbuildinfo.cmake file.
conan_basic_setup()  # Prepares the CMakeList.txt for Conan.

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
        mycoinlib
        ${CONAN_LIBS}
        )


include(CTest)
add_subdirectory(src)
add_subdirectory(test)