
#include <iostream>
#include "../neuron/neuron.h"

int main (int argc, char *argv[]) {
  using namespace std;
  anne::neuron n0;


  cout << "\nTEST NEURON\n\n" ;


  cout << "COLORS\n======\n";
  cout << "initial color: " << n0.state.color() << "\n";
  n0.state.color(anne::var::RED);
  cout << "set to red: " << n0.state.color() << "\n";
  n0.state.color(anne::var::BLUE);
  cout << "set to blue: " << n0.state.color() << "\n";
  n0.state.color(anne::var::GREEN);
  cout << "set to green: " << n0.state.color() << "\n"
       << "\n";


  cout << endl;
  return 0;
}
