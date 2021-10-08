#pragma once
#include "Request.hpp"
#include <iostream>
#include <string.h>
class LeavingRequest: public Request
{
public:
	LeavingRequest(const std::string sender);
};

