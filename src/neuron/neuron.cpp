#include "neuron.h"
#include <iostream>

/* ==== neuron_output ==== */

void neuron_output::_initialize () {
  _buffer = new unsigned[128];
}

void neuron_output::_release () {
  delete [] _buffer;
}

/* ==== neuron_input ==== */

void neuron_input::_initialize () {
  std::cout<<"In neuron input init\n";
}

void neuron_input::_release () {
  std::cout<<"In neuron output release\n";
}

/* ==== neuron_state ==== */

void neuron_state::_initialize () {
  std::cout<<"In neuron state init\n";
}

void neuron_state::_release () {
  std::cout<<"In neuron state release\n";
}

/* ==== neuron ==== */

neuron::neuron() {
  std::cout<<"In neuron CONSTRUCTOR\n";
}

neuron::~neuron() {
  std::cout<<"In neuron DESTRUCTOR\n";
}
