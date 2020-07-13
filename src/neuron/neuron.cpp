#include "neuron.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, anne::neuron::COLORS acolor) {
  switch (acolor) {
  case anne::neuron::COLORS::GREEN:
    os << "Green";
    break;
  case anne::neuron::COLORS::RED:
    os << "Red";
    break;
  case anne::neuron::COLORS::BLUE:
    os << "Blue";
    break;
  default:
    os << "(unknown color)";
  }
  return os;
}

namespace anne {

  /* ==== neuron ==== */

  neuron::neuron() : color(neuron::COLORS::GREEN) { }
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
