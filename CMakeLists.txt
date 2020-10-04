cmake_minimum_required(VERSION "3.18.3")

project("listdir")

#Look for the boost package in system
find_package(Boost REQUIRED) 

include_directories(${Boost_INCLUDE_DIR}) 
link_directories(${Boost_LIBRARY_DIRS})

set(Boost_USE_STATIC_LIBS        OFF)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
set(BOOST_ALL_DYN_LINK           ON)

#Use jsoncpp as a amalgamated library
set(JSONCPP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp)
add_subdirectory(jsoncpp)
include_directories(${JSONCPP_INCLUDE_DIR})
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/lib)
add_executable("${PROJECT_NAME}" "Main.cpp")

target_link_libraries("${PROJECT_NAME}" ${Boost_LIBRARIES}) 
target_link_libraries("${PROJECT_NAME}" jsoncpp)
ADD_DEPENDENCIES("${PROJECT_NAME}" jsoncpp)

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "Main.cpp" DESTINATION src)

include(CTest)

add_test("test1" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" "C:/")

include(CPack)