#include "neuron.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const anne::neuron::STATES& state) {
  switch (state) {
  case anne::neuron::STATES::ACCEPTING_INPUT:
    os << "Accepting inputs";
    break;
  case anne::neuron::STATES::COMPLETE:
    os << "Complete";
    break;
  default:
    os << "(unknown neuron state)";
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const anne::neuron& n) {
  os << "(neuron)";
  return os;
}

namespace anne {

  neuron::connection::~connection() {}
  neuron::connection::connection(neuron * n, double f = 1.0) : next(n), factor(f) {}

  neuron::neuron() : state(neuron::STATES::ACCEPTING_INPUT), output(0) { }


  neuron::neuron(double processor(std::vector<double>)) : neuron() {
    _processor = processor;
  }

  neuron::neuron(neuron&& other) noexcept {
    state = other.state;
    output = other.output;
    _processor = other._processor;
  }

  neuron::~neuron() { 
    this->_release();
  }

  neuron& neuron::operator=(const neuron& other) {
    state = other.state;
    return *this;
  }

  neuron& neuron::operator=(neuron&& other) noexcept {
    state = other.state;
    std::cout << "neuron assignment not implemented" << std::endl;
    return *this;
  }

  void neuron::_release() { 
  }

  void neuron::connect(neuron& other, const double factor) {
    connections.emplace_back(&other, factor);
  }
  void neuron::connect(neuron& other) {
    connect(other, 1);
  }

  void neuron::process_input() {
    output = _processor(input);
    state = STATES::COMPLETE;

    for (auto& it = connections.begin(); it != connections.end(); ++it) {
      neuron& n = *((*it).next);
      n.input.push_back(output);
    }

  }

}
