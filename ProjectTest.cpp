#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector <string> NFA;
vector <int> acceptStates;
vector <int> States;
vector <string> alphabet; //NOT IN USE ATM
vector<vector<string>> VEC;
vector<vector<int>> gd;
string State;
string alpSize;
string accStates;
int numState;
int betSize;



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
                        int test = accStates[i] -'0';
                         acceptStates.push_back(test);
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
                         NFA.push_back(line);
                        //  while(ss>>sub){
                        //         for(int k = 0;k<sub.size();k++){
                        //                 NFA.push_back(sub[k]);
                        //         }
                        //  }
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
                //cout<<s<<" ";
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
        
//places a vector into the vecotr of vectors and prints

        VEC.push_back(NFA);
        Graph g(numState);
        for(int i = 0;i<VEC.size();i++){
                for(int j =0;j<VEC[i].size();j++){
                string test = VEC[i][j];
                for(int k = 0;k<test.size();k++){
                        if(isdigit(test[k])){
                        int p = test[k]-'0';
                        g.addEdge(j,p);
                        for(int y = 0;y<acceptStates.size();y++){
                                if(p == acceptStates[y]){
                                        acceptStates.push_back(j);
                                        if(j == acceptStates[y-1])
                                        acceptStates.pop_back();
                                }
                        }
                        }
                }
                
                }
        }
        for(int i = 0;i<numState;i++){

                g.BFS(i);
                cout<<endl;
                
        }

        // for(int i = 0;i<acceptStates.size();i++){
        //         cout<<acceptStates[i]<<endl;
        // }

        for(int i = 0;i<NFA.size();i++){
                cout<<i;
                for(int j = 0;j<20;j++){
                        if(isdigit(NFA[i][j]))
                        cout<<" found  "<<NFA[i][j]<<" at ";
                }
                cout<<endl;
        }
        
	return 0;
}




