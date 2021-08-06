#pragma once

#include "Song.hpp"

class Album {
	Song* album;
	unsigned int songs;
	char* albumName;
public:
	Album();
	Album(Song *album, unsigned int songs, const char* albumName );
	Album(const Album&);
	Album& operator=(const Album&);
	~Album();

	void printAlbum() const;

	int getLength() const;
	const char* getArtist() const;

	Song* findSong(const char*);
	void deleteDuplicates(const char*,const char*,int, int);

	void copyChar(const char*, char*);
};