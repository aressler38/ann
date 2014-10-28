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
  
}

void neuron_input::_release () { }

std::istream& operator>> (std::istream &input, neuron_input &n) {
  input >> n._in;
  return input;
}

/* ==== neuron_state ==== */

void neuron_state::_initialize () { }

void neuron_state::_release () { }

/* ==== neuron ==== */

neuron::neuron() { }

neuron::~neuron() { }
