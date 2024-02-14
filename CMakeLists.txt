# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(DBusFrameworkProject LANGUAGES CXX)

set(INSTALL_DIR "/app/src")

find_package(Qt6 REQUIRED COMPONENTS Core DBus)

set(CMAKE_AUTOMOC ON) 
set(CMAKE_AUTORCC ON) 
set(CMAKE_AUTOUIC ON)

qt_add_executable(dbusframework
    ./src/dbusframeworkadaptor.cpp ./src/dbusframeworkadaptor.h
    ./src/main.cpp
)

target_link_libraries(dbusframework PRIVATE
    Qt6::Core
    Qt6::DBus
)


install(TARGETS dbusframework
    RUNTIME DESTINATION "${INSTALL_DIR}"
    BUNDLE DESTINATION "${INSTALL_DIR}"
    LIBRARY DESTINATION "${INSTALL_DIR}"
)
