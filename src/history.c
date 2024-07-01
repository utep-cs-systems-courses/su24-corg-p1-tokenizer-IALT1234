#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_Item {

  int id;

  char *str;

  struct s_Item *next;

} Item;



typedef struct s_List {

  struct s_Item *root;

} List;

/* Initialize the linked list to keep the history. */

List* init_history(){
  List *history = (List*)malloc(sizeof(List));
  
  history->root = NULL;
  return history;
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){

  Item *new = (Item*)malloc(sizeof(List));
  new->str = strdup(str);
  
  if (list == NULL){

    list->root = new;
    return;
  }
  Item *temp = list->root;
  
  while (temp->next != NULL) {
    temp = temp->next;
  }
 
  temp->next = new;
}

/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){
  if (list == NULL) return NULL;

  Item *current = list->root;
  while (current != NULL) {
    if (current->id == id) {
      return current->str;
    }
    current = current->next;
  }
  return NULL;
}



/*Print the entire contents of the list. */

void print_history(List *list){
  if (list == NULL) return;

  Item *current = list->root;
  while (current != NULL) {
    printf("ID: %d, String: %s\n", current->id, current->str);
    current = current->next;
  }

}

/*Free the history list and the strings it references. */

void free_history(List *list){
  if (list == NULL) return;

  Item *current = list->root;
  while (current != NULL) {
    Item *next = current->next;
    free(current->str); // Free the string
    free(current); // Free the item
    current = next;
  }
  free(list); // Free the list
}
