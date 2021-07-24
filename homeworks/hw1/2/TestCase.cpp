#include "TestCase.hpp"

TestCase::TestCase(const std::string& name, const Error& error)
{
	this->name = name;
	errorCase = error;
}

std::string TestCase::getName() const
{
	return std::string(name);
}

bool TestCase::isPassing() const
{
	if (getErrorType() == ErrorType::None ||
		getErrorType() == ErrorType::Warning) {
		return true;
	}
	return false;
}

bool TestCase::hasError() const
{
	if (getErrorType() == ErrorType::None) {
		return false;
	}
	return true;
}

ErrorType TestCase::getErrorType() const
{
	return errorCase.getType();
}

std::string TestCase::getErrorMessage() const
{
	return errorCase.getMessage();
}