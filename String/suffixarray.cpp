#include <bits/stdc++.h>

#define MAX_N 100010
#define ii pair<int,int>
char T[MAX_N],P[MAX_N]; //String / Pattern
int n,m; // Tamanho da string de entrada / Padrao a ser buscado
int RA[MAX_N], tempRA[MAX_N]; // array definitivo e temporario de rank
int SA[MAX_N], tempSA[MAX_N]; // suffix array definitivo e temporario
int c[MAX_N]; // couting sort
int Phi[MAX_N],PLCP[MAX_N],LCP[MAX_N];

using namespace std;


void countingSort(int k);
void constructSA();
ii stringMatching();
void computeLCP();

int main(){
  scanf("%s",T);
  n = strlen(T);
  T[n++] = '$';
  constructSA();
  for (int i = 0; i < n; i++)
    printf("%2d\t%s\n", SA[i], T + SA[i]);



  return 0;
}

void countingSort(int k) {

int i, sum, maxi = max(300, n);
memset(c, 0, sizeof c);
for (i = 0; i < n; i++)
  c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for (i = 0; i < n; i++)
    tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];  // ordena o array de sufixo se necessário
  for (i = 0; i < n; i++)
    SA[i] = tempSA[i];  //Atualiza o suffix array
}

void constructSA() {
int i, k, r;
for (i = 0; i < n; i++)
  RA[i] = T[i]; // rank inicial
for (i = 0; i < n; i++)
  SA[i] = i; // S.A. inicial
for (k = 1; k < n; k <<= 1) {
  countingSort(k); //Radix sort baseado no segundo item
  countingSort(0); // stable sort baseado no primeiro item
  tempRA[SA[0]] = r = 0;
  for (i = 1; i < n; i++)

    tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
    (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; i++)
    // update the rank array RA
    RA[i] = tempRA[i];
    if (RA[SA[n-1]] == n-1) break;
  // nice optimization trick
  }
}


ii stringMatching() {
// string matching in O(m log n)
  int lo = 0, hi = n-1, mid = lo;
  // valid matching = [0..n-1]
  while (lo < hi) {
  // find lower bound
    mid = (lo + hi) / 2;
  // this is round down
    int res = strncmp(T + SA[mid], P, m); // try to find P in suffix ’mid’
    if (res >= 0)
      hi = mid;
  // prune upper half (notice the >= sign)
    else
    lo = mid + 1;
  // prune lower half including mid
  }
  // observe ‘=’ in "res >= 0" above
  if (strncmp(T + SA[lo], P, m) != 0) return ii(-1, -1);
  // if not found
  ii ans; ans.first = lo;
  lo = 0; hi = n - 1; mid = lo;
  while (lo < hi) {
  // if lower bound is found, find upper bound
    mid = (lo + hi) / 2;
    int res = strncmp(T + SA[mid], P, m);
    if (res > 0)
      hi = mid;
    // prune upper half
    else
    lo = mid + 1;
  // prune lower half including mid
  }
  // (notice the selected branch when res == 0)
  if (strncmp(T + SA[hi], P, m) != 0)
    hi--;
  // special case
  ans.second = hi;
  return ans;
} // return lower/upperbound as first/second item of the pair, respectively


void computeLCP() {
  int i, L;
  Phi[SA[0]] = -1;
// default value
  for (i = 1; i < n; i++)
    Phi[SA[i]] = SA[i-1]; // compute Phi in O(n)
// remember which suffix is behind this suffix
  for (i = L = 0; i < n; i++) {
// compute Permuted LCP in O(n)
    if (Phi[i] == -1) {
       PLCP[i] = 0;
       continue;
     }
  // special case
    while (T[i + L] == T[Phi[i] + L])
      L++;
  // L increased max n times
    PLCP[i] = L;
    L = max(L-1, 0);
// L decreased max n times
  }
  for (i = 0; i < n; i++)
// compute LCP in O(n)
  LCP[i] = PLCP[SA[i]];
// put the permuted LCP to the correct position
}
