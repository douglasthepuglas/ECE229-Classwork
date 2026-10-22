/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 14
 * Description:
 ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 31 // include null terminator in buffer
#define ROS roster[i]
#define ROSTER_PRINT (ROS.name.first, ROS.name.middle_initial, ROS.name.last, ROS.id, ROS.age, ROS.sex)

struct student_name {
    char first[MAX_NAME_LEN];
    char middle_initial;
    char last[MAX_NAME_LEN];

};

struct student{
    struct student_name name;
    int id, age;
    char sex;

};

void add_student(struct student *roster, int num_students);

int main(void) {
    printf("Student Records Archive.\n");

    int num_students = 0;
    struct student *current_roster = NULL;
    while(1) {
        char action;
        printf("Action (a=add, l=list, q=quit): ");
        scanf("%c", &action);
        switch (toupper(action)) {
            case 'a':
                ++num_students;

                struct student *new_roster = malloc(num_students * sizeof(struct student));
                memcpy(new_roster, current_roster, sizeof(struct student) * (num_students - 1));

                add_student(new_roster, num_students);
                free(current_roster);
                current_roster = new_roster;

            case 'l':
                printf("Current roster:\n");
                for(int i; i < num_students; ++i) {
                    printf("", ROSTER_PRINT);
                }

        }
    }
    return(0);
}

void add_student(struct student *roster, int num_students) {
    char first_name[MAX_NAME_LEN];
    char m_initial;
    char last_name[MAX_NAME_LEN];
    int  id, age;
    char sex;
    int index = num_students - 1;

    printf("Enter First Name: ");
    fgets(&first_name, MAX_NAME_LEN, stdin);
    strcpy(roster[index].name.first, first_name);

    printf("Enter middle initial: ");
    scanf("%c", m_initial);
    m_initial = toupper(m_initial);
    roster[index].name.middle_initial = m_initial;

    printf("Enter last name: ");
    fgets(&last_name, MAX_NAME_LEN, stdin);
    strcpy(roster[index].name.last, last_name);

    printf("Enter student ID: ");
    scanf("%d", &id);
    roster[index].id = id;

    printf("Enter age: ");
    scanf("%d", &age);
    roster[index].age = age;

    printf("Enter sex (m/f): ");
    scanf("%c", &sex);
    sex = toupper(sex);
    roster[index].sex = sex;

    printf('Student added successfully.\n');
}