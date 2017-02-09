cmake_minimum_required(VERSION 3.6)
project(benchmarks)

set(CMAKE_CXX_STANDARD 14)
# Set Build Type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE string "Choose the type of build, options are: Debug Release." FORCE)
endif ()
if (Coverage)
    set(CMAKE_BUILD_TYPE Debug)
endif ()

#set compile flags, add default compile flags in the quotes
set(COMPILE_FLAGS "-Wall")
if (${CMAKE_BUILD_TYPE} MATCHES DEBUG)
    set(COMPILE_FLAGS ${COMPILE_FLAGS}) #add other flags for debug mode
elseif (${CMAKE_BUILD_TYPE} MATCHES RELEASE)
    set(COMPILE_FLAGS ${COMPILE_FLAGS} "O2")
endif ()
add_definitions(${COMPILE_FLAGS})

add_subdirectory(include)
add_subdirectory(benchmark)