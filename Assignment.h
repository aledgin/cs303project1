// Alfred Ledgin
// 10/3/2015
// CS 303
// Project 1

#pragma once
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Assignment
// This is a class of objects called Assignments.  Each Assignment has an
    // assigned date, a due date, a completed date, a description, and a
    // status.  Appropriate member functions are included for editing,
    // displaying, and comparing Assignments.  Assignments use Date objects;
    // thus, the use of this class requires the Date class ("Date.h") written
    // by Dr. Mohammad Kuhail.
{

    public:

        enum statusType { assigned, completed, late };
        // Reference: "Other data types." _cplusplus.com_.
            // cplusplus.com, 2015. Web. 28 Sept. 2015.
            // <http://www.cplusplus.com/doc/tutorial/other_data_types/>.


        Assignment();
        // Preconditions: An Assignment object needs to be created.
        // Postconditions: This is the default constructor.  It creates an
            // Assignment object with default Dates and strings, and with the
            // status set to "assigned."


        const Date obtainAssignedDate() const {return assignedDate;}
        // Preconditions: An Assignment's assigned date is needed.
        // Postconditions: This function returns the Assignment's assigned
            // date.


        const Date obtainDueDate() const {return dueDate;}
        // Preconditions: An Assignment's due date is needed.
        // Postconditions: This function returns the Assignment's due date.


        const string obtainDescription() const {return description;}
        // Preconditions: An Assignment's description is needed.
        // Postconditions: This function returns the Assignment's description.


        const statusType obtainStatus() const {return status;}
        // Preconditions: An Assignment's status is needed.
        // Postconditions: This function returns the Assignment's status.


        void setAssignedDate(string inputDate);
        // Preconditions: An Assignment's assigned date needs to be set.
        // Postconditions: This function sets the assigned date to the given
            // date.  If the given date is invalid, this function sets a flag
            // variable indicating the Assignment has an invalid date.


        void setDueDate(string inputDate);
        // Preconditions: An assignment's due date needs to be set.
        // Postconditions: This function sets the due date to the given date.
            // If the given date is invalid, this function sets a flag
            // variable indicating the Assignment has an invalid date.


        void setCompletedDate(string inputDate);
        // Preconditions: An assignment's completed date needs to be set.
        // Postconditions: This function sets the completed date to the given
            // date.  If the given date is invalid, this function sets a flag
            // variable indicating the Assignment has an invalid date.


        void setDescription(string inputDescription)
            {description = inputDescription;}
        // Preconditions: An assignment's description needs to be set.
        // Postconditions: This function sets the description to the given
            // string.


        void setStatus(int inputStatus);
        // Preconditions: An assignment's status needs to be set.
        // Postconditions: This function sets the status to the appropriate
            // value based on the given integer
            // (0 -> "assigned", 1 -> "completed", 2 -> "late").


        const ostream& display(ostream& output) const;
        // Preconditions: An Assignment's data needs to be output in a text
            // format.
        // Postconditions: This function sends the Assignment's data to the
            // given output stream with appropriate text formatting.


        const bool operator<(const Assignment& rhs) const
            {return (dueDate < rhs.obtainDueDate());}
        // Preconditions: Two assignments need to be compared based on their
            // due dates, for the purpose of sorting by due date.
        // Postconditions: This function returns true if the left-hand-side
            // Assignment's due date is earlier than the right-hand-side
            // Assignment's due date, and it returns false otherwise.


        const bool operator==(const Assignment& rhs) const
            {return (dueDate == rhs.obtainDueDate());}
        // Preconditions: Two Assignments need to be evaluated for having the
            // same due date.
        // Postconditions: This function returns true if both given Assignments
            // have the same due date, and false otherwise.


        const bool hasInvalidDate() const {return invalidDate;}
        // Preconditions: An Assignment needs to be evaluated to determine
            // whether it was given an invalid date as input data.
        // Postconditions: This function reads the flag variable that is set
            // when an Assignment is given an invalid date, and it returns
            // the appropriate Boolean value.


    private:

        Date assignedDate;
        Date dueDate;
        Date completedDate;
        string description;
        statusType status;
        bool invalidDate = false;
            // All dates are valid until an invalid date is input.

};