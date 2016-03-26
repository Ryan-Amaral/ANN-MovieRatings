//  File: Movie.h
//	Purpose: Header file for Movie.cpp
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#ifndef _MOVIE_H
#define _MOVIE_H

#include <string>

/// Contains information about movies, and their rating.
class Movie
{
public:
	Movie(std::string name,
		double actionLevel,
		double comedyLevel,
		double familyLevel,
		double noirLevel,
		double horrorLevel,
		double romanceLevel,
		double warLevel,
		double adventureLevel,
		double crimeLevel,
		double dramaLevel,
		double fantasyLevel,
		double historicalLevel,
		double mysteryLevel,
		double scifiLevel,
		double thrillerLevel,
		double westernLevel,
		bool isCartoon,
		bool isAnime,
		bool is3dAnimated,
		bool isMusical,
		bool isSport,
		bool isBiography,
		bool isDocumentary,
		bool isParody,
		double rating);

	std::string Name;

	// continuous values
	double ActionLevel; // basic
	double ComedyLevel; // basic
	double FamilyLevel;
	double NoirLevel;
	double HorrorLevel; // basic
	double RomanceLevel;
	double WarLevel;
	double AdventureLevel; // basic
	double CrimeLevel;
	double DramaLevel;
	double FantasyLevel; // basic
	double HistoricalLevel;
	double MysteryLevel;
	double ScifiLevel; // basic
	double ThrillerLevel;
	double WesternLevel;

	// binary values
	bool IsCartoon;
	bool IsAnime;
	bool Is3dAnimated;
	bool IsAnimated; // basic
	bool IsMusical;
	bool IsSport;
	bool IsBiography;
	bool IsDocumentary; // basic
	bool IsParody;

	// rating from 0 to 1
	double Rating; // movies have ratings by me (may not be my actual rating)
};

#endif