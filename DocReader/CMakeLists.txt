cmake_minimum_required(VERSION 3.16)

project(DocReader VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ICON_NAME "logo.icns")
set(app_WINRC app_win32.rc)
set_property(SOURCE app_win32.rc APPEND PROPERTY
        OBJECT_DEPENDS ${PROJECT_SOURCE_DIR}/icons/logo.ico
        )

set(MACOSX_BUNDLE_ICON_FILE ${ICON_NAME})
set(${PROJECT_NAME}_MAC_ICON "${PROJECT_SOURCE_DIR}/icons/${ICON_NAME}")
set_source_files_properties(${${PROJECT_NAME}_MAC_ICON} PROPERTIES
      MACOSX_PACKAGE_LOCATION "Resources")
      

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools PrintSupport)

set(TS_FILES DocReader_zh_CN.ts)

qt6_add_resources(RESOURCES mainres.qrc)

set(PROJECT_SOURCES
        main.cpp
        util.h
        util.cpp
        custom_signstamp_pos_dialog.h
        custom_signstamp_pos_dialog.cpp
        custom_signstamp_riding_dialog.h
        custom_signstamp_riding_dialog.cpp
        custom_signstamp_keyword_dialog.h
        custom_signstamp_keyword_dialog.cpp
        watermark_dialog.h
        watermark_dialog.cpp
        ofdpdfsignerproxy.h
        ofdpdfsignerproxy.cpp
        myprogressbox.h
        myprogressbox.cpp
        mymessagebox.h
        mymessagebox.cpp
        iteminfo.h
        iteminfo.cpp
        stamp_button.h
        stamp_button.cpp
        anno_button.h
        anno_button.cpp
        tool_anno.h
        tool_anno.cpp
        tool_attachment.h
        tool_attachment.cpp
        tool_stamp.h
        tool_stamp.cpp
        tree_attachment.h
        tree_attachment.cpp
        tree_stamp.h
        tree_stamp.cpp
        tree_anno.h
        tree_anno.cpp
        tree_docment.h
        tree_docment.cpp
        tool_smallpic.h
        tool_smallpic.cpp
        tree_smallpic.h
        tree_smallpic.cpp
        stampwidget.h
        stampwidget.cpp
        tabbutton.h
        tabbutton.cpp
        mytabbar.h
        mytabbar.cpp
        fontaddthread.h
        fontaddthread.cpp
        mainwidget.cpp
        mainwidget.h
        mainwidget.ui
        ${${PROJECT_NAME}_MAC_ICON}
        ${TS_FILES}
        ${RESOURCES}
        ${app_WINRC}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DocReader
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET DocReader APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(DocReader SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(DocReader
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(DocReader PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport ${CMAKE_DL_LIBS})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.DocReader)
endif()
set_target_properties(DocReader PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

#windows
#set_target_properties(DocReader PROPERTIES LINK_FLAGS
#   "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\"")
   
include(GNUInstallDirs)
install(TARGETS DocReader
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DocReader)
endif()
