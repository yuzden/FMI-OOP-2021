#include "Error.hpp"

Error::Error()
{
	Message = new char[1];
	strcpy(Message, "");
	error = ErrorType::None;
}

Error::Error(const char* message, ErrorType error)
{
	copyMessage(message);
	this->error = error;
}

Error& Error::operator=(const Error& other)
{
	if (&other != this) {
		delete[] Message;
		copyMessage(other.Message);
		error = other.error;
	}
	return *this;
}

Error::Error(const Error& other)
{
	copyMessage(other.Message);
	error = other.error;
}

Error::~Error()
{
	delete[] Message;
}

bool Error::hasMessage() const
{
	if (strlen(Message) != 0) {
		return true;
	}
	else {
		return false;
	}
}

const char* Error::getMessage() const
{
	if (hasMessage() == true) {
		return Message;
	}
	return "";
}

ErrorType Error::getType() const
{
	return error;
}

Error Error::newNone()
{
	return Error("", ErrorType::None);
}

Error Error::newBuildFailed(const char* message)
{
	return Error(message, ErrorType::BuildFailed);
}

Error Error::newWarning(const char* message)
{
	return Error(message, ErrorType::Warning);
}

Error Error::newFailedAssertion(const char* message)
{
	return Error(message,ErrorType::FailedAssertion);
}

void Error::copyMessage(const char* source)
{
	Message = new char[strlen(source) + 1];
	strcpy(Message, source);
}