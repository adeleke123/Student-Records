#include <stdio.h>
#include <stdlib.h>
#include "student_operations.h"
#include "student_records.h"

/**
 * searchAndDisplayStudent - Searches for a student by roll number and displays their information.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */
void searchAndDisplayStudent(Student **students, int numStudents) {
    int rollNumber;

    printf("Enter roll number to search: ");
    if (scanf("%d", &rollNumber) != 1) {
        printf("Invalid input. Please enter a valid roll number.\n");
        while (getchar() != '\n'); // Clear the input buffer
        return;
    }

    // Search for the student
    Student *foundStudent = searchStudent((const Student **)students, numStudents, rollNumber); // Cast to const to match function signature

    // Display the student's information
    if (foundStudent != NULL) {
        displayStudentInfo(foundStudent);
    } else {
        printf("Student not found.\n");
    }
}

/**
 * modifyStudent - Modifies the information of a student.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */
void modifyStudent(Student **students, int numStudents) {
    int rollNumber;

    printf("Enter roll number to modify: ");
    if (scanf("%d", &rollNumber) != 1) {
        printf("Invalid input. Please enter a valid roll number.\n");
        while (getchar() != '\n'); // Clear the input buffer
        return;
    }

    // Get the index of the student to modify
    int index = searchStudentIndex((const Student **)students, numStudents, rollNumber); // Get the index

    if (index != -1) {
        // Prompt for new information
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

        printf("Student information modified successfully.\n");
    } else {
        printf("Student not found.\n");
    }
}

/**
 * displayStudentInfo - Displays the information of a student.
 *
 * @student: A pointer to the student to display.
 */
void displayStudentInfo(const Student *student) { // Use const to indicate the student won't be modified
    if (student != NULL) {
        printf("Name: %s\n", student->name);
        printf("Roll Number: %d\n", student->rollNumber);
        printf("Marks: %.2f\n", student->marks);
    } else {
        printf("No student information available.\n");
    }
}
