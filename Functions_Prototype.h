#ifndef FUNCTIONS_PROTOTYPE_H_
#define FUNCTIONS_PROTOTYPE_H_

#endif /* FUNCTIONS_PROTOTYPE_H_ */

/*Functions Prototype*/

/* addStudent function */
/* This function collects new student details from the user and adds them to the student linked list */
void addStudent(const struct student *const ptr);

/* displayStudents function */
/* This function displays the details of all students currently in the system */
void displayStudents(void);

/* searchStudentByID function */
/* This function searches for a student by their ID and displays their details if found */
void searchStudentByID(int id);

/* updateStudent function */
/* This function updates the details of a student with the given ID */
void updateStudent(int id);

/* deleteStudent function */
/* This function deletes a student from the linked list by their ID */
void deleteStudent(int id);

/* calculateAverageGPA function */
/* This function calculates and returns the average GPA of all students */
float calculateAverageGPA(void);

/* searchHighestGPA function */
/* This function finds and displays the student with the highest GPA */
void searchHighestGPA(void);
