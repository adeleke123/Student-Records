#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include this for string manipulation functions
#include "student_records.h"

// Function prototype
int searchStudentIndex(const Student **students, int numStudents, int rollNumber);

/**
 * modifyStudent - Modifies the information of a student.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */
void modifyStudent(Student **students, int numStudents) {
    int rollNumber;

    printf("Enter roll number to modify: ");
    while (scanf("%d", &rollNumber) != 1) {
        printf("Invalid input. Please enter a valid roll number: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    int index = searchStudentIndex((const Student **)students, numStudents, rollNumber); // Get the index

    if (index != -1) {
        printf("Enter new name: ");
        scanf("%49s", students[index]->name); // Modify directly using the index

        printf("Enter new roll number: ");
        while (scanf("%d", &students[index]->rollNumber) != 1) {
            printf("Invalid input. Please enter a valid roll number: ");
            while (getchar() != '\n'); // Clear the input buffer
        }

        printf("Enter new marks: ");
        while (scanf("%f", &students[index]->marks) != 1) {
            printf("Invalid input. Please enter valid marks: ");
            while (getchar() != '\n'); // Clear the input buffer
        }

        printf("Student information modified.\n");
    } else {
        printf("Student not found.\n");
    }
}
