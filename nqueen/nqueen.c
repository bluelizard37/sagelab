/*---------------------------------------------------------------------------
 * 
 * nqueen.c 
 *
 *     10/10/2016 - 
 *
 *     <sagenyx@sagewicked.com>
 *
 *     Copyright (c) 2016 RedBack Networks, Inc.
 *     All rights reserved.
 *
 *---------------------------------------------------------------------------
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int*
alloc_vec(int n)
{
    int *vec = malloc(sizeof(int)*n);
    int i;
    for (i=0; i < n; i++) {
        vec[i] = -1;
    }
    return vec;
}

void
print_q(int n, int *vec)
{
    int i,j;
    int q;
    for (i=0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n\n");

    for (i=0; i < n; i++) {
        q = vec[i];
        for (j=0; j < n; j++) {
            if (j== q) {
                printf("Q");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

bool
is_safe(int cc, int cr, int *vec) 
{
   int i;
   int row, col;

   if ((cr == 0)  && (cc==0)) return true;

   for (i=0; i <=cr-1; i++) {
        col = vec[i];
        row = i;
        printf("[%s]: checking for cur (%d, %d) against exist (%d, %d) \n",
               __FUNCTION__, cr, cc, row, col);

        if ( (cc == col) || (( cr - cc) == (row - col)) || 
             ((cr+cc) == (row+ col))) {
            return false;
        }
   }
   return true;
}

bool
solve_n_queen(int n, int cr, int *vec) 
{
    int i;
   
    if (cr >= n) return false;

    for (i=0; i < n; i++) {
        if (is_safe(i,cr, vec)) {
            printf("[%s]: setting current row %d queen at %d\n",
                   __FUNCTION__, cr, i);
            vec[cr] = i;
            if (cr==(n-1)) return true;
            if (solve_n_queen(n,cr+1, vec)) {
                return true;
            } else {
                printf("[%s]: unsetting current row %d queen at %d\n",
                   __FUNCTION__, cr, i);
                vec[cr] = -1;
            }
        }
    }

    return false;
}


int main()
{
    int n = 8;
    int *vec = alloc_vec(n); 
    solve_n_queen(n,0,vec);
    print_q(n,vec);

   return 0;
}
