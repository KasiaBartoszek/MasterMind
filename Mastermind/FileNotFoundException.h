#pragma once
#include <iostream>
#include <exception>

class FileNotFoundException : public std::exception
{
public:
	FileNotFoundException();
	~FileNotFoundException();		
	const char * what() const throw ();
};													

