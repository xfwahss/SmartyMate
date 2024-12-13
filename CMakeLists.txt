cmake_minimum_required(VERSION 3.29)
project(SmartyMate CXX)

set(CMAKE_C_STANDARD 17)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "D:/GreenSoftware/Qt/6.8.1/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

include_directories(include)
add_executable(SmartyMate src/main.cxx
        src/DesktopMate.cxx
)
target_link_libraries(SmartyMate Qt::Core Qt::Gui Qt::Widgets)