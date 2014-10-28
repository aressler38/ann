#ifndef __neuron_header__
#define __neuron_header__

#include <iostream>

/** 
 * A generalized object of a neural network. 
 * @abstract 
 */
class neural_object {
  public: 
    neural_object() { }
    virtual ~neural_object() { }
    virtual void _initialize() = 0;
    virtual void _release() = 0;
};

/**
 * An object that accepts inputs for a neuron.
 */
class neuron_input : public neural_object {
  public:  
    neuron_input() : neural_object() { _initialize(); }
    ~neuron_input() { _release(); }
    friend void operator>>(neuron_input&, std::string&);
  private:
    unsigned *_buffer;
    void _initialize();
    void _release();
};

/**
 * An object that governs the output of a neuron.
 * A classical node has a one output signal.
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
    neuron_state() : neural_object() { _initialize(); }
    ~neuron_state() { _release(); }
  private:
    unsigned *_buffer;
    void _initialize();
    void _release();
};


/**
 * A general purpose neuron that acts as a single node in a neural network.
 */
class neuron {
  public:
    neuron();
    ~neuron();
  private:
    neuron_input _input;
    neuron_output _output;
    neuron_state _state;
};

#endif
