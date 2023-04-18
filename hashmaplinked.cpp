// C++ program to represent undirected and weighted graph
// using STL. The program basically prints adjacency list
// representation of graph
#include <bits/stdc++.h>
using namespace std;
vector <int> acceptingStates;
vector<int> States;
// vector<int> trans;
vector<string> v1;
vector<vector<string>> eNFA;

string State;
string alpSize;
string accStates;
int numState;
int betSize;
vector<pair<int,int>> trans[64];
// To add an edge
void addEdge(vector <pair<int, int> > adj[], int u,
									int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	//adj[v].push_back(make_pair(u, wt));
    trans[u].push_back(make_pair(v,wt));
}
void addEdgeTran(vector <pair<int, int> > trans[], int u,
									int v, int wt)
{
	//adj[u].push_back(make_pair(v, wt));
	//adj[v].push_back(make_pair(u, wt));
    trans[u].push_back(make_pair(v,wt));
}
// void removeEdge(vector <pair<int, int> > adj[], int u,
// 									int v, int wt)
// {
// 	adj[u].at();
// 	//adj[v].push_back(make_pair(u, wt));
    
// }
void check(vector<pair<int,int> > trans[], int V){
    int v,w;
    for(int u = 0;u<V;u++){
        for (auto it = trans[u].begin(); it!=trans[u].end(); it++){
            v = it->first;
			w = it->second;
            if(w==0){
                
                int x,y;
                
                for (auto it = trans[v].begin(); it!=trans[v].end(); it++){
                    cout << "Node " << v << " makes an edge with \n";
                    x = it->first;
			        y = it->second;
                    // if(u+1==v){
                    //     x++;
                    // }
                    cout << "\tNode " << x << " with edge weight ="
				<< y << "\n";
                    string test = to_string(x);
                    if(eNFA[u][y]=="{}")
                    eNFA[u][y].clear();
                    eNFA[u][w].clear();
                    eNFA[u][w].append(" {} ");
                    eNFA[u][y].append(test+" ");

                
                }
            }
        }
    }
}

// Print adjacency list representation of graph
void printGraph(vector<pair<int,int> > trans[], int V)
{
	int v, w;
	for (int u = 0; u < V; u++)
	{
		cout << "Node " << u << " makes an edge with \n";
		for (auto it = trans[u].begin(); it!=trans[u].end(); it++)
		{
			v = it->first;
			w = it->second;
            States.push_back(v);
            if(w == 0 && v!=-1){
                acceptingStates.push_back(u);
                
                

            }
            if(v!=-1)
             cout << "\tNode " << v << " with edge weight ="
				<< w << "\n";
            
			
            
		}
		cout << "\n";
	}
}

void addTransition(vector<pair<int,int> > adj[], int V){
   
        int v,w;
        for (int u = 0; u < V; u++)
	    {
		for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
		{
			v = it->first;
			w = it->second;
            //cout<<endl<<endl<<"-----TEST 1------"<<endl<<endl;
            //if(w==0){
                
            cout << "Node " << u<< " makes an edge with \n";
                         cout << "\tNode " << v << " with edge weight ="
				<< w << "\n";
            //}
            int x,y;
             for (auto it = trans[v].begin(); it!=trans[v].end(); it++){
                    
                    x = it->first;
			        y = it->second;
                //     cout<<endl<<endl<<"-----TEST 2------"<<endl<<endl;
                //     //if(y==0){
                //     cout << "Node " << v << " makes an edge with \n";
                //          cout << "\tNode " << x << " with edge weight ="
				// << y << "\n";
                    //}
             
                //     int h,k;
                //     for (auto it = trans[x].begin(); it!=trans[x].end(); it++){
                //         h = it->first;
			    //         k = it->second;
                //         cout<<endl<<endl<<"-----TEST 3------"<<endl<<endl;
                //         //if(k==0){
                //         cout << "Node " << x << " makes an edge with \n";
                //          cout << "\tNode " << h << " with edge weight ="
				// << k << "\n";
                //         //}
                //         int t,e;
                //         for (auto it = trans[h].begin(); it!=trans[h].end(); it++){
                //         t = it->first;
			    //         e = it->second;
                //         cout<<endl<<endl<<"-----TEST 4------"<<endl<<endl;
                //        // if(e==0){
                //         cout << "Node " << h << " makes an edge with \n";
                //          cout << "\tNode " << t << " with edge weight ="
				// << e << "\n";
                //        //}
                //        int a,s;
                //         for (auto it = trans[t].begin(); it!=trans[t].end(); it++){
                //         a = it->first;
			    //         s = it->second;
                //         cout<<endl<<endl<<"-----TEST 5------"<<endl<<endl;
                //        // if(e==0){
                //         cout << "Node " << t << " makes an edge with \n";
                //          cout << "\tNode " << a << " with edge weight ="
				// << s << "\n";
                    //     }
                    // }
                    // }
             //}
            
			
           
		}
        
		cout << "\n";
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
                             for(int k = 0;k<sub.size();k++){
                                    if(isdigit(sub[k])){
                                        //cout<<i-3<<" "<<sub[k]<<" found at "<<j<<endl;
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
	// int f;
    // for (int u = 0; u < V; u++)
	// {
    //     addTransition(adj,trans,V,u);
	// 	//cout << "Node " << u << " makes an edge with \n";
	// 	for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
	// 	{
    //         f=it->first;
    //         if(f!=-1)
    //         cout<<u<<" "<<f<<endl;
            
    //         //addTransition(adj,trans,V,f);
    //     }
    // }
    
	//printGraph(adj, V);
    
   addTransition(adj,V);
   
   
    sort(acceptingStates.begin(),acceptingStates.end());
    acceptingStates.erase(unique(acceptingStates.begin(),acceptingStates.end()),acceptingStates.end());
   
    sort(States.begin(),States.end());
    States.erase(unique(States.begin(),States.end()),States.end());

    //  sort(trans.begin(),trans.end());
    // trans.erase(unique(trans.begin(),trans.end()),trans.end());

    // cout<<endl<<endl<<"ACCEPTING STATES"<<endl;
    // for(int i = 0;i<acceptingStates.size();i++){
    //     cout<<acceptingStates[i]<<endl;
    // }
    // cout<<endl<<endl<<"STATES : "<<endl;
    // for(int i = 0;i<States.size();i++){
    //     cout<<States[i]<<endl;
    // }
    cout<<endl<<endl<<"TRANS : "<<endl;
    //check(trans, V);
    // for(int i = 0;i<eNFA.size();i++){
    //     cout<<i<<" ";
    //     for(int j = 0;j<eNFA[i].size();j++){
    //         cout<<eNFA[i][j];
    //     }
    //     cout<<endl;
    // }

    
    return 0;
}








