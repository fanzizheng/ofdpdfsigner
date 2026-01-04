cmake_minimum_required(VERSION 3.5)

project(webext VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)

add_definitions(-DNOMINMAX)



set(PROJECT_SOURCES
#windows
#        qtservice_p.h
#        qtservice.h
#        qtservice.cpp
#        qtservice_win.cpp
#mac linux windows
        main.cpp
        ../ofdpdfsigner/ofdpdfsigner/basic/FZZBytes.h
        ../ofdpdfsigner/ofdpdfsigner/basic/FZZBytes.cpp
        Util.h
        Util.cpp
        RestfulServer.h
        RestfulServer.cpp
        mongoose.h
        mongoose.cpp
        ../DocReader/ofdpdfsignerproxy.h
        ../DocReader/ofdpdfsignerproxy.cpp
        fontaddthread.h
        fontaddthread.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(webext
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET webext APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(webext SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(webext
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(webext
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../ofdpdfsigner/ofdpdfsigner/
        ${CMAKE_CURRENT_SOURCE_DIR}/../DocReader/

)

target_link_libraries(webext PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)

set_target_properties(webext PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE

)

#windows
#set_target_properties(webext PROPERTIES LINK_FLAGS
#   "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\"")

install(TARGETS webext
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(webext)
endif()
