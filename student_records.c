#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include this for string manipulation functions
#include "student_records.h"

// Function prototype
int searchStudentIndex(const Student **students, int numStudents, int rollNumber);

/**
 * addStudent - Adds a new student to the array.
 *
 * @students: An array of Student pointers.
 * @numStudents: A pointer to the number of students in the array.
 */
void addStudent(Student ***students, int *numStudents) {
    // Implementation for adding a student...
}

/**
 * displayStudents - Displays the list of students.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */
void displayStudents(const Student **students, int numStudents) {
    // Implementation for displaying students...
}

/**
 * deleteStudent - Deletes a student from the array.
 *
 * @students: An array of Student pointers.
 * @numStudents: A pointer to the number of students in the array.
 * @index: The index of the student to delete.
 */
void deleteStudent(Student ***students, int *numStudents, int index) {
    // Implementation for deleting a student...
}

/**
 * searchStudentIndex - Searches for a student by roll number and returns the index.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 * @rollNumber: The roll number to search for.
 * Return: The index of the found student, or -1 if not found.
 */
int searchStudentIndex(const Student **students, int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            return i; // Return the index of the found student
        }
    }
    return -1;  // Student not found
}
