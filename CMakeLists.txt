cmake_minimum_required(VERSION 3.16)
project(QtPhoneBook LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(QtPhoneBook
    main.cpp
    contact.cpp
    phonebook.cpp
    mainwindow.cpp
)

target_link_libraries(QtPhoneBook PRIVATE Qt6::Widgets)
target_compile_features(QtPhoneBook PRIVATE cxx_std_17)

set_target_properties(QtPhoneBook PROPERTIES
    WIN32_EXECUTABLE TRUE
)

