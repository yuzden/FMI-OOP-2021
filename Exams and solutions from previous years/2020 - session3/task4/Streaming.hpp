#pragma once
#include "MultimediaFile.hpp"
class Streaming : public MultimediaFile  {
	std::string path;
public:
	Streaming() = default;
	Streaming(const std::string& path);

	std::string getPath() const;
	void setPath(const std::string& newPath);

	void print_debug_state() const override;
	MultimediaFile* copy() const override;

};