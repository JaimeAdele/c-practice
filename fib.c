// write fibonacci function using dynamic programming

#include <stdio.h>
#include <stdlib.h>

// returns nth fibonacci number
int fib(int n) {
  int *table = malloc((sizeof (int)) * n);
  // set first two elements to 1 (fib(1) = 1 and fib(2) = 1)
  table[0] = 1;
  table[1] = 1;
  
  for (int i = 2; i < n; i++) {
    table[i] = table[i - 1] + table[i - 2];
  }

  return table[n - 1];
}

int main() {
  printf("fib(%d) = %d\n", 7, fib(7));
  return 0;
}