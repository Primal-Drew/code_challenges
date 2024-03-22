#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alphabet_position(char *text) {
  const size_t text_len = strlen(text);
  char *s = calloc(text_len * 3 + 1, sizeof(char));

  for (char *ptr = text; *ptr; ptr++) {
    if (*ptr < 'A' || *ptr > 'z')
      continue;
    int c = 0;
    if (*ptr < 'a')
      c = *ptr - 'A' + 1;
    else
      c = *ptr - 'a' + 1;
    if (ptr == text)
      sprintf(s, "%d", c);
    else
      sprintf(s, "%s %d", s, c);
  }

  return s;
}