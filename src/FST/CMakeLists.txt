file(GLOB SRCS *.cpp)

add_library(FST_LIB ${SRCS})
target_include_directories(FST_LIB PUBLIC .)