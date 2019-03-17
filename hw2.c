#include <limits.h>
#include <string.h>
#include "hw2.h"
/*
 * This function returns the smallest integer in the list elements that is
 * passed as parameter. Created a new variable int small which returns the
 * smallest integer in the list. 
 * */
int smallest(int elements[], int size) {
  int small;   /*Declaring Variable small that stores and return the final
 smallest value in the list elements*/
  if (size<=0) { 
    return INT_MAX;
  }
  else {
    int i;   /* Declaring variable to use in the for loop*/
    small = elements[0];
    for (i=0;i<size;i++){
      if (elements[i]<small) {
        small = elements[i];
      } 
    }
    return small;
  }
} 
/*This function reverse the given string and stores that in the destination
 * that is passed as parameter. Variable i used in the for loop from 0 to
 * length of the source string that is passed as paramter. Using variable j that
 * I have initially assigned 0 but increment by 1 everytime I complete one loop
 * of the for loop to move that to next index value.
 */
void reverse(const char source[], char destination[]) {
  int i, j=0, length = strlen(source);  /* Declaring variable i to be used in
 the for loop, declaring j=0 for indexing the reverse list, declaring length
 equal to the length of the given source string to be used in the for loop*/
  for (i=length; i>0;i--) {
    destination[j] = source[i-1];
    j++;
  }
  destination[j] = '\0'; 
}
/*This functions return 1 if the given arguments can be added without overflow
 * or underflow and 0 when they can't be added.
 * Created int variable sum that stores the value of a+b.
 * Created sign_a, sign_b, sign_sum which stores the most significant bit so
 * that I can compare if there is overflow or underflow based on a logic.
 * Returning based on logic 0 or 1 which decide if the addition is possible
 * or not.
 */
int addOK(int a, int b) {
  int sign_a, sign_b, sign_sum, sum; /*Declaring sign_a, sign_b, sign_sum which
stores the sign bit of a,b, and sum respectively. sum stors the sum of a and b*/
  sum = a + b;
  sign_a = a>>31 & 0x1;
  sign_b = b>>31 & 0x1;
  sign_sum = sum>>31 & 0x1;
  return( ((!sign_b) & (!sign_sum) ) |( sign_a & sign_sum ) | ( (!sign_a) & sign_b ) );
}
