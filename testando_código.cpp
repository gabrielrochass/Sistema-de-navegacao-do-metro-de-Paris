#include <iostream>
#include <vector>
using namespace std;


#include <iostream>
#include <queue>
#include <map>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,float> Parint;

struct Graph
{
    int size;
    int numEdges;
    list<Parint> *adjL;    
    vector<int> Mark;                   
    vector<int> Distance;                
};

Graph* create_graph(int n){
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->size = n;
    g->numEdges = 0;
    g->adjL = new list<Parint>[n];
    g->Mark = vector<int>(n, 0);
    g->Distance = vector<int>(n, 1e9);         

    return g;
}

int n(Graph* g){
    return g->size;
}

void setEdge(Graph* g,int i,int j,float wt)
{
    if (wt != 0)
    {
        g->numEdges++;
    }
    g->adjL[i].emplace_back(j,wt);
    g->adjL[j].emplace_back(i,wt);
}
Graph* init_metro(Graph* g)
{
    setEdge(g,0,1,10);
    setEdge(g,1,2,8.5);
    setEdge(g,2,3,6.3);
    setEdge(g,3,4,13);
    setEdge(g,4,5,3);
    setEdge(g,4,6,2.4);
    setEdge(g,4,7,30);
    setEdge(g,3,7,15.3);
    setEdge(g,2,8,9.4);
    setEdge(g,1,8,10);
    setEdge(g,1,9,3.5);
    setEdge(g,7,8,9.6);
    setEdge(g,8,10,12.2);
    setEdge(g,7,11,6.4);
    setEdge(g,2,12,18.7);
    setEdge(g,3,12,12.8);
    setEdge(g,3,13,1.1);
    setEdge(g,12,13,5.1);

}

int main()
{
    vector<string> rel_est_index (14);
    Graph* metro = create_graph(14);
    init_metro(metro);

    return 0;
}