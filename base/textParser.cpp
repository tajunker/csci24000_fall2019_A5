//textParser.cpp
//parses an input file
//save output to output file 


#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

// start main
int main() {

	
	// The following declares an object of ifstream in order to open the input.txt file
	std::ifstream inputFile; 

	
	// The following declares an object of ofstream in order to create the output.txt file
	std::ofstream outputFile; 

	
	// The following opens the text file used as input
	inputFile.open("input.txt"); 

	
	// The following opens the text file used as output
	outputFile.open("output.txt");


	// If the input.txt file is not openable...
	if (!inputFile) {
	
		// Output the following error message to the console.
		std::cerr << "Unable to open file input.txt \n\n";
	

	}
	
	// If input.txt file is openable run the following code
	else {
	

		std::string currentLine;
		
		// The following while loop, read each line of the input.txt file until there
		// are no more lines to get with the getline function
		while (getline(inputFile, currentLine)) {

	
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

				int firstIntegerParsed, secondIntegerParsed, ifSpaceParsed;
				
				// Parse string to integer and save them to variables
				firstIntegerParsed = atoi(firstInteger.c_str()); 
				
				secondIntegerParsed = atoi(secondInteger.c_str());
				
				ifSpaceParsed = atoi(ifSpace.c_str());

				int temp;

				temp = firstIntegerParsed + secondIntegerParsed + ifSpaceParsed;
				
				// For loop to loop through the sum of integers to print words to output.txt file
				for (int i = 0; i < temp-1; ++i) {
				
					// Write to output file
					outputFile << wordString << ","; 
				
				}

				// Write to output file
				outputFile << wordString << "\n\n"; 

			}
		}
	}
} // end main
