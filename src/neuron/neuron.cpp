#include "neuron.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, anne::var::COLORS acolor) {
  switch (acolor) {
  case anne::var::COLORS::GREEN:
    os << "Green";
  default:
    os << "(unknown color)";
  }
  return os;
}

namespace anne {

  /* ==== neuron_output ==== */

  void neuron_output::_initialize () { }

  void neuron_output::_release () { }

  /* ==== neuron_input ==== */

  void neuron_input::_initialize () { }

  void neuron_input::_release () { }


  /* ==== neuron_state ==== */

  neuron_state::neuron_state ()
    : _buffer(nullptr),
      _color(var::COLORS::GREEN)
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

  void neural_net::add(neuron& n) { 
    _nodes.push_back(n);
  }


  void neural_net::bfs(void(*cf)(neuron&))
  {
  }

  size_t neural_net::size() const {
    return _nodes.size();
  }

}
