// reading a text file
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
  string line;
  ifstream myfile;("myData.rtf");  /// Use the my edited version of the rtf file
                     /// The other one has a bunch of junk that makes it impossible to read
  
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
