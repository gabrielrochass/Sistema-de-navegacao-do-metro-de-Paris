#include <bits/stdc++.h>
using namespace std;

typedef pair<int,float> Parint;

vector<vector<pair<int, Parint>>> realDist() {
    vector<vector<pair<int, double>>> realStations(14); 

    realStations[0].push_back({1, 10.0});

    realStations[1].push_back({2, 8.5});
    realStations[1].push_back({8, 10.0});
    realStations[1].push_back({9, 3.5});

    realStations[2].push_back({3, 6.3});
    realStations[2].push_back({8, 9.4});
    realStations[2].push_back({12, 18.7});

    realStations[3].push_back({4, 13.0});
    realStations[3].push_back({7, 15.3});
    realStations[3].push_back({12, 12.8});
    realStations[3].push_back({13, 1.1});

    realStations[4].push_back({5, 3.0});
    realStations[4].push_back({6, 2.4});
    realStations[4].push_back({7, 30.0});

    realStations[7].push_back({8, 9.6});
    realStations[7].push_back({11, 6.4});

    realStations[8].push_back({10, 12.2});

    realStations[12].push_back({13, 5.1});

    return realStations;
}

// criar lista de adj com distâncias diretas entre as estações -> só vai pra frente
vector<vector<Parint>> strDist() 
{
    vector<vector<Parint>> stations(15); // setando com um tamanho a mais para dar match com o número das estações (inciando do 1)
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
    return stations;
}

//int heuristic(Graph*g, vector<vector<Parint>> stations, int origin,int nextDest, int dest){
//    float p = getEdge(g,origin,nextDest);
//    float h = calc_dist_ret(stations, nextDest, dest);
//    return p + h;
//}

void Dijkstra(Graph* g,int s)
{
    priority_queue< Parint, vector<Parint>, greater<Parint>> H;
    int v;
    for (int i=0; i< g->size;i++)
    {
        g->Distance[i] = 1000000;
        setMark(g,i,0);
    }
    H.push(make_pair(0,s));
    g->Distance[s] = 0;
    setMark(g,s,1);
    while(!H.empty())
    {
        int u = H.top().second;
        H.pop();

        for(auto edge: g->adjL[u])
        { 
            int v = edge.first;
            int wt = edge.second;

            if((getMark(g,v) != 1) && g->Distance[u] + wt < g->Distance[v])
            {
                g->Distance[v] = g->Distance[u] + heuristic(wt);
                H.emplace(g->Distance[v], v);
            }
        }
        setMark(g, u, 1);
    }
}

float calc_dist_ret(vector<vector<Parint>> stations, int origin,int dest)
{
    float distancia = 0.0;
    for (int i = origin; i < 15;i++){
        if (stations[origin][i].first == dest)
        {
            distancia = stations[origin][i].second;
            break;
        }
    }
    return distancia;
}

int main()
{
    Graph* metro = create_graph(14);
    init_metro(metro);
    vector<vector<Parint>> stations = strDist(); // cria a tabela com distâncias em linha reta até as outras estações
    return 0;
}