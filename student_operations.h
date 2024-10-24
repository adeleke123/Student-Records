#ifndef STUDENT_OPERATIONS_H
#define STUDENT_OPERATIONS_H

#include "student_records.h"

/**
 * searchStudent - Searches for a student by roll number.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 * @rollNumber: The roll number to search for.
 * 
 * Return: A pointer to the found Student, or NULL if not found.
 */
const Student *searchStudent(const Student **students, int numStudents, int rollNumber);

/**
 * searchAndDisplayStudent - Searches for a student by roll number and displays their information.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */
void searchAndDisplayStudent(Student **students, int numStudents);

/**
 * displayStudentInfo - Displays the information of a student.
 *
 * @student: A pointer to the student to display.
 */
void displayStudentInfo(const Student *student);

/**
 * modifyStudent - Modifies the information of a student.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */
void modifyStudent(Student **students, int numStudents);

/**
 * saveStudentsToFile - Saves the student records to a file.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 * @filename: The name of the file to save to.
 */
void saveStudentsToFile(Student **students, int numStudents, const char *filename);

/**
 * loadStudentsFromFile - Loads student records from a file.
 *
 * @students: A pointer to an array of Student pointers (to be allocated).
 * @numStudents: A pointer to an integer for storing the number of students loaded.
 * @filename: The name of the file to load from.
 */
void loadStudentsFromFile(Student ***students, int *numStudents, const char *filename);

#endif /* STUDENT_OPERATIONS_H */
