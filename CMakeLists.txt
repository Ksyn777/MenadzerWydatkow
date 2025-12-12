cmake_minimum_required(VERSION 3.16)

project(MenadzerWydatkow VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)


set(TS_FILES MenadzerWydatkow_pl_PL.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui


        databasemanager.h databasemanager.cpp
        addtransactiondialog.h addtransactiondialog.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/AddTransactionDialog.ui



        globals.h globals.cpp
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MenadzerWydatkow
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        resources.qrc
        img/add.png img/all.png img/edit.png img/remove.png
        removedialog.h removedialog.cpp removedialog.ui
        editdialog.h editdialog.cpp editdialog.ui
        alltransactions.h alltransactions.cpp alltransactions.ui
        colormodel.h colormodel.cpp
    )

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MenadzerWydatkow APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(MenadzerWydatkow SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MenadzerWydatkow
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(MenadzerWydatkow PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MenadzerWydatkow PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(MenadzerWydatkow PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MenadzerWydatkow PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(MenadzerWydatkow PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
target_link_libraries(MenadzerWydatkow PRIVATE Qt${QT_VERSION_MAJOR}::Core)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MenadzerWydatkow)
endif()
set_target_properties(MenadzerWydatkow PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS MenadzerWydatkow
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MenadzerWydatkow)
endif()
