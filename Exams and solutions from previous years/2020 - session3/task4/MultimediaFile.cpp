#include "MultimediaFile.hpp"

MultimediaFile::MultimediaFile(const std::string& name, const unsigned int& size, const std::string& format)
	:name(name), size(size), format(format)
{
}

void MultimediaFile::setName(const std::string& newName)
{
	name = newName;
}

void MultimediaFile::setSize(const unsigned int& newSize)
{
	size = newSize;
}

void MultimediaFile::setFormat(const std::string& newFortmat)
{
	format = newFortmat;
}

std::string MultimediaFile::getName() const
{
	return name;
}

unsigned int MultimediaFile::getSize() const
{
	return size;
}

std::string MultimediaFile::getFormat() const
{
	return format;
}

void MultimediaFile::print_debug_state() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Size: " << size << std::endl;
	std::cout << "Format: " << format << std::endl;
}

