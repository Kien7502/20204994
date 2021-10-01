#include <stdio.h>
int main(){
  double num, fraction;
  int integer;
  printf("Please  enter a real number: ");
  scanf("%f", &num);
  printf("The integer part is %d\n", (int)num);
  printf("The remaining fraction is %f\n", num -(int)num);
  return 0;
}
