#include <stdio.h>
#include <stdlib.h>
#include "student_operations.h"

void searchAndDisplayStudent(Student **students, int numStudents) {
    int rollNumber;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);

    const Student *student = searchStudent((const Student **)students, numStudents, rollNumber);
    if (student) {
        displayStudentInfo(student);
    } else {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

void displayStudentInfo(const Student *student) {
    printf("Student Info:\n");
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Marks: %.2f\n", student->marks);
}

void modifyStudent(Student **students, int numStudents) {
    int rollNumber;
    printf("Enter roll number of the student to modify: ");
    scanf("%d", &rollNumber);

    int index = searchStudentIndex((const Student **)students, numStudents, rollNumber);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Modifying details for student: %s\n", students[index]->name);
    printf("Enter new name: ");
    scanf("%49s", students[index]->name);
    
    printf("Enter new marks: ");
    scanf("%f", &students[index]->marks);
    
    printf("Student details updated successfully.\n");
}

// Other functions like saveStudentsToFile, loadStudentsFromFile, etc. would go here...
