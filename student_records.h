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

typedef struct Student
{
	char name[50];
	int rollNumber;
	float marks;
} Student;

/**
 * addStudent - Adds a new student to the array.
 *
 * @students: An array of Student pointers.
 * @numStudents: A pointer to the number of students.
 */
void addStudent(Student **students, int *numStudents);

/**
 * displayStudents - Displays the information of all students.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 */
void displayStudents(Student **students, int numStudents);

/**
 * searchStudent - Searches for a student by roll number.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 * @rollNumber: The roll number to search for.
 *
 * Return: A pointer to the found student, or NULL if not found.
 */

Student *searchStudent(Student **students, int numStudents, int rollNumber);

/**
 * modifyStudent - Modifies the information of a student.
 *
 * @student: A pointer to the student to modify.
 * @numStudents: The number of an array of student.
 */

void modifyStudent(Student **students, int numStudents);

/**
 * deleteStudent - Deletes a student from the array.
 *
 * @students: An array of Student pointers.
 * @numStudents: A pointer to the number of students.
 * @index: The index of the student to delete.
 */
void deleteStudent(Student **students, int *numStudents, int index);

#endif /* STUDENT_RECORDS_H */
