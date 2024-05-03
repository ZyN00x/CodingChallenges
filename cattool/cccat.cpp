#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std ; 

void PrintFile(string &path){

  fstream file(path.c_str()) ; 
  if(file.fail()){
    cout<<"\n Couldn't open that file\n" ; 
    return  ; 
  }
  string line;  
  while(getline(file , line)){
    cout<<line<<'\n' ; 
  }
  file.close() ; 
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Error: No Arguments\n";
    return 1;
  }


  for(int i  = 1 ; i < argc ; ++i){
    if(string(argv[i]) == "-"){
      string line ;
      int j = 1 ; 
      while(getline(cin , line)){
        cout<<j++<<' '<<line<<'\n';
      }
    }else{
      string arg = argv[i] ; 
      PrintFile(arg) ; 

    }
  }

  return 0;
}
