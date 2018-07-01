//Worked on by Ben Cohen and Jose Banda August 29,2016
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib> //for exit()

using namespace std;

int calculation(int input);

int main(){
	//Setup
	cout << "This program will compute some calculations for some numbers that will be entered by the user." << endl;
	cout << "Input an integer N > 0: ";
	int input;
	cin >> input;
	int incorrect = 0;
	//Error Checking
	if (!cin){
		cout << "Error: You typed a letter. Program will end" << endl;
		return 0;
	}
  	while (input <= 0 && incorrect < 4){
		cout << "Your input was incorrect, enter N > 0! \nEnter N: ";
		cin >> input;
		incorrect++;
	}
	if (input <= 0 && incorrect == 4){
		cout << "Error: You entered incorrectly 5 times, the program will now end." << endl;
		return 0;
}
	//calculations and output
	cout << "Your input is: " << input << endl;
	cout << "The sum of the first " << input << " Positive integers is: " << calculation(input)<< endl;
	long double factorial = input;
	for (int y = input - 1; y > 0; y--){
		factorial *= y;
	}
	cout << "The factorial of " << input << " is: " << factorial << endl;
	exit(1);
  return 0;
}
//used in calculations
int calculation(int input){
  int sum = 0;
	for (int x = input; x > 0; x--){
		sum += x;
	}
	return sum;
}
