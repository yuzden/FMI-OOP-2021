#pragma once
#include "MultimediaFile.hpp"

class AudioFile : public MultimediaFile {
	unsigned length;
	std::string artist;
public:
	AudioFile(const std::string& name = "", const unsigned int& size = 0,
		const std::string& format = "", const unsigned &length = 0, const std::string& artist ="");

	unsigned getLength() const;
	std::string getArtist() const;

	void setLength(const unsigned& newLength);
	void setArtist(const std::string& newArtist);

	void print_debug_state() const override;
	MultimediaFile* copy() const override;
};