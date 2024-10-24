#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_operations.h"

// Function to search for a student by roll number
const Student *searchStudent(const Student **students, int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            return students[i];
        }
    }
    return NULL; // Student not found
}

// Function to search and display student information
void searchAndDisplayStudent(Student **students, int numStudents) {
    int rollNumber;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);

    const Student *student = searchStudent((const Student **)students, numStudents, rollNumber);
    if (student) {
        displayStudentInfo(student);
    } else {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

// Function to display student information
void displayStudentInfo(const Student *student) {
    printf("Student Info:\n");
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Marks: %.2f\n", student->marks);
}

// Function to modify student information
void modifyStudent(Student **students, int numStudents) {
    int rollNumber;
    printf("Enter roll number of the student to modify: ");
    
    // Ensure valid input for roll number
    while (scanf("%d", &rollNumber) != 1) {
        printf("Invalid input. Please enter a valid roll number: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    int index = searchStudentIndex((const Student **)students, numStudents, rollNumber);
    if (index == -1) {
        printf("Student with roll number %d not found.\n", rollNumber);
        return;
    }

    // Display current student details
    printf("Modifying details for student: %s\n", students[index]->name);
    printf("Current marks: %.2f\n", students[index]->marks);
    
    printf("Enter new name (max 49 characters): ");
    scanf("%49s", students[index]->name);  // Limit input to avoid overflow

    printf("Enter new marks: ");
    while (scanf("%f", &students[index]->marks) != 1) {
        printf("Invalid input. Please enter valid marks: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    printf("Student details updated successfully.\n");
}

// Function to save student records to a file
void saveStudentsToFile(Student **students, int numStudents, const char *filename) {
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

    // Count the number of students in the file
    *numStudents = 0;
    while (!feof(file)) {
        char name[50];
        int rollNumber;
        float marks;
        if (fscanf(file, "%49s %d %f", name, &rollNumber, &marks) == 3) {
            (*numStudents)++;
        }
    }

    // Allocate memory for students
    *students = malloc(*numStudents * sizeof(Student *));
    fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning

    for (int i = 0; i < *numStudents; i++) {
        (*students)[i] = malloc(sizeof(Student)); // Allocate memory for each Student
        fscanf(file, "%49s %d %f", (*students)[i]->name, &(*students)[i]->rollNumber, &(*students)[i]->marks);
    }

    fclose(file);
    printf("Student records loaded from %s successfully.\n", filename);
}
