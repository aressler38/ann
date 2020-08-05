#ifndef __neuron_header__
#define __neuron_header__

#include <iostream>
#include <streambuf>
#include <vector>
#include <functional>

namespace anne {


  /**
   * A general purpose neuron that acts as a single node in a neural network.
   */
  class neuron {
    public:
	    enum class STATES {
        ACCEPTING_INPUT,
        COMPLETE
      };

      class connection {
				public:
          connection(neuron*, double);
          ~connection();
          connection& connection::operator=(const connection&) = delete;
          neuron * next;
					double factor;
      };

      STATES state;

      std::vector<double> input;
      double output;
      std::vector<connection> connections;

      ~neuron();
      neuron();
      neuron(double processor(const std::vector<double>));
      neuron(neuron&&) noexcept;
      neuron& neuron::operator=(const neuron&);
      neuron& neuron::operator=(neuron&&) noexcept;

      void connect(neuron&);
      void connect(neuron&, const double);
      void process_input();

    private:
      void _release();
      std::function<double(std::vector<double>)> _processor;
  };

}

std::ostream& operator<<(std::ostream& os, const anne::neuron::STATES&);
std::ostream& operator<<(std::ostream& os, const anne::neuron&);

#endif
