#define MAX_STR 32
#define MAX_ACTOR 5

enum MovieGenre {
  HORROR,
  COMEDY,
  DRAMA,
  ACTION,
  ARTSY
};

typedef struct {
  char name[MAX_STR];
} Actor;

typedef struct {
  char title[MAX_STR];
  int year;
  enum MovieGenre genre;
  char lead[MAX_STR];
} Movie;

typedef struct node1 {
  struct node1 *next;
  struct node1 *prev;
  Movie *data;
} Node;

typedef struct {
  Node *head;
  Node *tail;
} DblList;

/* Linked list functions */
void dl_init(DblList*); // done
void dl_add(DblList *dlist, Movie *newMovie); // 90% done (ordering)
void dl_del(DblList *dlist, Movie *newMovie); // done
void dl_printFwd(DblList *dlist); // done
void dl_printBack(DblList *dlist); // done
void dl_printByGenre(DblList *dlist, enum MovieGenre genre); // done
void dl_cleanup(DblList *dlist); // done

/* Assorted functions */
void movieSearch(DblList *dlist, Movie **moviePtr); // done
void runUI(DblList *dlist); // done, commented
void addMenu(DblList *dlist); // done, commented
void removeMenu(DblList *dlist); // done, commented
void printMenu(DblList *dlist); // done, commented

