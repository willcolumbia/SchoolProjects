#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;


int main(int argc, char* argv[]){
	for(int i =0;i<argc;i++){
         ifstream in(argv[i+1]);
           if(in.is_open()){
              string line;
               while(getline(in,line)){
        	cout<<line.back()<<endl;
                }
        }
        }

	return 0;
}




