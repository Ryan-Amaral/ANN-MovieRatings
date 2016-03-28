//  File: GeneticAlgorithm.cpp
//	Purpose: Implementation file for GeneticAlgorithm.h
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#include "GeneticAlgorithm.h"
#include <cstdlib>

/// Creates a new object with mutation probability and learning rate.
GeneticAlgorithm::GeneticAlgorithm(const int mutationProb, const int learningRate)
{
	_mutationProb = mutationProb;
	_learningRate = learningRate;
}

/// Don't need to delete anything.
GeneticAlgorithm::~GeneticAlgorithm() {}

/// Uses quick sort to sort organisms from best to worst
void GeneticAlgorithm::sortOrganismsByScore(MovieRater** organisms, const int length) const
{
	MovieRater* pivot = organisms[0]; // pivot is always last element
	unsigned int pivotIndex = 0;
	// giter all split by partition
	for (unsigned int i = 1; i < length; i++)
	{
		// if element is less than pivot, insert in far left
		if (organisms[i]->ErrorRate < pivot->ErrorRate)
		{
			organisms[pivotIndex] = organisms[i];
			organisms[i] = organisms[pivotIndex + 1];
			organisms[pivotIndex + 1] = pivot;
			pivotIndex++;
		}
	}

	// quick sort left side
	if (pivotIndex > 0)
	{
		sortOrganismsByScore(&organisms[0], pivotIndex);
	}
	// quick sort right side
	if (pivotIndex < length - 1)
	{
		sortOrganismsByScore(&organisms[pivotIndex + 1], length - pivotIndex - 1);
	}
}

/// Gets the sum of scores of all organisms to be used in roullete select later.
double GeneticAlgorithm::sumScores(const MovieRater** organisms, const int length) const
{
	double total = 0;
	for (int i = 0; i < length; ++i)
	{
		total += organisms[i]->ErrorRate;
	}

	return total;
}

/// Combines two randomly selected organisms genes into a new one.
void GeneticAlgorithm::recombineGenes(const MovieRater** organisms, const int length, const double totalScore, double* outGenes) const
{
	double randy = ((float)rand() / (float)RAND_MAX) * totalScore;
	double accumulation = 0;

	double* genes1 = new double[NeuralNetwork::WeightLength];
	double* genes2 = new double[NeuralNetwork::WeightLength];

	// select first organism
	for (int i = 0; i < length; ++i)
	{
		if ((totalScore - organisms[i]->ErrorRate + accumulation) <= randy)
		{
			// select this one
			organisms[i]->getNeuralNetwork()->copyWeights(genes1);
			break;
		}
		// add score to accumulation
		accumulation++;
	}

	// new randy
	randy = ((float)rand() / (float)RAND_MAX) * totalScore;
	accumulation = 0;

	// select second organism
	for (int i = 0; i < length; ++i)
	{
		if ((totalScore - organisms[i]->ErrorRate + accumulation) <= randy)
		{
			// select this one
			organisms[i]->getNeuralNetwork()->copyWeights(genes2);
			break;
		}
		// add score to accumulation
		accumulation++;
	}

	// recombine and mutate
	for (int gene = 0; gene < NeuralNetwork::WeightLength; ++gene)
	{
		// choose what to take gene from, 50/50
		outGenes[gene] = (rand() % 2 == 0) ? 
				genes1[gene] : genes2[gene];

		// mutate if can
		if (((float)rand() / (float)RAND_MAX) <= _mutationProb)
		{
			// plus or minus learning rate
			outGenes[gene] += (rand() % 2 == 0) ? 
				_learningRate : -_learningRate;
		}
	}
}