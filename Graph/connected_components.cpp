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

  int r,from,to,vertex,numCC=0;
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
  for(int i =0;i<n;i++){
      if(!visitado[i]){
        dfs_rec(i);
        numCC++;
      }
  }
  cout << "Componentes conexos: " << numCC << endl;
  return 0;
}

//Implementação recursiva da DFS
void dfs_rec(int vertex){
  visitado[vertex] = true;
  for(int i = 0;i<graph[vertex].size();i++){
    int nxt = graph[vertex][i];
    if(!visitado[nxt])
      dfs_rec(nxt);
  }

}
