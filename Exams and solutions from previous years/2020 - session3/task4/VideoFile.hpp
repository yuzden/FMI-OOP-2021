#pragma once
#include "AudioFile.hpp"
#include <vector>

class VideoFile: public MultimediaFile {
private:
	std::string subtitles;
	std::vector<AudioFile> audios;
public:
	VideoFile() = default;
	VideoFile(const std::string& name, const unsigned int& size,
		const std::string& format, const std::string& subtitles, const std::vector<AudioFile>& audios);

	std::string getSubtitles() const;
	std::vector<AudioFile> getAudios() const;

	void setSubtitles(const std::string& newSub);
	void setAudios(const std::vector<AudioFile>& newAudios);

	void print_debug_state() const override;
	MultimediaFile* copy() const override;
};