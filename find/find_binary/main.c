#include <stdio.h>
#include <stdlib.h>
#define N 10000

int
main ()
{

  int i, p, r, l, id[N];

  for (i = 0; i < N; i++)
    id[i] = i;

  while (scanf ("%d", &p) == 1)
    {
      l = 0;
      r = N-1;
      while (r >= l)
	{
	  int m = (l + r) >> 1;
	  if (p == id[m])
	    {
	      printf ("index %d = %d\n", p, m);
	      break;
	    }
	  if (p < id[m])
	    r = m - 1;
	  else
	    l = m + 1;
	}

    }

  return EXIT_SUCCESS;

}
