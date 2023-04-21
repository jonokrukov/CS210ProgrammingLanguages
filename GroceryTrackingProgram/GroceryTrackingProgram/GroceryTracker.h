#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H
#include <string>
#include <map>


class GroceryTracker {
   public:
	   GroceryTracker();
	   void displayMenu();
	   void menuInput();
	   void backupData();

   private:
	   std::map<std::string, int> m_groceryCountMap;
	   std::string m_currentGrocery;

	   void createMapFromFile();
	   void printNumericList();
	   std::string nCharString(int t_size, char t_x);
	   void searchGrocery();
	   void printHistogramList();
};

#endif

