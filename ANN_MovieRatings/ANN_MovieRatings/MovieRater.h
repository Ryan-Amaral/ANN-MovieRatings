//  File: MovieRater.h
//	Purpose: Header file for MovieRater.cpp
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#ifndef _MOVIE_RATER_H
#define _MOVIE_RATER_H

#include "NeuralNetwork.h"
#include "Movie.h"

/// The 'organism' that uses the NeuralNetwork. Tries to get as close as possible to actual rating on movies.
class MovieRater
{
private:
	NeuralNetwork* neuralNet;
public:
	MovieRater();
	~MovieRater();
	NeuralNetwork* getNeuralNetwork() const;
	float rateMovie(Movie& movie) const;
};

#endif