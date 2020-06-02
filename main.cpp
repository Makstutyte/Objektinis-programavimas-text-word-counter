#include "functions.h"

 
int main()
{
    setlocale(LC_ALL,"en_US.utf8");

	std::multimap<std::string, Word> word_data;
	std::vector<std::string> url;

	Output(url, word_data);
	
	return 0;
}