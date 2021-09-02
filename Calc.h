#ifndef CALC
#define CALC


struct calculator{
	
	float num1;
	float num2;

	
};

float calc(float*, float*,const int);

float getFloat();

void sceneRenderer(const int,float*,float*);

void changeInt(int*,const int);

void changeFloat(float*,const float);

void mainLoop(float*,float*);

void calcProcess(const int, float, float);


#endif