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
      neuron(neuron&&);
      ~neuron();

      neuron& neuron::operator=(const neuron&);
      neuron& neuron::operator=(neuron&&);

    private:
      void _release();
  };

}

std::ostream& operator<<(std::ostream& os, anne::neuron::COLORS acolor);

#endif
