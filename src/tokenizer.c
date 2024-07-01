#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int space_char(char c){ // true if c not a tab or space, and not zero
  if((c == ' ' || c == '\t')&&c != '\0')
    return 1;
      
  return 0;
}
int non_space_char(char c){ // true if c not a tab or space, and not zero
  if((c != ' ' || c != '\t')&&c != '\0')
    return 1;
      
  return 0;
} 
char *token_start(char *s){ // * to first (non-space) char in first token in s.  Return zero if there are no tokens in s.
  if (s == NULL)
    return NULL;
  
  while (1){
    if(non_space_char(*s))
      return s;
    s++;
  }  
  return NULL;
  
}
  
char *token_terminator(char *token){ // * to char after end of token.
  if (token == NULL)
    return NULL;
  
  while (1){
    if(space_char(*token))
      return token;
    token++;
  }  
  return NULL;

}  
  
int count_tokens(char *s){ // the number of tokens in s

  int counter = 0;
  while(*s!='\0'){
    if(space_char(*s))
      counter++;
    s++;
  
  return counter;
    
  }
  return 0;

}  
  
char *copy_str(char *inStr, short len){ // return a pointer to a (terminated) copy of inStr
  if (inStr == NULL || len <= 0)
    return NULL;
  
  char *copy = (char *)malloc((len + 1) * sizeof(char));
  if (copy == NULL)
    return NULL;
  
  strncpy(copy, inStr, len);
  copy[len] = '\0';
  
  return copy;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.



   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

*/

char **tokenize(char* str){
  int tokens_count = count_tokens(str);
  char **tokens = (char **)malloc((tokens_count + 1) * sizeof(char *));
  int i = 0;
  char *token = token_start(str);


  while (token) {
    char *end = token_terminator(token);
    tokens[i] = copy_str(token, end - token);
    i++;
    
    token = token_start(end);
  }
  tokens[i] = NULL;
  return tokens;
}

/* Prints all tokens. */

void print_tokens(char **tokens){
  if (tokens == NULL) return;
  for (int i = 0; tokens[i] != NULL; i++) {
    printf("Token[%d]: %s\n", i, tokens[i]);
  }
}



/* Frees all tokens and the vector containing themx. */

void free_tokens(char **tokens){
  if (tokens == NULL) return;
  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }
  free(tokens);

}
