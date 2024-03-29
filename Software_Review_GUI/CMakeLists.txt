cmake_minimum_required(VERSION 3.14)

project(Software_Review_GUI LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_executable(Software_Review_GUI
  main.cpp
  softwaregui.h softwaregui.cpp
  software.h software.cpp
  softwarelist.h softwarelist.cpp
  filewriter.h filewriter.cpp
  listwriter.h listwriter.cpp
  filereader.h filereader.cpp
  listreader.h listreader.cpp
)
target_link_libraries(Software_Review_GUI Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Software_Review_GUI Qt${QT_VERSION_MAJOR}::Widgets)


include(GNUInstallDirs)
install(TARGETS Software_Review_GUI
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
