// Alfred Ledgin
// 10/3/2015
// CS 303
// Project 1

#pragma once
#include <iostream>
#include <list>
#include "Date.h"
#include "Assignment.h"
using namespace std;

class AssignmentList
// This class is a special container designed for Assignment objects.
    // It places assignments into C++-standard doubly linked lists and
    // includes appropriate functions for managing assignments within the list.
    // Since this class uses Assignment objects and Date objects, both the
    // Assignment class ("Assignment.h") and Dr. Mohammad Kuhail's Date class
    // ("Date.h") are required in order to use this class.
{

    public:

        const ostream& displayAll(ostream& output);
        // Preconditions: All assignments within the list need to be displayed.
        // Postconditions: This function displays each assignment, all of which
            // are sorted by due date.


        bool addAssignment(Assignment inputAssignment);
        // Preconditions: An assignment needs to be added to the list.
        // Postconditions: This function adds a given assignment to the list
            // if its dates are valid, if its due date is later than its
            // assigned date, and if the list does not already have an
            // assignment with the same assigned date.


        bool completeAssignment(string inputAssignedDate,
            string inputCompletedDate, AssignmentList& inputCompletedList);
        // Preconditions: An assignment in the list needs to be completed.
        // Postconditions: This function finds an assignment in the list
            // based on the given assigned date, it changes that assignment's
            // status to "completed" or "late" (based on the completed and due
            // dates), and it then moves the assignment to a given list of
            // completed assignments.


        bool editAssignment(string inputAssignedDate,
            string desiredDescription = "",
            string desiredDueDate = "");
        // Preconditions: The due date or description of an assignment needs to
            // be edited.
        // Postconditions: This function finds an assignment in the list
            // based on the given assigned date, and it changes the
            // assignment's description and due date to the given values,
            // provided the given values are not empty strings.  Changing one
            // value without changing the other is achieved by passing an
            // empty string for the value that is not to be changed.
            // This function will only edit an assignment with the "assigned"
            // status.


        const int countLateAssignments() const {return lateAssignments;}
        // Preconditions: The number of late assignments in the list needs to
            // be counted.
        // Postconditions: Late assignments are counted as soon as their
            // presence is known.  This function simply returns the number
            // of late assignments that has already been counted.


        int obtainSize() {return theData.size();}
        // Preconditions: The number of assignments in the list is needed.
        // Postconditions: This function returns the size of the list.


    private:


        bool find(Assignment inputAssignment);
        // Preconditions: An assignment needs to be evaluated to determine
            // whether an assignment with the same assigned date exists within
            // the list.
        // Postconditions: This function iterates through the list and returns
            // true if an assignment with the same assigned date as the given
            // assignment exists within the list, and it returns false
            // otherwise.


        void insert(Assignment inputAssignment);
        // Preconditions: An assignment needs to be inserted into the list
            // according to its due date.
        // Postconditions: This function inserts a given assignment into the
            // list, before the assignment with the next due date.


        list<Assignment> theData;
        list<Assignment>::iterator AssignmentIterator;
        list<Assignment>::const_iterator constAssignmentIterator;
        int lateAssignments;

};