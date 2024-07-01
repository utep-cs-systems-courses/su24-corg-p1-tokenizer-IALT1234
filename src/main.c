#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"
#include <ctype.h>

int main(){
  List *history = init_history();
  char input[256];

  while (1) {
    printf("Enter a command: ");
    if (!fgets(input, sizeof(input), stdin)) break;
    input[strcspn(input, "\n")] = 0; // Remove newline
    if (input[0] == '!' && isdigit(input[1])) {
      int id = atoi(&input[1]);
      char *history_str = get_history(history, id);
      printf("Recalled: %s\n", history_str ? history_str : "No such item");

    } else {
      add_history(history, input);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      free_tokens(tokens);
    }
  }

  free_history(history);
  return 0;

}
