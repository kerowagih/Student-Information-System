/*
 ========================================================================================================
 Name        : C Project (Student Management System).
 Author      : Kerollos Wagih Hares
 Description : The Student Management System is a C program designed to manage student information
               efficiently.
               It allows the user to perform various operations such as adding new students, displaying
               all students, searching for a student by ID, updating student details, calculating
               the average GPA, and finding the student with the highest GPA.
               This system utilizes fundamental programming concepts including conditions, loops,
               strings, structures, and pointers, besides the ability to use data structures efficiently
               like the linked list.
 ========================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"			/* Structures header file */

#define Exit 8		/* Exit the Program */
#define error 0.0	/* for check if the list is empty when using calculateAverageGPA Function */

/* Define a pointer to structure node to point the start of the linked list */
struct node *head = NULL;

#include "Functions_Prototype.h"	/* Functions Prototype header file */

int main (void){ /*Start of the program*/
	/* Using 2 lines to to show the output of printf function */
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int operation = 0;		/* Define this variable to read the the operation from the user */
	int id = 0;				/* Define this variable to read the ID student from the user for any operation */
	float Average_GPA = 0;	/* Define this variable for calculate average GPA operation */

	for ( ; ; ){	/* Infinite loop to repeat the code */
		/* Display the options */
		printf ("---------------------------------------------------\n");
		printf ("1. Add Student.\n");
		printf ("2. Display Students.\n");
		printf ("3. Search Student by ID.\n");
		printf ("4. Update Student Information.\n");
		printf ("5. Delete Student.\n");
		printf ("6. Calculate Average GPA.\n");
		printf ("7. Search for Student with Highest GPA.\n");
		printf ("8. Exit.\n");
		printf ("Enter Your Choice: ");
		scanf ("%d",&operation);	/* Read the operation from user */
		if (operation == Exit){		/* check if the user need to Exit the program */
			printf ("Exit...");
			break;		/* Exit: Terminates the program */
		}		/* End of if statement */
		else{	/* The user chose to continue the program */
			switch (operation){		/* Chose the operation using switch statement*/

			case 1:		/* Add a Student operation */
				/* Add a Student: Prompts the user for new student details and adds them to the system */
				/* Create a student structure and use it to save the student information */
				/* Dynamic memory allocation */
				struct student *S = (struct student*)malloc(sizeof(struct student));
				/* Read the student ID from the user (should be a positive integer) */
				do {
					printf ("Enter Student ID (Positive integer): ");
					scanf ("%d",&(S->id));
				} while (S->id <= 0);	/* check if the student id is a positive number */
				printf ("Enter Student Name: ");
				scanf ("%s",S->name);
				/* Read the student age from the user (should be a positive integer) */
				do {
					printf ("Enter Student age (Positive integer): ");
					scanf ("%d",&(S->age));
				} while ( S->age <= 0);	/* check if the student age is a positive number */
				/* Read the student GPA from the user (should be a positive integer from 0 to 4) */
				do {
					printf ("Enter Student GPA (Positive integer From 0 to 4): ");
					scanf ("%f",&(S->gpa));
				} while ( S->gpa < 0 || S->gpa > 4 );	/* check if the student GPA is a positive number from 0 to 4 */
				/* Call the addStudent function and pass the student structure information */
				addStudent (S);
				break;	/* End of Add a Student operation */

			case 2:		/* Display All Students operation */
				/* Display All Students: Shows a list of all stored student records */
				/* Call the displayStudents function */
				displayStudents ();
				break;	/* End the Display All Students operation */

			case 3:		/* Search for a Student by ID operation */
				/* Search for a Student by ID: Allows the user to find a specific student
				 * using their unique ID */
				/* Read the student ID from the user (should be a positive integer) */
				do {
				printf ("Enter Student ID to Search (positive integer): ");
				scanf("%d",&id);
				} while ( id <= 0 );	/* check if the student id is a positive number */
				/* Call the searchStudentByID function and pass the student ID */
				searchStudentByID (id);
				break;	/* End of Search for a Student by ID operation */

			case 4:		/* Update Student Information operation */
				/* Update Student Information: Facilitates the updating of details for an existing
				 * student identified by their ID */
				/* Read the student ID from the user (should be a positive integer) */
				do {
				printf ("Enter Student ID to Update it’s information (Positive integer): ");
				scanf("%d",&id);
				} while ( id <= 0 );	/* check if the student id is a positive number */
				/* Call the updateStudent function and pass the student ID */
				updateStudent (id);
				break;	/* End of Update Student Information operation */

			case 5:		/* Delete a Student operation */
				/* Delete a Student: Removes a student's record based on their ID */
				/* Read the student ID from the user (should be a positive integer) */
				do {
				printf ("Enter Student ID to Delete it’s information (positive integer): ");
				scanf("%d",&id);
				} while ( id <= 0 );	/* check if the student id is a positive number */
				/* Call the deleteStudent function and pass the student ID */
				deleteStudent (id);
				break;	/* End of Delete a Student operation */

			case 6:		/* Calculate Average GPA operation */
				/* Calculate Average GPA: Computes and displays the average GPA of all students */
				/* Call the calculateAverageGPA and store the return value in Average_GPA variable */
				Average_GPA = calculateAverageGPA();
				if (Average_GPA == error){	/* check if the list is empty */
					printf ("Empty List.\n");
					printf ("No students are present to calculate average GPA.\n");
				}		/* End of if statement */
				else{	/* The list is not empty */
					printf ("Average GPA: %f.\n",Average_GPA); /* Print the average GPA */
				}		/* End of else statement */
				break;	/* End of Calculate Average GPA operation */

			case 7:		/* Find Student with Highest GPA operation */
				/* Find Student with Highest GPA: Identifies and displays the student with the
				 * highest GPA */
				/* Call the searchHighestGPA function */
				searchHighestGPA();
				break;	/* End of Find Student with Highest GPA operation */

			default:	/* Default case (wrong input) */
				printf ("Invalid Operation.\n");
				break;	/* End of default case */

			}	/* End of switch statement*/
		}		/* End of else statement */
	}			/* End of infinite loop */
	return 0;	/* return statement to end the main function */
}				/* End of the program */
