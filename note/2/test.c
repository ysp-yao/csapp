#include <stdio.h>

int main() {
 
  int x = 0x80000001;
  printf("%d\n", x);

  short y = (short)x;
  printf("%d\n", y);


  return 0;
}
