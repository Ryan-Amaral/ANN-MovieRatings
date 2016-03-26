//  File: Movie.h
//	Purpose: Header file for Movie.cpp
//  Project: ANN_MovieRatings
//  Author: Ryan Amaral
//  Created On: March 26, 2016

#ifndef _MOVIE_H
#define _MOVIE_H

/// Contains information about movies, and their rating.
class Movie
{
private:
	// non-discrete values
	double _actionLevel;
	double _comedyLevel;
	double _familyLevel;
	double _noirLevel;
	double _horrorLevel;
	double _romanceLevel;
	double _warLevel;
	double _adventureLevel;
	double _crimeLevel;
	double _dramaLevel;
	double _fantasyLevel;
	double _historicalLevel;
	double _mysteryLevel;
	double _scifiLevel;
	double _thrillerLevel;
	double _westernLevel;

	// binary values
	bool _isCartoon;
	bool _isAnime;
	bool _is3dAnimated;
	bool _isMusical;
	bool _isSport;
	bool _isBiography;
	bool _isDocumentary;
	bool _isParody;

	double _rating; // movies have ratings by me (may not be my actual rating)
public:
	Movie(double actionLevel,
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
};

#endif