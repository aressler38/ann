#include "neural_net.h"

namespace anne {

  neural_net::neural_net() { }
  neural_net::~neural_net() { }

  void neural_net::add(neuron& n) { 
    _nodes.push_back(n);
  }

  size_t neural_net::size() const {
    return _nodes.size();
  }

}
