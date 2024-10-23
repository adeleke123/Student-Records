#include <stdio.h>
#include "menu.h"
#include "student_operations.h"
#include "student_records.h"
/**
 * displayMenu - Entry point
 * @void - Parameter
 * Return: Success
 */

void displayMenu(void)
{
	printf("\nStudent Record System\n");
	printf("1. Add Student\n");
	printf("2. Display Students\n");
	printf("3. Search Student\n");
	printf("4. Modify Student\n");
	printf("5. Delete Student\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");
}

/**
 * getUserChoice - Entyr Point
 * @void - parameter
 * Return: choice
 */

int getUserChoice(void)
{
	int choice;

	scanf("%d", &choice);
	return (choice);
}
