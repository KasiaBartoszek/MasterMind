#include "WrongFileContentException.h"


WrongFileContentException::WrongFileContentException()
{
}


WrongFileContentException::~WrongFileContentException()
{
}

const char * WrongFileContentException::what() const throw ()
{
	return "Wrong file content.";
}