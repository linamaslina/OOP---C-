#include "Document.hpp"
#include <iostream>
#include <sstream>

Document::Document(const std::string& name, const std::string& location, const std::string& extension): Object(name, location, extension)
{}

Object* Document::clone() const
{
	return new Document(*this);
}

bool Document::operator==(const Comparable* obj) const
{
	const Document* o = dynamic_cast<const Document*>(obj);
	if (o == NULL)
	{
		return false;
	}
	if (o->lines.size() != lines.size()|| lines.size()==0 || o->lines.size()==0)
	{
		return false;
	}
	int size = lines.size();
	for (int i = 0; i < size; i++)
	{
		if (o->lines[i] != lines[i])
		{
			return false;
		}
	}
	return true;
}

bool Document::operator!=(const Comparable*obj) const 
{
	const Document* o = dynamic_cast<const Document*>(obj);
	if (o == NULL)
		return false;
	if (o == this)
	{
		return false;
	}
	else return true;
}

std::string Document::debug_print() const
{
	int size = lines.size();
	int count = 0;
	std::string temp="";
	for (int i = 0; i < size; i++)
	{
		count = i;
		temp += "Line " +std::to_string(count + 1) + ":"+ lines[i] +"\n";
	}

	return temp;
}

std::string Document::to_string() const
{
	std::string temp="";
	temp = name + "\n" + location + "\n" + extension + "\n";
	int size = lines.size();
	for (int i = 0; i < size; i++)
	{
		temp =temp+ lines[i] + "\n";
	}
	return temp;
}

void Document::from_string(const std::string& other)
{
	lines.clear();
	std::vector<std::string> temp;
	
	std::istringstream iss(other);

	std::string line="";
	while (std::getline(iss, line))
	{
		temp.push_back(line);
	}

	int size = temp.size();
	
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			count = 0;
			set_name(temp[i]);
		}
		else if (i == 1)
		{
			set_location(temp[i]);
		}
		else if (i == 2)
		{
			set_extension(temp[i]);
		}
		else
		{
			lines.push_back(temp[i]);
			
		}
	}
}

void Document::write_line(const std::string& line)
{
	lines.push_back(line);
}

std::string Document::read_line()
{
	size_t size = lines.size();
	if (size <= 0 || count >= size)
	{
		throw std::out_of_range("can\'t read line");
	}
	else if (count < size)
	{
		int temp = count;
		count++;
		return lines[temp];
	}
	throw std::out_of_range("can\'t read line");
}

std::string Document::read_line(const unsigned line)
{
	size_t size = lines.size();
	if (size<0||line==0 )
	{
		throw std::out_of_range("can\'t read line");
	}
	if (line <= size)
	{
		count = line;
		return lines[count-1];
	}
	else throw std::out_of_range("can\'t read line");
}