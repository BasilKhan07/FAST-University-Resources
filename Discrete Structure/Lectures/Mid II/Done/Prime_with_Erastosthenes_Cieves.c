#include <stdio.h>
#include <math.h>

#define MAX 1000000

    int main() {
    	int i,j;
  /* Create an array of values, where '1' indicates that a number is prime.
   * Start by assuming all numbers are prime by setting them to 1.
   */
  char primes[MAX];
  for (i =0 ; i<MAX; i++) {
    primes[i] = 1;
  }

  /* Loop through a portion of the array (up to the square root of MAX). If
   * it's a prime, ensure all multiples of it are set to zero (false), as they
   * clearly cannot be prime.
   */
  int limit = sqrt(MAX) + 1;
  for (i=2; i<limit; i++) {
    if (primes[i-1]) {
      for (j=i*i; j<=MAX; j+=i) {
        primes[j-1] = 0;
      }
    }
  }
	printf("Primes Calculated");
//	scanf("%d");
  /* Output the results */
  int count = 0;
  for (i=2; i<=MAX; i++) {
    if (primes[i-1]) {
      printf("%d\n", i);
      count++;
    }
  }
  printf("There were %d primes up to %d", count, MAX);

  return 0;
}

