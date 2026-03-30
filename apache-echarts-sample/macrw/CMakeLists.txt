cmake_minimum_required(VERSION 3.10)
project (macrw)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    Drogon
    GIT_REPOSITORY https://github.com/drogonframework/drogon
    GIT_TAG v1.9.0
)
FetchContent_GetProperties(Drogon)
if(NOT drogon_POPULATED)
    FetchContent_Populate(Drogon)
endif()

FetchContent_Declare(
  DataFrame
  GIT_REPOSITORY https://github.com/hosseinmoein/DataFrame.git
  GIT_TAG 2.1.0
)
FetchContent_GetProperties(DataFrame)
if(NOT dataframe_POPULATED)
    FetchContent_Populate(DataFrame)
endif()

add_compile_options(-fcoroutines)
find_package(Threads REQUIRED)

add_executable(macrw src/main.cpp)

target_include_directories(macrw PRIVATE ${dataframe_SOURCE_DIR}/include)
target_link_libraries(macrw PRIVATE drogon DataFrame Threads::Threads)
