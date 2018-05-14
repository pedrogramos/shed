#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>


using namespace std;

// exemplo de como escrever para um ficheiro .txt que é criado pelo prog
//





int main(int argc, char const *argv[])
{
  
  // exemplo para o calculo do produto interno

  int x1 = 4; int y1 = 1;
  int x2 = 7; int y2 = 1;

  int x3 = 14; int y3 = 1;
  int x4 = 12; int y4 = 1;

  float vx1 = 0; float vy1 = 0; 
  float vx2 = 0; float vy2=0.3;


  //normalizar 1

  // calculo este inicialmente e de cada vez que chego a um ponto usando a ini: odom e o final: ponto destino
    float d=sqrt(pow((x2-x1 ),2)+pow((y2-y1),2));
    // vetores normalizados -> versor
    float dx=(x2-x1 )/d;
    float dy=(y2-y1)/d;


  //normalizar 2 - exemplo  opposite directions
    /*
    float d2=sqrt(pow((x4-x3),2)+pow((y4-y3),2));
    // vetores normalizados -> versor
    float dx2=(x4-x3)/d2;
    float dy2=(y4-y3)/d2;
    */

  // calculo este na recepção do serviço em que o ponto inicial é a odom e o final é o destino
    float d2=sqrt(pow((vx2-vx1),2)+pow((vy2-vy1),2));
    // vetores normalizados -> versor
    float dx2=(vx2-vx1) / d2;
    float dy2=(vy2-vy1) / d2;

    float res1= dx*dx2 + dy*dy2;

  // depois faço a verificação se o res1 for = -1 ou perto, next point

    cout << res1 << endl;
	return 0;
}