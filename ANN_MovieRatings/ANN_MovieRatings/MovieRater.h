//  File: MovieRater.h
//	Purpose: Header file for MovieRater.cpp
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#ifndef _MOVIE_RATER_H
#define _MOVIE_RATER_H

#include "NeuralNetwork.h"

class MovieRater
{
private:
	NeuralNetwork* neuralNet;
public:
	MovieRater();
	void setNeuralNetwork(NeuralNetwork* neuralNet);
	NeuralNetwork* getNeuralNetwork();
	
};

#endif