cmake_minimum_required(VERSION 3.0.0)
project(libpwny VERSION 1.0.0)

include_directories(include)

file(GLOB SRCS src/*.c)
add_library(pwny STATIC ${SRCS})

set_property(TARGET pwny PROPERTY C_STANDART 99)
set_property(TARGET pwny PROPERTY POSITION_INDEPENDENT_CODE ON)

set_target_properties(pwny PROPERTIES OUTPUT_NAME pwny)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})