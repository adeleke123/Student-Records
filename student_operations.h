#ifndef STUDENT_OPERATIONS_H
#define STUDENT_OPERATIONS_H

#include "student_records.h"

/**
 * searchAndDisplayStudent - Searches for a student by roll number and displays their information.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */
void searchAndDisplayStudent(Student **students, int numStudents);

/**
 * modifyStudent - Modifies the information of a student.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */

void modifyStudent(Student **students, int numStudents);

/**
 * deleteStudent - Deletes a student from the array.
 *
 * @students: An array of Student pointers.
 * @numStudents: A pointer to the number of students in the array.
 * @index: The index of the student to delete.
 */
void deleteStudent(Student **students, int *numStudents, int index);

/**
 * displayStudentInfo - Displays the information of a student.
 *
 * @student: A pointer to the student to display.
 */
void displayStudentInfo(Student *student);

/**
 * modifyStudentInfo - Modifies the information of a student.
 *
 * @student: A pointer to the student to modify.
 */
void modifyStudentInfo(Student *student);

#endif /* STUDENT_OPERATIONS_H */
