#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
  int x;
  int y;
} point;

typedef struct node *link;
struct node
{
  point p;
  link next;
};

link **grid;
int G;
float d;
int cnt = 0;

link **
malloc2d (int r, int c)
{
  int i;
  link **t = (link **) malloc (r * sizeof (link *));
  for (i = 0; i < r; i++)
    t[i] = (link *) malloc (c * sizeof (link *));
  return t;
}

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

void
gridinsert (float x, float y)
{
  int i, j;
  link s;
  int X = x * G + 1;
  int Y = y * G + 1;
  link t = (link) malloc (sizeof (*t));
  t->p.x = x;
  t->p.y = y;
  for (i = X - 1; i <= X + 1; i++)
    for (j = Y - 1; j <= Y + 1; j++)
      for (s = grid[i][j]; s != NULL; s = s->next)
	if (distance (s->p, t->p) < d)
	  cnt++;

  t->next = grid[X][Y];
  grid[X][Y] = t;

}

int
main (int argc, const char **argv)
{

  int i, j, N = atoi (argv[1]);
  d = atof (argv[2]);
  G = 1 / d;
  grid = malloc2d (G + 3, G + 3);

  for (i = 0; i < G + 3; i++)
    for (j = 0; j < G + 3; j++)
      grid[i][j] = NULL;

  for (i = 0; i < N; i++)
    gridinsert (rand_float (), rand_float ());

  printf ("%d edges shorted than %f\n", cnt, d);

  return EXIT_SUCCESS;
}
