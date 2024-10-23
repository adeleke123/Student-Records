#ifndef MENU_H
#define MENU_H

#include "student_records.h"

/**
 * displayMenu - Displays the main menu options to the user.
 */
void displayMenu(void);

/**
 * getUserChoice - Prompts the user to enter their choice and returns it.
 *
 * Return: The user's choice as an integer.
 */
int getUserChoice(void);

/**
 * handleUserChoice - Handles the user's choice from the menu.
 *
 * @students: A pointer to an array of Student pointers.
 * @numStudents: A pointer to the number of students in the array.
 */
void handleUserChoice(Student ***students, int *numStudents);

/**
 * searchStudentIndex - Searches for a student by roll number and returns the index.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 * @rollNumber: The roll number to search for.
 * Return: The index of the found student, or -1 if not found.
 */
int searchStudentIndex(const Student **students, int numStudents, int rollNumber);

#endif /* MENU_H */
