#include "ulam.h"

int is_prime(int n) {
  if(n < 2) {
    return false;
  }

  int low = 2;
  int high = floor(sqrt(n));
  while(low <= high) {
    if(n % low == 0) {
      return false;
    }
    low++;
  }
  return true;
}