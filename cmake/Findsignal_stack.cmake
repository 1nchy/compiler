set(signal_stack_FOUND TRUE)
set(signal_stack_ROOT_DIR ${CMAKE_SOURCE_DIR}/third/signal_stack)

find_path(signal_stack_INCLUDE_DIR NAMES signal_stack.hpp PATHS ${signal_stack_ROOT_DIR}/include)
find_library(signal_stack_LIBRARY NAMES libsignal_stack.a PATHS ${CMAKE_SOURCE_DIR}/lib)

set(signal_stack_INCLUDE_DIR ${signal_stack_INCLUDE_DIR})
set(signal_stack_LIBRARIES ${signal_stack_LIBRARY})