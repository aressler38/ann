#define BOOST_TEST_MODULE NeuralNetTest

#include "../src/neuron/neuron.h"
#include "../src/neural_net/neural_net.h"
#include <iostream>
#include <vector>
#include <boost/test/unit_test.hpp>

namespace bt = boost::unit_test;

BOOST_AUTO_TEST_SUITE(NeuronTestSuite)

BOOST_AUTO_TEST_CASE(test1)
{
	const int layer_size = 5;
	const int layer_count = 1;
	anne::neural_net net_0;
	net_0.create_layer(layer_size);

	BOOST_TEST(net_0.size() == layer_count * layer_size);
	std::cout << "OK: add test\n";
}

BOOST_AUTO_TEST_SUITE_END()
