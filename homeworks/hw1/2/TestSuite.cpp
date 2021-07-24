#include "TestSuite.hpp"
#include "TestCase.hpp"

TestSuite::TestSuite(std::string name)
{
	nameSuite = name;
}

void TestSuite::add(const TestCase& newCase)
{
	Tests.push_back(newCase);
}

std::vector<TestCase> TestSuite::filterPassing() const
{
	std::vector<TestCase> isPass;
	for (int i = 0; i < Tests.size(); i++) {
		if (Tests[i].isPassing() == true) {
			isPass.push_back(Tests[i]);
		}
	}
	return isPass;
}

std::vector<TestCase> TestSuite::filterFailing() const
{
	std::vector<TestCase> isFail;
	for (int i = 0; i < Tests.size(); i++) {
		if (Tests[i].isPassing() == false) {
			isFail.push_back(Tests[i]);
		}
	}
	return isFail;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType specifiedError) const
{
	std::vector<TestCase> specError;
	for (int i = 0; i < Tests.size(); i++) {
		if (Tests[i].getErrorType() == specifiedError) {
			specError.push_back(Tests[i]);
		}
	}
	return specError;
}

void TestSuite::removeByErrorType(ErrorType removeType)
{
	std::vector<TestCase> newTests;
	for (int i = 0; i < Tests.size(); i++) {
		if (Tests[i].getErrorType() != removeType) {
			newTests.push_back(Tests[i]);
		}
	}
	Tests = newTests;
}

std::string TestSuite::getName() const
{
	return std::string(nameSuite);
}