/**************************************************
 * Lab:         Lab 15
 * Description: Text adventure. Find things to make soup, eat soup, profit.
 * ***********************************************/

// You will need all four of these: string.h for fgets() and the string
// handling around it, ctype.h for tolower(), stdbool.h if you write a helper
// that returns true or false.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CHARS 100 // including terminator

// Useful defines:
// enum used for the 4 directions. These double as the subscripts into a room's
// exit[] array, so exit[N] is always the way north no matter what order they
// are written in.
enum direction { N, E, S, W };
const char *directions_list[] = { "North", "East", "South", "West" };

// The rooms, so everything below can say which room it means by name instead
// of by number. A new room goes in both this enum and the map[] below, but
// then a slip is a compile error rather than a door that quietly opens
// somewhere else.
enum place { LIVING_ROOM, DINING_ROOM, KITCHEN, OFFICE, PANTRY, NOT_CRAFTED, USED };

// Every command the game understands, and the list of words you have to
// recognise. get_command() returns one of these, so main() can switch on it
// instead of picking the words apart again. UNKNOWN is what you give back for
// anything else, including a blank line.
enum command { QUIT, HELP, GO, INVENTORY, LOOK, GET, DROP, MAKE, EAT, UNKNOWN };

enum items { SPOON, NAPKIN, SOUP_CAN, BOWL, CAN_OPENER, BOWL_OF_SOUP };

// room structure
struct room {
  char *name;    // name of the room
  struct room *exit[4]; // possible exits N,E,S,W -- NULL means no exit that way
};

// item structure
struct item {
  char *name;    // name of the item
  struct room *location;  // where is this item located, null for player inventory
};



// Map...
//
//  Dining Room -- Kitchen -- Pantry
//       |            |
//  Living Room -- Office
//
// North is up and east is right, so the Kitchen is EAST of the Dining Room and
// the Dining Room is WEST of the Kitchen. Every pair of exits has to agree like
// that, or the house folds in on itself. Naming the room and the direction in
// each initializer below is what keeps them straight; anything left out is
// NULL, which is exactly what "no exit that way" means.
struct room map[] = {
  [LIVING_ROOM] = {
    .name = "Living Room",
    .exit = { [N] = &map[DINING_ROOM], [E] = &map[OFFICE] }
  },
  [DINING_ROOM] = {
    .name = "Dining Room",
    .exit = { [E] = &map[KITCHEN], [S] = &map[LIVING_ROOM] }
  },
  [KITCHEN] = {
    .name = "Kitchen",
    .exit = { [E] = &map[PANTRY], [S] = &map[OFFICE], [W] = &map[DINING_ROOM] }
  },
  [OFFICE] = {
    .name = "Office",
    .exit = { [N] = &map[KITCHEN], [W] = &map[LIVING_ROOM] }
  },
  [PANTRY] = {
    .name = "Pantry",
    .exit = { [W] = &map[KITCHEN] }
  },
  [NOT_CRAFTED] = { // Placeholder for items to be made later
    .name = "\n"   // Impossible to enter as user, therefore safe character to use as placeholder
  },
  [USED] = {
    .name = '\0'
  }
};

// Initial objects and their locations. A NULL location means the player is
// carrying it -- so you start with the pocket fluff and nothing else.
//
// Careful: the last entry is the end-of-list marker, and its location is NULL
// too. Stop at the NULL *name*, or a loop looking for what the player carries
// will walk straight off the end of the array:
//
//     for (int i = 0; obj[i].name != NULL; i++) ...
//

struct item obj[] = {
  { "Spoon", &map[KITCHEN] },
  { "Napkin", &map[DINING_ROOM] },
  { "Soup Can", &map[PANTRY] },
  { "Bowl", &map[LIVING_ROOM] },
  { "Can Opener", &map[OFFICE] },
  { "Bowl of Soup", &map[NOT_CRAFTED] },
  { NULL, NULL } // null item to flag the end of the list
};

