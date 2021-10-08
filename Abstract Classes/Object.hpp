#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"
#include <string>
#pragma once
class Object :
    public Comparable,public Debug, public Serializable
{
protected:
    std::string name;
    std::string location;
    std::string extension;
public:
    Object(const std::string& name, const std::string& location, const std::string& extension);
    Object(const Object&)=default;
    Object& operator=(const Object&) = default;
    virtual Object* clone()const= 0;
    
    virtual ~Object() = default;
    void set_name(std::string);
    void set_location(std::string);
    void set_extension(std::string);
    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;
};

