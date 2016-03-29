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
	double _mutationProb; // how likely a gene is to mutate and recombonation
	double _learningRate; // how quickly learning will happen (higher is not always better)
public:
	GeneticAlgorithm(const int mutationProb, const int learningRate);
	~GeneticAlgorithm();
	void sortOrganismsByScore(MovieRater** organisms, const int length) const;
	double sumScores(MovieRater** organisms, const int length) const;
	void recombineGenes(MovieRater** organisms, const int length, const double totalScore, double* outGenes) const;
};

#endif