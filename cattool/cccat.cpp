#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

void PrintFile(string &path)
{
  fstream file(path.c_str());
  if (file.fail())
  {
    cout << "\n Couldn't open that file\n";
    return;
  }
  string line;
  while (getline(file, line))
  {
    cout << line << '\n';
  }
  file.close();
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    cout << "Error: No Arguments\n";
    return 1;
  }

  string line;

  for (int i = 1; i < argc; ++i)
  {
    if (string(argv[i]) == "-")
    {
      while (getline(cin, line))
      {
        cout << line << '\n';
      }
    }
    else if (string(argv[i]) == "-n")
    {
      int number{1};
      while (getline(cin, line))
      {
        cout << number++ << ' ' << line << '\n';
      }
    }
    else if (string(argv[i]) == "-b")
    {
      bool blankline{false}; // flag to determine the blank lines
      int number{1};
      while (getline(cin, line))
      {
        if (blankline)
        {
          cout << line << '\n';
          blankline = 0;
        }
        else
        {
          cout << number++ << ' ' << line << '\n';
          blankline = 1;
        }
      }
    }
    else
    {
      string arg = argv[i];
      PrintFile(arg);
    }
  }

  return 0;
}
