#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
// #define DEBUG
using namespace std;

/*
22100579 Jinju Lee 
ref: 
official reference: https://cplusplus.com/reference/algorithm/
Blog: https://blockdmask.tistory.com/76
Blog: https://life-with-coding.tistory.com/403
*/

vector<list<char>> adjacency;
vector<list<char>> adjacencyTranspose;

void getAdjList(string filename);
void printAdjList(vector<list<char>> adj);
void transposeAdjList(vector<list<char>> adj);

int main(void){

    getAdjList("hw5_data.txt");
    cout << "\n---Adjacency List------------------------------\n\n";
    printAdjList(adjacency);
    cout << "\n---Adjacency Transposed List-------------------\n\n";
    transposeAdjList(adjacency);
    printAdjList(adjacencyTranspose);
    cout << "\n-----------------------------------------------\n";

    return 0;
}

void getAdjList(string filename){
    ifstream file;
    file.open(filename);
    bool flag = false;
    
    if(file.is_open()){
        while (!file.eof()){
            string str;
            stringstream stream;
            char token;
            int count = -1;
            list<char> adj;

            getline(file, str);
            stream.str(str);

            if(flag){
                while(stream >> token){
                    #ifdef DEBUG
                    cout << token << "\t";
                    #endif 
                    if(token == '1') {
                        adj.push_back((count) + 'A');
                    }
                    count++;
                }
                adjacency.push_back(adj);
                #ifdef DEBUG
                cout << endl;
                #endif
            }else flag = true;

        }
        file.close();
    }
}

void printAdjList(vector<list<char>> adj){
    for(int i = 0; i < adj.size(); i++){
        cout << (char)(i +'A') << " : ";
        for(list<char>::iterator it = adj.at(i).begin();it != adj.at(i).end(); it++){
            cout << *it ;
            if(it != --(adj.at(i).end())) cout << " -> ";
        }
        cout << endl;
    }
}

void transposeAdjList(vector<list<char>> adj){
    for(int i = 0; i < adj.size(); i++){
        list<char> tmp;
        adjacencyTranspose.push_back(tmp);
    }
    for(int i = 0; i < adjacency.size(); i++){
        for(list<char>::iterator it = adj.at(i).begin();it != adj.at(i).end(); it++){
            adjacencyTranspose.at(*it - 'A').push_back((char)(i + 'A'));
        }
    }
    
}