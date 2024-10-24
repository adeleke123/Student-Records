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

    // Count the number of students in the file
    *numStudents = 0;
    char line[100]; // Buffer to read each line
    while (fgets(line, sizeof(line), file)) {
        if (strlen(line) > 1) { // Ignore empty lines
            (*numStudents)++;
        }
    }

    // Allocate memory for students
    *students = malloc(*numStudents * sizeof(Student *));
    if (!*students) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning

    for (int i = 0; i < *numStudents; i++) {
        (*students)[i] = malloc(sizeof(Student));
        if (!(*students)[i]) {
            perror("Memory allocation failed for student");
            // Free previously allocated memory in case of failure
            for (int j = 0; j < i; j++) {
                free((*students)[j]);
            }
            free(*students);
            fclose(file);
            return;
        }
        fscanf(file, "%49s %d %f", (*students)[i]->name, &(*students)[i]->rollNumber, &(*students)[i]->marks);
    }

    fclose(file);
    printf("Student records loaded from %s successfully.\n", filename);
}
