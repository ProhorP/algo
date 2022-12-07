#include <stdio.h>
#include <stdlib.h>
#define V 5

typedef struct node *link;
struct node
{
  int v;
  link next;
};

link
new (int v, link next)
{
  link x = (link) malloc (sizeof (*x));
  x->v = v;
  x->next = next;
  return x;
}

int
main ()
{

  int i, j;
  link adj[V];
  link t, y;

  for (i = 0; i < V; i++)
    adj[i] = NULL;

  while (scanf ("%d %d", &i, &j) == 2)
    {
      adj[i] = new (j, adj[i]);
      adj[j] = new (i, adj[j]);
    }

  for (i = 0; i < V; i++)
    for (t = adj[i]; t != NULL; t = y)
      {
	y = t->next;
	free (t);
      }

  return EXIT_SUCCESS;
}
