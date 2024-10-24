#include <stdio.h>
#include "menu.h"
#include "student_operations.h"

// Function to display the menu options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Student\n");
    printf("2. Search and Display Student\n");
    printf("3. Modify Student\n");
    printf("4. Display All Students\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
    printf("7. Save Students to File\n");
    printf("8. Load Students from File\n");
    printf("Please enter your choice: ");
}

/**
 * handleUserChoice - Handles user choice from the menu.
 *
 * @choice: The choice made by the user.
 * @students: An array of Student pointers.
 * @numStudents: A pointer to the number of students.
 */
void handleUserChoice(int choice, Student ***students, int *numStudents) {
    switch (choice) {
        case 1:
            addStudent(students, numStudents); // Adding a student
            break;
        case 2:
            searchAndDisplayStudent(*students, *numStudents); // Search and display student
            break;
        case 3:
            modifyStudent(*students, *numStudents); // Modify student record
            break;
        case 4:
            displayStudents((const Student **)(*students), *numStudents); // Display all students
            break;
        case 5: {
            int rollNumber;
            printf("Enter roll number to delete: ");
            if (scanf("%d", &rollNumber) != 1) {
                printf("Invalid input. Please enter a valid roll number.\n");
                while (getchar() != '\n'); // Clear the input buffer
                break;
            }
            int index = searchStudentIndex((const Student **)(*students), *numStudents, rollNumber);
            if (index != -1) {
                deleteStudent(students, numStudents, index); // Delete student by index
            } else {
                printf("Student not found.\n");
            }
            break;
        }
        case 6:
            printf("Exiting program...\n");
            break; // Exit will be handled in main loop
        case 7:
            saveStudentsToFile(*students, *numStudents, "students.txt"); // Save students to file
            break;
        case 8:
            loadStudentsFromFile(students, numStudents, "students.txt"); // Load students from file
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}
