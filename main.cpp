// Alfred Ledgin
// 10/3/2015
// CS 303
// Project 1

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "AssignmentFile.h"
using namespace std;


void displayMenu();
// Preconditions: The program's main menu needs to be displayed.
// Postconditions: This function prints the main menu to the console output.


int main()
{

    bool quit = false;
    ifstream inputFile;
    ofstream outputFile;
    string filename;
    cout << "Assignment Manager" << endl << endl; // Title.
    char menuChoice = '9'; // Force the filename prompt.
    AssignmentFile assignments;

    // Loop the program until the user quits.
    while (!quit)
    {

        if (menuChoice == '9') // Prompt for the filename.
        {
            while (filename == "")
            {
                cout <<
                    "Enter the name of the assignment file (or 'q' to quit): ";
                cin >> filename;
                cout << endl;
                if (filename == "q" || filename == "Q")
                    // Allow the user to quit here.
                {
                    quit = true;
                    exit(0);
                }
                inputFile.open(filename);
                if (!inputFile) // If the file does not exist, create it.
                {
                    outputFile.open(filename);
                    if (!outputFile) // If the name is invalid:
                    {
                        cout << "Error: Cannot write to file." << endl << endl;
                        filename = "";
                    }
                    outputFile.close();
                }
                assignments.read(inputFile);
                    // Read the assignment data, if any.
                inputFile.close();
            }
        }

        displayMenu();
        string menuChoiceStr;
        cin >> menuChoiceStr;
        menuChoice = menuChoiceStr[0]; // Only use the first input character.
        cout << endl;

        // Create assignment variables to be populated.
        Assignment newAssignment;
        string inputAssignedDate;
        string inputDueDate;
        string inputCompletedDate;
        string inputDescription;
        string inputStatus;

        switch(menuChoice)
        {

            case '1': assignments.completed.displayAll(cout); 
                assignments.uncompleted.displayAll(cout);
                cout << endl; break;

            case '2': cout << "Enter the assigned date: ";
                cin >> inputAssignedDate;
                cout << endl << "Enter the description (no spaces): ";
                cin >> inputDescription; // Assumes the user does not enter spaces.
                cout << endl << "Enter the due date: ";
                cin >> inputDueDate;
                cout << endl << "Enter the status (assigned/completed/late): ";
                cin >> inputStatus;
                    // Take assignment data from the user.
                newAssignment.setAssignedDate(inputAssignedDate);
                newAssignment.setDueDate(inputDueDate);
                newAssignment.setDescription(inputDescription);
                newAssignment.setStatus(assignments.convertStatus(inputStatus));
                    // Create the assignment.
                if (!assignments.uncompleted.addAssignment(newAssignment))
                    // Add the assignment to the uncompleted list, if possible.
                    cout << endl << "Cannot add assignment" << endl;
                cout << endl;
                break;

            case '3': cout << "Enter the assigned date: ";
                cin >> inputAssignedDate;
                cout << endl << "Enter the new due date: ";
                cin >> inputDueDate;
                cout << endl;
                    // Take the new data from the user.
                if (!assignments.uncompleted.editAssignment(inputAssignedDate, "", inputDueDate))
                    // Edit the uncompleted assignment, if possible.
                    cout << "Cannot edit assignment" << endl << endl;
                break;

            case '4': cout << "Enter the assigned date: ";
                cin >> inputAssignedDate;
                cout << endl << "Enter the new description (no spaces): ";
                cin >> inputDescription; // Assumes the user does not enter spaces.
                cout << endl;
                    // Take the new assignment data from the user.
                if (!assignments.uncompleted.editAssignment(inputAssignedDate, inputDescription))
                    // Edit the uncompleted assignment, if possible.
                    cout << "Cannot edit assignment" << endl << endl;
                break;

            case '5': cout << "Enter the assigned date: ";
                cin >> inputAssignedDate;
                cout << endl << "Enter the completed date: ";
                cin >> inputCompletedDate;
                cout << endl;
                    // Take the completed assignment data from the user.
                if (!assignments.uncompleted.completeAssignment(inputAssignedDate, inputCompletedDate, assignments.completed))
                    // Complete the assignment, if possible.
                    cout << "Cannot complete assignment" << endl << endl;
                break;

            case '6': cout << "Late assignments: " <<
                assignments.completed.countLateAssignments() << endl << endl;
                break;

            case '7': outputFile.open(filename);
                assignments.write(outputFile); // Overwrite the file.
                outputFile.close(); break;

            case '8': quit = true; break; // The loop will end.

            case '9': filename = ""; break;
                // This will cause a new filename prompt.

            default: break; // Any other input causes the menu to repeat.

        }

    }

    return 0;

}


void displayMenu()
{
    cout << "Menu:" << endl
        << "1. Display all assignments" << endl
        << "2. Add assignment" << endl
        << "3. Edit assignment due date" << endl
        << "4. Edit assignment description" << endl
        << "5. Complete assignment" << endl
        << "6. Count late assignments" << endl
        << "7. Save updates" << endl
        << "8. Exit" << endl
        << "9. Change assignment file" << endl << endl
        << "Enter menu selection: ";
}