// Alfred Ledgin
// 10/3/2015
// CS 303
// Project 1

#include <iostream>
#include "Assignment.h"
using namespace std;


Assignment::Assignment()
{
    status = assigned;
    description = " ";
}


void Assignment::setAssignedDate(string inputDate)
{
    try
    {
        assignedDate = Date(inputDate);
    }
    catch (std::exception)
    {
        invalidDate = true;
    }
}


void Assignment::setDueDate(string inputDate)
{
    try
    {
        dueDate = Date(inputDate);
    }
    catch (std::exception)
    {
        invalidDate = true;
    }
}


void Assignment::setCompletedDate(string inputDate)
{
    try
    {
        completedDate = Date(inputDate);
    }
    catch (std::exception)
    {
        invalidDate = true;
    }
}


void Assignment::setStatus(int inputStatus)
// A status is input as an integer and then set to the appropriate value.
// The status is assumed to be "assigned" unless specified otherwise.
{
    switch(inputStatus)
    {
        case 0: status = assigned; break;
        case 1: status = completed; break;
        case 2: status = late; break;
        default: status = assigned; break;
    }
}


const ostream& Assignment::display(ostream& output) const
{

    string statusStr;
    if (status == completed)
        statusStr = "completed";
    else if (status == late)
        statusStr = "late";
    else
        statusStr = "assigned";
    string dueDateString = dueDate.toString();
    string assignedDateString = assignedDate.toString();

    // Consistently use hyphens in date strings.
    for (int counter = 0; counter < dueDateString.length(); counter++)
    {
        if (dueDateString[counter] == '/')
            dueDateString[counter] = '-';
    }
    for (int counter = 0; counter < assignedDateString.length(); counter++)
    {
        if (assignedDateString[counter] == '/')
            assignedDateString[counter] = '-';
    }

    output << dueDateString << ", " << description << ", "
        << assignedDateString << ", " << statusStr << endl;
    return output;

}