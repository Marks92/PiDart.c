/* CS 153 PROGRAM ASSIGNMENT #6

Program that test dart throws and finds pi
based off the number of darts thrown that fall
within the circumference of the circle. 

Mark Schuberth 
 
10/22/2018 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> /* used for srand() */

/* returns a random double between -1 and 1 */
double randDouble()
{
  return 2*(double)rand()/((double)RAND_MAX)-1;
}

/* uses pointers for x and y to create a random */
/* distance of x and y between -1 and 1 */
void throwDart(double *x, double *y)
{
 *x = randDouble();
 *y = randDouble();
}

/* main function that asks user for number of */
/* darts and then computes pi based on how many */
/* fall within the circle */
int main()
{
 int darts = 0, i, count = 0;
 double x, y, dist, calcPi;
 
 /* used to initialize rand() */
 srand(time(NULL));
 
 /* prompts user for # of darts to throw */
 printf("Please enter number of darts: ");
 scanf("%d", &darts);
 
 /* main loop that calls throwDart() and */
 /* computes how many fall within the circle */
 /* these darts are used to calculate pi */
 for(i = 0; i <= darts; i++)
 {
  throwDart(&x, &y);
  
  dist = sqrt(x*x + y*y);
  
  /* darts within circle counted here */
  if(dist <= 1)
  {
   count++;
  }
 }
 
 /* calculation of pi using darts within circle */
 calcPi = (double)count/darts*4;
 printf("Calculation of pi = %0.3lf", calcPi);
 
 return 0;
}