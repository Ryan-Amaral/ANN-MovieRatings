//  File: NeuralNetwork.h
//	Purpose: Header file for NeuralNetwork.cpp
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#ifndef _NEURAL_NETWORK_H
#define _NEURAL_NETWORK_H

/// Standard feedforward neural network. Topology can be created on instantiation.
/// All non-input neurons have biases, and all neurons are clamped between 0 and 1.
/// Weights start between -1 and 1, but can grow to be any value as the GA sees fit.
class NeuralNetwork
{
private:
	int _layers; // how many layers are in the net
	int* _layerSizes; // the size of each layer
	float** _neuronValues; // the neurons (values of), first index is layer, second is neuron in layer
	float*** _weights; // the weights connecting neurons together
					   // first index is layer, second is start neuron, third is end neuron
	float** _biases; // the bias for each neuron
public:
	NeuralNetwork(int layers, int* topology);
	void feedForward(float* values);
	float getValue() const;
};

#endif