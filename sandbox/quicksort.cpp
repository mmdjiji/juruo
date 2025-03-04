#include <stdio.h>

void quick_sort(int s[], int l, int r) {
  if(l<r) {
    int i=l, j=r, x=s[l];
    while(i<j){
      while(i<j && s[j] >= x) j--;
      if(i<j) s[i++] = s[j];
      while(i<j && s[i] < x) i++;
      if(i<j) s[j--] = s[i];
    }
    s[i] = x;
    quick_sort(s, l, i-1);
    quick_sort(s, i+1, r);
  }
}

int main() {
  int a[10] = {54, 34, 123, 34, 1, 23, 45, 56, 23, 1};
  quick_sort(a, 0, 9);
  for(int i=0; i<10; ++i) {
    printf("%d ", a[i]);
  }
  return 0;
}
