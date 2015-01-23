#include "dendrite.h"
#include "../neuron/neuron.h"

namespace anne {

  dendrite::dendrite () { }

  dendrite::~dendrite () { }

  /**
   * @return copy of the weight
   */
  dendrite::weight dendrite::get_weight () {
    return _weight;
  }

  /**
   * For each property in w, set this _weight.
   */
  void dendrite::set_weight (dendrite::weight& w) {
    _weight.scalar = w.scalar;
  }

  void dendrite::connect(neuron& n1, neuron& n2) {
    _n[0] = n1;
    _n[1] = n2;
  }

}
