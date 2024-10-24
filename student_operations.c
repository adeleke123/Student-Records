#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_operations.h"

// Function to save student records to a file
void saveStudentsToFile(const Student **students, int numStudents, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s %d %.2f\n", students[i]->name, students[i]->rollNumber, students[i]->marks);
    }

    fclose(file);
    printf("Student records saved to %s successfully.\n", filename);
}

// Function to load student records from a file
void loadStudentsFromFile(Student ***students, int *numStudents, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    *numStudents = 0;  // Reset the number of students

    char name[50];
    int rollNumber;
    float marks;

    while (fscanf(file, "%s %d %f", name, &rollNumber, &marks) == 3) {
        // Allocate memory for a new student
        (*students)[*numStudents] = malloc(sizeof(Student));
        if (!(*students)[*numStudents]) {
            perror("Memory allocation failed");
            fclose(file);
            return;
        }

        // Copy student data
        strcpy((*students)[*numStudents]->name, name);
        (*students)[*numStudents]->rollNumber = rollNumber;
        (*students)[*numStudents]->marks = marks;
        (*numStudents)++;
    }

    fclose(file);
    printf("Student records loaded from %s successfully.\n", filename);
}

// Function to modify a student record
void modifyStudent(Student **students, int numStudents) {
    int rollNumber;
    printf("Enter the roll number of the student to modify: ");
    scanf("%d", &rollNumber);

    int index = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student with roll number %d not found.\n", rollNumber);
        return;
    }

    // Modify student details
    printf("Enter new name: ");
    scanf("%s", students[index]->name);
    printf("Enter new marks: ");
    scanf("%f", &students[index]->marks);

    printf("Student record updated successfully.\n");
}

// Function to search and display a student by roll number
void searchAndDisplayStudent(Student **students, int numStudents) {
    int rollNumber;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            printf("Student found:\n");
            printf("Name: %s\n", students[i]->name);
            printf("Roll Number: %d\n", students[i]->rollNumber);
            printf("Marks: %.2f\n", students[i]->marks);
            return;
        }
    }

    printf("Student with roll number %d not found.\n", rollNumber);
}
