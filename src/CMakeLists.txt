
add_library(dendrite STATIC dendrite/dendrite.cpp neural_net/neural_net.cpp)
add_library(neuron STATIC neuron/neuron.cpp neural_net/neural_net.cpp)

add_executable(${PROJECT_NAME} main.cpp)

