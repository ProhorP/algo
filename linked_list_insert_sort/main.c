#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;

struct node
{
  int item;
  link next;
} node;

struct node heada = { 0, NULL }, headb = { 0, NULL };

int
main ()
{
  link t, x;
  int i = 0;

  for (i = 0, t = &heada; i < 5; i++)
    {

      t->next = (link) malloc (sizeof (node));
      t = t->next;
      t->next = NULL;
      t->item = rand () % 1000;

    }

  for (t = heada.next; t != NULL; t = heada.next)
    {
      heada.next = t->next;

      for (x = &headb; x->next != NULL; x = x->next)
	if (x->next->item > t->item)
	  break;
      t->next = x->next;
      x->next = t;
    }

  x = headb.next;

  while (x != NULL)
    {
      printf ("%d\n", x->item);
      x = x->next;
    }

  return EXIT_SUCCESS;
}
