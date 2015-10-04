// Alfred Ledgin
// 10/3/2015
// CS 303
// Project 1

#pragma once
#include <iostream>
#include "StringTokenizer.h"
#include "Assignment.h"
#include "AssignmentList.h"
using namespace std;

class AssignmentFile
// This is a class of objects designed for the purpose of reading a text file
    // and converting it into a list of assignments, as well outputting a list
    // of assignments to a text file.  It is the interface between saved
    // assignment data (stored in a text file) and a list of assignments
    // that is being processed.  Each AssignmentFile has two corresponding
    // lists of assignments--one for uncompleted assignments and another for
    // completed assignments.  Use of this class requires the Assignment class
    // ("Assignment.h"), the AssignmentList class ("AssignmentList.h"), and the
    // StringTokenizer ("StringTokenizer.h") class written by
    // Dr. Mohammad Kuhail.
{

    public:

        bool read(istream& input);
        // Preconditions: A text file needs to be read so that its data can be
            // converted to a list or lists of assignments.
        // Postconditions: This function reads a text file and parses each line
            // of text in order to build the needed list(s) of assignments.


        bool write(ostream& output);
        // Preconditions: Data from the lists of assignments need to be output
            // to a text file.
        // Postconditions: This function outputs each assignment from the two
            // lists of assignments, to the given output stream, assumed to
            // point to a text file.


        int convertStatus(string inputStatus);
        // Preconditions: A string indicating an assignment's status needs to
            // read and converted to the corresponding integer representation
            // of an assignment's status.
        // Postconditions: This function evaluates the string indicating an
            // assignment's status, and it sets that assignment's status
            // to one of three available options, based on the given string.

        
        AssignmentList uncompleted;
        AssignmentList completed;

};