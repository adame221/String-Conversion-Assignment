/* StringConversion.cpp : Prompts the user to enter a charter sting no longer than 25 characters.  Then it passes the charter string
	into diferent functions (upper, lower, and reverse).
*/
#include "stdafx.h"
#include <iostream>
#include <cctype>
using namespace std;

//Declare prototypes 
void upper(char *);
void lower(char *);
void reverse(char *, const int);

int main()
{
	// Constant for the size of a line of input
	const int SIZE = 26;

	// Array to hold a line of input
	char letters[SIZE];

	//
	cout << "Please enter no more than 25 characters: " << endl;
	cin.getline(letters, SIZE);
	cout << endl;

	//Declare a new array to pass to the reverse function
	const int NEW_SIZE = strlen(letters);
	char newLetters[SIZE];

	//Set the original array to the newly created array
	for (int count = 0; count < SIZE; count++) {
		newLetters[count] = letters[count];
	}

	//Call approiate functions
	upper(letters);
	lower(letters);
	reverse(newLetters, SIZE);

	system("pause");
	return 0;
}

/* This function converts the accepted char array passed in as a parameter and converts all the letters in the array to
to upper cased letters.  The numbers and special characters get ignored.*/
void upper(char *upperLetters)
{
	// Convert all lowercase characters to uppercase
	for (int count = 0; count < strlen(upperLetters); count++)
	{
		// convert it to an uppercase character.
		if (islower(upperLetters[count]))
		{
			upperLetters[count] = toupper(upperLetters[count]);
		}
	}
	// Display the converted line of input.
	cout << "Upper letters result: " << upperLetters << endl;
	return;
}

/* This function converts the accepted char array passed in as a parameter and converts all the letters in the array to 
	to lower cased letters.  The numbers and special characters get ignored.*/
void lower(char *lowerLetters)
{
	// Convert all lowercase characters to uppercase
	for (int count = 0; count < strlen(lowerLetters); count++)
	{
		// Convert it to an lowercase character.
		if (isupper(lowerLetters[count]))
		{
			lowerLetters[count] = tolower(lowerLetters[count]);
		}
	}

	// Display the converted line of input.
	cout << "Lower letters result: " << lowerLetters << endl;
	return;
}

/* This function reverse the accepted char array and char the lower cased letters to upper case and the upper case 
	letters to lower case and does not to numbers and special characters.
*/
void reverse(char *reverseLetters, const int size) {

	// Loop through the param array and convert all lowercase characters to uppercase
	for (int count = 0; count < strlen(reverseLetters); count++)
	{
		if(islower(reverseLetters[count])) {
			reverseLetters[count] = toupper(reverseLetters[count]);
		} else  {
			if (isupper(reverseLetters[count])) {
				reverseLetters[count] = tolower(reverseLetters[count]);
			}
		}
	} 

	//Display the output to the screen
	reverseLetters[size] = '\0';
	cout << "Reverse letters result: " << reverseLetters << endl;
	return;
}