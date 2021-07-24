#pragma once
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

enum class ErrorType {
    None,
    BuildFailed,
    Warning,
    FailedAssertion,
};

class Error {

private:
   char* Message;
   ErrorType error;

public:
    Error();
    Error(const char*, ErrorType);
    Error& operator=(const Error&);
    Error(const Error&);
    ~Error();

    bool hasMessage() const;

    const char* getMessage() const;
  
    ErrorType getType() const;

    static Error newNone();
    static Error newBuildFailed(const char* message);
    static Error newWarning(const char* message);
    static Error newFailedAssertion(const char* message); 

    void copyMessage(const char*);
};