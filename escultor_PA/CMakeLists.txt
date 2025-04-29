cmake_minimum_required(VERSION 3.16)

project(escultor_PA LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(escultor_PA main.cpp
    sculptor.h sculptor.cpp)

include(GNUInstallDirs)
install(TARGETS escultor_PA
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
