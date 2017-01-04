#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

int main(){
  DblList *movies;
  movies = malloc(sizeof(DblList));
  dl_init(movies);
  
  // Make a sample movie
  Movie *m1;
  m1 = malloc(sizeof(Movie));
  strcpy(m1->title, "Abominable Samsquamtch");
  m1->year = 2009;
  m1->genre = HORROR;
  strcpy(m1->lead, "Bob");

  // Make another sample movie
  Movie *m2;
  m2 = malloc(sizeof(Movie));
  strcpy(m2->title, "Zimbabwe The Movie");
  m2->year = 2001;
  m2->genre = COMEDY;
  strcpy(m2->lead, "Linda");

  // Add the sample movie
  dl_add(movies, m1);
  dl_add(movies, m2);

  // Run the user interface
  runUI(movies);
  
  // Free all memory used
  dl_cleanup(movies);
}
