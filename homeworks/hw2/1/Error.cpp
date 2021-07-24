#include "Error.hpp"

Error::Error(const std::string& message)
{
	this->message = message;
}

std::string Error::get_message() const
{
	return message;
}

void Error::set_message(const std::string newMessage)
{
	message = newMessage;
}
