#pragma once
#include <string>
#include "Error.hpp"

class TestCase {
private:
    
    std::string name;
    Error errorCase;
   
public:
    TestCase(const std::string& , const Error& );

    std::string getName() const;
    bool isPassing() const;

    bool hasError() const;

    ErrorType getErrorType() const;

    std::string getErrorMessage() const;
};