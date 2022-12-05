#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;

struct node
{
  int item;
  link next;
} node;

struct node heada, headb;

int
main ()
{
  link t, u, x, a = &heada, b;
  int i = 0;

  for (i = 0, t = a; i < 5; i++)
    {

      t->next = (link) malloc (sizeof (node));
      t = t->next;
      t->next = NULL;
      t->item = rand () % 1000;

    }

  b = &headb;
  b->next = NULL;

  for (t = a->next; t != NULL; t = u)
    {
      u = t->next;

      for (x = b; x->next != NULL; x = x->next)
	if (x->next->item > t->item)
	  break;
      t->next = x->next;
      x->next = t;
    }

  x = b;

  while (x != NULL)
    {
      printf ("%d\n", x->item);
      x = x->next;
    }

  return EXIT_SUCCESS;
}
