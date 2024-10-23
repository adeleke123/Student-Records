#include "student_records.h"
#include "menu.h"
#include "student_operations.h"

/**
 * freeMemory - freememory allocation
 *
 * @students: an Array of Students Pointers.
 * @numStudents: The number of students in tha array
 */

void freeMemory(Student **students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        free(students[i]);
    }
    free(students);
}

/**
 * main - Entry point
 * Return: sucess
 */

int main(void) {
    Student **students = NULL;
    int numStudents = 0;
    int rollNumber; // Declare rollNumber here

    while (1) {
        displayMenu();

        int choice = getUserChoice();

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
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
            case 5:
                // Calculate the index of the student to delete
                int index = searchStudentIndex(students, numStudents, rollNumber);
                if (index != -1) {
                    deleteStudent(students, &numStudents, index);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 6:
                freeMemory(students, numStudents);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
