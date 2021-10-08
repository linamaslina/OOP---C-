#include "LeavingRequest.hpp"
#include <iostream>
#include <string.h>

LeavingRequest::LeavingRequest(const std::string sender) : Request("I want to leave!", sender)
{

}