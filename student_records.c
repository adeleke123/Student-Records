#include "student_records.h"

/**
 * addStudent - Adds a new student to the array.
 *
 * @students: An array of Student pointers.
 * @numStudents: A pointer to the number of students.
 */

void addStudent(Student **students, int *numStudents)
{
	students[*numStudents] = malloc(sizeof(Student));
	/* Allocate memory for a new student*/
	printf("Enter name: ");/*Get student information from the user*/
	scanf("%s", students[*numStudents]->name);
	printf("Enter roll number: ");
	scanf("%d", &students[*numStudents]->rollNumber);
	printf("Enter marks: ");
	scanf("%f", &students[*numStudents]->marks);
	(*numStudents)++; /* Increment the number of students*/
}

/**
 * displayStudents - Displays the information of all students.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students.
 */

void displayStudents(Student **students, int numStudents)
{
	printf("\nStudent Records:\n");
	for (int i = 0; i < numStudents; i++)
	{
		printf("Name: %s\n", students[i]->name);
		printf("Roll Number: %d\n", students[i]->rollNumber);
		printf("Marks: %.2f\n\n", students[i]->marks);
	}
}

Student *searchStudent(Student **students, int numStudents, int rollNumber)
{
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i]->rollNumber == rollNumber)
		{
			return (students[i]);
		}
	}
		return (NULL); /* Student not found*/
}

/**
 * modifyStudent - Modifies the information of a student.
 *
 * @students: An array of Student pointers.
 * @numStudents: The number of students in the array.
 */

void modifyStudent(Student **students, int numStudents)
{
	int rollNumber;

	printf("Enter roll number to modify: ");
	scanf("%d", &rollNumber);

	Student *foundStudent = searchStudent(students, numStudents, rollNumber);

	if (foundStudent != NULL)

	{
		printf("Enter new name: ");
		scanf("%s", foundStudent->name);

		printf("Enter new roll number: ");
		scanf("%d", &foundStudent->rollNumber);

		printf("Enter new marks: ");
		scanf("%f", &foundStudent->marks);

		printf("Student information modified.\n");
	}
	else
	{
		printf("Student not found.\n");
	}
}

/**
 * deleteStudent - Deletes a student from the array.
 *
 * @students: An array of Student pointers.
 * @numStudents: A pointer to the number of students.
 * @index: The index of the student to delete.
 */

void deleteStudent(Student **students, int *numStudents, int index)
{
	/* Shift elements after the deleted index*/
	for (int i = index; i < *numStudents - 1; i++)
	{
		students[i] = students[i + 1];
	}
	/* Free memory for the deleted student*/
	free(students[*numStudents - 1]);
	(*numStudents)--; /* Decrement the number of students*/
}
