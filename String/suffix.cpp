#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1010
char T[MAX_N];
int SA[MAX_N];

bool comp(int a, int b ){
  return strcmp(T+a,T+b) < 0;
}

int main(){
    int n  = strlen(fgets(T,sizeof T, stdin));
    for(int i = 0; i <n ;i++)
      SA[i] = i;
    sort(SA,SA+n,comp);
    for(int i = 0; i < n;i++){
      printf("%2d\t%s\n",SA[i],T+SA[i]);
    }

    return 0;
}
