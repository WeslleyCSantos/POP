#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<vi>

vector<bool> visitado;
int n;
vii graph;

void bfs(int vertex);

 int main() {
   int r,from,to,vertex;
   cin >> n;
   graph.resize(n);
   visitado.resize(n,false);
   cin >> r;
   while(r--){
     cin >> from >> to;
     graph[from].push_back(to);
     // Comente a próxima linha caso o grafo seja direcionado
     graph[to].push_back(from);
   }
   cin >> vertex;
   bfs(vertex);
  return 0;
}

void bfs(int vertex){
  
  queue<int> q;
  q.push(vertex);
  visitado.resize(n,false);
  visitado[vertex] = true;
  while(!q.empty()){
    int vtx = q.front();q.pop();
    cout << "->" << vtx;
    for(int i = 0;i<graph[vtx].size();i++){
      int nxt = graph[vtx][i];
      if(!visitado[nxt]){
        q.push(nxt);
        visitado[nxt] = true;
      }
    }
  }
  cout << endl;
}
