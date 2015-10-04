// Alfred Ledgin
// 10/3/2015
// CS 303
// Project 1

#include <iostream>
#include "AssignmentList.h"
using namespace std;


const ostream& AssignmentList::displayAll(ostream& output)
{
    for (AssignmentIterator = theData.begin();
        AssignmentIterator != theData.end();
        AssignmentIterator++)
    {
        AssignmentIterator->display(output);
    }
    return output;
}


bool AssignmentList::addAssignment(Assignment inputAssignment)
{
    if (inputAssignment.hasInvalidDate())
        return false;
    if (!find(inputAssignment)) // Look for assignment with same assigned date.
    {
        if (!(inputAssignment.obtainDueDate() <=
            inputAssignment.obtainAssignedDate()))
        {
            insert(inputAssignment);
            if (inputAssignment.obtainStatus() == 2)
                lateAssignments++; // Keep track of late assignments.
            return true;
        }
    }
    return false;
}


bool AssignmentList::completeAssignment(string inputAssignedDate,
    string inputCompletedDate, AssignmentList& inputCompletedList)
{
    for (AssignmentIterator = theData.begin();
        AssignmentIterator != theData.end(); AssignmentIterator++)
        // Find the assignment.
    {
        try
        {
            if (AssignmentIterator->obtainAssignedDate() ==
                Date(inputAssignedDate))
            {
                if (Date(inputCompletedDate) > AssignmentIterator->obtainDueDate())
                {
                    AssignmentIterator->setStatus(2);
                    lateAssignments++; // Keep track of late assignments.
                }
                else
                    AssignmentIterator->setStatus(1);
                inputCompletedList.addAssignment(*AssignmentIterator);
                // Move the completed assignment.
                theData.remove(*AssignmentIterator);
                // Reference: "std::list::remove." _cplusplus.com_.
                    // cplusplus.com, 2015. Web. 28 Sept. 2015.
                    // <http://www.cplusplus.com/reference/list/list/remove/>.
                return true;
            }
        }
        catch (std::exception)
        {
            return false;
        }
    }
    return false;
}


bool AssignmentList::editAssignment(string inputAssignedDate,
    string desiredDescription, string desiredDueDate)
{
    for (AssignmentIterator = theData.begin();
        AssignmentIterator != theData.end(); AssignmentIterator++)
        // Find the assignment.
    {
        try
        {
            if (AssignmentIterator->obtainAssignedDate() ==
                Date(inputAssignedDate))
            {
                if (AssignmentIterator->obtainStatus() == 0)
                    // Only edit assignments with the "assigned" status.
                {
                    if (desiredDescription != "")
                        AssignmentIterator->setDescription(desiredDescription);
                    if (desiredDueDate != "")
                    {
                        AssignmentIterator->setDueDate(desiredDueDate);
                        Assignment tempAssignment = *AssignmentIterator;
                        theData.remove(*AssignmentIterator);
                        // Reference: "std::list::remove." _cplusplus.com_.
                            // cplusplus.com, 2015. Web. 28 Sept. 2015.
                            // <http://www.cplusplus.com/reference/list/list/remove/>.
                        insert(tempAssignment);
                        // Move the assignment if editing the due date.
                    }
                    return true;
                }
            }
        }
        catch (std::exception)
        {
            return false;
        }
    }
    return false;
}


bool AssignmentList::find(Assignment inputAssignment)
{
    for (AssignmentIterator = theData.begin();
        AssignmentIterator != theData.end();
        AssignmentIterator++)
    {
        if (AssignmentIterator->obtainAssignedDate()
            == inputAssignment.obtainAssignedDate())
            return true;
    }
    return false;
}


void AssignmentList::insert(Assignment inputAssignment)
{

    if (!obtainSize()) // If the list is empty.
        theData.push_front(inputAssignment);

    else
    {

        for (AssignmentIterator = theData.begin();
            AssignmentIterator != theData.end();
            AssignmentIterator++)
        {

            // If we find an assignment with a later due date, insert this
                // assignment before it and exit the function.
            if (inputAssignment.obtainDueDate() <= AssignmentIterator->obtainDueDate())
            {
                theData.insert(AssignmentIterator, inputAssignment);
                // Reference: "std::list::insert." _cplusplus.com_.
                    // cplusplus.com, 2015. Web. 2 Oct. 2015.
                    // <http://www.cplusplus.com/reference/list/list/insert/>.
                return;
            }

        }

        theData.push_back(inputAssignment);
        // If we have not found an assignment with a later due date, place
            // this assignment at the end of the list.

    }

}