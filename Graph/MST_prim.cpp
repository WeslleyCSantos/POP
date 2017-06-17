#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvii vector<vii>

int n;
vvii graph;
vi taken;
priority_queue<ii> pq;
int prim(int vtx);
void process(int vtx);

int main() {
  int r,from,to,vertex,w;
  cin >> n;
  graph.resize(n);
  cin >> r;
  while(r--){
    cin >> from >> to >> w;
    graph[from].push_back(ii(to,w));
    // Comente a próxima linha caso o grafo seja direcionado
    graph[to].push_back(ii(from,w));
  }
  cin >> vertex;
  prim(vertex);

  return 0;
}

void process(int vtx) {
  taken[vtx] = 1;
  for(int i = 0; i < graph[vtx].size();i++) {
    ii v = graph[vtx][i];
    if(!taken[v.first])
      pq.push(ii(-v.second,-v.first));
  }

}


int prim(int vtx) {
  taken.assign(n,0);
  int u,w;
  process(vtx);
  int mst = 0;
  while(!pq.empty()) {
    ii front = pq.top(); pq.pop();
    u = -front.second; w = -front.first;
    if(!taken[u]){
      mst+=w, process(u);
    }
  }

  return mst;
}
