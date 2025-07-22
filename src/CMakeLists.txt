set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
# set(CMAKE_WIN32_EXECUTABLE TRUE)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/resources.qrc)
file(GLOB_RECURSE HEADERS  ${PROJECT_SOURCE_DIR}/src/*.h)

include_directories(${PROJECT_SOURCE_DIR}/third-party/chess-library/include)

find_package(Boost REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_add_resources(RESOURCES ${PROJECT_SOURCE_DIR}/resources.qrc)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${RESOURCES}
) 

source_group("Source Files" FILES ${SOURCES})
source_group("Header Files" FILES ${HEADERS})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -O3)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${THIRD_PARTY_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE 
        ${Boost_INCLUDE_DIR}/stage/lib
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Boost::headers
        ntdll.lib
)