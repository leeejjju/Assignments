#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
// #define DEBUG
#define INT_MAX 50000
using namespace std;

/*
22100579 Jinju Lee 
ref: 
lecture slide: ch24, pp10-29, pp51-63
official reference: https://cplusplus.com/reference/algorithm/
Blog:   https://yabmoons.tistory.com/364
        https://karupro.tistory.com/12
        https://lucysworld.tistory.com/31
*/

struct vertex{
    int id;
    string name;
    int distance; //shortest path from source to this vertex
    int pre;
    int visited;
};
typedef struct vertex vertex;

struct compare{
    bool operator()(vertex &a, vertex &b){
        return a.distance > b.distance;
    }
};


void getAdjList(string filename);
void printAdjList();
void printAdjMatrix();

void dijkstra(int size, int target);
void floyd(int size);

void init_ss(int size, int source);
void printResult(int dist[][31]);

vector<vector<pair<int, int>>> L; // adjacency list
vector<vector<int>> M;//adjacency matrix
vector<vertex> V;

int dijk[31][31];
int flo[31][31];

int main(void){
    //Read input file
    //Create array of adjacency list for a given graph
    getAdjList("hw6-1.txt");

    #ifdef DEBUG
    cout << "\n---Adjacency List------------------------------\n\n";
    printAdjList();
    cout << "\n---Adjacency Matrix------------------------------\n\n";
    printAdjMatrix();
    cout << endl;
    #endif

    //Apply Dijkstra's algorithm for |V| times and print result
    printf("\nThe followings are shortest distances between cities with Dijkstra's algorithm.\n");
    for(int i = 0; i < V.size(); i++) dijkstra(V.size(), i);
    printResult(dijk);

    //Run Floyd’s algorithm and print result
    printf("\nThe followings are shortest distances between cities with Floyd algorithm as follows.\n");
    floyd(V.size());
    // tmp(V.size());
    printResult(flo);

    return 0;
}


void init_ss(int size, int source){
    for(int i = 0; i < size; i++){
        V.at(i).id = i; //set id
        V.at(i).distance = INT_MAX; //init distance as infinite value(int_max)
        V.at(i).pre = -1;// init predecessor. -1 means NIL
        V.at(i).visited = false;
    }
    V.at(source).distance = 0;
}

void getAdjList(string filename){
    ifstream file;
    file.open(filename);
    bool flag = false;
    if(file.is_open()){

        while (!file.eof()){

            string line, one;
            int count = 0;
            vector<pair<int, int>> adj;
            vector<int> matrix;
            bool flag = false;
            getline(file, line);
            stringstream stream(line);
            while(stream >> one){

                #ifdef DEBUG
                cout << one << "\t";
                #endif 

                if(flag){
                    if(one != "INF") {
                        if(one != "0"){
                            pair<int, int> t = {count, stoi(one)};
                            adj.push_back(t);
                        }
                        matrix.push_back(stoi(one));
                    }else{
                        matrix.push_back(INT_MAX);
                    }
                    count++;

                }else{ //save the first word in each line as vertex name. 
                    vertex v;
                    v.name = one;
                    V.push_back(v);
                    flag = true;
                }
            }
            L.push_back(adj);
            M.push_back(matrix);

            #ifdef DEBUG 
            cout << endl;
            #endif

        }
        file.close();
    }
}

void printAdjList(){
    for(int i = 0; i < V.size(); i++){
        cout << V.at(i).name << " : ";
        for(vector<pair<int, int>>::iterator it = L.at(i).begin();it != L.at(i).end(); it++){
            cout << V[(*it).first ].name<< ":" << (*it).second ;
            if(it != --(L.at(i).end())) cout << " -> ";
        }
        cout << endl;
    }
    cout << endl;
}

void printAdjMatrix(){
    for(int i = 0; i < V.size(); i++){
        cout << V.at(i).name << " : ";
        for(vector<int>::iterator it = M.at(i).begin();it != M.at(i).end(); it++){
            if(*it == INT_MAX) cout << "INF";
            else cout << (*it) ;
            if(it != --(M.at(i).end())) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void dijkstra(int size, int source){
    init_ss(size, source);
    int current = source;

    priority_queue<vertex, vector<vertex>, compare> Q; //대기열...? 닿은애들(미방문인) 냅다 넣어두는데 그중 dist가 최소인걸 매번 뺴야해서... 

    int dist[31]; //index = vertex id
    for(int i = 0; i < size; i++) dist[i] = INT_MAX;

    while(1){
        
        //시작노드 처리... 본인 방문표시, 
        V.at(current).visited = 2;

        #ifdef DEBUG
        // cout << "current point(" << V.at(current).name <<  "): ";
        #endif

        //(adjList사용)미완료 인접 vertex들의 dist 업데이트, 첫방문(visit == 0)이면 큐에 넣기 
        for(vector<pair<int,int>>::iterator it = L.at(current).begin(); it != L.at(current).end(); it++){
            
            #ifdef DEBUG
            // cout << V.at((*it).first).name << " ";
            #endif

            if(V.at((*it).first).visited == 2) continue;//미완료 컷

            V.at((*it).first).distance = min((V.at(current).distance + (*it).second), V.at((*it).first).distance); //dist 업데이트 
            dist[(*it).first] = min((dist[current] + (*it).second), dist[(*it).first]); //dist 업데이트 

            if(V.at((*it).first).visited == 0){//처음방문시 큐에 넣기
                Q.push(V.at((*it).first));
                    V.at((*it).first).visited = 1;
            }

           
        }

        #ifdef DEBUG
        // cout << endl;
        #endif

        current = Q.top().id;
        Q.pop();

        if(Q.empty()) break; 
        

    }

    for(int i = 0; i < size; i++){
        dijk[source][i] = V.at(i).distance;
    }

}

//TODO
void floyd(int size){

  // Initialize the dist array to the graph's adjacency matrix.
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      flo[i][j] = M[i][j];
    }
  }

  printf("start\n");

  // Iterate over all vertices.
  for (int k = 0; k < size; k++) {
    // For each vertex i, update the shortest path distance from i to j
    // via k.
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        flo[i][j] = min(flo[i][j], flo[i][k] + flo[k][j]);
        #ifdef DEBUG
        // printf("flo[%d][%d] is %d\n", i, j, flo[i][j]);
        #endif
      }
      
    }
  }
}

void printResult(int dist[][31]){

    cout << "\n         :     ";
    for(int i = 0; i < V.size(); i++){
        cout << V.at(i).name ;
        for(int k = 0; k < 8-(V.at(i).name.length()); k++ ) cout << ' ';
        cout << " ";
    }
    cout << "\n____________________________________________________________________________________________________\n";

    for(int i = 0; i < V.size(); i++){
        // dijkstra(V.size(), i);
        cout << V.at(i).name ;
        for(int k = 0; k < 8-(V.at(i).name.length()); k++ ) cout << ' ';
        cout << " : ";

        for(int j = 0; j < V.size(); j++){
            if(dist[i][j] == INT_MAX) cout << "INF ";
            else{
                for(int k = 0; k < 8-(to_string(dist[i][j]).length()); k++ ) cout << ' ';
                cout << dist[i][j] << ' ';
            }
        }
        cout << endl;
    } 
}
