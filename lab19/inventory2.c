#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NAME_LEN 25

int read_line(char str[], int n);

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;  /* points to first part */

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void delete(void);

/********************************************************
 * main: Prompts the user to enter an operation code,   *
 *       then calls a function to perform the requested *
 *       action. Repeats until the user enters the      *
 *       command 'q'. Prints an error message if the    *
 *       user enters an illegal code.                   *
 ********************************************************/
int main(void)
{
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');   /* skips to end of line */

        switch (code) {
            case 'i': insert();
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print();
                      break;
            case 'd': delete();
                      break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }

        printf("\n");
    }
}

/********************************************************
 * find_part: Looks up a part number in the inventory   *
 *            list. Returns a pointer to the node       *
 *            containing the part number; if not found, *
 *            returns NULL.                             *
 ********************************************************/
struct part *find_part(int number)
{
    struct part *p;
    for (p = inventory;
         p != NULL && number > p->number;
         p = p->next);

    if (p != NULL && number == p->number)
        return p;

    return NULL;
}

/********************************************************
 * insert: Prompts the user for information about a new *
 *         part and inserts it into the inventory list. *
 *         List remains sorted by part number. Prints   *
 *         an error if the part already exists or if    *
 *         memory can't be allocated.                   *
 ********************************************************/
void insert(void)
{
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next);

    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

/********************************************************
 * search: Prompts the user to enter a part number,     *
 *         then looks up the part in the database.      *
 *         If found, prints name and quantity on hand.  *
 *         Otherwise, prints an error message.          *
 ********************************************************/
void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);

    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } else {
        printf("Part not found.\n");
    }
}

/********************************************************
 * update: Prompts the user to enter a part number.     *
 *         If found, asks for quantity change and       *
 *         updates the database. Otherwise, prints an   *
 *         error message.                               *
 ********************************************************/
void update(void)
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);

    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

/********************************************************
 * print: Prints a listing of all parts in the database,*
 *        showing part number, name, and quantity.      *
 *        Parts appear in ascending order.              *
 ********************************************************/
void print(void)
{
    struct part *p;

    printf("Part Number   Part Name                  Quantity on Hand\n");

    for (p = inventory; p != NULL; p = p->next) {
        printf("%7d        %-25s%11d\n", p->number, p->name, p->on_hand);
    }
}

// helper function to read in one line and clear the input buffer.
int read_line(char str[], int n)
{
	int ch, i=0;

	while(isspace(ch = getchar())); // ignore leading spaces

	while(ch != '\n' && ch != EOF) {
		if(i<n){	// store char in array if there is room
			str[i] = ch;
			++i;
		}
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

void delete(void)
{
    struct part *cur, *prev;
    int number;

    if (inventory == NULL) {
        printf("Database empty.\n");
        return;
    }

    printf("Enter part number (enter 0 to cancel): ");
    scanf("%d", &number);
    if (!number) {
        printf("Cancelled\n");
        return;
    }

    for (cur = inventory, prev = NULL;
         cur != NULL && number != cur->number;
         prev = cur, cur = cur->next);

    if (cur == NULL) {
        printf("Part does not exist.\n");
        return;
    }

    if (prev == NULL) {
        inventory = cur->next;
    }
    else {
        prev->next = cur->next;
    }

    printf("Part #%d deleted.\n", cur->number);
    free(cur);
}
