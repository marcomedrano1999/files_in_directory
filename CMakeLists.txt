cmake_minimum_required(VERSION "3.18.3")

project("listdir")

find_package(Boost REQUIRED) 

include_directories(${Boost_INCLUDE_DIR}) 

link_directories(${Boost_LIBRARY_DIRS})

set(Boost_USE_STATIC_LIBS        OFF)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
set(BOOST_ALL_DYN_LINK           ON)

find_package(JsonCpp REQUIRED)
include_directories(${JsonCpp_INCLUDE_DIRS})

set(JsonCpp_USE_STATIC_LIBS        OFF)
set(JsonCpp_USE_MULTITHREADED      ON)
set(JsonCpp_USE_STATIC_RUNTIME     OFF)
set(JsonCpp_ALL_DYN_LINK           ON)

add_executable("${PROJECT_NAME}" "Main.cpp")

target_link_libraries("${PROJECT_NAME}" ${Boost_LIBRARIES}) 
target_link_libraries("${PROJECT_NAME}" ${JsonCpp_LIBRARIES})

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "Main.cpp" DESTINATION src)

include(CTest)

add_test("test1" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" "C:/prueba")

include(CPack)