#include <bits/stdc++.h>
using namespace std;
vector <int> acceptingStates;
vector<int> States;


string State;
string alpSize;
string accStates;
int numState;
int betSize;

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

void addTrans(map <int,vector<int>> &mp,int x,int y){
    mp[x].push_back(y);
}
 void addtoVec(vector<int>x,int y){
    x.push_back(y);
}
void show(map<int, vector<int> >& mapOfSet)
{
    // Using iterator to access
    // key, value pairs present
    // inside the mapOfSet
    for (auto it = mapOfSet.begin();
         it != mapOfSet.end();
         it++) {
 
        // Key is integer
        cout << it->first << " => ";
        
        // Value is a set of string
        vector<int> st = it->second;
        sort(st.begin(),st.end());
        st.erase(unique(st.begin(),st.end()),st.end());
        for(int i = 0;i<st.size();i++){
            cout<<" "<<st[i]<<" ";
        }
        cout << '\n';
    }
}

int main(int argc, char* argv[]){
    readInput(argc,argv);
    map <int,vector<int>> tr;
    map <int,vector<int>> mp;
    vector<int> eclose;
    ifstream in(argv[1]);
           if(in.is_open()){
              string line;
              string sub;
              int i=0;
                while(getline(in,line)&&!line.empty()){
                        if(i>=3){
                            States.push_back(i);
                                 stringstream ss(line);
                        string sub;
                        int j = 0;
                         while(ss>>sub){
                             for(int k = 0;k<sub.size();k++){
                                int y =0;
                                    if(isdigit(sub[k])){
                                        y = sub[k]-'0';
                                        addTrans(mp,i-3,y);
                                        addTrans(tr,j,y);
                                    }
                                }
                            j++;   
                         }
                        }
                        i++;     
                }
           }
           
        show(tr);
        cout<<endl<<endl;
         show(mp);
    return 0;
}