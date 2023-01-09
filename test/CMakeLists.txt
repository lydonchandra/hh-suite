#include(${CMAKE_CURRENT_SOURCE_DIR}/../src/CMakeLists.txt)

find_package(OpenMP)
if (OPENMP_FOUND)
    message("-- Found OpenMP")
    add_definitions(-DOPENMP)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif ()

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/../src/hhsuite_config.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/../src/hhsuite_config.h")
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/cs)

add_executable(hhblits_test${EXE_SUFFIX} hhblits_test.cpp)
target_link_libraries(hhblits_test${EXE_SUFFIX} HH_OBJECTS)