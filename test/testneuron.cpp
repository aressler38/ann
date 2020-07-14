#define BOOST_TEST_MODULE NeuronTest

#include "../src/neural_net/neural_net.h"
#include "../src/neuron/neuron.h"
#include <iostream>
#include <vector>
#include <boost/test/unit_test.hpp>

namespace bt = boost::unit_test;

BOOST_AUTO_TEST_SUITE(NeuronTestSuite, *bt::label("my label"))

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
}

BOOST_AUTO_TEST_CASE(test_2)
{
	anne::neural_net net_0;
	anne::neuron n0, n1, n2;
	net_0.add(n0);
	net_0.add(n1);
	net_0.add(n2);
	BOOST_TEST(net_0.size() == 3);
	std::cout << "OK: add test\n";
}

BOOST_AUTO_TEST_CASE(test_copy) {
	class dummy {
	public:
		dummy() {
			std::cout << "DUMMY CONSTRUCTOR\n";
		}
		dummy(const dummy &oth) {
			std::cout << "DUMMY COPY CONST\n";
		}
		explicit dummy(dummy &&oth) noexcept {
			std::cout << "DUMMY MOVE CONST\n";
		}
		~dummy() {
			std::cout << "DUMMY DESTRUCTOR\n";
		}
	};


	auto l = std::vector<dummy>();
	std::cout << "test\n";
	l.push_back(dummy());

}

BOOST_AUTO_TEST_SUITE_END()
