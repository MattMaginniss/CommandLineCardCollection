# CommandLineCardCollection

This project is a Command Line Program for tracking a baseball card collection using a user created interlaced list.

The cards will have the following fields:
* Player name
* Year
* Condition
* Value
* nextName
* nextYear
* nextCondition

This is a TUI project to interact with the program. The TUI menu options must provide the following functionality:

1. Load a file – allows the user to load a specified file of cards replacing the currently loaded list of cards. The user should be informed if the file does not exist. Note: The file loaded may not be in alphabetic order according to the player’s name.
  * The format of the text file is described below:
    * The information for each card will be stored on a single line as a CSV file in the following format:
        name,year,condition,value
      
      Each field is separated by a comma with no spaces.
      
2. Save a file – writes the current list of loaded cards to a user-specified file in the
format mentioned above.
  * When writing to a file, if the file exists go ahead and overwrite the file, but also output a message stating the file was overwritten.
  * The file must be written out in ascending order by the player's name.
  
3. Delete card – prompts the user for the player's name and deletes the card from the list.
  * The search for the player's name should be case insensitive.
  * When a card is deleted then make sure to free the memory for the card node.
  
4. Add card – prompts the user for all the fields needed and adds the card to the current list of cards. If there is not a currently loaded list, this should create a new list.

5. Print cards ascending by player's name

  * Each column for all required output must be aligned. The money must be formatted as shown above and align at the decimal point.

6. Print cards descending by player's name

7. Print cards ascending by year

8. Print cards descending by year 

9. Print cards ascending by condition

10. Print cards descending by condition

11. Quit – terminates the program. Upon exiting the program must clean-up all allocated
resources.
