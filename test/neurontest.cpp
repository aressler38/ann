#ifndef FOO
#define FOO "FOO IS NOT DEFINED"
#endif

#define BOOST_TEST_MODULE NeuronTest

#include <cassert>
#include <iostream>
#include "../src/neural_net/neural_net.h"
#include "../src/neuron/neuron.h"
#include <boost/test/unit_test.hpp>

#include <vector>


BOOST_AUTO_TEST_SUITE(NeuronTestSuite)

	BOOST_AUTO_TEST_CASE(test1)
	{
		std::cout << "\nTEST NEURON\n\n";
		anne::neuron n0;
		std::cout << "COLORS\n======\n";
		std::cout << "initial color: " << n0.color << "\n";
		n0.color = anne::neuron::COLORS::RED;
		std::cout << "set to red: " << n0.color << "\n";
		n0.color = anne::neuron::COLORS::BLUE;
		std::cout << "set to blue: " << n0.color << "\n";
		n0.color = anne::neuron::COLORS::GREEN;
		std::cout << "set to green: " << n0.color << "\n"
			<< "\n";
		std::cout << FOO << "\n";
	}


	BOOST_AUTO_TEST_CASE(test2)
	{
		anne::neural_net net_0;
		anne::neuron n0, n1, n2;
		net_0.add(n0);
		net_0.add(n1);
		net_0.add(n2);
		assert(net_0.size() == 3);
		std::cout << "OK: add test\n";
	}

BOOST_AUTO_TEST_SUITE_END()
