cmake_minimum_required(VERSION 3.29)
project(LibrarySystemBackend)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(LibraryBackend
    src/main.cpp
    src/book.cpp
    src/user.cpp
    src/libraryService.cpp
)
