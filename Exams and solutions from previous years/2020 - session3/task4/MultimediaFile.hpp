#pragma once
#include <string>
#include <iostream>

class MultimediaFile {
protected:
	std::string name;
	unsigned int size;
	std::string format;
public:
	MultimediaFile(const std::string& name = "", const unsigned int& size = 0, const std::string& format = "");
	virtual ~MultimediaFile() = default;

	void setName(const std::string& newName);
	void setSize(const unsigned int& newSize);
	void setFormat(const std::string& newFortmat);

	std::string getName() const;
	unsigned int getSize() const;
	std::string getFormat() const;

	virtual void print_debug_state() const = 0;

	virtual MultimediaFile* copy() const = 0;
};