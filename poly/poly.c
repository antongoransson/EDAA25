#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "error.h"
#include "poly.h"
// SCORE  908

struct poly_t {
  poly_t* next;
  long degree;
  int nbr;
};

poly_t*	new_poly_from_string(const char* c)
{
  poly_t* head;
  poly_t* curr;
  poly_t* next;

  head = calloc(1,sizeof(poly_t));
  curr = head;
  curr->degree=0;
  int i;
  for (i = 0; i < strlen(c); i++) {
    if (c[i] == 'x') {
      i++;
      if (c[i] == '^') {
        i++;
        while (isdigit(c[i])) {
          curr->degree= curr->degree*10 + c[i]-'0';
          i++;
        }
      } else {
      curr->degree = 1;
      }
    } else if (isdigit(c[i])) {
      while (isdigit(c[i])) {
        if (curr->nbr == -1)
          curr->nbr = curr->nbr*(c[i]-'0');
        else
          curr->nbr = curr->nbr*10 + c[i]-'0';
        i++;
      }
      i--;
    } else if (c[i] == '+' || c[i] == '-') {
        next = calloc(1, sizeof(poly_t));
        curr->next = next;
        if (curr->nbr == 0)
          curr->nbr=1;
        curr = next;
        curr->degree = 0;
        if (c[i] == '-')
          curr->nbr=-1;
        else
          curr->nbr=0;
      }
  }
  return head;
}

poly_t* mul(poly_t* p1, poly_t* p2)
{
  poly_t* curr;
  poly_t* next;
  poly_t* newP = calloc(1, sizeof(poly_t));;
  poly_t* currp2 = p2;
  poly_t* currp3;

  curr = currp3 = newP;
  long d1,d2;
  int nbr1,nbr2;


  int same_deg=0;
  while (p1 != NULL) {
    d1 = p1->degree;
    nbr1 = p1->nbr;
    while (currp2 != NULL) {
      d2 = currp2->degree;
      nbr2 = currp2->nbr;
      while (currp3 != NULL) {
        if (currp3->degree == (d1 + d2) ) {
          currp3->nbr = currp3->nbr + nbr1 * nbr2;
          same_deg=1;
        }
        currp3 = currp3->next;
      }
      if (!same_deg) {
        next = calloc(1, sizeof(poly_t));
        curr->degree = d1 + d2;
        curr->nbr = nbr1 * nbr2;
        curr->next = next;
        curr = next;
      }
      currp2 = currp2->next;
      same_deg = 0;
      currp3 = newP;
    }
    p1 = p1->next;
    currp2 = p2;
  }
  return newP;
}

void print_poly(poly_t* p)
{
  poly_t* poly = p;
  while (poly != NULL) {
    if (poly != p) {
      if (poly->nbr > 0)
        printf("+ ");
      else
        printf("- ");
    }
    if (poly->degree > 0 && poly->nbr != 1) {
      if (poly->nbr <0)
        printf("%d",-poly->nbr );
      else
        printf("%d",poly->nbr );
    } else if (poly->degree == 0)
      printf("%d",poly->nbr );
    if (poly->degree > 1)
      printf("x^%ld ",poly->degree);
    else if (poly->degree == 1)
        printf("x ");
    poly = poly->next;
  }
  printf("%s\n","");
}
void free_poly(poly_t* p)
{
  poly_t* q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}
