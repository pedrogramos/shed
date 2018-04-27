#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;

// exemplo de como escrever para um ficheiro .txt que é criado pelo prog
//


void getTime(){
  //string file =filename.c_str();
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  //string a =fprintf( "The current date/time is: %s", asctime (timeinfo) );
  outfile << asctime (timeinfo);
}


int main(int argc, char const *argv[])
{
  std::ofstream outfile ("test.txt");
  unsigned int i=0;

  /*

while(i<3){

  if (i==2){
    //outfile.open ("test.txt");
    outfile << "dif de 000"<< std::endl; //escreve numa linha
    //outfile.close();
  }

  if (i==1){
    //outfile.open ("test.txt");
    outfile << "i=1"<< std::endl; //escreve na linha seguinte
    //outfile.close();
  }


 i++;

}*/


getTime();
  

	return 0;
}