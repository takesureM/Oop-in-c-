#include"Song.h"

Song::Song(string name, double duration, Genre genre)
{
	this->setName(name);
	this->setDuration(duration);
	this->setGenre(genre);
}

Song::Song()
{
	this->setName("unknown");
	this->setDuration(0);
	this->setGenre(Default);
}

string Song::getName()
{
	return this->_name;
}

double Song::getDuration()
{
	return this->_duration;
}

Genre Song::getGenre()
{
	return this->_genre;
}

void Song::setName(string name)
{
	this->_name = name;
}

void Song::setDuration(double duration)
{
	if (duration < 0)
	{
		throw exception("The duration must be not zero ");
	}
	this->_duration = duration;
}

void Song::setGenre(Genre genre)
{
	this->_genre = genre;
}