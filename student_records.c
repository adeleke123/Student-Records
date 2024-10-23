#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_records.h"

// Function prototype
int searchStudentIndex(const Student **students, int numStudents, int rollNumber);

/**
 * addStudent - Adds a new student to the array.
 *
 * @students: A pointer to an array of Student pointers.
 * @numStudents: A pointer to the number of students in the array.
 */
void addStudent(Student ***students, int *numStudents) {
    // Increase the size of the array to accommodate a new student
    *students = realloc(*students, (*numStudents + 1) * sizeof(Student *));
    if (*students == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Allocate memory for the new student
    (*students)[*numStudents] = malloc(sizeof(Student));
    if ((*students)[*numStudents] == NULL) {
        printf("Memory allocation for student failed.\n");
        return;
    }

    // Get student information
    printf("Enter name: ");
    scanf("%49s", (*students)[*numStudents]->name); // Limit input to 49 characters

    printf("Enter roll number: ");
    while (scanf("%d", &(*students)[*numStudents]->rollNumber) != 1) {
        printf("Invalid input. Please enter a valid roll number: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    printf("Enter marks: ");
    while (scanf("%f", &(*students)[*numStudents]->marks) != 1) {
        printf("Invalid input. Please enter valid marks: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    // Increment the student count
    (*numStudents)++;
    printf("Student added successfully.\n");
}

/**
 * displayStudents - Displays the list of students.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */
void displayStudents(const Student **students, int numStudents) {
    printf("List of Students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Roll Number: %d, Marks: %.2f\n", 
               students[i]->name, 
               students[i]->rollNumber, 
               students[i]->marks);
    }
}

/**
 * deleteStudent - Deletes a student from the array.
 *
 * @students: A pointer to an array of Student pointers.
 * @numStudents: A pointer to the number of students in the array.
 * @index: The index of the student to delete.
 */
void deleteStudent(Student ***students, int *numStudents, int index) {
    if (index < 0 || index >= *numStudents) {
        printf("Invalid index. Student not found.\n");
        return;
    }

    // Free the memory of the student to be deleted
    free((*students)[index]);

    // Shift students down to fill the gap
    for (int i = index; i < *numStudents - 1; i++) {
        (*students)[i] = (*students)[i + 1];
    }

    // Decrease the size of the array
    *students = realloc(*students, (*numStudents - 1) * sizeof(Student *));
    if (*students == NULL && *numStudents > 1) {
        printf("Memory reallocation failed.\n");
        return;
    }

    // Decrement the student count
    (*numStudents)--;
    printf("Student deleted successfully.\n");
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
