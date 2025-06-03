#include <stdio.h>
#include <stdlib.h>
#include <string.h>			/* for using strcpy function */
#include "Structures.h"		/* Structures header file */

#define error 0.0		/* for check if the list is empty when using calculateAverageGPA Function */

/* Pointer to structure node to point the start of the linked list */
extern struct node *head;

/* Functions Definitions */
/* addStudent function */
/* Add a new student to the linked list */
/* This function takes a constant pointer to constant student structure */
void addStudent(const struct student *const ptr){
	printf ("---------------------------------------------------\n");
	struct node *current = NULL;	/* Pointer to node */
	current = head;					/* Current pointer points to the start of the linked list */
	while (current != NULL){		/* check if the student's ID already exists */
		if (ptr->id == current->data.id){
			printf ("This ID is already reserved.\n");	/* print an error message and return */
			return;
		}
		current = current->next;
	}
	/* The input student ID is not exist */
	/* Create a node structure for new node (Dynamic memory allocation) */
	struct node *link = (struct node*)malloc(sizeof(struct node));
	if (link == NULL){		/* Check if memory allocation fails */
		printf ("Cannot allocate a memory.\n");	/* print an error message and return */
		return;
	}
	/* Allocate successfully */
	/* Copy the student data to the new node */
	link->data.id = ptr->id;
	strcpy(link->data.name , ptr->name);
	link->data.age = ptr->age;
	link->data.gpa = ptr->gpa;
	/* Add the node to the end of the linked list */
	if (head == NULL){	/* 	Case of adding the first node in the list */
		link->next = NULL;
		head = link;
	}
	else{		/* Case of adding another */
		current = head;
		while (current->next != NULL){	/* Loop until reach the last node */
			current = current->next;
		}
		link->next = NULL;
		current->next = link;
	}
	/* The operation is done */
	printf ("Successful Operation.\n");
	printf ("The student is added to the list successfully.\n");
}	/* End of addStudent function */

/* displayStudents function */
/* Displays all students in the linked list */
void displayStudents(void){
	printf ("---------------------------------------------------\n");
	if (head == NULL){	/* Check if the list is empty */
		/* print a message indicating no students are present */
		printf ("Empty List.\n");
		printf ("No students are present.\n");
	}
	else{	/* The list is not empty */
		struct node *current = NULL;	/* Pointer to node */
		current = head;					/* Current pointer points to the start of the linked list */
		while (current != NULL){	/* Traverse the list and print the details of each student */
			printf ("[ID: %d, ",current->data.id);
			printf ("Name: %s, ",current->data.name);
			printf ("Age: %d, ",current->data.age);
			printf ("GPA: %f]\n",current->data.gpa);
			current = current->next;
		}
	}
}	/* End of displayStudents function */

/* searchStudentByID function */
/* Search for a student by their ID in the linked list */
/* This function takes the student ID as integer */
void searchStudentByID(int id){
	printf ("---------------------------------------------------\n");
	if (head == NULL){	/* Check if the list is empty */
		/* print a message indicating no students are present */
		printf ("Empty List.\n");
		printf ("No students are present to Search.\n");
	}
	else{	/* The list is not empty */
		struct node *current = NULL;	/* Pointer to node */
		current = head;					/* Current pointer points to the start of the linked list */
		while (current != NULL){
			if (current->data.id == id){	/* Check if the student is found */
				/* print their details */
				printf ("Student Found.\n");
				printf ("[ID: %d, ",current->data.id);
				printf ("Name: %s, ",current->data.name);
				printf ("Age: %d, ",current->data.age);
				printf ("GPA: %f]\n",current->data.gpa);
				return;
			}
			current = current->next;
		}
		/* The student is not found */
		/* Print a message indicating the student was not found */
		printf ("Student with ID %d not Found.\n",id);
	}
}	/* End of searchStudentByID function */

/* updateStudent function */
/* Update the details of a student with a given ID in the linked list */
/* This function takes the student ID as integer */
void updateStudent(int id){
	printf ("---------------------------------------------------\n");
	if (head == NULL){	/* Check if the list is empty */
		/* print a message indicating no students are present */
		printf ("Empty List.\n");
		printf ("No students are present to Update.\n");
	}
	else{	/* The list is not empty */
		struct node *current = NULL;	/* Pointer to node */
		current = head;					/* Current pointer points to the start of the linked list */
		while (current != NULL){
			if (current->data.id == id){	/* Check if the student is found */
				/* Update the student's information (student name, age, GPA) */
				printf ("Enter New Student Name: ");
				scanf ("%s",current->data.name);
				/* Read the new student age from the user (should be a positive integer) */
				do {
					printf ("Enter New Student age (Positive integer): ");
					scanf ("%d",&(current->data.age));
				} while ( current->data.age <= 0 );	/* check if the new student age is a positive number */
				/* Read the new student GPA from the user (should be a positive integer from 0 to 4) */
				do {
					printf ("Enter New Student GPA (Positive integer From 0 to 4): ");
					scanf ("%f",&(current->data.gpa));
				} while ( current->data.gpa < 0 || current->data.gpa > 4 );	/* check if the new student GPA is a positive number from 0 to 4 */
				printf ("---------------------------------------------------\n");
				/* Successful operation */
				printf ("Student details updated successfully.\n");
				return;
			}
			current = current->next;
		}
		printf ("---------------------------------------------------\n");
		/* The student is not found */
		/* Print a message indicating the student was not found */
		printf ("Student with ID %d not Found.\n",id);
	}
}	/* End of updateStudent function */

