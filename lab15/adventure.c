/**************************************************
 * Lab:         Lab 15
 * Description: Text Adventure Starter kit
 *              You may use this starter kit for your text
 *              adventure for lab 15.
 *
 *              It compiles and runs as it stands, but it does
 *              not get far: get_command() is a stub that returns
 *              QUIT, so the game greets you and ends on the
 *              spot. Writing get_command() is the first job and
 *              the biggest one. The TBDs are yours.
 * ***********************************************/

// You will need all four of these: string.h for fgets() and the string
// handling around it, ctype.h for tolower(), stdbool.h if you write a helper
// that returns true or false.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Useful defines:
// enum used for the 4 directions. These double as the subscripts into a room's
// exit[] array, so exit[N] is always the way north no matter what order they
// are written in.
enum direction { N, E, S, W };

// The rooms, so everything below can say which room it means by name instead
// of by number. A new room goes in both this enum and the map[] below, but
// then a slip is a compile error rather than a door that quietly opens
// somewhere else.
enum place { LIVING_ROOM, DINING_ROOM, KITCHEN, OFFICE, PANTRY };

// Every command the game understands, and the list of words you have to
// recognise. get_command() returns one of these, so main() can switch on it
// instead of picking the words apart again. UNKNOWN is what you give back for
// anything else, including a blank line.
enum command { QUIT, HELP, GO, INVENTORY, LOOK, GET, DROP, UNKNOWN };

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
  { "Soup", &map[PANTRY] },
  { "Bowl", &map[LIVING_ROOM] },
  { "Letter Opener", &map[OFFICE] },
  { "Pocket Fluff", NULL },
  { NULL, NULL } // null item to flag the end of the list
};

// function declarations
void init_game(void);
void game_help(void);    // prints basic instructions for use

// command proc
enum command get_command(void); // returns QUIT when the player is done
char command_buffer[100]; // store input from user
char *verb;  // current command verb, as they typed it
char *noun;  // the rest of the line after the verb, or NULL if there was none


// Globals...
struct room *player_location;

int main(void) {

  enum command cmd;

  init_game();

  printf("Welcome to the game!\n");
  // TBD: Add intro text and initial instructions.
  game_help();

  while ((cmd = get_command()) != QUIT) {
    switch (cmd) {

      case HELP:
        game_help();
        break;

      // The five below are the lab. Each one prints a placeholder for now, so
      // you can see that the command and the noun arrived intact; delete the
      // printf as you write the real thing.

      case GO:
        // TBD: work out which direction the noun names, then follow
        // player_location->exit[that direction] if it is not NULL. Say where
        // they ended up, or that they can't go that way.
        printf("(go: not written yet, noun = \"%s\")\n", noun ? noun : "(none)");
        break;

      case LOOK:
        // TBD: name the room, the items whose location is this room, and the
        // directions whose exit is not NULL.
        printf("(look: not written yet)\n");
        break;

      case INVENTORY:
        // TBD: list the items whose location is NULL, or say they are carrying
        // nothing.
        printf("(inventory: not written yet)\n");
        break;

      case GET:
        // TBD: find an item in this room whose name matches the noun and set
        // its location to NULL. Say so, or say it isn't here.
        printf("(get: not written yet, noun = \"%s\")\n", noun ? noun : "(none)");
        break;

      case DROP:
        // TBD: find a carried item whose name matches the noun and set its
        // location to player_location. Say so, or say they don't have it.
        printf("(drop: not written yet, noun = \"%s\")\n", noun ? noun : "(none)");
        break;

      case UNKNOWN:
      default:
        printf("I don't know how to \"%s\". Type help for help.\n", verb);
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
  printf("\nHere's how to play\n");
  // TBD: Add basic instruction text. enum command above is the list of words
  // you need to describe.

  return;
}

/* ---------------------------------------------------------------------------
   get_command() -- read one line from the player and report what they asked
   for. This one is yours, and it is the heart of the lab: everything in main()
   is waiting on what you return from here.

   A plan, in the order the work happens:

     1. Print the prompt, so the player knows it is their turn. printf("\n> ")
        is enough.

     2. Read a line into command_buffer with fgets(), and CHECK WHAT IT
        RETURNS. fgets() hands back NULL when there is no more input -- the
        player pressed Ctrl+D, or a file being piped in ran out. Nothing else
        is ever coming, so return QUIT when that happens. Skip this check and
        fgets() leaves the *previous* command sitting in the buffer, which the
        loop in main() then runs again, and again, forever. It is the single
        most common way this lab hangs, and it does not hang quietly: a version
        of this kit without the check printed fifty-six million lines in three
        seconds.

     3. fgets() keeps the newline the player typed, and "go\n" does not match
        the word "go". Write a '\0' over it. strcspn(command_buffer, "\n")
        tells you where it is.

     4. Split the line into the verb (the first word) and the noun (the rest).
        strchr() finds the first space; a '\0' written over that space ends the
        verb, and what comes after it is the noun. Set noun to NULL when there
        is no noun, because main() tests for exactly that. Take the WHOLE rest
        of the line, not just the next word -- "Letter Opener" and "Pocket
        Fluff" are two-word item names, and the example session types
        "get paper clip".

     5. Work out which command the verb names and return it. An array of
        strings kept in the same order as enum command turns this into a short
        loop: if names[GO] is "go", then the subscript you find the word at IS
        the value to return. That is what an enum is for, and it is the same
        trick as exit[N] in the map above. Keeping the two lists in step is
        your job -- add a command and you add it in both places.

     6. Return UNKNOWN for anything you don't recognise, including a blank
        line. main() already prints a "don't know how" message for it.

   One thing you will need on the way: the player types "get letter opener",
   but the item is stored as "Letter Opener", so your comparisons have to
   ignore capitals. strcmp() does not. strcasecmp() does, but it is not part of
   standard C -- under -std=c99 it isn't even declared, and your compiler will
   say so. tolower() from <ctype.h> is standard, and a function that walks two
   strings a character at a time, lowering each one as it goes, is about four
   lines long. Write it as its own function: you will want it again for the
   item names in GET and DROP.
   --------------------------------------------------------------------------- */
enum command get_command(void)
{
  // TBD: all of the above.
  //
  // Until then this returns QUIT, which is why the game ends the moment it
  // starts. That is also your first test: once you are reading a line and
  // returning something else, the loop in main() starts answering you.
  return QUIT;
}
