#pragma once
#include"Album.h"
#include <string>

class Band
{
public:
	void setName(string name);
	void setDescription(string description);
	void setAlbums(Album* albums);
	void setCountAlbums(int countAlbums);

	string getName();
	string getDescription();
	Album* getAlbums();
	int getCountAlbums();

	Band(string name, string description, Album* albums, int countAlbums);
	Band();

	Song* FindSong(string songTitle);
	Album* FindAlbum(Song* song);
	Song* GetAllSongs(int& allSongsCount);
	Song* getAllGenreSongs(Genre findingGenre, int& allSongsCount);


private:
	string _name;
	string _description;
	Album* _albums;
	int _countAlbums;
};

void DemoBand();
