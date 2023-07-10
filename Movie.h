#pragma once
#include <iostream>
#include <sstream>
#include <windows.h>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define start int main()
#define infinite while(true)
#define space "\t\t"
#define elif else if
#define br '\n'
#define bye return 0
#define ll long long
#define ld long double
#define dl double
#define fl float
#define str string
#define red system("color 04")
#define green system("color 02")
#define cls system("cls")
using namespace std;
class Movie
{
private:
	vector<str> movieGenres = {
		"Action", "Adventure", "Animation", "Comedy", "Crime",
		"Drama", "Documentary", "Family", "Fantasy", "Horror",
		"Musical", "Mystery", "Romance", "Science-Fiction",
		"Thriller", "Western"
	};
	vector <str> Title, Genre, Country;
	vector <int> ReleaseDate;
	vector <fl> TicketPrice;
	bool isFound(str title_);		// hidden
	bool isGenre(str genre_);		// hidden
	bool Validate(int release_);	// hidden
	bool Validate(fl price_);		// hidden
	int indexMovie(str title_);		// hidden
public:
	void addMovie();    //  for admin

	void delMovie();    //  for admin

	void allMovies();   // for admin or user

	void searchMovie(); // for admin or user
};
/*
  Movie Management:
	Implement classes to represent movies,
	including attributes like
	title,
	genre,
	duration, and showtimes.
	Allow users to
		browse movies,
		view movie details,
		and check available showtimes.
*/