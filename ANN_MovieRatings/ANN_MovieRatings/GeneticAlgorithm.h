//  File: GeneticAlgorithm.h
//	Purpose: Header file for GeneticAlgorithm.cpp
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#ifndef _GENETIC_ALGORITHM_H
#define _GENETIC_ALGORITHM_H

#include "MovieRater.h"

/// Contains functinality to improve a neural network.
class GeneticAlgorithm
{
private:
	MovieRater** _population; // the organisms in the population
public:
	GeneticAlgorithm();
	~GeneticAlgorithm();
	void sortOrganisms(MovieRater** organisms, const int length);

	int PopulationSize; // the size of the population
};

#endif