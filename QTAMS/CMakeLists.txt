cmake_minimum_required(VERSION 3.5)

project(QTAMS VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QTAMS
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        FinalProject_gui_Sammed/Account.cpp FinalProject_gui_Sammed/Account.h FinalProject_gui_Sammed/accountLog.txt FinalProject_gui_Sammed/AccountManager.cpp FinalProject_gui_Sammed/AccountManager.h FinalProject_gui_Sammed/bank_transaction_history.txt FinalProject_gui_Sammed/BankAccount.cpp FinalProject_gui_Sammed/BankAccount.h FinalProject_gui_Sammed/DoublyLinkedList.cpp FinalProject_gui_Sammed/DoublyLinkedList.h FinalProject_gui_Sammed/ListNode.h FinalProject_gui_Sammed/plot.R FinalProject_gui_Sammed/Result_1.txt FinalProject_gui_Sammed/Result_2.txt FinalProject_gui_Sammed/Rplots.pdf FinalProject_gui_Sammed/SharesValueSortStrategy.h FinalProject_gui_Sammed/SortingStrategy.h FinalProject_gui_Sammed/Stock_Portfolio_Info.txt FinalProject_gui_Sammed/stock_transaction_history.txt FinalProject_gui_Sammed/StockAccount.cpp FinalProject_gui_Sammed/StockAccount.h FinalProject_gui_Sammed/SymbolSortStrategy.h

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QTAMS APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QTAMS SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QTAMS
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QTAMS PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QTAMS)
endif()
set_target_properties(QTAMS PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QTAMS
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTAMS)
endif()
