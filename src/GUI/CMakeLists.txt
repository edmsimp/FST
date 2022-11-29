include(FetchContent)
 
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
)
 
FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(ftxui-gui main.cpp)
include_directories(BalancedTree)
# target_include_directories(ftxui-starter PRIVATE .)
 
# target_link_libraries(ftxui-starter
#     PRIVATE ftxui::screen
#     PRIVATE ftxui::dom
#     PRIVATE ftxui::component
# )