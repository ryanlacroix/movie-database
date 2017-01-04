#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

/*     Function: runUI                                   */
/*           in: Location of dynamic linked list         */
/*      Purpose: Runs a simple interface for the user to */
/*               navigate the movie database             */

void runUI(DblList *dlist)
{
  while(1)
  {
    printf("Welcome to the movie database! Your options are as follows: \n");
    printf("Command       Description \n");
    printf("    add        Enter menu to add movie to database\n");
    printf(" remove        Enter menu to remove movie from database\n");
    printf("  print        Enter menu for database printing options\n");
    printf("   exit        Exits the program\n");
    char input[MAX_STR];
    scanf("\n%[^'\n']s", input);
  
    if (strcmp(input, "add") == 0) {
     addMenu(dlist);
    }
    if (strcmp(input, "remove") == 0) {
     removeMenu(dlist);
    }
    if (strcmp(input, "print") == 0) {
     printMenu(dlist);
    }
    if (strcmp(input, "exit") == 0) {
     return;
    }
  }
}

/*     Function: addMenu                                 */
/*           in: Location of Dynamic Linked List         */
/*      Purpose: Interface for the user to add a movie   */
/*               to the database                         */

void addMenu(DblList *dlist)
{
  printf("Enter the title of the movie to add: ");
  char title[MAX_STR];
  scanf("\n%[^'\n']s", title);

  printf("Enter the year of the movie to add: ");
  int year;
  scanf("%d", &year);

  printf("Enter the name of the lead actor/actress: ");
  char player[MAX_STR];
  scanf("\n%[^'\n']s", player);
 
  printf("Enter the genre (options: horror, action, comedy, artsy, drama): ");
  char genre[MAX_STR];
  scanf("\n%[^'\n']s", genre);

  // create the movie as per user's input
  Movie *m1;
  m1 = malloc(sizeof(Movie));
  strcpy(m1->title, title);
  m1->year = year;

  // set correct genre
  if (strcmp(genre, "horror") == 0)
    m1->genre = HORROR;
  if (strcmp(genre, "action") == 0)
    m1->genre = ACTION;
  if (strcmp(genre, "drama") == 0)
    m1->genre = DRAMA;
  if (strcmp(genre, "comedy") == 0)
    m1->genre = COMEDY;
  if (strcmp(genre, "artsy") == 0)
    m1->genre = ARTSY;

  strcpy(m1->lead, player);
  // add the movie to the database
  dl_add(dlist, m1);
}

/*     Function: removeMenu                              */
/*           in: Location of dynamic linked list         */
/*      Purpose: Interface for the user to remove a      */
/*               from the database                       */

void removeMenu(DblList *dlist)
{
  printf("Here are the movies currently in the database:\n");
  dl_printFwd(dlist);
  printf("\n");
  
  Movie *searchMov;
  movieSearch(dlist, &searchMov);
  dl_del(dlist, searchMov);
}

/*     Function: printMenu                               */
/*           in: Location of dynamic linked list         */
/*      Purpose: Interface for the user to print movies  */
/*               from the database                       */

void printMenu(DblList *dlist)
{
  printf("How would you like the movies to be printed?\n ");
  printf("options: forward, backward, genre\n");
  char entry[MAX_STR];
  scanf("\n%[^'\n']s", entry);
  if (strcmp(entry, "forward") == 0) {
    dl_printFwd(dlist);
  }
  if (strcmp(entry, "backward") == 0) {
    dl_printBack(dlist);
  }
  if (strcmp(entry, "genre") == 0) {
    printf("What genre is to be printed?\n");
    printf("options: horror, action, comedy, artsy, drama\n");
    char genreEntry[MAX_STR];
    scanf("\n%[^'\n']s", genreEntry);
    if (strcmp(genreEntry, "horror") == 0) {
      dl_printByGenre(dlist, HORROR);
      return;
    }
    if (strcmp(genreEntry, "action") == 0) {
      dl_printByGenre(dlist, ACTION);
      return;
    }
    if (strcmp(genreEntry, "comedy") == 0) {
      dl_printByGenre(dlist, COMEDY);
      return;
    }
    if (strcmp(genreEntry, "artsy") == 0) {
      dl_printByGenre(dlist, ARTSY);
      return;
    }
    if (strcmp(genreEntry, "drama") == 0) {
      dl_printByGenre(dlist, DRAMA);
      return;
    }
  }
}
