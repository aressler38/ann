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

  neuron_state::neuron_state () 
    : _buffer(nullptr),
      _color(var::GREEN)
  { } 


  void neuron_state::_release () { 
    if ( _buffer ) {
      delete [] _buffer;
    }
  }

  /**
   * Return the current color value
   */
  var::COLORS neuron_state::color() { return _color; }

  /**
   * Set the color value
   */
  void neuron_state::color(var::COLORS c) { _color = c; }

  /* ==== neuron ==== */

  neuron::neuron() { }
  void neuron::_release() { }

  neuron::~neuron() { }

}
