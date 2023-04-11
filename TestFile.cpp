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
                         while(ss>>sub){
                            for(int k = 0;k<sub.size();k++){
                                if(sub[k]=='{' || sub[k] == '}'|| sub[k]==','){
                                    sub[k] = ' ';
                                    
                                }
                            }
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



int main(int argc, char* argv[]){
    readInput(argc,argv);
    readNFA(argc,argv);
    cout<<"ALPHABET SIZE: "<<betSize<<endl<<endl;
     for(int i = 0;i<eNFA.size();i++){
        cout<<i<<" ";
        for(int j = 0;j<eNFA[i].size();j++){
            cout<<" "<<eNFA[i][j];
        }
        cout<<endl;
        
    }

    //ADD NEW ACCEPTING STATES
    for(int i = 0;i<eNFA.size();i++){
         string line = eNFA[i][0];
         for(int j = 0;j<line.size();j++){
            if(isdigit(line[j])){
                acceptStates.push_back(i);
            }
         }
        
    }
    //REMOVE DUPLICATE ACCEPTING STATES
    sort(acceptStates.begin(),acceptStates.end());
    acceptStates.erase(unique(acceptStates.begin(),acceptStates.end()),acceptStates.end());
    
    //bool test = true;
    //while(test){
        for(int i = 0;i<eNFA.size();i++){
            int q,r,s = i;
            for(int j = 0;j<eNFA[i].size();j++){
                int s = j;
                string rs = eNFA[i][j];
                if(!rs.empty())
                cout<<rs<<endl;
            }
        }
        //test == false;
   // }
    
    // for(int i = 0;i<acceptStates.size();i++){
    //     cout<<acceptStates[i]<<endl;
    // }
    // return 0;
}   