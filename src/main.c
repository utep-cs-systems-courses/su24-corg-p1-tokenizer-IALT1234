#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"


int main(){

  char text[100];
  
  printf("Say something:\n");
  
  fgets(text, sizeof(text), stdin);
  
  printf("%s", text);

  if(space_char(*text))
    printf("NO");

  else
    printf("YES");

  
  return 0;
}
