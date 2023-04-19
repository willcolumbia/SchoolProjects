#include <bits/stdc++.h>
using namespace std;
vector <int> acceptingStates;
vector<int> States;
vector<string> v1;
vector<vector<string>> eNFA;
vector<pair<int, int> > NFA[64];
vector<pair<int, int> > hNFA[64];
vector<pair<int, int> > tNFA[64];
vector<pair<int, int> > jNFA[64];

string State;
string alpSize;
string accStates;
int numState;
int betSize;
// To add an edge
void addEdge(vector <pair<int, int> > adj[], int u,int v, int wt)
{
    
	adj[u].push_back(make_pair(v, wt));
   
}
int check(vector<pair<int,int> > adj[],vector<pair<int,int> > NFA[], int V){
  int v, w;
  int r;
		for (auto it = adj[V].begin(); it!=adj[V].end(); ++it)
		{
			v = it->first;
			w = it->second;
            // cout<< V << "  ";
            //  cout << v << "  "<< w << "\n";
             int x,y;
            if(w==0){
                r = 0;
                for (auto it2 = adj[v].begin(); it2!=adj[v].end(); ++it2){
                    x = it2->first;
			        y = it2->second;
                    //if(y!=0)
                    addEdge(NFA,V,x,y);
                    
                }
            }
            else if(w!=0){
                r=1;
            }
			
            
		}
        
        return r;
}


// Print adjacency list representation of graph
void printGraph(vector<pair<int,int> > adj[], int V)
{
	int v, w;
	for (int u = 0; u < V; u++)
	{
		for (auto it = adj[u].begin(); it!=adj[u].end(); ++it)
		{
			v = it->first;
			w = it->second;
            States.push_back(v);
            if(w == 0 && v!=-1){
                acceptingStates.push_back(u);
                
                

            }
            
            cout<< u << "  ";
             cout << v << "  "<< w << "\n";
            
			
            
		}
		
	}
}

    


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
                         acceptingStates.push_back(test);
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
            int i =0;
            while(getline(in,line)&&!line.empty()){
                        if(i>=3){
                         stringstream ss(line);
                        string sub;
                        int j = 0;
                         while(ss>>sub){
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

// Driver code
int main(int argc, char* argv[])
{
    readInput(argc,argv);
    readNFA(argc,argv);


    int V = numState;
	vector<pair<int, int> > adj[V];
    ifstream in(argv[1]);
           if(in.is_open()){
              string line;
              string sub;
              int i=0;
                while(getline(in,line)&&!line.empty()){
                        if(i>=3){
                                 stringstream ss(line);
                        string sub;
                        int j = 0;
                         while(ss>>sub){
                             for(int k = 0;k<sub.size();k++){
                                int y =0;
                                    if(isdigit(sub[k])){
                                        y = sub[k]-'0';
                                        addEdge(adj,i-3,y,j);
                                        addEdge(jNFA,i-3,y,j);
                                    }
                                }
                                // if(sub=="{}"){
                                //    addEdge(adj,i-3,-1,j);
                                // }
                            j++;
                               
                         }
                         
                        }
                        i++;
                        
                }
                
           }
	
    

    
    
    // for(int i = 0;i<eNFA.size();i++){
    //     cout<<i<< " ";
    //     for(int j = 0;j<eNFA[i].size();j++){
    //         cout<<j<<"  "<<eNFA[i][j];
    //     }
    //     cout<<endl;
    // }
 
    
   cout<<eNFA[0][0]<<endl;
   
   
    sort(acceptingStates.begin(),acceptingStates.end());
    acceptingStates.erase(unique(acceptingStates.begin(),acceptingStates.end()),acceptingStates.end());
   
    sort(States.begin(),States.end());
    States.erase(unique(States.begin(),States.end()),States.end());

    
    return 0;
}








