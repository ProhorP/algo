#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;

struct node
{
  int item;
  link next;
}node;


int
main (int argc, char **argv)
{

  int i, n = atoi (argv[1]), m = atoi (argv[2]);

  link t = (link) malloc (sizeof (node));
  link x = t;

  t->item = 1;
  t->next = t;

  for (i = 2; i <= n; i++)
    {
      x = (x->next = (link) malloc (sizeof (node)));
      x->item = i;
      x->next = t;
    }

  while (x != x->next)
    {
      for (i = 1; i < m; i++)
	x = x->next;
      link old_next = x->next;
      x->next = old_next->next;
      free (old_next);

    }

  printf ("%d\n", x->item);

  return EXIT_SUCCESS;

}
