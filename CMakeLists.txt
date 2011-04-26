#---------------------------------------------------------------
# Test for findstlsoft
#---------------------------------------------------------------
cmake_minimum_required(VERSION 2.6.0 FATAL_ERROR)

set(PROJECT_NAME stlsoftfs)

# define project and rule for the build language
project(${PROJECT_NAME} CXX)

# be sure you've get cmake-modules from git://github.com/snikulov/cmake-modules.git
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../cmake-modules)

find_package(Stlsoft)
if(STLSOFT_FOUND)
    include_directories(${STLSOFT_INCLUDE_DIR})
    file(GLOB ${PROJECT_NAME}_sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
    add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_sources})
    target_link_libraries(${PROJECT_NAME} rt)
else(STLSOFT_FOUND)
    message(FATAL_ERROR "Stlsoft not found!")
endif(STLSOFT_FOUND)



