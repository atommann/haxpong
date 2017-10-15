#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *line;
  int y;
  int i;
  int j;
  char *s;
  unsigned char chars[256][5];
  int nchars;
  line = malloc(1000);

  /* Read standard in */
  nchars = 0;
  while (1)
  {
    /* Read next char */
    chars[nchars][0] = 0;
    chars[nchars][1] = 0;
    chars[nchars][2] = 0;
    chars[nchars][3] = 0;
    chars[nchars][4] = 0;
    for (y=6; y>=0; y--)
    {
      s = fgets(line, 1000, stdin);
      if (s != line) goto nomorechars;
      for (i=0; line[i] != 0 && i < 5; i++)
        if (line[i] == '*')
          chars[nchars][i] |= 1<<y;
    }
    nchars++;
    s = fgets(line, 1000, stdin);
    if (s != line) goto nomorechars;
  }

nomorechars:

  /* Write fonts to standard out */
  printf("const int font_count = %d;\n", nchars);
  printf("const unsigned char font[%d][5] = {", nchars);
  for (i=0; i<nchars; i++)
  {
    printf("\n  {");
    for (j=0; j<5; j++)
    {
      printf("0x%02x%s", chars[i][j], (j<4)?", ":"");
    }
    printf("}%s", (i<nchars-1)?",":"");
  }
  printf("};\n");
  
  return 0;
}
