#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

std::vector<float> readFile(string path){
  float value;
  string discard;
  std::vector<float> aux;

  ifstream myReadFile;
  myReadFile.open(path.c_str());
  if (myReadFile.is_open()) {
    while (myReadFile >> discard >> value) {
      
      //fscanf(myReadFile,"%s %f",discard, value)
      aux.push_back(value);
          
    }
  }
  myReadFile.close();

for (std::vector<float>::const_iterator i = aux.begin(); i != aux.end(); ++i)
    std::cout << *i << ' ';
  cout << endl;


return aux;

}



int main(int argc, char const *argv[])
{

	 std::vector<float> setValues;
	 setValues = readFile("markersSettings.txt");
	 cout << setValues.at(1) << endl;


	return 0;
}