#include "VideoFile.hpp"

VideoFile::VideoFile(const std::string& name, const unsigned int& size, 
	const std::string& format, const std::string& subtitles, const std::vector<AudioFile>& audios)
	:MultimediaFile(name,size,format), subtitles(subtitles), audios(audios)
{
}

std::string VideoFile::getSubtitles() const
{
	return subtitles;
}

std::vector<AudioFile> VideoFile::getAudios() const
{
	return audios;
}

void VideoFile::setSubtitles(const std::string& newSub)
{
	subtitles = newSub;
}

void VideoFile::setAudios(const std::vector<AudioFile>& newAudios)
{
	audios = newAudios;
}

void VideoFile::print_debug_state() const
{
	MultimediaFile::print_debug_state();

	std::cout << "Lenght: " << subtitles << std::endl;
	for (auto audio : audios) {
		audio.print_debug_state();
	}
}

MultimediaFile* VideoFile::copy() const
{
	return new VideoFile(*this);
}
