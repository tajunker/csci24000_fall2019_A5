//textParserBlackBelt.cpp
//parses an input file
//save output to output file 

#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <cstdio>
#include <utility>

//function prototypes
bool is_digit(const char value) { return std::isdigit(value); }

// the following did not run on tesla 
// bool is_numeric(const std::string& value) { return std::any_of(value.begin(), value.end(), is_digit); }

bool is_numeric(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

// start main
int main() {


	// The following declares an object of ifstream in order to open the input.txt file
	std::ifstream inputFile;


	// The following declares an object of ofstream in order to create the output.txt file
	std::ofstream outputFile;
	

	// The following opens the text file used as input
	inputFile.open("badinput.txt");
	

	// The following opens the text file used as output
	outputFile.open("output.txt");


	// If the input.txt file is not openable...
	// output the following error message to the console.
	if (!inputFile) {
	

		std::cerr << "Unable to open file input.txt \n\n";
	

	}
	
	// If input.txt file is openable run the following code
	else {

		std::string currentLine;
		

		// The following while loop, read each line of the input.txt file until there
		// are no more lines to get with the getline function
		while (getline(inputFile, currentLine)) {
		    
		    
		    // Check to see if integer line is empty
		    if (currentLine.length() == 0) {
		    

		    	// Output the following error message to the console
		        std::cerr << "Found an empty line, please check input file and try again... \n\n";
		        return 1;
		    

		    }
			

	    	// The following instantiates an object called ss of stringstream 
			std::stringstream ss(currentLine);
			

			while (ss) {


				std::string firstInteger, secondInteger, ifSpace;

				std::string wordString;

				getline(ss, firstInteger, ',');

				getline(ss, secondInteger, ',');

				getline(ss, ifSpace, ' ');

				getline(ss, wordString);
				
				// Read the string in the next line and save it to wordString
			    getline(inputFile, wordString);

			    
			    // Check to see if the line containing a word is empty
			    if (wordString.length() == 0) {


		    		// Output the following error message to the console
    		        std::cerr << "Found an empty line, please check input file and try again... \n\n";
    		        return 1;


    		    }

				int firstIntegerParsed, secondIntegerParsed, ifSpaceParsed;

				firstIntegerParsed = atoi(firstInteger.c_str()); //parsing string to integer and saving them
				secondIntegerParsed = atoi(secondInteger.c_str());
				ifSpaceParsed = atoi(ifSpace.c_str());

				int temp;

				temp = firstIntegerParsed + secondIntegerParsed + ifSpaceParsed;
				
				
				// Check to see if the numbers in the input file are valid.
				if (!is_numeric(firstInteger) || !is_numeric(secondInteger) || !is_numeric(ifSpace) || temp == 0) {


					// Output the following error message to the console.
				    std::cerr << "Non valid integers, please check input file and try again... \n";
				    return 1;


				}
				
				// For loop to loop through the sum of integers to print words to output.txt file
				for (int i = 0; i < temp-1; ++i) {

					// Write to output file
					outputFile << wordString << ",";
				}

				// Write to output file
				outputFile << wordString << "\n";

			}
		}
	}
	
	return 0;
}
