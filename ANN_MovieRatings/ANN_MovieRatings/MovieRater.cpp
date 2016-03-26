//  File: MovieRater.cpp
//	Purpose: Implementation file for MovieRater.h
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#include "MovieRater.h"
#include <cmath>

/// Creates a new MovieRater with a neural net of specified dimensions.
MovieRater::MovieRater(const int netLayers, const int* netTopology, const bool isBasic)
{
	_neuralNet = new NeuralNetwork(netLayers, netTopology);
	_isBasic = isBasic;

	// use less criteria
	if (_isBasic)
	{
		_movieCriteria = new double[BASIC_CRITERIA_AMOUNT];
	}
	// use more
	else
	{
		_movieCriteria = new double[COMPLEX_CRITERIA_AMOUNT];
	}

	Score = 0;
}

/// Deconstructs this MovieRater object.
MovieRater::~MovieRater()
{
	if (_neuralNet != nullptr)
	{
		delete _neuralNet;
	}
}

/// Gets a pointer to this objects neural net.
NeuralNetwork* MovieRater::getNeuralNetwork() const
{
	return _neuralNet;
}

/// Rates the passed in movie.
/// Returns how close the rating is to the actual rating,
/// 1 is best, 0 is worst.
double MovieRater::rateMovie(const Movie& movie)
{
	if (_isBasic)
	{
		_movieCriteria[0] = movie.ActionLevel;
		_movieCriteria[1] = movie.ComedyLevel;
		_movieCriteria[2] = movie.HorrorLevel;
		_movieCriteria[3] = movie.AdventureLevel;
		_movieCriteria[4] = movie.FantasyLevel;
		_movieCriteria[5] = movie.ScifiLevel;
		_movieCriteria[6] = (movie.IsAnimated) ?
			1 : 0;
		_movieCriteria[7] = (movie.IsDocumentary) ?
			1 : 0;
	}
	else
	{
		_movieCriteria[0] = movie.ActionLevel;
		_movieCriteria[1] = movie.ComedyLevel;
		_movieCriteria[2] = movie.FamilyLevel;
		_movieCriteria[3] = movie.NoirLevel;
		_movieCriteria[4] = movie.HorrorLevel;
		_movieCriteria[5] = movie.RomanceLevel;
		_movieCriteria[6] = movie.WarLevel;
		_movieCriteria[7] = movie.AdventureLevel;
		_movieCriteria[8] = movie.CrimeLevel;
		_movieCriteria[9] = movie.DramaLevel;
		_movieCriteria[10] = movie.FantasyLevel;
		_movieCriteria[11] = movie.HistoricalLevel;
		_movieCriteria[12] = movie.MysteryLevel;
		_movieCriteria[13] = movie.ScifiLevel;
		_movieCriteria[14] = movie.ThrillerLevel;
		_movieCriteria[15] = movie.WesternLevel;
		_movieCriteria[16] = (movie.IsCartoon) ?
			1 : 0;
		_movieCriteria[17] = (movie.IsAnime) ?
			1 : 0;
		_movieCriteria[18] = (movie.Is3dAnimated) ?
			1 : 0;
		_movieCriteria[19] = (movie.IsAnimated) ?
			1 : 0;
		_movieCriteria[20] = (movie.IsMusical) ?
			1 : 0;
		_movieCriteria[21] = (movie.IsSport) ?
			1 : 0;
		_movieCriteria[22] = (movie.IsBiography) ?
			1 : 0;
		_movieCriteria[23] = (movie.IsDocumentary) ?
			1 : 0;
		_movieCriteria[24] = (movie.IsParody) ?
			1 : 0;
	}

	double ratingGuess = _neuralNet->feedForward(_movieCriteria);
	double ratingScore = 1 - (abs(ratingGuess - movie.Rating));

	Score += ratingScore;

	return ratingScore;
}