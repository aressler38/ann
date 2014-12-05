#include "neuron.h"
#include <iostream>

namespace anne {

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


  /* ==== neuron_state ==== */

  void neuron_state::_initialize () { }

  void neuron_state::_release () { }

  /* ==== neuron ==== */

  neuron::neuron() { }

  neuron::~neuron() { }

}
