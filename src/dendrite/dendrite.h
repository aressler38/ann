#ifndef __dendrite_header__
#define __dendrite_header__

#include <vector>
#include "../neuron/neuron.h"
#include <iostream>
#include "../buffer/impulse.h"

namespace anne {

  /**
   * Weight is at least scalar, but it might also have some
   * other properties.
   */
  struct d_weight {
    double scalar;
  };


  /**
   * Edge in graph. Connects neurons and relays data.
   */
  class dendrite {
    public:
      typedef d_weight weight;
      dendrite();
      ~dendrite();
      weight get_weight();
      void set_weight(weight&); // use for training too
      void connect(neuron&, neuron&);
      void send(impulse&);

    private:
      weight _weight;
      std::vector<neuron> _n;
  };

}

#endif
