#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_records.h"

// Function prototype for searchStudentIndex
int searchStudentIndex(const Student **students, int numStudents, int rollNumber);

/**
 * addStudent - Adds a new student to the system.
 * 
 * @students: Pointer to the array of student pointers.
 * @numStudents: Pointer to the number of students.
 */
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

/**
 * displayStudents - Displays all students.
 * 
 * @students: Array of student pointers.
 * @numStudents: Number of students.
 */
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

/**
 * deleteStudent - Deletes a student record.
 * 
 * @students: Pointer to the array of student pointers.
 * @numStudents: Pointer to the number of students.
 * @index: The index of the student to delete.
 */
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

/**
 * searchStudent - Searches for a student by roll number.
 * 
 * @students: Array of student pointers.
 * @numStudents: Number of students.
 * @rollNumber: Roll number to search for.
 * Return: Pointer to the student if found, NULL otherwise.
 */
const Student *searchStudent(const Student **students, int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            return students[i]; // Return the pointer to the found student
        }
    }
    return NULL;  // Student not found
}

/**
 * searchStudentIndex - Searches for the index of a student by roll number.
 * 
 * @students: Array of student pointers.
 * @numStudents: Number of students.
 * @rollNumber: Roll number to search for.
 * Return: Index of the student if found, -1 otherwise.
 */
int searchStudentIndex(const Student **students, int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            return i; // Return the index of the found student
        }
    }
    return -1;  // Student not found
}

/**
 * calculateAverageMarks - Calculates the average marks of all students.
 * 
 * @students: Array of student pointers.
 * @numStudents: Number of students.
 * Return: The average marks.
 */
float calculateAverageMarks(const Student **students, int numStudents) {
    float total = 0.0;
    for (int i = 0; i < numStudents; i++) {
        total += students[i]->marks;
    }
    return numStudents > 0 ? total / numStudents : 0.0;
}

/**
 * sortStudentsByMarks - Sorts students by their marks in ascending or descending order.
 * 
 * @students: Array of student pointers.
 * @numStudents: Number of students.
 * @ascending: 1 for ascending order, 0 for descending order.
 */
void sortStudentsByMarks(Student **students, int numStudents, int ascending) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if ((ascending && students[j]->marks > students[j + 1]->marks) ||
                (!ascending && students[j]->marks < students[j + 1]->marks)) {
                Student *temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted successfully.\n");
}

/**
 * saveStudentsToFile - Saves the student records to a file.
 * 
 * @students: Array of student pointers.
 * @numStudents: Number of students.
 * @filename: The name of the file to save the records to.
 */
void saveStudentsToFile(const Student **students, int numStudents, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s %d %.2f\n", students[i]->name, students[i]->rollNumber, students[i]->marks);
    }

    fclose(file);
    printf("Student records saved successfully.\n");
}

/**
 * loadStudentsFromFile - Loads student records from a file.
 * 
 * @students: Pointer to the array of student pointers.
 * @numStudents: Pointer to the number of students.
 * @filename: The name of the file to load the records from.
 */
void loadStudentsFromFile(Student ***students, int *numStudents, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    *numStudents = 0;
    char name[50];
    int rollNumber;
    float marks;

    while (fscanf(file, "%49s %d %f", name, &rollNumber, &marks) == 3) {
        *students = realloc(*students, (*numStudents + 1) * sizeof(Student *));
        (*students)[*numStudents] = malloc(sizeof(Student));

        strcpy((*students)[*numStudents]->name, name);
        (*students)[*numStudents]->rollNumber = rollNumber;
        (*students)[*numStudents]->marks = marks;

        (*numStudents)++;
    }

    fclose(file);
    printf("Student records loaded successfully.\n");
}
