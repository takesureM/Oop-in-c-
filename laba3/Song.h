#pragma once
#include"Genre.h"
#include<iostream>
#include<string>
using namespace std;

class Song
{
private:
	string _name;
	double _duration;
	Genre _genre;

public:
	void setName(string name);
	void setDuration(double duration);
	void setGenre(Genre genre);

	string getName();
	double getDuration();
	Genre getGenre();

	Song(string name, double duration, Genre genre);
	Song();
};
