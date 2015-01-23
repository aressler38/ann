#ifndef __neuron_header__
#define __neuron_header__

#include <iostream>
#include <streambuf>
#include <vector>

namespace anne {

  /** Anything that acts like an enum variable goes in namespace var */
  namespace var {
    enum COLORS { GREEN, BLUE, RED } ;
  }

  /**
   * A generalized object of a neural network.
   * @abstract
   */
  class neural_object {
    public:
      neural_object() { }
      virtual ~neural_object() { }
      virtual void _release() = 0;
  };

  /**
   * An object that accepts inputs for a neuron.
   *
   * @deprecated
   */
  class neuron_input : public neural_object {
    public:
      neuron_input() : neural_object() { _initialize(); }
      ~neuron_input() { _release(); }
      friend std::istream& operator>> (std::istream&, neuron_input&);
    private:
      void _initialize();
      void _release();
      std::vector<float>* _in;
  };

  /**
   * An object that governs the output of a neuron.
   */
  class neuron_output : public neural_object {
    public:
      neuron_output() : neural_object() { _initialize(); }
      ~neuron_output() { _release(); }
    private:
      unsigned *_buffer;
      void _initialize();
      void _release();
  };

  /**
   * A neuron's state object that represents a given state of a neuron.
   */
  class neuron_state : public neural_object {
    public:
      neuron_state();
      ~neuron_state() { _release(); }

      var::COLORS color();
      void color(var::COLORS);

    private:
      unsigned *_buffer;
      var::COLORS _color;
      void _initialize();
      void _release();
  };

  /**
   * A general purpose neuron that acts as a single node in a neural network.
   */
  class neuron : public neural_object {
    public:
      neuron();
      ~neuron();
      neuron_state state;
    private:
      void _release();
      neuron_input _input;
      neuron_output _output;
  };

  /**
   * A collection of neurons and dendrites.
   */
  class n_net {
    public:
      n_net() {}
      ~n_net() {}
      void add(neuron&);
      bool remove(neuron&);
      void bfs(void(*cf)(neuron));
    private:
      std::vector<neuron> _nodes;
  };

}

#endif
