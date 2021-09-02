#include "includes.h"

float calc(float* x,float* y,const int choice){

	switch(choice){

		case 0:

			return *x + *y;
			break;

		case 1:

			return *x - *y;
			break;

		case 2:

			return *x / *y;
			break;

		case 3:

			return *x * *y;
			break;

/*		case 4:

			return x % y;
			break;*/
		default:

			return 0;
	}

	return 0;
}


float getFloat(){
	float dat = 0.0f;

	printf("\n\nPlease input a float (decimal number): \t");
	scanf("%f",&dat);

	return dat;
}

void changeInt(int* x, const int change){

	*x = change;

}

void changeFloat(float* x, const float change){

	*x = change;
}

void sceneRender(const int choice, float* x, float* y){

	int i;
	const char frame[41] = "########################################\0";
	const char* strings[10][50] = {

		{"\n0. Menu\0"},
		{"1. Add\0"},
		{"2. Minus\0"},
		{"3. Divide\0"},
		{"4. Times\0"},
		{"5. Reset numbers\0"},
		{"6. Set L-Operand\0"},
		{"7. Set R-Operand\0"},
		{"64. exit\0"}
	};

	/* ugly macros */

	#ifdef _WIN32
		system("cls");
	#endif

	#ifdef _WIN64
		system("cls");
	#endif

	#ifdef __unix__
		system("reset");
	#endif

	/* ugly macros */


	switch(choice){ /* Reason for the switch is because I was going to render unique scenes for each calculation process but now I think its easier for me to just render it in at the bottom of the menu */

		case 0: /*This will be the menu */ 

			printf("%s",frame);
			printf("\t\tL-Operand: ");
			printf("%f",*x);
			printf("  R-Operand: ");
			printf("%f",*y);
			printf("\n");
			for(i = 0; i < 9; ++i){

				printf("%s",*strings[i]);
				printf("\n");}

			printf("\n");
			printf("%s",frame);

			printf("\n\nEnter a number:  \t");
			break;

		default: /* Return to menu in event that a wrong input is detected*/

			sceneRender(0,x,y);
			break;
	}

}

void calcProcess(const int choice, float x, float y){

	const char str[100] = {"\n\nCalculation output:\n\n\0"};
	

	switch(choice){

		case 0:
			printf("%s",str);
			printf("%f",x);
			printf(" + ");
			printf("%f",y);
			printf(" = ");
			
			break;

		case 1:
			printf("%s",str);
			printf("%f",x);
			printf(" - ");
			printf("%f",y);
			printf(" = ");
			
			break;

		case 2:
			printf("%s",str);
			printf("%f",x);
			printf(" / ");
			printf("%f",y);
			printf(" = ");
		
			
			break;

		case 3:

			printf("%s",str);
			printf("%f",x);
			printf(" * ");
			printf("%f",y);
			printf(" = ");
			
			break;

		default:
			printf("DEFAULT");
			break;

	}

}


void mainLoop(float* x, float* y){
	const char str[100] = {"\n\nPress enter to return... \n\0"};
	bool running = 1;
	int calcChoice = 0;

	sceneRender(0,x,y);

	while(running){

		scanf("%d",&calcChoice);

		switch(calcChoice){ 

			case 1: /* add */
				
				calcProcess(calcChoice-1,*x,*y);
				*x = calc(x,y,0);
				*y = 0;
				printf("%f",*x);
				getchar();
				*x = 0;

				break;

			case 2:
				calcProcess(calcChoice-1,*x,*y);
				*x = calc(x,y,calcChoice-1);
				*y = 0;
				printf("%f",*x);
				getchar();
				*x = 0;
				
				break;

			case 3:

				calcProcess(calcChoice-1,*x,*y);
				*x = calc(x,y,calcChoice-1);
				*y = 0;
				printf("%f",*x);
				getchar();
				*x = 0;
				break;

			case 4:
				
				calcProcess(calcChoice-1,*x,*y);
				*x = calc(x,y,calcChoice-1);
				*y = 0;
				printf("%f",*x);
				getchar();
				*x = 0; 
				break;

			case 5:/* RESET NUMBERS */

				*x = 0;
				*y = 0;
				sceneRender(0,x,y);
				
				break;

			case 6:

				*x = getFloat();

				getchar();

				break;


			case 7:

				*y = getFloat();

				getchar();

				break;


			case 64: /* Hard coded program end */
				sceneRender(100,x,y);
				running = 0;
				break;

			default: /* return to menu on error */
				sceneRender(0,x,y);
				break;
		}
		
		printf("%s",str);
		getchar();
		sceneRender(0,x,y);

	}

}

