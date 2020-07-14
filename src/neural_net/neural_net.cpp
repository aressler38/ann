#include "neural_net.h"

namespace anne {

  neural_net::neural_net() { 
  }
  neural_net::~neural_net() { }

  void neural_net::add(neuron& n) { 
    _nodes.push_back(n);
  }

  size_t neural_net::size() const {
    return _nodes.size();
  }

  neural_net::layer_t& neural_net::create_layer(size_t size = 0) {
    auto layer = new layer_t();
    this->_layers.push_back(*layer);
    if (size > 0) {
      for (int i = 0; i < size; ++i) {
        auto n = new neuron();
        layer->push_back(*n);
      }
    }
    return *layer;
  }

}
