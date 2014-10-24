MAKE = /usr/bin/make
SRC_ROOT = src
C = g++


all:
	$(MAKE) -C src/neuron
	$(C) -o neuron src/neuron/neuron.o  src/test/neurontest.cpp

