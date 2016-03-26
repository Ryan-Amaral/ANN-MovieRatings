//  File: NeuralNetwork.cpp
//	Purpose: Implementation file for NeuralNetwork.h
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#include "NeuralNetwork.h"
#include <cmath>

// help from: http://stackoverflow.com/questions/18773343/how-to-calculate-euler-constant-or-euler-powered-in-c
const double EulerConstant = std::exp(1.0);

/// Creates a neural network of specified topology.
NeuralNetwork::NeuralNetwork(const int layers, const int* topology)
{
	_layers = layers;
	_layerSizes = new int[_layers];
	_neuronValues = new double*[_layers];
	_weights = new double**[_layers];

	// create the size of each layer
	for (int layer = 0; layer < layers; ++layer)
	{
		// set the size of layer
		_layerSizes[layer] = topology[layer];

		// initialize neurons of the layer
		_neuronValues[layer] = new double[_layerSizes[layer]];

		// create the weights for previous layer, connecting to this layer
		// (not for first layer)
		if (layer > 0)
		{
			_weights[layer - 1] = new double*[_layerSizes[layer - 1] + 1]; // +1 because bias
			for (int startNeuron = 0; startNeuron < _layerSizes[layer - 1] + 1; ++startNeuron)
			{
				_weights[layer - 1][startNeuron] = new double[_layerSizes[layer]]; // end nodes size of current layer
			}
			
		}
	}
}

/// Deconstructs the neural network
NeuralNetwork::~NeuralNetwork()
{
	for (int layer = 0; layer < _layers; ++layer)
	{
		if (_neuronValues[layer] != nullptr)
		{
			delete[] _neuronValues[layer];
		}
		if (layer  != _layers - 1)
		{
			for (int startNeuron = 0; startNeuron < _layerSizes[layer] + 1; ++startNeuron)
			{
				if (_weights[layer][startNeuron] != nullptr)
				{
					delete[] _weights[layer][startNeuron];
				}
			}
			if (_weights[layer] != nullptr)
			{
				delete[] _weights[layer];
			}
		}
	}

	if (_neuronValues != nullptr)
	{
		delete[] _neuronValues;
	}

	if (_weights != nullptr)
	{
		delete[] _weights;
	}

	if (_layerSizes != nullptr)
	{
		delete[] _layerSizes;
	}
}

/// Feeds input into the network and returns the result from the output node.
double NeuralNetwork::feedForward(const double* values)
{
	// assign input neurons the values from input values
	for (int neuron = 0; neuron < _layerSizes[0]; ++neuron)
	{
		_neuronValues[0][neuron] = values[neuron];
	}

	// pass values through all layers
	for (int layer = 0; layer < _layers - 1; ++layer)
	{
		// set neurons in next layer to 0
		for (int nextNeuron = 0; nextNeuron < _layerSizes[layer + 1]; ++nextNeuron)
		{
			_neuronValues[layer + 1][nextNeuron] = 0;
		}

		// each neuron passes values to next neurons, multiplied by weights
		for (int neuron = 0; neuron < _layerSizes[layer] + 1; ++neuron)
		{
			if (neuron < _layerSizes[layer])
			{
				// each neuron in the next layer
				for (int nextNeuron = 0; nextNeuron < _layerSizes[layer + 1]; ++nextNeuron)
				{
					_neuronValues[layer + 1][nextNeuron] +=
						_neuronValues[layer][neuron] * _weights[layer][neuron][nextNeuron];
				}
			}
			// add the extra bias weight to next neurons
			else
			{
				// each neuron in the next layer
				for (int nextNeuron = 0; nextNeuron < _layerSizes[layer + 1]; ++nextNeuron)
				{
					_neuronValues[layer + 1][nextNeuron] +=
						_weights[layer][neuron][nextNeuron];
				}
			}
		}

		// apply activation function to all neurons in next layer
		for (int neuron = 0; neuron < _layerSizes[layer + 1]; ++neuron)
		{
			_neuronValues[layer + 1][neuron] = activationFunction(_neuronValues[layer + 1][neuron]);
		}
	}

	// return final layer neuron (should only by one)
	return _neuronValues[_layers - 1][0];
}


/// Takes an input of any value and returs it between 0 and 1.
/// Sigmoid activation function: https://en.wikipedia.org/wiki/Sigmoid_function
double NeuralNetwork::activationFunction(double input)
{
	return (1 / (1 + (powf(EulerConstant, -input))));
}

/* code for weights
// connect each weight to each neuron in current layer
for (int startNeuron = 0; startNeuron < _layerSizes[layer - 1] + 1; ++startNeuron)
{
	for (int endNeuron = 0; endNeuron < _layerSizes[layer]; ++endNeuron)
	{
		_weights[layer - 1][startNeuron][endNeuron] = 0;
	}
}
*/