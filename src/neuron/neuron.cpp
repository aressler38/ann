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

  neuron::neuron() : color(neuron::COLORS::GREEN) {
    std::cout << "created a neuron\n";
  }

  neuron::neuron(neuron&& other) {
    std::cout << "moved a neuron\n";
    color = other.color;
  }

  neuron::~neuron() { 
    this->_release();
  }

  neuron& neuron::operator=(const neuron& other) {
    std::cout << "copied a neuron\n";
    color = other.color;
    return *this;
  }

  neuron& neuron::operator=(neuron&& other) {
    std::cout << "move assigned a neuron\n";
    color = other.color;
    return *this;
  }

  void neuron::_release() { 
    std::cout << "neuron release\n";
  }

}
