#pragma once

class Utility
{
public:
	// Method to clear the console
	static void ClearConsole();
	// Method to wait for user to press Enter
	static void WaitForEnter();
	// Method to clear leftover data in the input buffer
	static void ClearInputBuffer();

//	The static keyword makes a function belong to the class itself, not to any object.
//	You can call it using the class name Utility::clearConsole(), without needing to create an instance.

};

