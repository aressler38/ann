#include "neural_net.h"

namespace anne {

  neural_net::neural_net() {
    std::cout << "created a neural net\n";
  }
  neural_net::~neural_net() {
    this->_release();
  }

  void neural_net::_release() {
    std::cout << "erasing neural net\n";
    _layers.erase(_layers.begin(), _layers.end());
  }
  //neural_net& neural_net::operator=(const neural_net& other) { return *this; }

  size_t neural_net::size() const {
    size_t count = 0;
    for (auto it = _layers.begin(); it != _layers.end(); ++it) {
      count += (*it).size();
    }
    return count;
  }

  void neural_net::create_layer(size_t size = 0) {
    std::cout << "creating a new layer of size " << size << "\n";
    auto layer = layer_t();

    layer.reserve(size);


		for (int i = 0; i < size; ++i) {
      auto n = neuron();
			layer.push_back(std::move(n));
		}

    this->_layers.push_back(std::move(layer));
  }

}
