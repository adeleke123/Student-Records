#include <stdio.h>
#include "menu.h"
#include "student_operations.h"
#include "student_records.h"

/**
 * displayMenu - Displays the main menu options to the user.
 */
void displayMenu(void) {
    printf("\n=== Student Record System ===\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student\n");
    printf("4. Modify Student\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
}

/**
 * getUserChoice - Prompts the user to enter their choice and returns it.
 *
 * Return: The user's choice as an integer.
 */
int getUserChoice(void) {
    int choice;

    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1) {
        printf("Invalid input! Please enter a number: ");
        while (getchar() != '\n'); // Clear invalid input
    }

    return choice;
}

/**
 * handleUserChoice - Handles the user's choice from the menu.
 *
 * @students: An array of Student pointers.
 * @numStudents: A pointer to the number of students in the array.
 */
void handleUserChoice(Student ***students, int *numStudents) {
    int choice;

    do {
        displayMenu();
        choice = getUserChoice();

        switch (choice) {
            case 1:
                addStudent(students, numStudents);
                break;
            case 2:
                displayStudents((const Student **)students, *numStudents);
                break;
            case 3:
                searchAndDisplayStudent((const Student **)students, *numStudents);
                break;
            case 4:
                modifyStudent(*students, *numStudents);
                break;
            case 5: {
                int rollNumber;
                printf("Enter roll number to delete: ");
                scanf("%d", &rollNumber);
                int index = searchStudentIndex((const Student **)students, *numStudents, rollNumber);
                if (index != -1) {
                    deleteStudent(students, numStudents, index);
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
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
