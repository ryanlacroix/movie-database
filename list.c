#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

/* List Functions */

/*     Function: dl_init                                 */
/*           in: Location of dynamic linked list         */
/*          out: Initialized linked list                 */
/*      Purpose: Initializes head and tail of the list   */
/*               to NULL                                 */

void dl_init(DblList *dlist){
  dlist->head = NULL;
  dlist->tail = NULL;
}

/*     Function: dl_add                                  */
/*           in: Location of dynamic linked list         */
/*           in: Movie to add to the list                */
/*          out: Location of modified linked list        */
/*      Purpose: Adds a new node to the list             */

void dl_add(DblList *dlist, Movie *newMovie){
  // Aplhabetical arrangement slightly off, fix later
  Node *currNode;
  Node *prevNode;
  Node *newNode;

  // Set up the new node
  newNode = malloc(sizeof(Node));
  newNode->data = newMovie;
  newNode->prev = NULL;
  newNode->next = NULL;
  prevNode = NULL;

  currNode = dlist->head;

  if (currNode == NULL) { // insert into empty list
    dlist->head = newNode;
    dlist->tail = newNode;
    return;
  }

  while (currNode != NULL)
  {
    // Compare first letter of movie titles
    if (currNode->data->title[0]>newMovie->title[0]) {
      break;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }
  if (currNode == NULL) {
    // set currNode to end of the list
    currNode = dlist->tail;
  }
  if (prevNode == NULL && currNode->next != NULL) { //insert at start
    currNode->prev = newNode;
    newNode->next = currNode;
    newNode->prev = NULL;
    dlist->head = newNode;
    return;
  }
  if (prevNode != NULL && currNode->next != NULL) {// insert at middle
    newNode->next = currNode;
    newNode->prev = currNode->prev;
    currNode->prev->next = newNode;
    currNode->prev = newNode;
    return;
  }
  if (prevNode != NULL && currNode->next == NULL) {// insert at end
    currNode->next = newNode;
    newNode->next = NULL;
    newNode->prev = currNode;
    dlist->tail = newNode;
    return;
  }
}

/*     Function: dl_del                                  */
/*           in: Location of dynamic linked list         */
/*           in: Address of movie to remove              */
/*          out: Location of modified linked list        */
/*      Purpose: Deletes a node in the list              */

void dl_del(DblList *dlist, Movie *newMovie)
{
  Node *currNode;
  Node *prevNode;

  prevNode = NULL;
  currNode = dlist->head;

  if (currNode == NULL) {
    printf("The list is empty!\n");
    return;
  }

  while (currNode != NULL)
  {
    if (currNode->data == newMovie) {
      // Movie to delete has been found
      break;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }
  if (currNode == NULL) {
    printf("That movie isn't in the list!\n");
    return;
  }
  if (prevNode == NULL && currNode->next == NULL) { //only item present
    dlist->head = NULL;
    dlist->tail = NULL;
    free(currNode->data);
    free(currNode);
    return;
  }
  if (prevNode == NULL && currNode->next != NULL) {// delete from start
    dlist->head = currNode->next;
    currNode->next->prev = NULL;
    free(currNode->data);
    free(currNode);
    return;
  }
  if (prevNode != NULL && currNode->next != NULL) {// delete from middle
    prevNode->next = currNode->next;
    currNode->next->prev = currNode->prev;
    free(currNode->data);
    free(currNode);
    return;
  }
  if (prevNode != NULL && currNode->next == NULL) {// delete from end
    dlist->tail = prevNode;
    prevNode->next = NULL;
    free(currNode->data);
    free(currNode);
    return;
  }
  
}

/*     Function: dl_printFwd                             */
/*           in: Location of dynamic linked list         */
/*      Purpose: Prints the list forwards                */

void dl_printFwd(DblList *dlist)
{
  Node *currNode;
  currNode = dlist->head;
  printf("\n");
  while (currNode != NULL)
  {
    printf("Title: %s Year: %d\n", currNode->data->title,
           currNode->data->year);
    currNode = currNode->next;
  }
  printf("\n");
}

/*     Function: dl_printBack                            */
/*           in: Location of dynamic linked list         */
/*      Purpose: Prints the list backwards               */

void dl_printBack(DblList *dlist)
{
  Node *currNode;
  currNode = dlist->tail;
  if (currNode == NULL)
    printf("null found at tail");

  printf("\n");
  while (currNode != NULL)
  {
    printf("Title: %s Year: %d\n", currNode->data->title,
           currNode->data->year);
    currNode = currNode->prev;
  }
  printf("\n");
}

/*     Function: dl_printByGenre                         */
/*           in: Location of dynamic linked list         */
/*           in: Genre of movies to search for           */
/*      Purpose: Prints the list by genre                */

void dl_printByGenre(DblList *dlist, enum MovieGenre genre)
{
  Node *currNode;
  currNode = dlist->head;
  while (currNode != NULL)
  {
    if (currNode->data->genre == genre) {
      printf("Title: %s Year: %d\n", currNode->data->title,
              currNode->data->year);
    }
    currNode = currNode->next;
  }
}

/*     Function: dl_cleanup                              */
/*           in: Location of dynamic linked list         */
/*      Purpose: Frees dynamically allocated memory      */

void dl_cleanup(DblList *dlist)
{
  Node *currNode;
  currNode = dlist->head;

  // free the nodes
  while (dlist->head != NULL)
  {
    currNode = dlist->head;
    dlist->head = dlist->head->next;
    free(currNode->data);
    free(currNode);
  }
  // free the list itself
  free(dlist);
}

/* Assorted Functions */

/*     Function: movieSearch                             */
/*           in: Location of dynamic linked list         */
/*           in: Location of pointer to a movie          */
/*      Purpose: Searches for a particular movie in      */
/*               the list                                */

void movieSearch(DblList *dlist, Movie **moviePtr)
{
  Node *currNode;
  char input[MAX_STR];

  printf("Please input movie title: ");
  scanf("\n%[^'\n']s", input);

  currNode = dlist->head;

  if (currNode == NULL) {
    printf("There are no movies in the list!");
    return;
  }
  while (currNode != NULL)
  {
    if (strcmp(currNode->data->title, input) == 0) {
      *moviePtr = currNode->data;
      return;
    }
    currNode = currNode->next;
  }
  printf("The movie was not found. Perhaps check spelling?\n");
  return;
}


