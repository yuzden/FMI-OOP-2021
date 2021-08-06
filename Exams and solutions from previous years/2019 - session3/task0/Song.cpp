#include "Song.hpp"

void Song::copyOther(const Song& other)
{
	copyChar(other.title, title);
	copyChar(other.autor, autor);
	this->year = other.year;
	this->seconds = other.seconds;
}

void Song::copyChar(const char* from, char* to )
{
	int charArraySize = strlen(from) + 1;
	to = new char[charArraySize];
	strcpy(to, from);
}


Song::Song()
	:year(0), seconds(0)
{
	copyChar("", title);
	copyChar("", autor);
}

Song::Song(const char* title, const char* autor, int year, int seconds)
	:year(year), seconds(seconds)
{
	copyChar(title, this->title);
	copyChar(autor, this->autor);
}

Song::Song(const Song& rhs)
{
	copyOther(rhs);
}

Song& Song::operator=(const Song& rhs)
{
	if (&rhs != this) {
		delete[] title;
		delete[] autor;
		copyOther(rhs);
	}
	return *this;
}

Song::~Song()
{ 
	delete[] title;
	delete[] autor;
}

const char* Song::getTitle() const
{
	return title;
}

const char* Song::getAutor() const
{
	return autor;
}

int Song::getYear() const
{
	return year;
}

int Song::getSeconds() const
{
	return seconds;
}

void Song::setTitle(const char* newTitle)
{
	copyChar(newTitle, title);
}

void Song::setAutor(const char* newAutor)
{
	copyChar(newAutor, autor);
}

void Song::setYear(const int& newYear)
{
	year = newYear;
}

void Song::setSeconds(const int& newSeconds)
{
	seconds = newSeconds;
}

void Song::print() const
{
	std::cout << "Title: " << title << std::endl;
	std::cout << "Autor: " << autor << std::endl;
	std::cout << "Year: " << year << std::endl;
	std::cout << "Seconds: " << seconds << std::endl;
}
