#include <stdio.h>
#include "menu.h"
#include "student_operations.h"

// Function to display the menu options
void displayMenu() {
    printf("\n=== Student Record System ===\n");
    printf("1. Add Student\n");
    printf("2. Search and Display Student\n");
    printf("3. Modify Student\n");
    printf("4. Display All Students\n");
    printf("5. Delete Student\n");
    printf("6. Calculate Average Marks\n");
    printf("7. Sort Students\n");
    printf("8. Save Students to File\n");
    printf("9. Load Students from File\n");
    printf("10. Exit\n");
    printf("Please enter your choice: ");
}

// Function to get the user's choice
int getUserChoice() {
    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n');  // Clear input buffer
        return -1;  // Invalid choice
    }
    return choice;
}

// Function to handle the user's choice
void handleUserChoice(int choice, Student ***students, int *numStudents) {
    switch (choice) {
        case 1:
            addStudent(students, numStudents);
            break;
        case 2:
            searchAndDisplayStudent(*students, *numStudents);
            break;
        case 3:
            modifyStudent(*students, *numStudents);
            break;
        case 4:
            displayStudents((const Student **)(*students), *numStudents);
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
                deleteStudent(students, numStudents, index);
            } else {
                printf("Student not found.\n");
            }
            break;
        }
        case 6:
            if (*numStudents > 0) {
                float average = calculateAverageMarks((const Student **)(*students), *numStudents);
                printf("The average marks of all students is: %.2f\n", average);
            } else {
                printf("No students to calculate average.\n");
            }
            break;
        case 7: {
            printf("Sort by marks in (1) Ascending or (2) Descending order? ");
            int sortOrder;
            scanf("%d", &sortOrder);
            sortStudentsByMarks(*students, *numStudents, sortOrder == 1 ? 1 : 0);
            printf("Students sorted by marks.\n");
            break;
        }
        case 8:
            saveStudentsToFile((const Student **)(*students), *numStudents, "students.txt");
            printf("Student records saved to 'students.txt'.\n");
            break;
        case 9:
            loadStudentsFromFile(students, numStudents, "students.txt");
            printf("Student records loaded from 'students.txt'.\n");
            break;
        case 10:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}
