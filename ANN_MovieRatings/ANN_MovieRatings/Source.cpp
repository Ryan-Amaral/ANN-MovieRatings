//  File: Source.cpp
//	Purpose: Main driver file for this project.
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#include "Movie.h"

using namespace std;

int trainingMoviesLength = 12; // amount of movies
Movie** trainingMovies = new Movie*[trainingMoviesLength];

int testingMoviesLength = 5; // amount of movies
Movie** testingMovies = new Movie*[testingMoviesLength];


void CreateMovies()
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
		"Musical",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.6, 0.6, 0.6, 0.2, 0.1, 1.0, 0.5, 0.1, 0.7, 0.7, 0.2, 0.8, 0.7, 0.6, 0.3, 0.2,
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
	// ask for basic or not

	// ask for topology of hidden layers

	// ask for generations

	// ask for organisms per generation

	// ask for mutation probability

	// ask for learning rate
}