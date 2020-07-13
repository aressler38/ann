#ifndef __neuron_header__
#define __neuron_header__

#include <iostream>
#include <streambuf>
#include <vector>

namespace anne {




  /**
   * A general purpose neuron that acts as a single node in a neural network.
   */
  class neuron {
    public:
	    enum class COLORS { GREEN, BLUE, RED } ;
      COLORS color;

      neuron();
      ~neuron();
    private:
      void _release();
  };

  /**
   * A collection of neurons and dendrites.
   */
  class neural_net {
    public:
      neural_net() {}
      ~neural_net() {}
      void add(neuron&);
      void bfs(void(*cf)(neuron&));
      size_t size() const;
    private:
      std::vector<neuron> _nodes;
  };

}

std::ostream& operator<<(std::ostream& os, anne::neuron::COLORS acolor);

#endif
