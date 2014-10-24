MAKE = /usr/bin/make
SRC_ROOT = src
C = g++

BUILD_DIR = build

all:
	$(MAKE) -C src/neuron
	$(C) -o $(BUILD_DIR)/neuron src/neuron/neuron.o  src/test/neurontest.cpp

