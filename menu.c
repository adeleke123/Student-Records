#include <stdio.h>
#include "menu.h"
#include "student_operations.h"

void handleUserChoice(int choice, Student **students, int *numStudents) {
    switch (choice) {
        case 1:
            // Code to add a student
            break;
        case 2:
            searchAndDisplayStudent(students, *numStudents);
            break;
        case 3:
            modifyStudent(students, *numStudents);
            break;
        case 4:
            // Code to display all students
            break;
        case 5:
            // Code for other operations
            break;
        case 6:
            printf("Exiting program...\n");
            exit(0); // Exit the program
        case 7: // Save students to file
            saveStudentsToFile(students, *numStudents, "students.txt");
            break;
        case 8: // Load students from file
            loadStudentsFromFile(&students, numStudents, "students.txt");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}
