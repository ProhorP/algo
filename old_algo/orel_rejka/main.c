#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
heads ()
{
  return rand () < RAND_MAX / 2;
}

int
main (int argc, char *argv[])
{

  int i, j, cnt;
  int N = atoi (argv[1]);
  int M = atoi (argv[2]);
  int *f = malloc ((N + 1) * sizeof (int));

  char *fs = malloc (((M / 10) + 2) * sizeof (char));

  for (i = 0; i <= N; i++)
    f[i] = 0;

  for (i = 0; i < M; i++, f[cnt]++)
    for (j = 0, cnt = 0; j < N; j++)
      if (heads ())
	cnt++;

  for (i = 0; i <= N; i++)
    {
      for (j = 0, cnt = 0; cnt <= f[i]; cnt += 10, j++)
	fs[j] = '*';
      fs[j] = '\0';
      printf ("%2d %s\n", i, fs);
    }

  free (fs);
  free (f);

  return EXIT_SUCCESS;

}
