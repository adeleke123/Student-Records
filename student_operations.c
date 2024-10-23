#include <stdio.h>
#include "student_operations.h"
#include "student_records.h"

/**
 * searchAndDisplayStudent - Searches for a student information by roll.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */

void searchAndDisplayStudent(Student **students, int numStudents) {
    int rollNumber;

    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);

    Student *foundStudent = searchStudent(students, numStudents, rollNumber);

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
    scanf("%d", &rollNumber);

    Student *foundStudent = searchStudent(students, numStudents, rollNumber);

    if (foundStudent != NULL) {
        modifyStudentInfo(foundStudent);
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

void deleteStudent(Student **students, int *numStudents, int index) {
    // Shift elements after the deleted index
    for (int i = index; i < *numStudents - 1; i++) {
        students[i] = students[i + 1];
    }

    // Free memory for the deleted student
    free(students[*numStudents - 1]);

    // Decrement the number of students
    (*numStudents)--;

    printf("Student deleted.\n");
}

/**
 * displayStudentInfo - Displays the information of a student.
 *
 * @student: A pointer to the student to display.
 */

void displayStudentInfo(Student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Marks: %.2f\n", student->marks);
}