/* deleteStudent function */
/* Iterates through the linked list of students starting with the Head of it to find the student
 * with the given ID then delete this node */
/* This function takes the student ID as integer */
void deleteStudent(int id){
	printf ("---------------------------------------------------\n");
	if (head == NULL){	/* Check if the list is empty */
		/* print a message indicating no students are present */
		printf ("Empty List.\n");
		printf ("No students are present to delete.\n");
	}
	else if (head->data.id == id){		/* Case of deleting the first node */
		struct node *current = NULL;	/* Pointer to node */
		current = head;					/* Current pointer points to the start of the linked list */
		head = head->next;				/* Remove the node from the list */
		free(current);					/* Free the memory allocated for the node */
		/* Successful operation */
		/* Print a success message */
		printf ("Student with ID %d deleted successfully.\n",id);
		return;
	}
	else{		/* Delete anther node */
		struct node *current = NULL;	/* Pointer to node */
		struct node *prev = NULL;		/* Pointer to node */
		prev = head;					/* Prev pointer points to the start of the linked list */
		current = head->next;			/* Current pointer points to the second node in the linked list */
		while (prev != NULL){			/* Loop until reach the student ID */
			if (current->data.id == id){
				/* The student is found */
				prev->next = current->next;	/* Remove the node from the list */
				free(current);				/* Free the memory allocated for the node */
				/* Successful operation */
				/* Print a success message */
				printf ("Student with ID %d deleted successfully.\n",id);
				return;
			}
			prev = prev->next;
			if (current->next != NULL){
				current = current->next;
			}
		}
		printf ("Student with ID %d not Found.\n",id);
	}
}	/* End of deleteStudent function */

/* calculateAverageGPA function */
/* Calculate and return the average GPA of all students in the linked list */
float calculateAverageGPA(void){
	printf ("---------------------------------------------------\n");
	if (head == NULL){	/* Check if the list is empty */
		return error;	/* returns error = 0.0 */
	}
	else{	/* The list is not empty */
		float sum = 0;		/* Define this variable to sum the GPAs of all students */
		int counter = 0;	/* Define this variable to count the number of students */
		struct node *current = NULL;	/* Pointer to node */
		current = head;					/* Current pointer points to the start of the linked list */
		while (current != NULL){
			sum += current->data.gpa;	/* Sum the GPAs of all students */
			counter++;					/* Count the number of students */
			current = current->next;
		}
		/* Compute and return the average GPA by dividing the total sum of GPAs by the number of students */
		return (sum/counter);
	}
}	/* End of calculateAverageGPA function */

/* searchHighestGPA function */
/* Search for the student with the highest GPA in the linked list */
void searchHighestGPA(void){
	printf ("---------------------------------------------------\n");
	if (head == NULL){	/* Check if the list is empty */
		/* Print a message indicating that there are no students */
		printf ("Empty List.\n");
		printf ("No students are present to delete.\n");
	}
	else if (head->next == NULL){	/* One student in the list */
		/* Print the details of this student */
		printf ("Student with highest GPA:\n");
		printf ("[ID: %d, ",head->data.id);
		printf ("Name: %s, ",head->data.name);
		printf ("Age: %d, ",head->data.age);
		printf ("GPA: %f]\n",head->data.gpa);
		return;
	}
	else{	/* More than one student in the list */
		struct node *current = NULL;	/* Pointer to node */
		current = head;					/* Current pointer points to the start of the linked list */
		float max_GPA = current->data.gpa;	/* Assume that the first student has the highest GPA */
		int id = 0;		/* ID of the student with highest GPA */
		while (current->next != NULL){	/* Traverse the list */
			current = current->next;
			if (current->data.gpa > max_GPA){
				/* keeping track of the student with the highest GPA encountered */
				max_GPA = current->data.gpa;
				id = current->data.id;
			}
		}
		printf ("Student with highest GPA:\n");
		current = head->next;
		while (current != NULL){	/* Reach to the student with highest GPA using its ID*/
			if (current->data.id == id){
				/* After finding the student with the highest GPA, print the details of that student */
				printf ("[ID: %d, ",current->data.id);
				printf ("Name: %s, ",current->data.name);
				printf ("Age: %d, ",current->data.age);
				printf ("GPA: %f]\n",current->data.gpa);
				return;
			}
			current = current->next;
		}
	}
}	/* End of searchHighestGPA function */
