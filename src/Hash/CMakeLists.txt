file(GLOB SRCS *.cpp)

add_library(HASH_LIB ${SRCS})
target_include_directories(HASH_LIB PUBLIC .)