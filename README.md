# CS210ProgrammingLanguages

**-Summarize the project and what problem it was solving**

This program is a solution for tracking the number of groceries on hand. It reads in an input file that contains the current groceries on hand and then counts each time it appears in the last. The program then backs this data up in an output file and displays a menu with options for the user. The options include a search feature that prints if the item searched was found and the number of times it appears in the list. Also included are two different ways to print out the entire list of groceries. One being a numerical list and the other being a histogram. Finally, the menu also gives the user the option to quit and close the program.

**-What did you do particularly well?**

I feel that my utilization of functions was particularly well done. Each distinct action the program can perform is relegated to its own function, and repetitive code was kept to a minimum. Keeping the majority of the code in the GroceryTracker.cpp file rather than main was another area I felt I did well in. One final area I felt was done well was my use of maps, which felt like dictionaries that I have utilized in other programming languages. 


**-Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**

There are multiple places where I could enhance this in order to improve efficiency and future expandability. For example, I could create a generic GroceryItem class and then derive specific groceries from that. This could allow the system to collect more data besides just counting. Implementing more unit testing as I code is another area I feel I could improve on. I want to have a suite of tests that I can trust if they pass. 


**-Which pieces of code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**

Surprisingly, the most challenging part of the code was ensuring the user input was being correctly handled. I was still not used to working with cin and clearing the cin buffer. Because of this, I had an issue where the program would need multiple inputs if more than one character was entered for menu selection. I was able to overcome this by researching on different forums like Reddit and StackOverflow to figure out what would cause hanging input. Once I realized it was a buffer issue, I used cin.clear() and cin.ignore() in the user input function to remedy it. Seeking help from other programmers is a resource I find extremely helpful, as a different perspective and mindset can be invaluable to solving difficult or hard-to-spot problems.


**-How did you make this program maintainable, readable, and adaptable?**

I made this program more maintainable, readable, and adaptable with my generous use of functions and by keeping the code relatively compartmentalized. My commenting throughout the code also provides a good overview of different aspects and functions, especially when paired with the documentation I created. Keeping my code out of main and in the class I created for it was another way I attempted to make this code more manageable for future development. Finally, adding m_ and t_ to the beginning of member variables and function parameters, respectively, was another method I used to maintain readability. 
