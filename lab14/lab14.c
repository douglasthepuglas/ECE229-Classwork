/**************************************************
 * Author:      Douglas Cannizzaro
 * Lab:         Lab 14
 * Description: Terrible (REALLY unsecure) student roster tracker with options
 *              to add a student, list all students, or wipe the entire roster
 *              by quitting. DO NOT use in place of Brightspace.
 ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 31 // include null terminator in buffer
#define ROS current_roster[i]
#define ROSTER_PRINT ROS.name.first, ROS.name.middle_initial, ROS.name.last, ROS.id, ROS.age, ROS.sex

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

void add_student (struct student **current_roster, int num_students);
void print_roster(struct student *current_roster, int num_students);

#define TRASH_SIZE 10
char trash_buffer[TRASH_SIZE]; // used as a blank address to dump extra newlines
                               // from fgets later. This is a terrible solution
                               // and easily exploitable, but I'm no
                               // professional or cybersecurity expert, so I
                               // plead the fifth. And I don't want to directly
                               // clone Donna's solution.

// Clear extra whitespace after scanf for fgets to work
#define DUMP_INPUT fgets(trash_buffer, TRASH_SIZE, stdin)

int main(void) {
    printf("Student Records Archive.\n");

    int num_students = 0;
    struct student *current_roster = NULL;
    while(1) {
        char action;
        printf("Action (a=add, l=list, q=quit): ");
        scanf(" %c", &action);
        DUMP_INPUT;

        switch (toupper(action)) {
            case 'A':
                ++num_students;
                add_student(&current_roster, num_students);
                break;

            case 'L':
                if (!current_roster) { // Check for empty roster
                    printf("No students in roster.\n\n");
                } else {
                    print_roster(current_roster, num_students);
                }
                break;
            case 'Q':
                printf("Exiting\n\n");
                exit(0);
                break;
            default:
                printf("Invalid input. ");
        }
    }
    return(0);
}

void add_student(struct student **current_roster, int num_students) {
    // Placeholder variables used as opposed to direct injection to the student
    // struct for readability, though direct injection would be more memory
    // efficient
    char first_name[MAX_NAME_LEN];
    char m_initial;
    char last_name[MAX_NAME_LEN];
    int  id, age;
    char sex;
    int  index = num_students - 1;

    // Duplicate old list to new memory block with extra space for added student
    struct student *new_roster = malloc(num_students * sizeof(struct student));
    memcpy(new_roster, *current_roster, sizeof(struct student) * (num_students - 1));

    // User inputs student details, throw into new spot in the new list
    printf("Enter First Name: ");
    fgets(first_name, MAX_NAME_LEN, stdin);
    first_name[strcspn(first_name, "\n")] = '\0';
    strcpy(new_roster[index].name.first, first_name);

    printf("Enter middle initial: ");
    scanf(" %c", &m_initial);
    DUMP_INPUT;

    m_initial = toupper(m_initial);
    new_roster[index].name.middle_initial = m_initial;

    printf("Enter last name: ");
    fgets(last_name, MAX_NAME_LEN, stdin);
    last_name[strcspn(last_name, "\n")] = '\0';
    strcpy(new_roster[index].name.last, last_name);

    printf("Enter student ID: ");
    scanf("%d", &id);
    DUMP_INPUT;
    new_roster[index].id = id;

    printf("Enter age: ");
    scanf("%d", &age);
    DUMP_INPUT;
    new_roster[index].age = age;

    printf("Enter sex (m/f): ");
    scanf(" %c", &sex);
    DUMP_INPUT;
    sex = toupper(sex);
    new_roster[index].sex = sex;

    // New memory block becomes subsequent working roster
    free(*current_roster);
    *current_roster = new_roster;

    printf("Student added successfully.\n\n");

}

void print_roster(struct student *current_roster, int num_students) {
    printf("\nCurrent roster:\n");
    for(int i = 0; i < num_students; ++i) {
        printf("====================================\n");  // divider
        printf("Name: %s %c %s\n"
                "ID  : %d\n"
                "Age : %d\n"
                "Sex : %c\n", ROSTER_PRINT); // I love automatic string concatenation
    }
    printf("\n\n");
}