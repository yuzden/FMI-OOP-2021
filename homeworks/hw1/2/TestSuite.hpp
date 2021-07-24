#pragma once
#include <string>
#include <vector>

#include "TestCase.hpp"

class TestSuite {
private:
    std::vector<TestCase> Tests;
    std::string nameSuite;
    
public:
    TestSuite(std::string name);

    void add(const TestCase&);

    std::vector<TestCase> filterPassing() const;
    
    std::vector<TestCase> filterFailing() const;

    std::vector<TestCase> filterByErrorType(ErrorType) const;

    void removeByErrorType(ErrorType);

    std::string getName() const;
};