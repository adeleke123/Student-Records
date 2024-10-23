#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include this for string manipulation functions
#include "student_records.h"

/**
 * addStudent - Adds a new student to the array.
 *
 * @students: A pointer to an array of Student pointers.
 * @numStudents: A pointer to the current number of students.
 */
void addStudent(Student ***students, int *numStudents) {
    // Reallocate memory for the student array to add a new student
    Student **temp = realloc(*students, (*numStudents + 1) * sizeof(Student *));
    
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);  // Exit if memory allocation fails
    }
    *students = temp;

    // Allocate memory for the new student
    (*students)[*numStudents] = malloc(sizeof(Student));
    if ((*students)[*numStudents] == NULL) {
        printf("Memory allocation for new student failed.\n");
        exit(1);  // Exit if memory allocation fails
    }

    printf("Enter name: "); // Get student information from the user
    scanf("%49s", (*students)[*numStudents]->name); // Limit input to avoid buffer overflow
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

    (*numStudents)++;  // Increment the number of students
}

/**
 * displayStudents - Displays the information of all students.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 */
void displayStudents(const Student **students, int numStudents) {
    printf("\nStudent Records:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s\n", students[i]->name);
        printf("Roll Number: %d\n", students[i]->rollNumber);
        printf("Marks: %.2f\n\n", students[i]->marks);
    }
}

/**
 * searchStudent - Searches for a student by roll number.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 * @rollNumber: The roll number to search for.
 * Return: A pointer to the found Student or NULL if not found.
 */
const Student *searchStudent(const Student **students, int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            return students[i]; // Return the pointer to the found student
        }
    }
    return NULL;  // Student not found
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
    while (scanf("%d", &rollNumber) != 1) {
        printf("Invalid input. Please enter a valid roll number: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    const Student *foundStudent = searchStudent((const Student **)students, numStudents, rollNumber);

    if (foundStudent != NULL) {
        // Cast away const to modify the student's information
        Student *modifiableStudent = (Student *)foundStudent;

        printf("Enter new name: ");
        scanf("%49s", modifiableStudent->name); // Limit input to avoid buffer overflow

        printf("Enter new roll number: ");
        while (scanf("%d", &modifiableStudent->rollNumber) != 1) {
            printf("Invalid input. Please enter a valid roll number: ");
            while (getchar() != '\n'); // Clear the input buffer
        }

        printf("Enter new marks: ");
        while (scanf("%f", &modifiableStudent->marks) != 1) {
            printf("Invalid input. Please enter valid marks: ");
            while (getchar() != '\n'); // Clear the input buffer
        }

        printf("Student information modified.\n");
    } else {
        printf("Student not found.\n");
    }
}

/**
 * deleteStudent - Deletes a student from the array.
 *
 * @students: A pointer to a dynamically allocated array of Student pointers.
 * @numStudents: A pointer to the current number of students.
 * @index: The index of the student to delete.
 */
void deleteStudent(Student ***students, int *numStudents, int index) {
    if (index < 0 || index >= *numStudents) {
        printf("Invalid index.\n");
        return;
    }

    // Free memory for the deleted student
    free((*students)[index]);

    // Shift elements after the deleted index
    for (int i = index; i < *numStudents - 1; i++) {
        (*students)[i] = (*students)[i + 1];  // Shift elements
    }

    // Optionally, shrink the memory for the array
    if (*numStudents > 1) {
        Student **temp = realloc(*students, (*numStudents - 1) * sizeof(Student *));
        if (temp == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
        *students = temp;
    }

    (*numStudents)--;  // Decrement the number of students
}
