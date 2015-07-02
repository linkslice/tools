#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[1000])
{
  char str[1000];
  int oid;
  int end = 0;

  if (argc>1){
    strcpy(str, argv[1]);
  }else{
    printf("input ENTIRE f5 oid to convert: ");
    scanf("%s",&str);
  }

  char * pch;

  pch = strtok (str,".");
  while (pch != NULL)
  {
    oid = atoi(pch);
    if (oid == 1){
      pch = strtok (NULL, ".");
      oid = atoi(pch);
      if (oid == 4){
        end++;
      }
    }
    if (end == 2){
      break;
    }
    if (oid >= 'A' && oid <= 'z' ) {
      printf("%c", oid);
      pch = strtok (NULL, ".");
    }else{
      pch = strtok (NULL, ".");
    }
  }
  printf("\n");
  return 0;
