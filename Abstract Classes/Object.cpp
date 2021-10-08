#include "Object.hpp"
#include <string.h>
Object::Object(const std::string& name, const std::string& location, const std::string& extension):
	name(name), location(location), extension(extension){}

void Object::set_name(std::string temp)
{
	this->name = temp;
}
void Object::set_location(std::string temp)
{
	this->location = temp;
}
void Object::set_extension(std::string temp)
{
	this->extension = temp;
}
std::string Object::get_name() const
{
	return name;
}

std::string Object::get_location() const
{
	return location;
}

std::string Object::get_extension() const
{
	return extension;
}

std::string Object::get_fullpath() const
{
	std::string temp =  location + "/"  + name + "." + extension;
	return temp;
}