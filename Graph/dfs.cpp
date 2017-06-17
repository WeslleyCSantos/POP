#include <iostream>
#include <vector>
#include <stack>


using namespace std;

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<vi>

void dfs_iter(int vertex);
void dfs_rec(int vertex);
vector<bool> visitado;
int n;
vii graph;
int main(){

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
  dfs_rec(vertex);
  cout << endl;
  visitado.clear();
  dfs_iter(vertex);



  return 0;
}

//Implementação iterativa da DFS(depth first search)
void dfs_iter(int vertex){
  stack<int> s;
  visitado.resize(n,false);
  s.push(vertex);
  visitado[vertex] = true;
  while(!s.empty()){
    int vtx = s.top(); s.pop();
    //A próxima linha mostra o fluxo do grafo
    cout << "->" << vtx;
    for(int i = 0;i<graph[vtx].size();i++){
      int nxt = graph[vtx][i];
      if(!visitado[nxt]){
        visitado[nxt] = true;
        s.push(nxt);
      }
    }
  }
  cout << endl;
}
//Implementação recursiva da DFS
void dfs_rec(int vertex){
  cout << "->" << vertex;
  visitado[vertex] = true;
  for(int i = 0;i<graph[vertex].size();i++){
    int nxt = graph[vertex][i];
    if(!visitado[nxt])
      dfs_rec(nxt);
  }

}
