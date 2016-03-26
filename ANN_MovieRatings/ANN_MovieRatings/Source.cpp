//  File: Source.cpp
//	Purpose: Main driver file for this project.
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#include "Movie.h"

using namespace std;

int trainingMoviesLength = 16; // amount of movies
Movie** trainingMovies = new Movie*[trainingMoviesLength];

int testingMoviesLength = 5; // amount of movies
Movie** testingMovies = new Movie*[testingMoviesLength];


void CreateMovies()
{
	// some are my actual ratings, but I am making sci-fi all highly rated to make it easier for network
	trainingMovies[0] = new Movie(
		"Star Wars: Episode IV - A New Hope",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.6, 0.1, 0.8, 0.0, 0.1, 0.3, 0.7, 0.8, 0.3, 0.1, 0.4, 0.0, 0.1, 1.0, 0.0, 0.0, 
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, false, 1.0);
	trainingMovies[1] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.25, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0, 
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[2] = new Movie(
		"Back to the Future",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.5, 0.4, 0.6, 0.1, 0.0, 0.8, 0.0, 0.6, 0.2, 0.1, 0.0, 0.8, 0.1, 0.9, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, false, 1.0);
	trainingMovies[3] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.2, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[4] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.2, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[5] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[6] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[7] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[8] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[9] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[10] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[11] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[12] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[13] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[14] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	trainingMovies[15] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);

	// test on these ones
	testingMovies[0] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	testingMovies[1] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	testingMovies[2] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	testingMovies[3] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
	testingMovies[4] = new Movie(
		"Spaceballs",
		//ac cm   fm   nr   hr   rm   wr   ad   cr   dr   ft   hs   ms   sc   th   ws
		0.7, 0.9, 0.5, 0.0, 0.0, 0.4, 0.5, 0.7, 0.6, 0.1, 0.0, 0.0, 0.1, 1.0, 0.1, 0.0,
		//crt  anime  anim   music  sport  bio    doc    parod  rating
		false, false, false, false, false, false, false, true, 1.0);
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