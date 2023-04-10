#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector <string> NFA;
vector<int> backedge;
vector <char> acceptStates;
vector <int> States;
vector <string> alphabet;
vector<vector<int>> VEC;
string State;
string alpSize;
string accStates;
int numState;
int betSize;
string ep = "{}";


/*TODO's
figure out how to put accepting states in a vector
figure out how to get number like 12 in to accepting states
*/


void readInput(int argc,char*argv[]){
         ifstream in(argv[1]);
           if(in.is_open()){
              string line;
              for(int i=0;i<3;i++){
                getline(in,line);
                if(i==0){
                         State = line.substr(line.find(":")+1);
                         numState = stoi(State);
                }
                else if(i==1){
                        alpSize = line.substr(line.find(":")+1);
                        betSize = stoi(alpSize);
                }
                else {
                      accStates =   line.substr(line.find(":")+1);
                      for(int i = 0;i<accStates.size();i++){
                if(!isspace(accStates[i])){
                        
                         acceptStates.push_back(accStates[i]);
                }
         }
                }
                }
                

                
        }
}

void readNFA(int argc,char*argv[]){
         ifstream in(argv[1]);
           if(in.is_open()){
              string line;
              string sub;
              int i=0;
                while(getline(in,line)&&!line.empty()){
                        if(i>=3){
                         stringstream ss(line);
                         //while(ss>>sub){
                                NFA.push_back(line);
                         //}
                        }
                        i++;
                        
                }
                
           }
}

class Graph{
        int V;
        vector<list<int>> adj;

public:
        Graph(int V);
        void addEdge(int v,int w);
        void BFS(int s);
};

Graph::Graph(int V){
        this->V=V;
        adj.resize(V);
}

void Graph::addEdge(int v,int w){
        adj[v].push_back(w);
}

void Graph::BFS(int s){
        vector<bool> visited;
        visited.resize(V,false);
        list<int> queue;
        visited[s] =true;
        queue.push_back(s);

        while(!queue.empty()){
                s = queue.front();
                backedge.push_back(s);
                cout<<s<<" ";
                queue.pop_front();

                for(auto adjacent : adj[s]){
                        if(!visited[adjacent]){
                                visited[adjacent] = true;
                                queue.push_back(adjacent);
                                
                        }
                }
        }
}

int main(int argc, char* argv[]){
         readInput(argc,argv);
         readNFA(argc,argv);
         //initalizes the number of states
        for(int i=0;i<numState;i++){
                States.push_back(i);  
        }
//prints the vector of accepting states
        // for(int i=0;i<acceptStates.size();i++){ 
        //         cout<<acceptStates[i]<<endl;
        // }

//prints NFA vector
        // for(int i = 0;i<NFA.size();i++){
        //         cout<<NFA[i];
        //         cout<<endl;
        // }

        
//places a vector into the vecotr of vectors and prints
        // VEC.push_back(NFA);
        
        Graph g(numState);
        g.addEdge(0,1);
        g.addEdge(0,4);
        g.addEdge(1,2);
        g.addEdge(3,1);
        g.addEdge(4,5);
        g.addEdge(5,6);
        g.addEdge(6,7);
        g.addEdge(7,4);
        cout<<"FOLLOWING BFS AT 0 "<<endl;
        bool test = true;
        for(int i = 0;i<numState;i++){
                g.BFS(i);
                cout<<endl;
                
        }
        
        // cout<<endl;
        // cout<<"TEST::  "<<endl<<endl;
        // for(int i = 0;i<backedge.size();i++){
        //         cout<<backedge[i];
        //         cout<<endl;
        // }
        // cout<< "TEST    "<<endl<<endl;
        // for(int i = 0;i<VEC.size();i++){
        //         for(int j =0;j<VEC[i].size();j++){
        //         cout<<j<<" "<<VEC[i][j]<<" ";
        //         cout<<endl;
        //         }
        // }
	return 0;
}




