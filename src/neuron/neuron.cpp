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

  neuron::connection::~connection() {}
  neuron::connection::connection(neuron* n, double f = 1.0) : next(n), factor(f) {}
  neuron::connection& neuron::connection::operator=(const neuron::connection& other) {
    next = other.next;
    factor = other.factor;
    return *this;
  }

  neuron::neuron() : color(neuron::COLORS::GREEN) {
    std::cout << "created a neuron\n";
  }

  neuron::neuron(neuron&& other) noexcept {
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

  neuron& neuron::operator=(neuron&& other) noexcept {
    std::cout << "move assigned a neuron\n";
    color = other.color;
    return *this;
  }

  void neuron::_release() { 
    std::cout << "neuron release\n";
  }

  void neuron::connect(neuron& other) {
    _connections.emplace_back(&other, 1.0);
  }
}
