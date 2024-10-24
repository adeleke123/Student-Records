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

// Other functions related to student operations can be added below
// If the modifyStudent or other related functions are here, you can add them
// For example, here's a modifyStudent function template:

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
