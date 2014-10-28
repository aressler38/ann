MAKE = /usr/bin/make
SRC_ROOT = src
C = g++

BUILD_DIR = build


all: prepare_build
	$(MAKE) -C src/neuron
	touch $(BUILD_DIR)/neuron && rm $(BUILD_DIR)/neuron
	$(C) -o $(BUILD_DIR)/neuron src/neuron/neuron.o  src/test/neurontest.cpp

prepare_build:
	if [ ! -e $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
