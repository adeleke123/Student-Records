#ifndef STUDENT_RECORDS_H
#define STUDENT_RECORDS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct Student - Represents a student.
 * 
 * @name: The name of the student.
 * @rollNumber: The roll number of the student.
 * @marks: The marks obtained by the student.
 */
typedef struct Student {
    char name[50];
    int rollNumber;
    float marks;
} Student;

/**
 * addStudent - Adds a new student to the array.
 * 
 * @students: A dynamically allocated array of Student pointers.
 * @numStudents: A pointer to the current number of students.
 */
void addStudent(Student ***students, int *numStudents);

/**
 * displayStudents - Displays the information of all students.
 * 
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 */
void displayStudents(const Student **students, int numStudents);

/**
 * searchStudent - Searches for a student by roll number.
 * 
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 * @rollNumber: The roll number to search for.
 * 
 * Return: A pointer to the found student, or NULL if not found.
 */
const Student *searchStudent(const Student **students, int numStudents, int rollNumber);

/**
 * searchStudentIndex - Searches for the index of a student by roll number.
 * 
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 * @rollNumber: The roll number to search for.
 * 
 * Return: The index of the student, or -1 if not found.
 */
int searchStudentIndex(const Student **students, int numStudents, int rollNumber);

/**
 * modifyStudent - Modifies the information of a student.
 * 
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 */
void modifyStudent(Student **students, int numStudents);

/**
 * deleteStudent - Deletes a student from the array.
 * 
 * @students: A dynamically allocated array of Student pointers.
 * @numStudents: A pointer to the current number of students.
 * @index: The index of the student to delete.
 */
void deleteStudent(Student ***students, int *numStudents, int index);

/**
 * saveStudentsToFile - Saves all student records to a text file.
 * 
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 * @filename: The name of the file to save the records to.
 */
void saveStudentsToFile(const Student **students, int numStudents, const char *filename);

/**
 * loadStudentsFromFile - Loads student records from a text file.
 * 
 * @students: A pointer to an array of Student pointers.
 * @numStudents: A pointer to the number of students.
 * @filename: The name of the file to load the records from.
 */
void loadStudentsFromFile(Student ***students, int *numStudents, const char *filename);

/**
 * sortStudentsByMarks - Sorts students by marks in ascending or descending order.
 * 
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 * @ascending: If non-zero, sorts in ascending order; otherwise, sorts in descending order.
 */
void sortStudentsByMarks(Student **students, int numStudents, int ascending);

/**
 * calculateAverageMarks - Calculates the average marks of all students.
 * 
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 * 
 * Return: The average marks.
 */
float calculateAverageMarks(const Student **students, int numStudents);

#endif /* STUDENT_RECORDS_H */
