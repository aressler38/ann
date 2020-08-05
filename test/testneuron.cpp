#define BOOST_TEST_MODULE NeuronTest

#include "../src/neuron/neuron.h"
#include <iostream>
#include <vector>
#include <boost/test/unit_test.hpp>
#include <numeric>

namespace anne {
	std::ostream& boost_test_print_type(std::ostream& os, const anne::neuron::STATES& state) {
		return ::operator<<(os, state);
	}
}

namespace bt = boost::unit_test;
namespace tt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(NeuronTestSuite, *bt::label("my label"))

BOOST_AUTO_TEST_CASE(test1) {
	anne::neuron n0;
	std::cout << "The initial state is " << n0.state << std::endl;
	BOOST_TEST(n0.state == anne::neuron::STATES::ACCEPTING_INPUT);
	BOOST_TEST(n0.output == 0);
}


BOOST_AUTO_TEST_CASE(test_connect) {
	anne::neuron n0, n1;

	n0.connect(n1);
}


double test_processor_1(const std::vector<double> x) {

	auto net_activation = std::accumulate(x.begin(), x.end(), decltype(x)::value_type(0));
	//auto net_activation = 0;

	return 2 * net_activation;
}

BOOST_AUTO_TEST_CASE(test_process) {
	anne::neuron n0_0(test_processor_1);
	anne::neuron n1_0(test_processor_1);
	anne::neuron n1_1(test_processor_1);
	anne::neuron n2_0(test_processor_1);

	n0_0.connect(n1_0, 1.0);
	n0_0.connect(n1_1, 1.0);
	n1_0.connect(n2_0, 1.0);
	n1_1.connect(n2_0, 1.0);

	BOOST_TEST(n0_0.output == 0);
	BOOST_TEST(n0_0.state == anne::neuron::STATES::ACCEPTING_INPUT);

	n0_0.input.push_back(1);

	// Should comput net activation and send to all connected nodes.
	n0_0.process_input();
	BOOST_TEST(n0_0.state == anne::neuron::STATES::COMPLETE);

	// Normally a neural_net should loop this.
	n1_0.process_input();
	n1_1.process_input();

	// Output stage.
	n2_0.process_input();

	BOOST_TEST(n0_0.output == 2);
	BOOST_TEST(n1_0.output == 4);
	BOOST_TEST(n1_1.output == 4);
	BOOST_TEST(n2_0.output == 16);
}

BOOST_AUTO_TEST_SUITE_END()
