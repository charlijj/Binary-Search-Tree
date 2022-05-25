#pragma once

#include "KV.h"

// set of valid user commands
const char Quit = 'Q';
const char Lookup = 'L';
const char Help = 'H';
const char Insert = 'I';
const char Print = 'P';


// get and return a valid command from the user (repeat until valid)
char getCommand();

// get and return an integer from the user (repeat until valid)
// if pos is true then it requires the user enter a value > 0
long getInt();

// get and return a real number from the user (repeat until valid)
double getValue();

// get and return a description string from the user
std::string getDescription();

// apply the given command to the KV list, L
// return true if it was a quit command, false otherwise
bool Process(char cmd, KVtree &T);

// display the available user commands
void printMenu();

