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
      neural_net();
			~neural_net();

      void add(neuron&);
      size_t size() const;
    private:
      std::vector<neuron> _nodes;
  };

}

#endif
