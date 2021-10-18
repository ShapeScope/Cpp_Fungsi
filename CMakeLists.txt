cmake_minimum_required(VERSION 3.0.0)
project(fungsi VERSION 0.1.0)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

include(CTest)
enable_testing()

add_subdirectory(includes)

find_package(Curses REQUIRED)
add_executable(fungsi main.cpp)
target_link_libraries(fungsi ${CURSES_LIBRARIES} includes)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
