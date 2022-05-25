#include "lab4.h"
#include <iostream>

int main()
{
   KVtree T;
   bool done = false;
   do {
      char cmd = getCommand();
      done = Process(cmd, T);
   } while (!done);
}

// constants for user commands were
//     Quit, Lookup, Help, Insert, Print
char getCommand()
{
   char cmd;
   bool quit = false;
   do {
      std::cout << std::endl;
      std::cout << "Enter a command (one of ILPQR or H for help): ";
      std::cin >> cmd;
      cmd = toupper(cmd);
      switch (cmd) {
         case Lookup:
         case Help:
         case Insert:
         case Print:
         case Quit:
            quit = true;
            break;
         default:
            std::cerr << "That was not a valid command, please try again" << std::endl;
      }
   } while (!quit);
   return cmd;
}

// get and return an integer from the user (repeat until valid)
long getInt()
{
   long userVal = 0;
   bool quit = false;
   std::cout << "Please enter an integer" << std::endl;
   do {
      std::cin >> userVal;
      if (std::cin.fail()) {
          std::cin.clear();
          std::string junk;
          std::cin >> junk;
          std::cerr << "Error: " << junk << " is not a valid integer, please try again";
          std::cerr << std::endl;
      } else {
          quit = true;
      }
   } while (!quit);
   return userVal;
}

// get and return a real number from the user (repeat until valid)
double getValue()
{
   double userVal = 0;
   bool quit = false;
   std::cout << "Please enter a number" << std::endl;
   do {
      std::cin >> userVal;
      if (std::cin.fail()) {
          std::cin.clear();
          std::string junk;
          std::cin >> junk;
          std::cerr << "Error: " << junk << " is not a valid number, please try again";
          std::cerr << std::endl;
      } else {
          quit = true;
      }
   } while (!quit);
   return userVal;
}

// get and return a description string from the user
std::string getDescription()
{
   std::string userVal = "";
   std::cout << "Please enter the description as one line of text" << std::endl;
   getline(std::cin, userVal);
   return userVal;
}

// apply the given command to the KV tree, L
// return true if it was a quit command, false otherwise
bool Process(char cmd, KVtree &T)
{
   std::string desc, junk;
   long key;
   double value;
   switch (cmd) {
      case Insert:
         std::cout << "First we will get the key you wish to lookup" << std::endl;
         key = getInt();
         std::cout << "Next we will get the associated value" << std::endl;
         value = getValue();
         getline(std::cin, junk); // get and discard the newline left over after getValue
         std::cout << "Finally, we will get the description" << std::endl;
         desc = getDescription();
         if (T.insert(key, desc, value)) {
            std::cout << "The data was successfully updated" << std::endl;
         } else {
            std::cout << "The attempted insert was unsuccessful" << std::endl;
         }
         break;

      case Lookup:
         std::cout << "First we will get the key you wish to lookup" << std::endl;
         key = getInt();
         if (T.lookup(key, desc, value)) {
            std::cout << "The data is: ";
            KVtree::printData(key, desc, value);
         } else {
            std::cout << "No node found with key " << key << std::endl;
         }
         break;

      case Help:
         printMenu();
         break;

      case Print:
         std::cout << "tree currently contains " << T.size() << " items:" << std::endl;
         T.print();
         break;

      case Quit:
         std::cout << "Bye!" << std::endl;
         return true;
         break;

      default:
         std::cerr << "Error: given invalid command to process, " << cmd << std::endl;
         break;
   }
   return false; // true results returned directly from quit case
}

void printMenu()
{
   std::cout << "The available commands are:" << std::endl;
   std::cout << "   " << Help << " to print this menu" << std::endl;
   std::cout << "   " << Insert << " to insert or update a key,desc,value set" << std::endl;
   std::cout << "   " << Print << " to print the tree content" << std::endl;
   std::cout << "   " << Lookup << " to lookup the desc,value for a given key" << std::endl;
   std::cout << "   " << Quit << " to quit the program" << std::endl;
}

