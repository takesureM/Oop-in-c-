#include"Album.h"

Album::Album(string name, int year, Song* song, int songCount)
{
	this->setName(name);
	this->setYear(year);
	this->setSongs(song);
	this->setSongCount(songCount);
}

Album::Album()
{
	this->setName("unknown");
	this->setYear(0);
	this->setSongs(nullptr);
	this->setSongCount(0);
}

string Album::getName()
{
	return this->_name;
}

int Album::getYear()
{
	return this->_year;
}

int Album::getSongCount()
{
	return this->_songsCount;
}

Song* Album::getSongs()
{
	return this->_songs;
}

void Album::setName(string name)
{
	this->_name = name;
}

void Album::setYear(int year)
{
	if (year < 0 || year >2020)
	{
		throw exception("The album must be below current year.");
	}
	this->_year = year;
}

void Album::setSongs(Song* song)
{
	this->_songs = song;
}

void Album::setSongCount(int songCount)
{
	if (songCount < 0)
	{
		throw exception("Songs must be greater than 0.");
	}
	this->_songsCount = songCount;
}