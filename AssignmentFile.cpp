// Alfred Ledgin
// 10/3/2015
// CS 303
// Project 1

#include <iostream>
#include "AssignmentFile.h"
using namespace std;


bool AssignmentFile::read(istream& input)
{

    string inputString;
    string inputDueDate;
    string inputDescription;
    string inputAssignedDate;
    string inputStatus;
    Assignment newAssignment;

    if (input)
    {

        while (getline(input, inputString))
        {

            int spaceCount = 0;
            for (int counter = 0; counter < inputString.length(); counter++)
            {
                if ((inputString[counter] == ' ') && (inputString[counter + 1] != ' '))
                    spaceCount++;
            }
            // Count the spaces in each line.
               // Count any string of consecutive spaces as a single space.

            String_Tokenizer tokenizer(inputString, ", ");
            if (tokenizer.has_more_tokens())
                inputDueDate = tokenizer.next_token();
            if (tokenizer.has_more_tokens())
            {
                inputDescription = "";
                while (spaceCount > 2)
                {
                    inputDescription += tokenizer.next_token();
                    spaceCount--;
                    if (spaceCount > 2)
                        inputDescription += " ";
                } // Handle descriptions that include spaces.
            }
            if (tokenizer.has_more_tokens())
                inputAssignedDate = tokenizer.next_token();
            if (tokenizer.has_more_tokens())
                inputStatus = tokenizer.next_token();

            // Consistently use hyphens in date strings.
            for (int counter = 0; counter < inputDueDate.length(); counter++)
            {
                if (inputDueDate[counter] == '/')
                    inputDueDate[counter] = '-';
            }
            for (int counter = 0; counter < inputAssignedDate.length();
                counter++)
            {
                if (inputAssignedDate[counter] == '/')
                    inputAssignedDate[counter] = '-';
            }

            newAssignment.setDueDate(inputDueDate);
            newAssignment.setDescription(inputDescription);
            newAssignment.setAssignedDate(inputAssignedDate);
            newAssignment.setStatus(convertStatus(inputStatus));

            // Add the assignment to the appropriate list.
            if (inputStatus == "assigned")
            {
                uncompleted.addAssignment(newAssignment);
            }
            else
                completed.addAssignment(newAssignment);

        }
        return true;

    }

    else
        return false;

}


bool AssignmentFile::write(ostream& output)
{
    if (output)
    {
        completed.displayAll(output);
        uncompleted.displayAll(output);
        return true;
    }
    else
        return false;
}


int AssignmentFile::convertStatus(string inputStatus)
{
    if (inputStatus == "completed")
        return 1;
    else if (inputStatus == "late")
        return 2;
    else 
        return 0;
}