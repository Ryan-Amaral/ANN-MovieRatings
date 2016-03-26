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
	NeuralNetwork* _neuralNet;
	bool _isBasic; // if true, use less criteria for movie rating
	double* _movieCriteria; // what the movies are rated based on
public:
	MovieRater(const int netLayers, const int* netTopology, const bool isBasic);
	~MovieRater();
	NeuralNetwork* getNeuralNetwork() const;
	double rateMovie(const Movie& movie);

	const int BASIC_CRITERIA_AMOUNT = 8; // the amount of criteria used if basic
	const int COMPLEX_CRITERIA_AMOUNT = 25; // the amount of criteria used if not basic
	double Score;
};

#endif