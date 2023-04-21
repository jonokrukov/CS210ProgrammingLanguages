#include "GroceryTracker.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// Default Constructor
GroceryTracker::GroceryTracker() {
	createMapFromFile();
	backupData();
}

// Function to handle displaying the menu
void GroceryTracker::displayMenu() {
	cout << "Input your selection (1-4)" << endl;
	cout << "1. Search specific grocery frequency" << endl;
	cout << "2. Print numeric list of all grocery's frequencies" << endl;
	cout << "3. Print histogram of all grocery's frequencies" << endl;
	cout << "4. Quit" << endl;
}

// Handles menu input
void GroceryTracker::menuInput() {
	char input = '-1';

	// Displays menu until quit is selected
	// Calls function that corresponds with selection
	while (true) {
		displayMenu();
		cin >> input;
		if (isdigit(input)) {
			if (input == '1') {
				searchGrocery();
				cout << endl << endl << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else if (input == '2') {
				printNumericList();
				cout << endl << endl << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else if (input == '3') {
				printHistogramList();
				cout << endl << endl << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else if (input == '4') {
				cout << "Quitting" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}
		}
		else {
			// Input validation
			cout << "ERROR: Please enter a number between 1-4" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

	}
	
}

// Backs up numeric data to frequency.dat
void GroceryTracker::backupData() {
	ofstream outFS;
	outFS.open("frequency.dat");

	// Error check for opening frequency.dat
	if (!outFS.is_open()) {
		cout << "Error opening frequency.dat" << endl;
	}

	// Writes map to frequency.dat
	for (auto i = m_groceryCountMap.begin(); i != m_groceryCountMap.end(); i++) {
		outFS << i->first << ": " << i->second << endl;
	}
	outFS.close();
}

// Creates map from input file
void GroceryTracker::createMapFromFile() {
	// Create input stream and open input file
	ifstream inFS;
	inFS.open("groceryList.txt");

	// Check if file properly opened
	if (!inFS.is_open()) {
		cout << "Error opening input file." << endl;
	}

	// While loop to add items to map and get counts
	while ((!inFS.eof()) && (inFS.good())) {
		m_currentGrocery = " ";
		inFS >> m_currentGrocery;
		transform(m_currentGrocery.begin(), m_currentGrocery.end(), m_currentGrocery.begin(), ::tolower);
		this->m_groceryCountMap[m_currentGrocery]++;
	}
	inFS.close();
}

// Prints list of groceries with numeric counts
void GroceryTracker::printNumericList() {
	// Prints key and then value
	for (auto i = m_groceryCountMap.begin(); i != m_groceryCountMap.end(); i++) {
		string capitalized = i->first;
		capitalized[0] = toupper(capitalized[0]);
		cout << capitalized << ": " << i->second << endl;
	}
}

// Returns string that consists of char t_x, int t_size number of times
string GroceryTracker::nCharString(int t_size, char t_x) {
	string newString;

	for (int i = 0; i < t_size; i++) {
		newString.push_back(t_x);
	}
	return newString;
}

// Searches map for user inputed grocery
void GroceryTracker::searchGrocery() {
	string input;
	cout << "Enter a grocery to search for: ";
	cin >> input;
	input[0] = tolower(input[0]);

	auto i = m_groceryCountMap.find(input);
	if (i != m_groceryCountMap.end()) {
		string capitalized = i->first;
		capitalized[0] = toupper(capitalized[0]);
		cout << capitalized << " " << i->second << endl;
	}
	else {
		cout << "Grocery not found" << endl;
	}
}

void GroceryTracker::printHistogramList() {
	for (auto i = m_groceryCountMap.begin(); i != m_groceryCountMap.end(); i++) {
		string capitalized = i->first;
		capitalized[0] = toupper(capitalized[0]);
		cout << capitalized << ": " << nCharString(i->second, '*') << endl;
	}
}