#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#endif /* STRUCTURES_H_ */

/*Structures Definition*/
/*Define a structure to represent the data of each student*/
struct student {
	int id;			/* Student ID */
	char name[50];	/* Student Name */
	int age;		/* Student Age */
	float gpa;		/* Student GPA */
};

/*Define a structure to represent a node in linked list*/
struct node {
	struct student data;	/* Student data */
	struct node *next;		/* Pointer to the next node */
};
