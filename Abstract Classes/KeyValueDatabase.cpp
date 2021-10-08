#include "KeyValueDatabase.hpp"
#include <stdexcept>
#include <sstream>

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension) : Object(name, location, extension)
{}

Object* KeyValueDatabase::clone() const
{
	return new KeyValueDatabase(*this);
}

bool KeyValueDatabase::operator==(const Comparable* obj)  const
{
	const KeyValueDatabase* o = dynamic_cast<const KeyValueDatabase*>(obj);
	if (o == nullptr)
	{
		return false;
	}
	
	if (o->database.size() != database.size() || database.size()==0 || o->database.size()==0)
	{
		return false;
	}
	int size = database.size();
	for (int i = 0; i < size; i++)
	{
		if (o->database[i] != database[i])
		{
			return false;
		}
	}
	return true;
}

bool KeyValueDatabase::operator!=(const Comparable* obj) const
{
	const KeyValueDatabase* o = dynamic_cast<const KeyValueDatabase*>(obj);
	if (o == NULL)
		return false;
	if (o == this)
	{
		return false;
	}
	else return true;
}

std::string KeyValueDatabase::debug_print() const
{
	int size = database.size();
	std::string temp="";
	for (int i = 0; i < size; i++)
	{
		temp += "{"+database[i].first + ":" + std::to_string(database[i].second) +"}"+"\n";
	}

	return temp;
}

std::string KeyValueDatabase::to_string() const
{
	std::string temp="";
	temp = name + "\n" + location + "\n" + extension + "\n";
	int size = database.size();
	for (int i = 0; i < size; i++)
	{
		temp = temp + database[i].first+":"+std::to_string(database[i].second) + "\n";
	}
	return temp;
}

void KeyValueDatabase::from_string(const std::string& other)
{
	database.clear();
	std::vector<std::string> temp;

	std::istringstream iss(other);

	std::string line;
	while (std::getline(iss, line))
	{
		temp.push_back(line);
	}
	int size = temp.size();

	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
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
			std::string key = temp[i].substr(0, temp[i].find(":", 0));
			
			std::stringstream num(temp[i].substr(temp[i].find(":")+1));
			int val = 0;
			num >> val;
			database.push_back(std::make_pair(key, val));
		}

	}
}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
	int size = database.size();
	if (database.size() < 0)
	{
		throw std::invalid_argument("invalid key");
	}
	for (int i = 0; i < size; i++)
	{
		if (database[i].first == entry.first)
		{
			throw std::invalid_argument("invalid key");
			
		}
	}
	database.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const
{
	int size = database.size();
	if (database.size() <= 0)
	{
		throw std::invalid_argument("invalid key");
	}
	for (int i = 0; i < size; i++)
	{
		if (database[i].first == key)
		{
			return database[i].second;
		}
	}
	throw std::invalid_argument("invalid key");
}
