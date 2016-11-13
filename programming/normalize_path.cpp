#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print(char *str)
{
  int i = 0;
  for ( i = 0; i < 20; i++ ) {
    printf("%c", str[i]);
  }
  printf("\n");
}

void remove_token(char *path)
{
    int last = strlen(path);
    while ( path[last] != '/' ) {
      last--;
    }
    path[last] = '\0';
}
// -- /dir-dir1/dir2/../dir3/./file.txt
char* get_next_token(char *path, int *off)
{
  int start = *off;
  char *next = (path + (*off));
  if ( path[*off] == '/' ){
    (*off)++;
  }
  while ( path[*off] != '/' && path[*off] != '\0' ) {
    (*off)++;
  }
  if ( path[*off] != '\0' ) {
    path[*off] = '\0';
    (*off)++;
  }
  return next;
}

char* normalize_path(char *path)
{
    char *dst = (char*)malloc(strlen(path)+1);
    if ( dst == NULL ) {
      return NULL;
    }

    int off = 0;
    while ( path[off] != '\0') {
      char *next = get_next_token(path, &off);
      if ( strncmp(next, "..", 2) == 0 ) {
        remove_token(dst);
      } else if ( strncmp(next, ".", 1) == 0 ) {
        continue;
      } else {
        if ( next[0] != '/' ) {
          strncat(dst, "/", 1);
        }
        strncat(dst, next, strlen(next));
      }
    }

    return dst;
}

int main(void)
{
    char *path = (char*)malloc(100);
    strcpy(path, "/dir/dir1/dir2/../../dir3/./file.txt");
    strcat(path, "\0");

    printf("Path = %s\n", path);
    char *npath = normalize_path(path);
    printf("Normalized path = %s\n", npath);
    if ( path != NULL ) {
      free(path);
    }
    return 0;
}
