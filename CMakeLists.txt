cmake_minimum_required(VERSION 2.8.9)

project(chinese-calendar)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)
find_package(Qt5Sql)
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Sql_INCLUDE_DIRS}.)
add_definitions(${Qt5Widgets_DEFINITIONS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(CALENDAR_SRCS
	main.cpp
	dateitem.cpp
	datemaskwidget.cpp
	chinesecalendar.cpp
	ccbo.cpp
	cnote.cpp
	aboutdialog.cpp
)

set(CALENDAR_UIS
	calendar.ui
    dateitem.ui
	aboutdialog.ui
)

qt5_wrap_ui(CALENDAR_UIS_H ${CALENDAR_UIS})
qt5_add_resources(CALENDAR_RES chinese-calendar.qrc)
add_executable(chinese-calendar ${CALENDAR_SRCS} ${CALENDAR_UIS_H} ${CALENDAR_RES})
qt5_use_modules(chinese-calendar Widgets Sql)
#target_link_libraries(chinese-calendar ${Qt5Widgets_LIBRARIES} ${Qt5Sql_LIBRARIES})

