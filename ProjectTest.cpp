#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>

using namespace std;

// char numState;
// int alpSize;
vector <string> NFA;
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
                while(getline(in,line)){
                        i++;
                        if(i>=4){
                         stringstream ss(line);
                         while(ss>>sub){
                                NFA.push_back(sub);
                         }
                        }
                        
                }
                
           }
}


int main(int argc, char* argv[]){
         readInput(argc,argv);
         readNFA(argc,argv);
          for(int i = 0;i<NFA.size();i++){
                cout<<NFA[i]<<" "<<i<<endl;
          }
         
	return 0;
}




