#include "AudioFile.hpp"

AudioFile::AudioFile(const std::string& name, const unsigned int& size,
	const std::string& format, const unsigned& length, const std::string& artist)
	:MultimediaFile(name, size, format), length(length), artist(artist)
{
}

unsigned AudioFile::getLength() const
{
	return length;
}

std::string AudioFile::getArtist() const
{
	return artist;
}

void AudioFile::setLength(const unsigned& newLength)
{
	length = newLength;
}

void AudioFile::setArtist(const std::string& newArtist)
{
	artist = newArtist;
}

void AudioFile::print_debug_state() const
{
	MultimediaFile::print_debug_state();

	std::cout << "Lenght: " << length << std::endl;
	std::cout << "Artist: " << artist << std::endl;
}

MultimediaFile* AudioFile::copy() const
{
	return new AudioFile(*this);
}
