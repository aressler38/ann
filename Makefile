MAKE = /usr/bin/make
SRC_ROOT = src
C = g++

BUILD_DIR = build


all: prepare_build neuron dendrite


neuron:
	$(MAKE) -C src/neuron
	touch $(BUILD_DIR)/neuron && rm $(BUILD_DIR)/neuron
	$(C) -o $(BUILD_DIR)/neuron src/neuron/neuron.o  src/test/neurontest.cpp

dendrite:
	$(MAKE) -C src/dendrite
	touch $(BUILD_DIR)/dendrite && rm $(BUILD_DIR)/dendrite
	$(C) -o $(BUILD_DIR)/dendrite src/dendrite/dendrite.o src/neuron/neuron.o  src/test/dendritetest.cpp

prepare_build:
	if [ ! -e $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
