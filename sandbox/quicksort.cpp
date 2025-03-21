#include <stdio.h>
#include <stdlib.h>
#include <time.h>

template<typename T>
void swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

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

void quicksort_faster(int s[], int l, int r) {
  if (l < r) {
    int i = l, j = r, x = s[rand() % (r - l + 1) + l]; // 随机化选择基准值
    while (i <= j) {
      while (s[i] < x)
        i++;
      while (s[j] > x)
        j--;
      if (i <= j) {
        swap(s[i], s[j]); // 交换元素
        i++;
        j--;
      }
    }
    quicksort_faster(s, l, j); // 递归排序左半部分
    quicksort_faster(s, i, r); // 递归排序右半部分
  }
}

int main() {
  srand((unsigned int)time(NULL));
  int a[10] = {54, 34, 123, 34, 1, 23, 45, 56, 23, 1};
  quicksort_faster(a, 0, 9);
  for(int i=0; i<10; ++i) {
    printf("%d ", a[i]);
  }
  return 0;
}
