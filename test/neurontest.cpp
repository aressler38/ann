#ifndef FOO
#def FOO "NOT DEFINED"
#endif

#include <cassert>
#include <iostream>
#include "../src/neuron/neuron.h"


#include <vector>

int main (int argc, char *argv[]) {
  using namespace std;

  cout << "\nTEST NEURON\n\n" ;

  {
    anne::neuron n0;
    cout << "COLORS\n======\n";
    cout << "initial color: " << n0.color << "\n";
    n0.color = anne::neuron::COLORS::RED;
    cout << "set to red: " << n0.color << "\n";
    n0.color = anne::neuron::COLORS::BLUE;
    cout << "set to blue: " << n0.color << "\n";
    n0.color = anne::neuron::COLORS::GREEN;
    cout << "set to green: " << n0.color << "\n"
         << "\n";
    cout << FOO << "\n";
  }


  {
    anne::neural_net net_0;
    anne::neuron n0, n1, n2;
    net_0.add(n0);
    net_0.add(n1);
    net_0.add(n2);
    assert(net_0.size() == 3);
    cout << "OK: add test\n";
  }

  /*
  {
    anne::neuron n0, n1;
    n0 = n1;
    cout << "OK: copy test\n";
  }
  */

  cout << endl;
  return 0;
}
