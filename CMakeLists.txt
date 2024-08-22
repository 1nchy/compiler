cmake_minimum_required(VERSION 3.26)
project(compiler)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE "Debug")

set(PROJECT_SOURCE_TARGET ${PROJECT_NAME}_source_target)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_executable(${PROJECT_NAME} main.cpp)

macro(add_third_libraries lib_name)
    message(STATUS "add third library: " ${lib_name})
    find_package(${lib_name} REQUIRED MODULE)
    if (${lib_name}_FOUND)
        if (${lib_name}_INCLUDE_DIR)
            include_directories(${${lib_name}_INCLUDE_DIR})
        endif (${lib_name}_INCLUDE_DIR)
        if (${lib_name}_LIBRARIES)
            link_libraries(${${lib_name}_LIBRARIES})
        endif (${lib_name}_LIBRARIES)
    endif (${lib_name}_FOUND)
endmacro(add_third_libraries)

add_third_libraries(trie_tree)
add_third_libraries(argument_parser)
add_third_libraries(signal_stack)
add_third_libraries(finite_state_machine)
add_third_libraries(abstract_factory)

add_subdirectory(src)
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_TARGET}
)