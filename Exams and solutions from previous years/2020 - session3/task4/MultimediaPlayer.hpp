#pragma once
#include "Streaming.hpp"
#include "VideoFile.hpp"
#include "AudioFile.hpp"

class MultimediaPlayer {
	std::vector<MultimediaFile*> files;

	void copyOther(const MultimediaPlayer&);
	void deleteAll();
public:
	MultimediaPlayer() = default;
	MultimediaPlayer(const MultimediaPlayer&);
	MultimediaPlayer& operator=(const MultimediaPlayer&);
	~MultimediaPlayer();

	void add(MultimediaFile*);
	void remove(unsigned index);

	void print_all_files_states(unsigned index) const;
};