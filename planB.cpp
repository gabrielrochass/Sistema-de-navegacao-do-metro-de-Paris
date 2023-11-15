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

// criar lista de adj com distâncias diretas entre as estações -> só vai pra frente
void strDist() {
    vector<vector<pair<int, float>>> stations(15); // setando com um tamanho a mais para dar match com o número das estações (inciando do 1)
    // stations[origem].push_back({destino, custo});
    
    // distâncias diretas a partir de E1(1) para todas as outras estações
    stations[1].push_back({1, 0.0});
    stations[1].push_back({2, 10.0});
    stations[1].push_back({3, 18.5});
    stations[1].push_back({4, 24.8});
    stations[1].push_back({5, 36.4});
    stations[1].push_back({6, 38.8});
    stations[1].push_back({7, 35.8});
    stations[1].push_back({8, 25.4});
    stations[1].push_back({9, 17.6});
    stations[1].push_back({10, 9.1});
    stations[1].push_back({11, 16.7});
    stations[1].push_back({12, 27.3});
    stations[1].push_back({13, 27.6});
    stations[1].push_back({14, 29.8});

    // E2(2) -> outras estações:
    stations[2].push_back({2, 0.0});
    stations[2].push_back({3, 8.5});
    stations[2].push_back({4, 14.8});
    stations[2].push_back({5, 26.6});
    stations[2].push_back({6, 29.1});
    stations[2].push_back({7, 26.1});
    stations[2].push_back({8, 17.3});
    stations[2].push_back({9, 10.0});
    stations[2].push_back({10, 3.5});
    stations[2].push_back({11, 15.5});
    stations[2].push_back({12, 20.9});
    stations[2].push_back({13, 19.1});
    stations[2].push_back({14, 21.8});

    // E3(3) -> outras estações:
    stations[3].push_back({3, 0.0});
    stations[3].push_back({4, 6.3});
    stations[3].push_back({5, 18.2});
    stations[3].push_back({6, 20.6});
    stations[3].push_back({7, 17.6});
    stations[3].push_back({8, 13.6});
    stations[3].push_back({9, 9.4});
    stations[3].push_back({10, 10.3});
    stations[3].push_back({11, 19.5});
    stations[3].push_back({12, 19.1});
    stations[3].push_back({13, 12.1});
    stations[3].push_back({14, 16.6});

    // E4(4) -> outras estações:
    stations[4].push_back({4, 0.0});
    stations[4].push_back({5, 12.0});
    stations[4].push_back({6, 14.4});
    stations[4].push_back({7, 11.5});
    stations[4].push_back({8, 12.4});
    stations[4].push_back({9, 12.6});
    stations[4].push_back({10, 16.7});
    stations[4].push_back({11, 23.6});
    stations[4].push_back({12, 18.6});
    stations[4].push_back({13, 10.6});
    stations[4].push_back({14, 15.4});

    // E5(5) -> outras estações:
    stations[5].push_back({5, 0.0});
    stations[5].push_back({6, 3.0});
    stations[5].push_back({7, 2.4});
    stations[5].push_back({8, 19.4});
    stations[5].push_back({9, 23.3});
    stations[5].push_back({10, 28.2});
    stations[5].push_back({11, 34.2});
    stations[5].push_back({12, 24.8});
    stations[5].push_back({13, 14.5});
    stations[5].push_back({14, 17.9});

    // E6(6) -> outras estações:
    stations[6].push_back({6, 0.0});
    stations[6].push_back({7, 3.3});
    stations[6].push_back({8, 22.3});
    stations[6].push_back({9, 25.7});
    stations[6].push_back({10, 30.3});
    stations[6].push_back({11, 36.7});
    stations[6].push_back({12, 27.6});
    stations[6].push_back({13, 15.2});
    stations[6].push_back({14, 18.2});

    // E7(7) -> outras estações:
    stations[7].push_back({7, 0.0});
    stations[7].push_back({8, 20.0});
    stations[7].push_back({9, 23.0});
    stations[7].push_back({10, 27.3});
    stations[7].push_back({11, 34.2});
    stations[7].push_back({12, 25.7});
    stations[7].push_back({13, 12.4});
    stations[7].push_back({14, 15.6});

    //E8(8) -> outras estações:
    stations[8].push_back({8, 0.0});
    stations[8].push_back({9, 8.2});
    stations[8].push_back({10, 20.3});
    stations[8].push_back({11, 16.1});
    stations[8].push_back({12, 6.4});
    stations[8].push_back({13, 22.7});
    stations[8].push_back({14, 27.6});

    // E9(9) -> outras estações:
    stations[9].push_back({9, 0.0});
    stations[9].push_back({10, 13.5});
    stations[9].push_back({11, 11.2});
    stations[9].push_back({12, 10.9});
    stations[9].push_back({13, 21.2});
    stations[9].push_back({14, 26.6});

    // E10(10) -> outras estações:
    stations[10].push_back({10, 0.0});
    stations[10].push_back({11, 17.6});
    stations[10].push_back({12, 24.2});
    stations[10].push_back({13, 18.7});
    stations[10].push_back({14, 21.2});

    // E11(11) -> outras estações:
    stations[11].push_back({11, 0.0});
    stations[11].push_back({12, 14.2});
    stations[11].push_back({13, 31.5});
    stations[11].push_back({14, 35.5});

    // E12(12) -> outras estações:
    stations[12].push_back({12, 0.0});
    stations[12].push_back({13, 28.8});
    stations[12].push_back({14, 33.6});

    // E13(13) -> outras estações:
    stations[13].push_back({13, 0.0});
    stations[13].push_back({14, 5.1});

    // E14(14) -> outras estações:
    stations[14].push_back({14, 0.0});

    // g[1][0].second; //g[1] acessa o segundo elemento (estação 1) do vector grande. g[1][0] acessa o primeiro vizinho da estação 1. 
    // g[1][0].second acessa a distancia entre a estação 1 e seu primeiro vizinho

    // priority queue: escolher qual o próximo vertice a ser visitado?

}

int main()
{
    vector<string> rel_est_index (14);
    Graph* metro = create_graph(14);
    init_metro(metro);
    strDist(); // cria a tabela com distâncias em linha reta até as outras estações

    return 0;
}