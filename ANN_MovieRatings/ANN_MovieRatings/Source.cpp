//  File: Source.cpp
//	Purpose: Main driver file for this project.
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#include "Movie.h"
#include "MovieRater.h"
#include "GeneticAlgorithm.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <regex>

using namespace std;

int trainingMoviesLength = 12; // amount of movies
Movie** trainingMovies = new Movie*[trainingMoviesLength];

int testingMoviesLength = 5; // amount of movies
Movie** testingMovies = new Movie*[testingMoviesLength];

/// Checks if input is an int up to nine digits and is between min and max, inclusive on both.
bool isValidInt(string input, int min, int max)
{
	string strRegex = "\\d{1,9}";

	if (regex_match(input, regex(strRegex)))
	{
		// return true if number is in range
		int newInt = stoi(input, nullptr);
		if (newInt >= min && newInt <= max)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

/// Checks if input is a double up to five digits before and after decimal and is between min and max, inclusive on both.
bool isValidDouble(string input, double min, double max)
{
	string strRegex = "\\d{0,5}\\.?\\d{0,5}";

	if (regex_match(input, regex(strRegex)))
	{
		// return true if number is in range
		double newDouble = stod(input, nullptr);
		if (newDouble >= min && newDouble <= max)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void createMovies()
{
	// I am making sci-fi all highly rated so we can judge results easier
	trainingMovies[0] = new Movie(
		"Good Sci-Fi Movie 1",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.1, 0.6, 0.0, 0.1, 0.3, 0.7, 0.8, 0.3, 0.1, 0.4, 0.0, 0.1, 1.0, 0.0, 0.0, 
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, false, false, 1.0);
	trainingMovies[1] = new Movie(
		"Good Sci-Fi Movie 2",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.8, 0.9, 0.25, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0, 
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[2] = new Movie(
		"Good Sci-Fi Movie 3",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.8, 0.4, 0.6, 0.1, 0.0, 0.8, 0.0, 0.6, 0.2, 0.1, 0.0, 0.8, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, false, false, 1.0);
	trainingMovies[3] = new Movie(
		"Good Sci-Fi Movie 4",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.1, 0.2, 0.3, 0.3, 0.7, 0.2, 0.2, 0.7, 0.6, 0.0, 0.2, 0.3, 1.0, 0.3, 0.0,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, false, false, 1.0);
	trainingMovies[4] = new Movie(
		"Good Sci-Fi Movie 5",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.9, 0.2, 0.5, 0.3, 0.0, 0.8, 0.6, 0.9, 0.9, 0.3, 0.2, 0.2, 0.4, 1.0, 0.1, 0.1,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		true, false, false, true, false, false, false, false, false, 1.0);
	trainingMovies[5] = new Movie(
		"Good Documentary",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.1, 1.0, 0.0, 0.3, 0.2, 0.0, 0.7, 0.0, 0.1, 0.0, 0.3, 0.2, 0.0, 0.1, 02,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, false, 0.9);
	trainingMovies[6] = new Movie(
		"Crappy Musical",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.3, 0.4, 0.8, 0.0, 0.0, 0.9, 0.2, 0.0, 0.6, 0.8, 0.0, 0.6, 0.2, 0.0, 0.1, 0.0,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, false, false, false, true, false, false, false, false, 0.4);
	trainingMovies[7] = new Movie(
		"Good Musical",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.3, 0.9, 0.8, 0.2, 1.0, 0.5, 0.2, 0.9, 0.7, 0.0, 0.8, 0.7, 0.75, 0.3, 0.0,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, true, false, true, true, false, false, false, false, 0.8);
	trainingMovies[8] = new Movie(
		"Cool sci-fi",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.8, 0.2, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, false, true, false, false, false, false, false, true, 1.0);
	trainingMovies[9] = new Movie(
		"Crappy Western",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.3, 0.6, 0.3, 0.4, 0.0, 0.4, 0.5, 0.5, 0.6, 0.3, 0.0, 0.6, 0.2, 0.0, 0.1, 1.0,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		true, false, false, true, true, false, false, false, false, 0.1);
	trainingMovies[10] = new Movie(
		"A Scary Movie 1",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.4, 0.0, 0.0, 0.0, 1.0, 0.4, 0.0, 0.0, 0.2, 0.2, 0.0, 0.0, 0.3, 0.1, 0.8, 0.0,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, false, false, 0.55);
	trainingMovies[11] = new Movie(
		"Alright cartoon",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.5, 0.5, 0.0, 0.2, 0.0, 0.0, 0.6, 0.7, 0.2, 0.3, 0.3, 0.1, 0.3, 0.1, 0.0,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		true, false, false, true, false, false, false, false, true, 0.6);

	// test on these ones
	testingMovies[0] = new Movie(
		"A Sci-Fi",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.8, 0.2, 0.4, 0.1, 0.0, 0.4, 0.6, 0.9, 0.2, 0.2, 0.2, 0.1, 0.2, 1.0, 0.1, 0.0,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, false, false, 1.0);
	testingMovies[1] = new Movie(
		"Another Sci-Fi",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.0, 0.5, 0.2, 0.3, 0.5, 0.5, 0.7, 0.2, 0.4, 0.0, 0.0, 0.2, 1.0, 0.4, 0.1,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		true, false, false, true, false, false, false, false, true, 1.0);
	testingMovies[2] = new Movie(
		"Western Drama",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.2, 0.6, 0.3, 0.4, 0.0, 0.4, 0.4, 0.4, 0.4, 0.8, 0.0, 0.7, 0.3, 0.0, 0.1, 1.0,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, false, true, 1.0);
	testingMovies[3] = new Movie(
		"Sci-Fi Musical",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.6, 0.6, 0.6, 0.2, 0.1, 1.0, 0.5, 0.1, 0.7, 0.7, 0.2, 0.8, 0.7, 1.0, 0.3, 0.2,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		false, false, false, false, true, false, false, false, false, 1.0);
	testingMovies[4] = new Movie(
		"Weird Movie",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
		//crt  anime  3danim anim   music  sport  bio    doc    parod  rating
		true, true, true, true, true, true, true, false, false, 1.0);
}

int main()
{
	bool isValid = false; // flag for input
	string strInput; // reusable string for input

	bool isBasic; // determines how many attributes of movie to use
	int hiddenLayers; // the amount of hidden layers
	int* hiddenLayerTopologies; // the amount of nodes per hidden layer
	int generations; // the amount of generations to run the program
	int organismsPerGen; // the amount of neural nets to run per generation
	double mutationProb; // the likelyhood of a mutation in the genetic algorithm
	double learningRate; // how much the mution changes a gene

	MovieRater** movieRaters; // the array of movie raters

	createMovies();

	// ask for basic or not
	do
	{
		cout << "Do you want to use only basic criteria? (y/n)" << endl;
		getline(cin, strInput);
		if (tolower(strInput[0]) == 'y')
		{
			isValid = true;
			isBasic = true;
		}
		else if (tolower(strInput[0]) == 'n')
		{
			isValid = true;
			isBasic = false;
		}
		else
		{
			isValid = false;
		}
	} while (!isValid);

	// ask for hidden layers
	do
	{
		cout << "How many hidden layers do you want? (0 - 9)" << endl;
		getline(cin, strInput);
		if (isValidInt(strInput, 0, 9))
		{
			isValid = true;
			hiddenLayers = stoi(strInput, nullptr);
		}
		else
		{
			isValid = false;
		}

	} while (!isValid);

	// ask for topology of hidden layers
	hiddenLayerTopologies = new int[hiddenLayers];
	for (int hl = 0; hl < hiddenLayers; ++hl)
	{
		cout << "How many nodes do you want in hidden layer " << (hl + 1) << "? (1 - 100)" << endl;
		getline(cin, strInput);
		if (isValidInt(strInput, 1, 100))
		{
			isValid = true;
			hiddenLayerTopologies[hl] = stoi(strInput, nullptr);
		}
		else
		{
			isValid = false;
			--hl;
		}
	}

	// ask for generations
	do
	{
		cout << "How many generations do you want to run the genetic algorithm for? (1 - 1,000,000)" << endl;
		getline(cin, strInput);
		if (isValidInt(strInput, 1, 100000))
		{
			isValid = true;
			generations = stoi(strInput, nullptr);
		}
		else
		{
			isValid = false;
		}
	} while (!isValid);

	// ask for organisms per generation
	do
	{
		cout << "How many organisms do you want per generation? (1 - 5,000)" << endl;
		getline(cin, strInput);
		if (isValidInt(strInput, 1, 5000))
		{
			isValid = true;
			organismsPerGen = stoi(strInput, nullptr);
		}
		else
		{
			isValid = false;
		}
	} while (!isValid);

	// ask for mutation probability
	do
	{
		cout << "What mutation probability do you want? (0.0 - 1.0)" << endl;
		getline(cin, strInput);
		if (isValidDouble(strInput, 0.0, 1.0))
		{
			isValid = true;
			mutationProb = stod(strInput, nullptr);
		}
		else
		{
			isValid = false;
		}
	} while (!isValid);

	// ask for learning rate
	do
	{
		cout << "What learning rate do you want? (1.0 - 100.0)" << endl;
		getline(cin, strInput);
		if (isValidDouble(strInput, 1.0, 100.0))
		{
			isValid = true;
			learningRate = stod(strInput, nullptr);
		}
		else
		{
			isValid = false;
		}
	} while (!isValid);

	// create the movie raters
	movieRaters = new MovieRater*[organismsPerGen];
	int netLayers = hiddenLayers + 2;
	int* netTopology = new int[netLayers];

	// get the full net topology
	netTopology[0] = (isBasic) ?
		MovieRater::BASIC_CRITERIA_AMOUNT : MovieRater::COMPLEX_CRITERIA_AMOUNT;
	for (int layer = 1; layer < netLayers - 1; ++layer)
	{
		netTopology[layer] = hiddenLayerTopologies[layer - 1];
	}
	netTopology[netLayers - 1] = 1;

	srand(time(NULL));
	// initialize movieRaters
	for (int mr = 0; mr < organismsPerGen; ++mr)
	{
		movieRaters[mr] = new MovieRater(netLayers, netTopology, isBasic);
	}

	MovieRater* bestMovieRater = new MovieRater(netLayers, netTopology, isBasic);
	double* bestGenes = new double[NeuralNetwork::WeightLength];

	double curRating;
	double curError;
	double bestScore = 99999;
	int bestScoreAchieved = 0; // the generation the best score was achieved

	double** newGenes = new double*[organismsPerGen]; // using bio lingo for genes
	// set lengths
	for (int i = 0; i < organismsPerGen; ++i)
	{
		newGenes[i] = new double[NeuralNetwork::WeightLength];
	}

	double totalScore;

	GeneticAlgorithm* geneticAlgorithm = new GeneticAlgorithm(mutationProb, learningRate);

	cout << endl << "+++++ START OF EVOLUTION! +++++" << endl << endl << endl;

	// run the sim
	for (int generation = 0; generation < generations; ++generation)
	{
		cout << "========== GENERATION " << generation << " ==========" << endl << endl;

		// asses each movie rater on all movies
		for (int curRater = 0; curRater < organismsPerGen; ++curRater)
		{
			//cout << "----- Movie Rater " << curRater << " -----" << endl;
			for (int curMovie = 0; curMovie < trainingMoviesLength; ++curMovie)
			{
				curRating = movieRaters[curRater]->rateMovie(trainingMovies[curMovie]);
				curError = abs(curRating - trainingMovies[curMovie]->Rating);
				/*cout << "-- Movie: " << trainingMovies[curMovie]->Name << " --" << endl
					<< "Actual Rating: " << trainingMovies[curMovie]->Rating * 5 << endl
					<< "Guessed Rating: " << curRating * 5 << endl
					<< "Error Rate: " << curError * 5 << endl;*/

				// add to raters error rate
				movieRaters[curRater]->ErrorRate += (curError * 5);
			}

			//cout << endl << "Total Error: " << movieRaters[curRater]->ErrorRate << endl << endl;
		}

		// sort by error ascending
		geneticAlgorithm->sortOrganismsByScore(movieRaters, organismsPerGen);

		cout << "Lowest Error this Generation: " << movieRaters[0]->ErrorRate << endl;
		// see if first is best
		if (movieRaters[0]->ErrorRate < bestScore)
		{
			bestScore = movieRaters[0]->ErrorRate;
			bestScoreAchieved = generation;

			// set best movie rater's neural net
			movieRaters[0]->getNeuralNetwork()->copyWeights(bestGenes);
		}
		cout << "All time lowest Error: " << bestScore << ", Achieved in Generation " << bestScoreAchieved << "." << endl << endl;

		totalScore = geneticAlgorithm->sumScores(movieRaters, organismsPerGen);
		for (int i = 0; i < organismsPerGen; ++i)
		{
			geneticAlgorithm->recombineGenes(movieRaters, organismsPerGen, totalScore, newGenes[i]);
		}

		// set all errors to 0 and resuply genes/weights
		for (int curRater = 0; curRater < organismsPerGen; ++curRater)
		{
			movieRaters[curRater]->ErrorRate = 0;
			movieRaters[curRater]->getNeuralNetwork()->setWeights(newGenes[curRater]);
		}
	}

	cout << endl << "+++++ EVOLUTION COMPLETE! +++++" << endl << endl << endl;

	// set weight/genes of best
	bestMovieRater->getNeuralNetwork()->setWeights(bestGenes);

	// show ratings on the movies and projected ratings
	for (int i = 0; i < trainingMoviesLength; ++i)
	{
		curRating = bestMovieRater->rateMovie(trainingMovies[i]);
		curError = abs(curRating - trainingMovies[i]->Rating);
		cout << "-- Movie: " << trainingMovies[i]->Name << " --" << endl
			<< "Actual Rating: " << trainingMovies[i]->Rating * 5 << endl
			<< "Guessed Rating: " << curRating * 5 << endl
			<< "Error Rate: " << curError * 5 << endl;
	}

	cout << endl << "+++++ Projected Ratings +++++" << endl;

	// projected ratings
	for (int i = 0; i < testingMoviesLength; ++i)
	{
		curRating = bestMovieRater->rateMovie(testingMovies[i]);
		curError = abs(curRating - testingMovies[i]->Rating);
		cout << "-- Movie: " << testingMovies[i]->Name << " --" << endl
			<< "Guessed Rating: " << curRating * 5 << endl;
	}

	cout << endl << endl << "Press any key to quit.";
	_getch();
}