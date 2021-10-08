#include "Repository.hpp"

void Repository::deleteAll()
{
    for (auto sub : subs)
    {
        delete sub;
    }
    subs.clear();
}

void Repository::copyOther(const Repository& other)
{
    for (auto sub : other.subs)
    {
        subs.push_back(sub->copy());
    }
}

Repository::Repository(const Repository& rhs)
{
    copyOther(rhs);
}

Repository& Repository::operator=(const Repository& rhs)
{
    if (this != &rhs)
    {
        deleteAll();
        copyOther(rhs);
    }
    return *this;
}

Repository::~Repository()
{
    deleteAll();
}


void Repository::add(Subscriber* newsub)
{
	subs.push_back(newsub->copy());
}


Subscriber* Repository::get(const std::string id) const
{
	size_t size = subs.size();

	for (unsigned i = 0; i < size; i++)
	{
		if (id == subs[i]->getId())
		{
			return subs[i];
		}
	}
	return nullptr;
}