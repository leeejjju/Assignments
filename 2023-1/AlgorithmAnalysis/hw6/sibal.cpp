#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;


typedef struct g_node {
    int city; //이건뭐야 출발지?
	int distance;  //엣지인가 그게...? 
    struct g_node *link;   //다음으로 향하는 링크
} list_node;

typedef struct h_node {
    int data;    
    struct g_node *link;   
} head_node;

const int num_nodes = 5;

void Create_array(head_node **my_graph){
	*my_graph = new head_node[num_nodes];
	for (int i=0; i<num_nodes; i++){
		(*my_graph)[i].data = i;
		(*my_graph)[i].link = NULL;
	}
}

void Read_from_file(int distance[][num_nodes]){
	ifstream inputFile("data.txt");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            inputFile >> distance[i][j];
            cout << distance[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}
    
void Insert(int data[][num_nodes], head_node *my_graph){
	for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
        	if (data[i][j] > 0){
        		list_node *new_node = new list_node;
				new_node->city = j;
				new_node->distance = data[i][j];
				new_node->link = NULL;
				
				list_node *temp = my_graph[i].link;
				if (temp==NULL)
					my_graph[i].link = new_node;
				else{
					list_node *prev=NULL;
					while (temp!=NULL){
						prev = temp;
						temp = temp->link;
					}
					prev->link = new_node;
				}
			}
		}
	}
}

void Display_Lists(head_node *my_graph){
	for (int i=0; i<num_nodes; i++){
		list_node *temp = my_graph[i].link;
		cout << "From " << i << ": ";
		while (temp != NULL){
			cout << temp->city << ", " << temp->distance << "     ";
			temp = temp->link;
		}
		cout << endl;
	}
}

int main(){
    head_node *my_graph=NULL;
	int distance[num_nodes][num_nodes];
	
	// Create array
    printf("#create array\n");
	Create_array(&my_graph);
	
	// Print array
    printf("#Print array\n");
	for (int i=0; i<num_nodes; i++){
		cout << i << ": ";
		cout << my_graph[i].data << ", ";
		cout << my_graph[i].link << endl;
	}
	cout << endl;
	
	//Read data from file
    printf("#Read data from file\n");
	Read_from_file(distance);

	// Create list
    printf("#Create list\n");
	Insert(distance, my_graph);
    
    // Display
    printf("#Display\n");
    Display_Lists(my_graph);		
}

