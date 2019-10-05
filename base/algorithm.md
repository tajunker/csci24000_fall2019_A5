# Goals: 
This program parses a text file known as input.txt and creates an output file, output.txt. The purpose of this is to get familiar with the C++ process of parsing and file input/output through the basics of the fstream library. 

# Input: 
This program takes in a text file called input.txt with integers and words formatted in a specific way. The blackbelt assignment accounts for edge cases and a potentially badly formatted file.

# Output: 
This program outputs the parsed strings into a new file created by this program called output.txt. In this file the integers and words parsed are printed however many times necessary to equal the sum of the integers in the line above the words found in the text file. 

# Steps: 
For this program we have one main function called main(). In our blackbelt assignment there are two extra functions to accomplish the necessary edge case checks.

- main(): This program has a main function. In main(), the getline function is used to manipulate large pieces of data into progressively smaller chunks. Together with the stringstream function, we swap back and forth to 'tokenize' a large line of input and control where each piece goes. In this main functin we read from a text file called input.txt. We check to verify that the file is openable and proceed with reading from the text file. In a while loop, we parse each new line of strings to integers and save them to variables using the getline function and the atoi and c_str functions. We then add the values of these variables in a new variable called temp. We also get the word on the next line and save it to a string variable. We then loop through a for loop until the value of temp is reached minus one, so as to not print a trailing comma after the words we want to output to the output.txt file. While within the while loop and until there is still a newline to get, an output.txt file is created and the words are written to this output file however many times necessary to equal the sum of the integers in the line above the words found in the text file.
