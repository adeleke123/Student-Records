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
 * @students: An array of Student pointers.
 * @numStudents: A pointer to the number of students in the array.
 */
void handleUserChoice(Student **students, int *numStudents);

#endif /* MENU_H */
