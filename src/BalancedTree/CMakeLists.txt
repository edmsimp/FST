file(GLOB SRCS *.cpp)

add_library(BALANCED_TREE_LIB ${SRCS})
target_include_directories(BALANCED_TREE_LIB PUBLIC .)