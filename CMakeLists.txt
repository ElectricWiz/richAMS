cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(Simulation)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

include_directories(${PROJECT_SOURCE_DIR}/headers)

file(GLOB sources ${PROJECT_SOURCE_DIR}/source/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/headers/*.hh)

file(GLOB MACRO_FILES ".mac")
file(COPY ${MACRO_FILES} DESTINATION ${PROJECT_BINARY_DIR})

set(SIM_SOURCE ${PROJECT_SOURCE_DIR}/source/Sim.cc)
list(APPEND sources ${SIM_SOURCE})

add_executable(sim source/Sim.cc ${sources} ${headers})
target_link_libraries(sim ${Geant4_LIBRARIES})

add_custom_target(Simulation DEPENDS sim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
