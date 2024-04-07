cmake_minimum_required(VERSION 3.5)

project(ComboBoxTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Widgets)

qt_standard_project_setup(REQUIRES 6.5)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        model.h model.cpp
	MainWindow.qml
)

qt_add_executable(ComboBoxTestBin WIN32 MACOSX_BUNDLE
    ${PROJECT_SOURCES}
)

target_link_libraries(ComboBoxTestBin
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Widgets
)

qt_add_qml_module(ComboBoxTestBin
    URI ComboBoxTestQml
    QML_FILES
      "MainWindow.qml"
    RESOURCE_PREFIX /ComboBoxTestQml
    NO_RESOURCE_TARGET_PATH    
)

set_target_properties(ComboBoxTestBin PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ComboBoxTestBin
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
