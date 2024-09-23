#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

unsigned long long int fib_iterative(int N){
   unsigned long long int x = 0;
   unsigned long long int y = 1;
   unsigned long long int next_int;

   if(N <= 0){ return 0; }    // checks if 'N' is 0.
   if (N == 1){ return 1; }   // checks if 'N' is 1. 
   for (int i = 2; i <= N; i++){
      next_int = x + y;       // 'next_int' is the sum of x & y.
      x = y;                  // 'x' value is assigned the 'y' value.
      y = next_int;           // 'y' value is assigned the 'next_int' value.
   }
   return y;
}

unsigned long long int fib_recursive(int N){
   if(N <= 0){ return 0; }    // checks if 'N' is 0.
   if(N == 1){ return 1; }    // checks if 'N' is 1.
   return fib_recursive(N - 1) + fib_recursive(N - 2);
}

int main(int argc, char* argv[]) {
   char *terminal_number = argv[1];
   char *method = argv[2];
   if (argc < 3){
      printf("ERROR: not enough arguments.\n");
      exit(0);
   }
   int number = 0;
   int term_num = strtol ( terminal_number, NULL, 10 );
   int N = number + term_num;

   if ( method[0] == 'r' ){         // Recursive method
      unsigned long long fib_value = fib_recursive(N);
      printf("%llu\n", fib_value);
   } else if ( method[0] == 'i' ){  // Iterative method
      unsigned long long fib_value = fib_iterative(N);
      printf("%llu\n", fib_value);
   } else {
      printf("ERROR: Invalid input.\n");
      exit(0);
   }
   return 0;
}
