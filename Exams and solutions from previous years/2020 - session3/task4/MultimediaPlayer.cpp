#include "MultimediaPlayer.hpp"

void MultimediaPlayer::copyOther(const MultimediaPlayer& rhs)
{
	for (auto file : rhs.files) {
		files.push_back(file->copy());
	}
}

void MultimediaPlayer::deleteAll()
{
	for (auto file : files) {
		delete file;
	}
	files.clear();
}

MultimediaPlayer::MultimediaPlayer(const MultimediaPlayer& rhs)
{
	copyOther(rhs);
}

MultimediaPlayer& MultimediaPlayer::operator=(const MultimediaPlayer& rhs)
{
	if (&rhs != this) {
		deleteAll();
		copyOther(rhs);
	}
	return *this;
}

MultimediaPlayer::~MultimediaPlayer()
{
	deleteAll();
}

void MultimediaPlayer::add(MultimediaFile* newFile)
{
	files.push_back(newFile->copy());
}

void MultimediaPlayer::remove(unsigned index)
{
	delete files[index];
	files.erase(files.begin() + index);
}

void MultimediaPlayer::print_all_files_states(unsigned index) const
{
	auto* temp = dynamic_cast<AudioFile*>(files[index]);

	if (temp) {
		char input;
		std::cout << "Do you want visualizations [y/n] ?";
		std::cin >> input;

		if (input == 'y') {
			std::cout << "There you go!\n";
		}
	}
	files[index]->print_debug_state();
}
