#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_records.h"

// Function prototype for searchStudentIndex
int searchStudentIndex(const Student **students, int numStudents, int rollNumber);

void addStudent(Student ***students, int *numStudents) {
    *students = realloc(*students, (*numStudents + 1) * sizeof(Student *));
    if (*students == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    (*students)[*numStudents] = malloc(sizeof(Student));
    if ((*students)[*numStudents] == NULL) {
        printf("Memory allocation for student failed.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%49s", (*students)[*numStudents]->name);

    printf("Enter roll number: ");
    while (scanf("%d", &(*students)[*numStudents]->rollNumber) != 1) {
        printf("Invalid input. Please enter a valid roll number: ");
        while (getchar() != '\n');
    }

    printf("Enter marks: ");
    while (scanf("%f", &(*students)[*numStudents]->marks) != 1) {
        printf("Invalid input. Please enter valid marks: ");
        while (getchar() != '\n');
    }

    (*numStudents)++;
    printf("Student added successfully.\n");
}

void displayStudents(const Student **students, int numStudents) {
    if (numStudents == 0) {
        printf("No students found.\n");
        return;
    }

    printf("List of Students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Roll Number: %d, Marks: %.2f\n", 
               students[i]->name, 
               students[i]->rollNumber, 
               students[i]->marks);
    }
}

void deleteStudent(Student ***students, int *numStudents, int index) {
    if (index < 0 || index >= *numStudents) {
        printf("Invalid index. Student not found.\n");
        return;
    }

    free((*students)[index]);

    for (int i = index; i < *numStudents - 1; i++) {
        (*students)[i] = (*students)[i + 1];
    }

    *students = realloc(*students, (*numStudents - 1) * sizeof(Student *));
    if (*students == NULL && *numStudents > 1) {
        printf("Memory reallocation failed.\n");
        return;
    }

    (*numStudents)--;
    printf("Student deleted successfully.\n");
}

const Student *searchStudent(const Student **students, int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            return students[i]; // Return the pointer to the found student
        }
    }
    return NULL;  // Student not found
}

int searchStudentIndex(const Student **students, int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            return i; // Return the index of the found student
        }
    }
    return -1;  // Student not found
}

// Additional functions (modifyStudent, saveStudentsToFile, loadStudentsFromFile, sortStudentsByMarks, calculateAverageMarks) would go here...
