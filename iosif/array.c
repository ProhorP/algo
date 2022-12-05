#include <stdlib.h>
#include <stdio.h>

int
main (int argc, char **argv)
{

  int i, j, n = atoi (argv[1]), m = atoi (argv[2]);

  int *t = (int *) malloc (n * sizeof (int));

  for (i = 0, j = 1; i < n - 1; i++, j++)
    t[i] = j;

  t[n - 1] = 0;

  i = n-1;

  while (i != t[i])
    {
      for (j = 1; j < m; j++)
	i = t[i];
      t[i] = t[t[i]];
    }

  printf ("%d\n", i + 1);

  free (t);

  return EXIT_SUCCESS;

}
