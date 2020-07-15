
add_library(dendrite STATIC dendrite/dendrite.cpp)
add_library(neuron STATIC neuron/neuron.cpp)
add_library(neural_net STATIC neural_net/neural_net.cpp)

add_executable(${PROJECT_NAME} main.cpp)

