#include <stdio.h>
#include <stdlib.h>
#include "student_operations.h"

// Existing functions...

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
        (*students)[i] = malloc(sizeof(Student));
        fscanf(file, "%49s %d %f", (*students)[i]->name, &(*students)[i]->rollNumber, &(*students)[i]->marks);
    }

    fclose(file);
    printf("Student records loaded from %s successfully.\n", filename);
}
