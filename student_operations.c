#include <stdio.h>
#include <stdlib.h> // Include this for malloc, free, realloc
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

    Student *foundStudent = searchStudent((const Student **)students, numStudents, rollNumber); // Cast to const to match function signature

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

    Student *foundStudent = searchStudent((const Student **)students, numStudents, rollNumber); // Cast to const to match function signature

    if (foundStudent != NULL) {
        // Assuming modifyStudentInfo is a function that modifies the student's info.
        modifyStudentInfo(foundStudent); // You need to define this function
        printf("Student information modified.\n");
    } else {
        printf("Student not found.\n");
    }
}

/**
 * deleteStudent - Deletes a student from the array.
 *
 * @students: An array of Student pointers.
 * @numStudents: A pointer to the number of students in the array.
 * @index: The index of the student to delete.
 */
void deleteStudent(Student ***students, int *numStudents, int index) { // Updated signature
    // Ensure index is valid
    if (index < 0 || index >= *numStudents) {
        printf("Invalid index. No student deleted.\n");
        return;
    }

    // Free memory for the deleted student
    free((*students)[index]);

    // Shift elements after the deleted index
    for (int i = index; i < *numStudents - 1; i++) {
        (*students)[i] = (*students)[i + 1];
    }

    // Decrement the number of students
    (*students) = realloc(*students, (*numStudents - 1) * sizeof(Student *)); // Adjust memory allocation
    if (*students == NULL && *numStudents > 1) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }

    (*numStudents)--; // Decrement the number of students
    printf("Student deleted.\n");
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
