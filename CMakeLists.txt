cmake_minimum_required(VERSION "3.17.3")


project("anne")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_definitions(
    -DFOO="bar"
)


add_library("dendrite" STATIC "src/dendrite/dendrite.cpp")
add_library("neuron" STATIC "src/neuron/neuron.cpp")

#add_executable("${PROJECT_NAME}" "src/main.cpp")
add_executable("${PROJECT_NAME}-neuron-test" "test/neurontest.cpp")
target_link_libraries("${PROJECT_NAME}-neuron-test" "neuron")

add_executable("${PROJECT_NAME}-dendrite-test" "test/dendritetest.cpp")
target_link_libraries("${PROJECT_NAME}-dendrite-test" "neuron")
target_link_libraries("${PROJECT_NAME}-dendrite-test" "dendrite")

#install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

