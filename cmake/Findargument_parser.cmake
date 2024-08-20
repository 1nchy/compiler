set(argument_parser_FOUND TRUE)
set(argument_parser_ROOT_DIR ${CMAKE_SOURCE_DIR}/third/argument_parser)

find_path(argument_parser_INCLUDE_DIR NAMES argument_parser.hpp PATHS ${argument_parser_ROOT_DIR}/include)
find_library(argument_parser_LIBRARY NAMES libargument_parser.a PATHS ${CMAKE_SOURCE_DIR}/lib)

set(argument_parser_INCLUDE_DIR ${argument_parser_INCLUDE_DIR})
set(argument_parser_LIBRARIES ${argument_parser_LIBRARY})