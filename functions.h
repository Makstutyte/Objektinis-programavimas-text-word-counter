#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <regex>

class Word 
{
    public:
    	int count = 1;
	    std::vector<int> row;
};

void simbol (char& simbol, char first, char second)
{
    while (!(simbol == first || simbol == second))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Invalid size entered" <<std::endl;
        std::cout << "Choose between the options  " << first << " or " << second << ": ";
        std::cin >> simbol;
    }
}

std::string lower_letters_no_punctuation(std::string word)
{
    for (size_t j=0; j< word.length(); ++j)
     {
       word[j] = tolower(word[j]);
     }

    word.erase (std::remove_if (word.begin (), word.end (), ispunct), word.end ());

	return word;
}

void ReadFile(std::vector<std::string> &url, std::multimap<std::string, Word> &word_data) 
{
    std::string file;
    std::cout << "Enter file name: "<< std::endl;
    std::cin >> file;
  	std::ifstream filename (file.c_str(), std::ios::in | std::ios::binary);

    try
    {
        std::string Exception = "THE READING FILE DOES NOT EXIST";
             if (filename) 
             { 
               std::cout << "reading file exists " << std::endl;
             }
                    else if(!filename) 
                    { 
                      throw (Exception); 
                    }
    }

    catch (std::string excep)
    {
       std::cout << excep << std::endl;
       std::exit(0); 
    }

	std::string line;
	int rowCounter = 1;
	std::string word;
	std::multimap<std::string, Word>::iterator it;
    
	while (!filename.eof())
	{
		getline(filename, line);
		std::vector<std::string> words;
        std::istringstream out_of_line(line);
        std::string temp;
        
        while(out_of_line >> temp)
        {
            words.push_back(temp);
        }

		for (int i = 0; i < words.size(); i++)
		{
			if (words[i].substr(0, 8) == "https://"|| words[i].substr(0, 7) == "http://" || words[i].substr(0, 4) == "www.") 
            		    url.push_back(words[i]);

          		// if (std::regex_match (words[i], std::regex("^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w \\.-]*)*\\/?$")))
          		   // url.push_back(words[i]);
         
	    else 
            {
		word = lower_letters_no_punctuation(words[i]);
		it = word_data.find(word);
                Word tmp;

                     if (word_data.find(word) == word_data.end()) 
                        {
                            tmp.row.push_back(rowCounter);
                            word_data.insert(std::make_pair(word, tmp));
                        }
                    
                            else if (word_data.find(word) != word_data.end()) 
                            {
                                it->second.row.push_back(rowCounter);
                                it->second.count++;
                            }
			}
		}

		rowCounter++;
	}
}

void Output(std::vector<std::string> url, std::multimap<std::string, Word> word_data) 
{
    ReadFile(url, word_data);
    char screen_or_file;
	std::cout << "output to screen (s) or file (f)? ";
	std::cin >> screen_or_file;
    simbol (screen_or_file, 's', 'f');

    std::string file;
    if (screen_or_file=='f')
    {
        std::cout << "enter output file name: ";
        std::cin >> file;
    }
 
	std::ofstream out(file.c_str());
	std::multimap<std::string, Word>::iterator it;

    if (screen_or_file == 's')
    {
        if (!url.empty())
        {
            std::cout << std::endl << "URL adresai tekste:" << std::endl;
            for (int i = 0; i < url.size(); i++) 
            {
                std::cout << url[i] << std::endl;
            }
        }

        std::cout << std::endl;
        std::cout << std::setw(20) << std::left << "Zodis" << std::setw(20) << "  Kiekis";  
        std::cout << "    Eilutes" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl;

        int how = 0;

        for(it = word_data.begin(); it != word_data.end(); it++)
        {
           if (it->second.count > 1) 
            {
                std::cout << std::setw(20) << std::left << it->first << "  " << std::setw(20)  << it->second.count << "  ";

                for (int j = 0; j < it->second.count; j++)
                {
                    std::cout << it->second.row[j];
                    how = j;
 
                   if (how + 1 != it->second.count)
                   {
                        std::cout << ", ";
                        how = 0;
                   }   
                }

                std::cout << std::endl;
            }
        }
    }

    else if (screen_or_file == 'f')
    {
        if (!url.empty())
        {
            out << std::endl << "URL adresai tekste:" << std::endl;
            for (int i = 0; i < url.size(); i++) 
            {
                out << url[i] << std::endl;
            }
        }

        out << std::endl;
        out << std::setw(20) << std::left << "Zodis" << std::setw(20) << "  Kiekis";  
        out << "    Eilutes" << std::endl;
        out << "--------------------------------------------------------------------------------" << std::endl;

        int how = 0;
        for(it = word_data.begin(); it != word_data.end(); it++)
        {
            if (it->second.count > 1) 
            {
                out << std::setw(20) << std::left << it->first << "  " << std::setw(20)  << it->second.count << "  ";
                
                for (int j = 0; j < it->second.count; j++)
                {
                    out << it->second.row[j];
                    how = j;

                   if (how + 1 != it->second.count)
                   {
                        out << ", ";
                        how = 0;
                   }   
                }
                out << std::endl;
            }
        }
    }
    	out.close();
}
