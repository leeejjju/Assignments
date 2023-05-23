#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#define DEBUG
using namespace std;

/*
22100579 Jinju Lee 
ref: 
official reference: https://cplusplus.com/reference/algorithm/
Blog: 
*/

vector<list<char>> adjacency;

void getAdjList(string filename);

int main(void){

    
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