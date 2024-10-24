#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_operations.h"

// Function to search and display a student's information
void searchAndDisplayStudent(Student **students, int numStudents) {
    int rollNumber;
    printf("Enter roll number to search: ");
    
    // Ensure valid input for roll number
    while (scanf("%d", &rollNumber) != 1) {
        printf("Invalid input. Please enter a valid roll number: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    const Student *student = searchStudent((const Student **)students, numStudents, rollNumber);
    if (student) {
        displayStudentInfo(student);
    } else {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

// Function to display a student's information
void displayStudentInfo(const Student *student) {
    printf("Student Info:\n");
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Marks: %.2f\n", student->marks);
}

// Function to modify a student's record
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

// Other functions like saveStudentsToFile, loadStudentsFromFile, etc. would go here...
