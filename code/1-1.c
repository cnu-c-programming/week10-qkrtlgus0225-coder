#include <stdio.h>

struct S1{
char c;
int i;
long long l;
}

struct S2{
  char c;
  int i;
  long long l;
}__attribute__((packde));

int main(){
  struct S1 s1;
  struct S2 s2;
  print("%zu %zu\n", sizeof(s1), sizeof(s2)); 
}
