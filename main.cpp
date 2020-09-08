// Author: Braeden Kilburn
// Created: 9/6/2020
// Convert Roman Numerals to Arabic Numerals (1,2,3...)

#include <iostream>

using namespace std;

void welcomeUser();
void requestRomanNumeral(string&);
void convertRomanToUpper(string&);
int convertRomanToArabic(string&);

int main()
{
	// Welcome User to the program
	welcomeUser();

	// Enter User Input
	string romanNumeral;
	requestRomanNumeral(romanNumeral);

	// Standardize capitalization
	convertRomanToUpper(romanNumeral);
	
	// Convert each character into numbers and get the total
	int arabicNumeral = convertRomanToArabic(romanNumeral);

	// Output conversion to user
	cout << romanNumeral << " is " << arabicNumeral << " in arabic numerals.\n"; 
		
	return 0;
}

// Welcomes the User and explains the programs duty
void welcomeUser()
{
  cout << "Welcome to Roman to Arabic 1.0!\n";
  cout << "Convert Roman Numerals to common Arabic Numerals.\n" << endl;
}

// Ask for and stores a roman numeral as a string
void requestRomanNumeral(string& romanNumeral)
{
	cout << "Enter Roman Numeral Here: ";
	cin >> romanNumeral;
}

// Converts each character in the romanNumeral string to uppercase
void convertRomanToUpper(string& romanNumeral)
{
	for (unsigned int i = 0; i < romanNumeral.size(); i++)
		{
		romanNumeral[i] =  toupper(romanNumeral[i]);
		}
}

// Goes through each character of the string and add it's equivalent value to runningTotal
// (Also checks that the subsequent character is not larger than the previous character,
//  if so, we will give the correct value of those two character combinations)
int convertRomanToArabic(string& romanNumeral)
{
	// runningTotal will be the sum of each roman numeral's equivalent arabic numeral
	int runningTotal {0};

	for (unsigned int i = 0; i < romanNumeral.size(); i++)
	{
		switch(romanNumeral[i])
		{
			case 'I':
			{
				if (romanNumeral[i+1] == 'V')
				{
				runningTotal += 4;
				i++;
				}
				else if (romanNumeral[i+1] == 'X')
				{
				runningTotal += 9;
				i++;
				}
				else runningTotal++;
				break;
			}
			case 'V':
			{
				runningTotal += 5;
				break;
			}
			case 'X':
			{
				if (romanNumeral[i+1] == 'L')
				{
				runningTotal += 40;
				i++;
				}
				else if (romanNumeral[i+1] == 'C')
				{
				runningTotal += 90;
				i++;
				}
				else runningTotal += 10;
				break;
			}
			case 'L':
			{
				runningTotal += 50;
				break;
			}
			case 'C':
			{
				if (romanNumeral[i+1] == 'D')
				{
				runningTotal += 400;
				i++;
				}
				else if (romanNumeral[i+1] == 'M')
				{
				runningTotal += 900;
				i++;
				}
				else runningTotal += 100;
				break;
			}
			case 'D':
			{
				runningTotal += 500;
				break;
			}
			case 'M':
			{
				runningTotal += 1000;
				break;
			}
		}
	}

	return runningTotal;
}