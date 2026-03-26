cmake_minimum_required(VERSION 3.5)
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
FetchContent_MakeAvailable(Drogon)

FetchContent_Declare(
  DataFrame
  GIT_REPOSITORY https://github.com/hosseinmoein/DataFrame.git
  GIT_TAG 2.1.0
)
FetchContent_MakeAvailable(DataFrame)

add_compile_options(-fcoroutines)
find_package(Threads REQUIRED)

add_executable(macrw src/main.cpp)

target_include_directories(macrw PRIVATE ${dataframe_SOURCE_DIR}/include)
target_link_libraries(macrw PRIVATE drogon DataFrame Threads::Threads)
