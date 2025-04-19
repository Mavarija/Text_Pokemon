#include "Utility.h"

void Utility::ClearConsole()
{
    // Platform-specific clear console command
#ifdef _WIN32
    system("cls");
#else
    (void)system("clear");
#endif
}

void Utility::WaitForEnter()
{
    // Function that temporarily pauses the program, until the Enter key is pressed.
    cin.get();
}

void Utility::ClearInputBuffer()
{
    // Clear the newline character left in the buffer 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
