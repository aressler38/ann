include_directories(
	${PROJECT_SOURCE_DIR}/src
	${Boost_INCLUDE_DIRS}
)


add_executable(testdendrite testdendrite.cpp)
target_link_libraries(testdendrite 
	neuron
	dendrite
	${Boost_FILESYSTEM_LIBRARY}
	${Boost_SYSTEM_LIBRARY}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	)
add_test(NAME "DendriteTest" COMMAND testdendrite)


add_executable(testneuron testneuron.cpp)
target_link_libraries(testneuron 
    neuron
	${Boost_FILESYSTEM_LIBRARY}
	${Boost_SYSTEM_LIBRARY}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	)
add_test(NAME "NeuronTest" COMMAND testneuron)


add_executable(testneural_net testneural_net.cpp)
target_link_libraries(testneural_net 
	neuron
    neural_net
	${Boost_FILESYSTEM_LIBRARY}
	${Boost_SYSTEM_LIBRARY}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	)
add_test(NAME "NeuralNetTest" COMMAND testneural_net)