// function declarations
void init_game(void);
void game_help(void);    // prints basic instructions for use
void look(int directions, int objects);
void capitalize_noun();

// command proc
enum command get_command(void); // returns QUIT when the player is done
char command_buffer[MAX_CHARS]; // store input from user
char *verb;  // current command verb, as they typed it
char *noun;  // the rest of the line after the verb, or NULL if there was none


// Globals...
struct room *player_location = LIVING_ROOM;

int main(void) {

  enum command cmd;

  init_game();

  printf("Welcome to the game!\n");
  game_help();

  while ((cmd = get_command()) != QUIT) {
    switch (cmd) {

      case HELP:
        game_help();
        break;

      case GO:
        capitalize_noun();
        enum direction chosen_direction;
        int valid_direction_flag = 0;
        for (int i = N; i <= W; ++i) {
          if (!strcmp(noun, directions_list[i])) {
            chosen_direction = i;
            valid_direction_flag = 1;
            break;
          }
        }

        if (!valid_direction_flag) {
          printf("Invalid direction.\n");
          look(0, 0);
          break;
        }

        if (player_location -> exit[chosen_direction] != NULL) {
          player_location = player_location -> exit[chosen_direction];
          look(0, 0);
          break;
        }

        capitalize_noun();
        printf("Nowhere %s you can go.\n", noun);
        look(0, 0);
        break;

      case LOOK:
        look(1, 1);
        break;

      case INVENTORY: {
        printf("You have: ");
        for (int i = 0; obj[i].name != NULL; ++i) {
            if (obj[i].location == NULL) {
                printf("%s  ", obj[i].name);
            }
          }
          printf("\n\n");
        break;
        }
      case GET:
        capitalize_noun();
        if (!strcmp(noun, "\n")) {
          printf("No object provided. Press help for help.\n\n");
          break;
        }

        int chosen_item_get = 0; // index of item in obj[n].
        int valid_item_flag_get = 0;
        for (int i = 0; obj[i].name != NULL; ++i) {
          if (!strcmp(noun, obj[i].name)) {
            chosen_item_get = i;
            valid_item_flag_get = 1;
            break;
          }
        }

        if (valid_item_flag_get && obj[chosen_item_get].location == player_location) {
          obj[chosen_item_get].location = NULL;
          printf("You have a %s.\n\n", obj[chosen_item_get].name);
          break;
        }

        capitalize_noun();
        printf("You don't see a %s here.\n\n", noun);

        break;

      case DROP:
        capitalize_noun();
        int chosen_item_drop = 0; // index of item in obj[n].
        int valid_item_flag_drop = 0;
        for (int i = 0; obj[i].name != NULL; ++i) {
          if (!strcmp(noun, obj[i].name)) {
            chosen_item_drop = i;
            valid_item_flag_drop = 1;
            break;
          }
        }

        if (valid_item_flag_drop && obj[chosen_item_drop].location == NULL) {
          obj[chosen_item_drop].location = player_location;
          printf("You dropped a %s.\n\n", obj[chosen_item_drop].name);
          break;
        }

        capitalize_noun();
        printf("You don't have a %s.\n\n", noun);
        break;

      case MAKE:
        if (player_location != &map[KITCHEN]) {
          printf("You cannot make that here.\n\n");
          break;
        }

        if (strstr(noun, "soup") && strstr(noun, "bowl")) {
          if (obj[SOUP_CAN].location == NULL && obj[BOWL].location == NULL && obj[CAN_OPENER].location == NULL) {
            obj[BOWL_OF_SOUP].location = NULL;
            printf("You made a Bowl of Soup.\n\n");
            obj[SOUP_CAN].location = &map[USED];
            obj[BOWL].location = &map[USED];
            break;
          }

          printf("You do not have everything you need to make that.\n\n");
          break;
        }

      case EAT:
        if (obj[BOWL_OF_SOUP].location != NULL) {
          printf("Nothing to eat.\n\n");
          break;
        }

        if (player_location != &map[DINING_ROOM]) {
          printf("You cannot eat that here.\n\n");
          break;
        }

        enum items required_items[] = { SPOON, NAPKIN };
        if (obj[SPOON].location != NULL) {
          printf("Can't eat soup with your hands!\n\n");
          break;
        }

        if (obj[NAPKIN].location != NULL) {
          printf("What if you make a mess?\n\n");
          break;
        }

        printf("You ate the soup. Delicious. YOU WIN!\n\n\n\n");
        exit(0);
        break;

      case UNKNOWN:
      default:
        // determine correct error; strcmp returns false for empty input, true if different
        (strcmp(verb, "")) ? printf("I don't know how to \"%s\". Type help for help.\n\n", verb) : printf("No command entered. Type help for help\n\n");
        break;
    }
  }

  printf("Thanks for playing!\n");
  return 0;
}

