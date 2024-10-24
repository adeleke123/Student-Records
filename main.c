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
        free(students[i]);  // Free each student
    }
    free(students);  // Free the array of pointers
}

/**
 * checkPassOrFail - Checks if a student passed or failed based on marks.
 * 
 * @marks: The marks obtained by the student.
 * Return: "Pass" if marks are >= 40, otherwise "Fail".
 */
const char* checkPassOrFail(float marks) {
    return marks >= 40.0 ? "Pass" : "Fail";
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
    scanf("%49s", userName); // Limit input to avoid buffer overflow
    printf("Hello, %s! Let's manage student records.\n", userName);

    // Main program loop
    while (1) {
        displayMenu();
        int choice = getUserChoice(); // Function to get user choice

        switch (choice) {
            case 1:
                if (numStudents < maxStudents) {
                    addStudent(&students, &numStudents); // Add new student
                    printf("Student has %s\n", checkPassOrFail(students[numStudents - 1]->marks)); // Check pass/fail
                } else {
                    printf("Student limit reached. Cannot add more students.\n");
                }
                break;
            case 2:
                displayStudents((const Student **)students, numStudents); // Display all students
                break;
            case 3:
                searchAndDisplayStudent(students, numStudents); // Search and display student by roll number
                break;
            case 4:
                modifyStudent(students, numStudents); // Modify student record
                break;
            case 5: {
                int rollNumber;
                printf("Enter roll number to delete: ");
                if (scanf("%d", &rollNumber) != 1) {
                    printf("Invalid input. Please enter a valid roll number.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                int index = searchStudentIndex((const Student **)students, numStudents, rollNumber);
                if (index != -1) {
                    deleteStudent(&students, &numStudents, index); // Delete student by index
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 6:
                // Calculate and display average marks
                if (numStudents > 0) {
                    float average = calculateAverageMarks((const Student **)students, numStudents);
                    printf("The average marks of all students is: %.2f\n", average);
                } else {
                    printf("No students to calculate average.\n");
                }
                break;
            case 7:
                // Sort students by marks
                printf("Sort by marks in (1) Ascending or (2) Descending order? ");
                int sortOrder;
                scanf("%d", &sortOrder);
                sortStudentsByMarks(students, numStudents, sortOrder == 1 ? 1 : 0);
                printf("Students sorted by marks.\n");
                break;
            case 8:
                // Save student records to file
                saveStudentsToFile(students, numStudents, "students.txt");
                break; // The success message will be handled in the function
            case 9:
                // Load student records from file
                loadStudentsFromFile(&students, &numStudents, "students.txt");
                break; // The success message will be handled in the function
            case 10:
                freeMemory(students, numStudents); // Free allocated memory
                printf("Exiting the program. Goodbye!\n");
                return EXIT_SUCCESS; // Exit successfully
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    // Memory cleanup is handled in case of exit
    freeMemory(students, numStudents); // Ensuring memory is freed on exit
    return 0;
}
