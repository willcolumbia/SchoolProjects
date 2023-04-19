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
                          
                        }
                        i++;       
                }
              }
           }

int main(int argc, char* argv[]){
    readNFA(argc,argv);
    for(int i = 0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }
}