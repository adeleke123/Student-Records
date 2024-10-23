#include <stdio.h>
#include <stdlib.h>
#include "student_records.h"
#include "menu.h"
#include "student_operations.h"

/**
 * freeMemory - Frees allocated memory for student records.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */
void freeMemory(Student **students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        free(students[i]);
    }
    free(students);
}

/**
 * main - Entry point for the Student Record System.
 * Return: Success status.
 */
int main(void) {
    // Allocate memory for a maximum number of students
    int maxStudents = 100;
    Student **students = malloc(maxStudents * sizeof(Student *));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE; // Exit if memory allocation fails
    }

    int numStudents = 0; // Initialize student count

    // User greeting
    printf("Welcome to the Student Record System!\n");
    printf("Please enter your name: ");
    char userName[50];
    scanf("%s", userName);
    printf("Hello, %s! Let's manage student records.\n", userName);

    // Main program loop
    while (1) {
        displayMenu();
        int choice = getUserChoice();

        switch (choice) {
            case 1:
                if (numStudents < maxStudents) {
                    addStudent(students, &numStudents);
                } else {
                    printf("Student limit reached. Cannot add more students.\n");
                }
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3:
                searchAndDisplayStudent(students, numStudents);
                break;
            case 4:
                modifyStudent(students, numStudents);
                break;
            case 5: {
                int rollNumber;
                printf("Enter roll number to delete: ");
                scanf("%d", &rollNumber);
                int index = searchStudentIndex(students, numStudents, rollNumber);
                if (index != -1) {
                    deleteStudent(students, &numStudents, index);
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 6:
                freeMemory(students, numStudents);
                printf("Exiting the program. Goodbye!\n");
                return EXIT_SUCCESS; // Exit successfully
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    // Memory cleanup is handled in case of exit
    return 0;
}
