cmake_minimum_required(VERSION "3.12.2")


project("anne")


add_library("dendrite" SHARED "src/dendrite/dendrite.cpp")
add_library("neuron" STATIC "src/neuron/neuron.cpp")

#add_executable("${PROJECT_NAME}" "src/main.cpp")
#add_executable("${PROJECT_NAME}-dendrite-test" "test/dendritetest.cpp")
add_executable("${PROJECT_NAME}-neuron-test" "test/neurontest.cpp")
target_link_libraries("${PROJECT_NAME}-neuron-test" "neuron")

#target_link_libraries("${PROJECT_NAME}-dendrite-test" "neuron")

#add_executable("${PROJECT_NAME}-neuron-test" "test/neurontest.cpp")

#install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

