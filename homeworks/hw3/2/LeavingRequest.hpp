#pragma once
#include "Request.hpp"
class LeavingRequest : public Request  {
public:
	LeavingRequest();
	LeavingRequest(const std::string& sender);
};