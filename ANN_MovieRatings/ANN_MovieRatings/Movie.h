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
	float _actionLevel;
	float _comedyLevel;
	float _familyLevel;
	float _noirLevel;
	float _horrorLevel;
	float _romanceLevel;
	float _warLevel;
	float _adventureLevel;
	float _crimeLevel;
	float _dramaLevel;
	float _fantasyLevel;
	float _historicalLevel;
	float _mysteryLevel;
	float _scifiLevel;
	float _thrillerLevel;
	float _westernLevel;

	// binary values
	bool _isCartoon;
	bool _isAnime;
	bool _is3dAnimated;
	bool _isMusical;
	bool _isSport;
	bool _isBiography;
	bool _isDocumentary;
	bool _isParody;

	float _rating; // movies have ratings by me (may not be my actual rating)
public:
	Movie(float actionLevel,
		float comedyLevel,
		float familyLevel,
		float noirLevel,
		float horrorLevel,
		float romanceLevel,
		float warLevel,
		float adventureLevel,
		float crimeLevel,
		float dramaLevel,
		float fantasyLevel,
		float historicalLevel,
		float mysteryLevel,
		float scifiLevel,
		float thrillerLevel,
		float westernLevel,
		bool isCartoon,
		bool isAnime,
		bool is3dAnimated,
		bool isMusical,
		bool isSport,
		bool isBiography,
		bool isDocumentary,
		bool isParody,
		float rating);
};

#endif