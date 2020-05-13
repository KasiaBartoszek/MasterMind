#pragma once
#include <iostream>
#include <exception>

class WrongFileContentException : public std::exception
{
public:
	WrongFileContentException();
	~WrongFileContentException();
	const char * what() const throw ();
};