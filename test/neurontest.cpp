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
    cout << "initial color: " << n0.state.color() << "\n";
    n0.state.color(anne::var::RED);
    cout << "set to red: " << n0.state.color() << "\n";
    n0.state.color(anne::var::BLUE);
    cout << "set to blue: " << n0.state.color() << "\n";
    n0.state.color(anne::var::GREEN);
    cout << "set to green: " << n0.state.color() << "\n"
         << "\n";
  }


  {
    anne::n_net net_0;
    net_0.add();
    net_0.add();
    net_0.add();
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
