
include_directories(
	${anne_SOURCE_DIR}/src
	${Boost_INCLUDE_DIRS}
)

add_executable(neurontest neurontest.cpp)
target_link_libraries(neurontest 
    neuron
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	)

#add_executable("dendritetest" "dendritetest.cpp")
#target_link_libraries("dendritetest" "neuron")
#target_link_libraries("dendritetest" "dendrite")

#add_test(NAME "DendriteTest" COMMAND dendritetest)
add_test(NAME "NeuronTest" COMMAND neurontest)
