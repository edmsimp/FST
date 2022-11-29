file(GLOB SRCS *.cpp)

add_library(LEVENSHTEIN_LIB ${SRCS})
target_include_directories(LEVENSHTEIN_LIB PUBLIC .)