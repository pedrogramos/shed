#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include <ctime>

using namespace std;


int main(int argc, char const *argv[])
{
	time_t lastTime = -3;
	time_t now;
	double teste;

	for(;;){

		float start = std::chrono::system_clock::now();
		std::cout << "f(42) = " << fibonacci(42) << '\n';
		float end = std::chrono::system_clock::now();
		
		std::chrono::duration<double> elapsed_seconds = end-start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		
		std::cout << "finished computation at " << std::ctime(&end_time)
		          << "elapsed time: " << elapsed_seconds.count() << "s\n";
/*
		printf(" inicializa: %.f\n",lastTime );
		teste=time(NULL);
		printf("now: %.f\n",teste );


		if(time(NULL) > lastTime+3){
		  printf("ENTROU CHAAMDA SERVICO!!\n");

		  time(&lastTime);
		  printf("lastTime %.f \n", lastTime);

		}*/


	}
	return 0;
}