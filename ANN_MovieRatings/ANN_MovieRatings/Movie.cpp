//  File: Movie.cpp
//	Purpose: Implementation file for Movie.h
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#include "Movie.h"

/// Set all rating criteria of the movie.
Movie::Movie(std::string name,
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
	bool isAnimated,
	bool isMusical,
	bool isSport,
	bool isBiography,
	bool isDocumentary,
	bool isParody,
	double rating)
{
	Name = name;
	ActionLevel = actionLevel;
	ComedyLevel = comedyLevel;
	FamilyLevel = familyLevel;
	NoirLevel = noirLevel;
	HorrorLevel = horrorLevel;
	RomanceLevel = romanceLevel;
	WarLevel = warLevel;
	AdventureLevel = adventureLevel;
	CrimeLevel = crimeLevel;
	DramaLevel = dramaLevel;
	FantasyLevel = fantasyLevel;
	HistoricalLevel = historicalLevel;
	MysteryLevel = mysteryLevel;
	ScifiLevel = scifiLevel;
	ThrillerLevel = thrillerLevel;
	WesternLevel = westernLevel;
	IsCartoon = isCartoon;
	IsAnime = isAnime;
	Is3dAnimated = is3dAnimated;
	IsMusical = isMusical;
	IsSport = isSport;
	IsBiography = isBiography;
	IsDocumentary = isDocumentary;
	IsParody = isParody;
	Rating = rating;
}