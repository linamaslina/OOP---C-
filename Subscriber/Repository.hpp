#pragma once
#include "Subscriber.hpp"
#include <string>
#include <vector>

class Repository {
private:
	std::vector<Subscriber*> subs;
	void deleteAll();
	void copyOther(const Repository&);
public:
	Repository() = default;
	Repository(const Repository&);
	Repository& operator=(const Repository&);

	void add(Subscriber*);

	~Repository();
	
	Subscriber* get(const std::string id) const;
};