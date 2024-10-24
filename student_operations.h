#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_operations.h"

// Modify the student details by roll number
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

// Save the student records to a file
void saveStudentsToFile(Student **students, int numStudents, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s %d %.2f\n", students[i]->name, students[i]->rollNumber, students[i]->marks);
    }

    fclose(file);
    printf("Student records saved successfully to %s.\n", filename);
}

// Load the student records from a file
void loadStudentsFromFile(Student ***students, int *numStudents, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    *numStudents = 0;
    *students = NULL;

    // Allocate memory for temporary storage of students
    Student *tempStudents = malloc(sizeof(Student) * 100); // Assuming max 100 students
    if (!tempStudents) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return;
    }

    // Read student records from file
    while (fscanf(file, "%49s %d %f", tempStudents[*numStudents].name, &tempStudents[*numStudents].rollNumber, &tempStudents[*numStudents].marks) != EOF) {
        (*numStudents)++;
    }

    *students = realloc(tempStudents, sizeof(Student) * (*numStudents)); // Resize to the actual number of students
    fclose(file);
    printf("Student records loaded successfully from %s.\n", filename);
}

// Other functions like searchAndDisplayStudent and displayStudentInfo would go here...
