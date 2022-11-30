file(GLOB SRCS *.cpp)

add_library(COMPLETERS_LIB ${SRCS})
target_include_directories(COMPLETERS_LIB PUBLIC .)

target_link_libraries(COMPLETERS_LIB PUBLIC BALANCED_TREE_LIB)