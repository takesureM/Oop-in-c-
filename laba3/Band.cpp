#include"Band.h"
constexpr auto COUNT_SONGS = 4;
constexpr auto COUNT_ALBUMS = 3;

Band::Band(string name, string description, Album* albums, int countAlbums)
{
	this->setName(name);
	this->setDescription(description);
	this->setAlbums(albums);
	this->setCountAlbums(countAlbums);

}

Band::Band()
{
	this->setName("Unknown");
	this->setDescription("Unknown");
	this->setAlbums(nullptr);
	this->setCountAlbums(0);
}

string Band::getName()
{
	return this->_name;
}

string Band::getDescription()
{
	return this->_description;
}

Album* Band::getAlbums()
{
	return this->_albums;
}

int Band::getCountAlbums()
{
	return this->_countAlbums;
}

void Band::setName(string name)
{
	this->_name = name;
}

void Band::setDescription(string description)
{
	this->_description = description;
}

void  Band::setAlbums(Album* albums)
{
	this->_albums;
}

void Band::setCountAlbums(int countAlbums)
{
	if (countAlbums < 0)
	{
		throw exception("Albums must be greater than zero!");
	}
	this->_countAlbums = countAlbums;
}

void DemoBand()
{
	Song* first = new Song[COUNT_SONGS];
	Song* second = new Song[COUNT_SONGS];
	Song* third = new Song[COUNT_SONGS];

	first[0] = Song("Burakai", 4.32, Gospel);
	first[1] = Song("Ndicharamba ndichinamata", 6.12, Gospel);
	first[2] = Song("Tururu", 5.30, Gospel);
	first[3] = Song("Tozeza Baba", 5.30, Gospel);

	second[0] = Song("Hukuru", 3.32, Gospel);
	second[1] = Song("Tererai", 12.12, Musewe);
	second[2] = Song("Madhawu", 5.30, Musewe);
	second[3] = Song("Mabasa Baba", 7.30, Gospel);

	
	third[0] = Song("Excess Love", 9.32, Gospel);
	third[1] = Song("Might War", 13.12, Love);
	third[2] = Song("Mi vangu", 5.30, Love);
	third[3] = Song("Buruka", 7.30, Gospel);

	Album* albums = new Album[COUNT_ALBUMS];
	albums[0] = Album("Ndazviende mberi", 2009, first, 4);
	albums[1] = Album("Mudiwa wangu", 2009, second, 4);
	albums[2] = Album("Zvininipise", 2009, third, 4);

	Band band = Band("Albums", "Name of the album.", albums, COUNT_ALBUMS);

	string songName;
	cout << "Name of the song?" << endl;
	getline(cin, songName);

	Song* song = band.FindSong(songName);
	if (song == nullptr)
	{
		cout << "There are no songs at the moment sorry! " << endl;
	}
	else
	{
		cout << "Name of the song " << song->getName()
			<< "Duration of the song " << song->getDuration() << endl;

		Album* album = band.FindAlbum(song);
		if (album == nullptr)
		{
			cout << "No album at the moment!";
		}
		else
		{
			cout << "Name of the song " << album->getName()
				<< "Duration of the song " << album->getSongCount()
				<< "Year" << album->getYear() << endl;

		}
	}

	int songsCount;
	Song* songs = band.GetAllSongs(songsCount);
	cout << "Number of songs " << songsCount << endl;
	delete[] songs;
	songs = band.GetAllSongs(songsCount);
	cout << "Number of songs left are " << songsCount << endl;
	delete[] songs;

	delete[] first;
	delete[] second;
	delete[] third;
	delete[] albums;

}

Song* Band::FindSong(string songTitle)
{
	Song* result = nullptr;
	for (int i = 0; i < this->getCountAlbums(); i++)
	{
		for (int j = 0; j < this->getAlbums()[i].getSongCount(); j++)
		{
			if (this->getAlbums()[i].getSongs()[j].getName() == songTitle)
			{
				result = &this->getAlbums()[i].getSongs()[j];
				break;
			}
		}
	}
	return result;
}

Album* Band::FindAlbum(Song* song)
{
	Album* result = nullptr;
	for (int i = 0; i < this->getCountAlbums(); i++)
	{
		for (int j = 0; j < this->getAlbums()[i].getSongCount(); j++)
		{
			if ((this->getAlbums()[i].getSongs()[j].getName() == song->getName()) &&
				(this->getAlbums()[i].getSongs()[j].getDuration() == song->getDuration()) &&
				(this->getAlbums()[i].getSongs()[j].getGenre() == song->getGenre()))
			{
				result = &this->getAlbums()[i];
				break;
			}
		}
	}
	return result;
}


Song* Band::GetAllSongs(int& allSongsCount)
{
	allSongsCount = 0;
	for (int i = 0; i < this->getCountAlbums(); i++)
	{
		allSongsCount += this->getAlbums()[i].getSongCount();
	}
	Song* all = new Song[allSongsCount];
	int k = 0;
	for (int i = 0; i < this->getCountAlbums(); i++)
	{
		for (int j = 0; j < this->getAlbums()[i].getSongCount(); j++, k++)
		{
			all[k] = this->getAlbums()[i].getSongs()[j];
		}
	}
	return all;
}

Song* Band::getAllGenreSongs(Genre findingGenre, int& allSongsCount)
{
	allSongsCount = 0;
	for (int i = 0; i < this->getCountAlbums(); i++)
	{
		for (int j = 0; j < this->getAlbums()[i].getSongCount(); j++)
		{
			if (this->getAlbums()[i].getSongs()[j].getGenre() == findingGenre)
			{
				allSongsCount++;
			}
		}
	}
	Song* all = new Song[allSongsCount];
	int k = 0;
	for (int i = 0; i < getCountAlbums(); i++)
	{
		for (int j = 0; j < this->getAlbums()[i].getSongCount(); j++)
		{
			if (this->getAlbums()[i].getSongs()[j].getGenre() == findingGenre)
			{
				all[k] = this->getAlbums()[i].getSongs()[j];
				k++;
			}
		}
	}
	return all;
}