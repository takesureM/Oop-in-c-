#pragma once
#include"Song.h"

class Album
{
private:
	string _name;
	int _year;
	Song* _songs;
	int _songsCount;

public:
	void setName(string name);
	void setYear(int year);
	void setSongs(Song* song);
	void setSongCount(int songCount);

	string getName();
	int getYear();
	Song* getSongs();
	int getSongCount();

	Album(string name, int year, Song* song, int songCount);
	Album();
};



