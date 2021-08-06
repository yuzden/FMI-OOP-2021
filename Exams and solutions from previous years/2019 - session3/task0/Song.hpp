#pragma once
#include <iostream>
#pragma warning(disable : 4996)

class Song {
protected:
	char* title;
	char* autor;
	int year;
	int seconds;

	void copyOther(const Song&);
public:
	Song();
	Song(const char* title, const char* autor, int year, int seconds);
	Song(const Song&);
	Song& operator=(const Song&);
	~Song();

	const char* getTitle() const;
	const char* getAutor() const;
	int getYear() const;
	int getSeconds() const;

	void setTitle(const char*);
	void setAutor(const char*);
	void setYear(const int&);
	void setSeconds(const int&);

	void print() const;

	void copyChar(const char*, char*);
};