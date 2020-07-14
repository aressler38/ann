#define BOOST_TEST_MODULE DendriteTest

#include <iostream>
#include <string>
#include "../src/neuron/neuron.h"
#include "../src/dendrite/dendrite.h"

#include <boost/test/unit_test.hpp>

namespace bt = boost::unit_test;

BOOST_AUTO_TEST_SUITE(DendriteTestSuite)

BOOST_AUTO_TEST_CASE(test)
{
  std::cout << "TEST DENDRITE\n" ;
}

BOOST_AUTO_TEST_SUITE_END()
