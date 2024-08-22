set(abstract_factory_FOUND TRUE)
set(abstract_factory_ROOT_DIR ${CMAKE_SOURCE_DIR}/third/abstract_factory)

find_path(abstract_factory_INCLUDE_DIR NAMES abstract_factory.hpp PATHS ${abstract_factory_ROOT_DIR}/include)

set(abstract_factory_INCLUDE_DIR ${abstract_factory_INCLUDE_DIR})