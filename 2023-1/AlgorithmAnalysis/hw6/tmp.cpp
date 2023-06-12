#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
// #define DEBUG
#define INT_MAX 2147483647
using namespace std;

/*
22100579 Jinju Lee 
ref: 
official reference: https://cplusplus.com/reference/algorithm/
Blog:   https://yabmoons.tistory.com/364
        https://karupro.tistory.com/12
*/

struct vertex{
    int id;
    string name;
    int distance; //shortest path from source to this vertex
    int pre;
    int visited;
    vector<pair<int,int>> adj;
};

struct compare{
    bool operator()(vertex &a, vertex &b){
        return a.distance > b.distance;
    }
};

void getAdjList(string filename);
void printAdjList();
void printAdjMatrix();

bool compare(vertex a, vertex b) { return a.distance > b.distance; }
void dijkstra(int size, int target);
void floyd(int numOfV);

void init_ss(int source, int* d, int* pre){
    for(int i = 0; i < ssize; i++){
        V.at(i).id = i; //set id
        V.at(i).distance = INT_MAX; //init distance as infinite value(int_max)
        V.at(i).pre = -1;// init predecessor. -1 means NIL
        V.at(i).visited = false;
        V.at(i).adj.assign(L.at(i).begin(), L.at(i).end());
        d[i] = INT_MAX;
        pre[i] = -1;
    }
    V.at(source).distance = 0;
    d[source] = 0;
    
}

//get shortest distance of s->v. compair s->u->v and s->v
void relax(int* d, int* pre, int u, int v, int w){


    // 일단 q에서 u랑 v를 찾아야함... 
    // 존나우울하다 진짜 아니 이래서 외부ㅐ여릉ㄹ 쓰는거구나 미친시발이걸 지금눈치채내 
    if(d[v] > d[u] + w){
        d[v] = (d[u] + w);
        pre[v] = u;
    }
}

vector<vector<pair<int, int>>> L; // adjacency list
vector<vector<int>> M;//adjacency matrix
vector<vertex> V;

int dijk[31][31];
int ssize;

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

    cout << "\n         :     ";
    for(int i = 0; i < V.size(); i++){
        cout << V.at(i).name ;
        for(int k = 0; k < 8-(V.at(i).name.length()); k++ ) cout << ' ';
        cout << " ";
    }
    cout << "\n____________________________________________________________________________________________________\n";

    for(int i = 0; i < V.size(); i++){
        dijkstra(V.size(), i);
        cout << V.at(i).name ;
        for(int k = 0; k < 8-(V.at(i).name.length()); k++ ) cout << ' ';
        cout << " : ";

        for(int j = 0; j < V.size(); j++){
            if(dijk[i][j] == INT_MAX) cout << "INF ";
            else{
                for(int k = 0; k < 8-(to_string(dijk[i][j]).length()); k++ ) cout << ' ';
                cout << dijk[i][j] << ' ';
            }
        }
        cout << endl;
    } 
    
    //Run Floyd’s algorithm and print result
    printf("\nThe followings are shortest distances between cities with Floyd algorithm as follows.\n");

    #ifdef DEBUG
    test();
    #endif

    return 0;
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
                        pair<int, int> t = {count, stoi(one)};
                        adj.push_back(t);
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
        ssize = V.size();
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



void dijkstra(int source){

    //이게 문제가 재배열의 기준이 dist여야하는데...? dist는 업데이틑되자나 
    //걍 프큐를 안쓰고 vector로 한다음 매번 dist기준 sort할까...? 걍 V...를 사용해야하나...? 그래도 되는건가...? 에라이 복사해서 쓰자 
    //나중에 접근할 때 S를 써야겠지 그르면...? 프린트도 여기서 해버린다는 마인드 
    
    int d[31];
    int pre[31];
    init_ss(source, d, pre);

    vector<vertex> S;
    vector<vertex> Q;
    Q.assign(V.begin(), V.end());
    
    while(!Q.empty()){
        sort(Q.begin(), Q.end(), compare);
        vertex u = Q.back();
        Q.pop_back();
        S.push_back(u);

        for(vector<pair<int,int>>::iterator it = u.adj.begin(); it != u.adj.end(); it++){
            //vertex u와 인접한 애들의 id를 it.firt로 알 수 있긴 한데
            //지금 이 id들을 가지고 Q에서 업데이트를 해야함 dist를. w는 it.second로 주면 되고 
            //이러면 함수에 Q자체를 줘야하나? Q랑 id랑 w랑... 
            relax(Q.begin(), u.id, (*it).first, (*it).second);
            SIBAL SIBAL JONNASIBAL

        }
    }

}

void floyd(int numOfV){




}

