#include "FileNotFoundException.h"


FileNotFoundException::FileNotFoundException()
{
}


FileNotFoundException::~FileNotFoundException()
{
}

const char * FileNotFoundException::what() const throw ()
{
	return "File was not found.";
}
