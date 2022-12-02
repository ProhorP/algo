#include <stdio.h>
#include <stdlib.h>
#define N 10000

int
main ()
{

  int i, j, p, q, t, id[N], sz[N];

  for (i = 0; i < N; i++)
    {
      id[i] = i;
      sz[i] = 1;
    }

  while (scanf ("%d %d", &p, &q) == 2)
    {

      for (i = p; i != id[i]; i = id[i]);
      for (j = q; j != id[j]; j = id[j]);

      if (i == j)
	continue;

      if (sz[i] < sz[j])
	{
	  id[i] = j;
	  sz[j] += sz[i];
	}
      else
	{
	  id[j] = i;
	  sz[i] += sz[j];
	}

      printf ("  %d %d\n", p, q);

    }

  for (i = 0; i < N; i++)
    {
      if (id[i] != id[id[i]])
	{
	  for (j = i; j != id[j]; j = id[j]);
	  id[i] = j;
	}
    }

  return EXIT_SUCCESS;

}
