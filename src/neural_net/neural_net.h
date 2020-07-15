#ifndef __neural_net_header__
#define __neural_net_header__

#include <vector>
#include "../neuron/neuron.h"

namespace anne {

  /**
   * A collection of neurons and dendrites.
   */
  class neural_net {
    public:
      typedef std::vector<neuron> layer_t;
      typedef std::vector<layer_t> layers_t;

      neural_net();
			~neural_net();
      neural_net& operator=(const neural_net& other) = delete;

      size_t size() const;

      /** create a layer and add it to the layers */
      void create_layer(size_t size);

    private:
      layers_t _layers;
      void _release();
  };

}

#endif
