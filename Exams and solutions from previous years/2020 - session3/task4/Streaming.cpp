#include "Streaming.hpp"

Streaming::Streaming(const std::string& path)
	:MultimediaFile(), path(path)
{
}

std::string Streaming::getPath() const
{
	return path;
}

void Streaming::setPath(const std::string& newPath)
{
	path = newPath;
}

void Streaming::print_debug_state() const
{
	std::cout << "Path: " << path << std::endl;
}

MultimediaFile* Streaming::copy() const
{
	return new Streaming(*this);
}
