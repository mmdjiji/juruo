#include <stdio.h>
#include <string.h>

int main() {

  int t;
  char num[15];
  scanf("%d", &t);
  while(t--) {
    scanf("%s", num);
    if(num[0] == '1') {
      if(num[1] == '\0') {
        printf("0\n");
      } else {
        for(int i=1; i<strlen(num); ++i) {
          if(num[i] != '0' || i == strlen(num)-1) {
            printf("%s", num+i);
            break;
          }
        }
        printf("\n");
      }
    } else {
      printf("%c%s\n", num[0] - 1, num + 1);
    }
  }

  return 0;
}