#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
  int x;
  int y;
} point;

float
rand_float ()
{
  return 1.0 * rand () / RAND_MAX;
}

float
distance (point a, point b)
{
  float dx = a.x - b.x;
  float dy = a.y - b.y;

  return sqrt (dx * dx + dy * dy);

}

int
main (int argc, char **argv)
{

  float d = (float) atof (argv[2]);
  int i, j, cnt = 0, N = (int) atoi (argv[1]);

  point *a = (point *) malloc (N * sizeof (point));

  for (i = 0; i < N; i++)
    {
      a[i].x = rand_float ();
      a[i].y = rand_float ();
    }

  for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++)
      if (distance (a[i], a[j]) < d)
	cnt++;

  printf ("%d edges shorted than %f\n", cnt, d);

  return EXIT_SUCCESS;
}
