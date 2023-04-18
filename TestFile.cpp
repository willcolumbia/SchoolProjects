#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<string> v1;
vector<vector<string>> eNFA;
vector <int> acceptStates;

string State;
string alpSize;
string accStates;
int numState;
int betSize;
//READ IN INPUTS FOR ALPHABET SIZE, ACCEPTING STATES, AND NUMBER OF STATES
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
//READ IN RAW E-NFA
void readNFA(int argc,char*argv[]){
         ifstream in(argv[1]);
           if(in.is_open()){
            string line;
            int i =0;
            while(getline(in,line)&&!line.empty()){
                        if(i>=3){
                         stringstream ss(line);
                        string sub;
                        int j = 0;
                         while(ss>>sub){
                             for(int k = 0;k<sub.size();k++){
                                    if(isdigit(sub[k])){
                                        cout<<i-3<<" "<<sub[k]<<" found at "<<j<<endl;
                                    }
                                }
                            j++;
                                v1.push_back(sub); 
                         }
                         eNFA.push_back(v1);
                          for(int j = 0;j<betSize+1;j++){
                            v1.pop_back();
                          }
                          
                        }
                        i++;       
                }
              }
           }

void addAcceptingStates(){
    for(int i = 0;i<eNFA.size();i++){
        string eTrans = eNFA[i][0];
         for(int j = 0;j<eTrans.size();j++){
            if(isdigit(eTrans[j])){
                acceptStates.push_back(i);
            }
            
        }
    }
    sort(acceptStates.begin(),acceptStates.end());
    acceptStates.erase(unique(acceptStates.begin(),acceptStates.end()),acceptStates.end());
}


class NFA{
    public:
        void setState(int state, int sym,char newState){
            //for(int i = 0;i<eNFA.size();i++){
                //for(int j = 0;j<eNFA[i].size();j++){
                   eNFA[state][sym].insert((eNFA[state][sym].length()-1),1,',');
                   eNFA[state][sym].insert((eNFA[state][sym].length()-1),1,newState);
                //}
            //}
        }
        void goToState(int x){
            vector <string> news;
           vector<int> another;
          // cout<<x;
                for(int j =0;j<eNFA[x].size();j++){
                    news.push_back(eNFA[x][j]);
                }
            
            for(int i = 0;i<news.size();i++){
                
                //cout<<news[i]<<endl<<endl;

        }
        // for(int i = 0;i<another.size();i++){
        //             cout<<" ASNOTHEWR "<<another[i];
        //         }
        }
        
};

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
                                cout<<"S : "<<s<<"  ADJACENT:  "<<adjacent<<" "<<endl;
                                visited[adjacent] = true;
                                queue.push_back(adjacent);
                                
                        }
                }
        }
}

int main(int argc, char* argv[]){
    readInput(argc,argv);
    readNFA(argc,argv);
    addAcceptingStates();
    cout<<"ALPHABET SIZE: "<<betSize<<endl<<endl;
    Graph g(numState);
    
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,4);
    //g.addEdge(0,2);

    g.BFS(0);
//  for(int i = 0;i<eNFA.size();i++){
//         for(int j = 0;j<eNFA[i].size();j++){
//             if(eNFA[i][j]!="{}"){
//                 string n = eNFA[i][j];
//                 n.erase(remove(n.begin(),n.end(),'{'),n.end());
//                 n.erase(remove(n.begin(),n.end(),'}'),n.end());
//                 n.erase(remove(n.begin(),n.end(),','),n.end());
//                 if(j==0){
//                     cout<<n<<" ";
//                 }
//             }
//         }
//         cout<<endl;
       
//  }
//  int r;
//  for(int i = 0;i<N.size();i++){
//     for(int j = 0;j<N[i].size();j++){
//         if(isdigit(N[i][j])){

//             int r = N[i][j]-'0';
//             pp.push_back(r);
//         }
//     }
//  }
//  for(int i= 0;i<pp.size();i++){
//     trial.goToState(pp[i]);
//  }
 
    return 0;
}   