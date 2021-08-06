#include "Album.hpp"

Album::Album()
	:album(nullptr), songs(0)
{
	copyChar("", albumName);
}

Album::Album(Song* album,unsigned int songs, const char* albumName)
{
	album = new Song[songs];
	this->album = album;
	this->songs = songs;
	copyChar(albumName, this->albumName);
}

Album::Album(const Album& other)
{
	album = new Song[other.songs];
	album = other.album;
	songs = other.songs;
	copyChar(other.albumName, albumName);
}

Album& Album::operator=(const Album& rhs)
{
	if (&rhs != this) {
		delete[] album;
		delete[] albumName;
		songs = rhs.songs;
		album = rhs.album;
		copyChar(rhs.albumName, albumName);
	}
	return *this;
}

Album::~Album()
{
	delete[] album;
	delete[] albumName;
}

void Album::printAlbum() const
{
	for (int i = 0; i < songs; i++) {
		album[i].print();
	}
}

int Album::getLength() const
{
	int Length = 0;
	for (int i = 0; i < songs; i++) {
		Length += album[i].getSeconds();
	}
	return Length;
}

const char* Album::getArtist() const
{
	for (int i = 1; i < songs; i++) {
		if (strcmp(album[0].getAutor(), album[i].getAutor()) == false) {
			const char* result = "Various Artists";
			return result;
		}
	}
	return album[0].getAutor();
}

Song* Album::findSong(const char* searchSong)
{
	for (int i = 0; i < songs; i++) {
		if (strcmp(album[i].getAutor(), searchSong) == true) {
			return &album[i];
		}
	}
	return nullptr;
}

void Album::deleteDuplicates(const char* dTitle, const char* dArtist, int dYear, int dLength)
{
	int count = 0;
	for (int i = 0; i < songs; i++) {
		if (strcmp(album[i].getTitle(), dTitle) == true && strcmp(album[i].getAutor(), dArtist) == true
			&& album[i].getYear() == dYear && album[i].getSeconds() == dLength) {
			count++;
		}
	}

	int newSize = songs - count;
	Song* newAlbum = new Song[newSize];
	int j = 0;
	for (int i = 0; i < songs; i++) {
		if (strcmp(album[i].getTitle(), dTitle) == true && strcmp(album[i].getAutor(), dArtist) == true
			&& album[i].getYear() == dYear && album[i].getSeconds() == dLength) {
		}
		else {
			newAlbum[j] = album[i];
			j++;
		}
	}
	newSize = songs;
	album = newAlbum;
}

void Album::copyChar(const char* from, char* to)
{
	int charArraySize = strlen(from) + 1;
	to = new char[charArraySize];
	strcpy(to, from);
}