void init_game(void)
{
  // start player in first room
  player_location = &map[LIVING_ROOM];

  return;
}

void game_help(void)
{
  // enum command { QUIT, HELP, GO, INVENTORY, LOOK, GET, DROP, UNKNOWN };
  printf("\n"
           "You are hungry and must eat. Find and prepare a meal.\n"
           "Enter command at \">> {Command}\"\n\n"

           "Commands:\n"
           "  Help:           Display these instructions again.\n"
           "  Go [direction]: Move to area in that direction if possible.\n"
           "  Inventory:      Check what you are carrying.\n"
           "  Look:           Check your surroundings.\n"
           "  Get [object]:   Add object to your inventory.\n"
           "  Drop [object]:  Remove object from your inventory.\n"
           "  Make [object]:  Make something new.\n"
           "  Eat:            Eat.\n"
           "  Quit:           Exit game.\n\n"
          );
  return;
}
void capitalize_noun() {
  noun[0] = toupper(noun[0]);
  int space_index = 0;
  while (noun[space_index] != ' ' && noun[space_index] != '\0') {
    ++space_index;
  }

  noun[space_index + 1] = toupper(noun[space_index + 1]);
}

enum command get_command(void)
{
  printf(">> ");
  if(fgets(command_buffer, MAX_CHARS, stdin) == NULL) {
    printf("Critical failure, input too long.\n");
    return QUIT;
  }

  for (int i = 0; i < MAX_CHARS; ++i) {
    command_buffer[i] = tolower(command_buffer[i]);
  }

  int len_input = strcspn(command_buffer, "\n");
  command_buffer[len_input] = '\0';

  // Extract verb
  int len_verb = strcspn(command_buffer, " ");
  command_buffer[len_verb] = '\0';
  verb = command_buffer;
  // printf("%c\n", verb[0]);

  // Extract noun
  noun = command_buffer + len_verb + 1;
  int len_noun = strcspn(noun, "\n");
  noun[len_noun] = '\0';

  // Return proper command
  char *command_strings[] = {"quit", "help", "go", "inventory", "look", "get", "drop", "make", "eat"};
  for (enum command i = QUIT; i < UNKNOWN; ++i) {
    if (!strcmp(verb, command_strings[i])) {
        return i;
    }
  }

  return UNKNOWN;
}

void look(int directions, int objects) {
  printf("You are in the %s.", player_location -> name);

  if (directions) {
    printf("\nOpen directions: ");
    for (int i = N; i <= W; ++i) {
      if (player_location -> exit[i] != NULL) {
        printf("%s   ", directions_list[i]);
      }
    }
  }

  if (objects) {
    printf("\nYou see: ");
    for (int i = 0; obj[i].name != NULL; ++i) {
      if (obj[i].location == player_location) {
        printf("%s    ", obj[i].name);
      }
    }
  }
  printf("\n\n");
}
