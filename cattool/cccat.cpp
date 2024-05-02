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
    if (argv[1] == NULL) {
        cout << "Error: No Arguments\n";
        return 1;
    }

    cout << "no of arguments: " << argc << '\n';
    cout << argv[1] << '\n';

    if (argv[1] == "-") {
        string line;
        int i{1};
        while (getline(cin, line)) {
            cout << i << ' ' << line << '\n';
            ++i;
        }
        return 0;
    }

    if (argc > 2) {
        for (int i = 1; i < argc; ++i) {
            string arg = argv[i];
            PrintFile(arg);
        }
        return 0;
    }

    string arg = argv[1];
    PrintFile(arg);

    return 0;
}
