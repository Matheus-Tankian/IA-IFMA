#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printMatriz(int * * matriz, int valorI, int valorJ) {
	for(int i = 0; i < valorI; i++) {
		for (int j = 0; j < valorJ; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

int main(int argc, char** argv)
{
	
	int valorI = 0;
	int valorJ = 0;
	int casasuja = 0;
	int cont = 0;
	int x = 0;
	int y = 0;
	int l =1;
	
	do{
	
			printf("informe o valor de I: ");
			scanf("%d",&valorI);
			
			printf("informe o valor de J: ");
			scanf("%d",&valorJ);
			do{
				printf("informe o valor de casa suja: ");
				scanf("%d",&casasuja);
			}while(casasuja >((valorI*valorJ)-1));
			
			
			
			
			int * * r = (int * * ) malloc(sizeof (int * ) * valorI);
			for (int i = 0; i < valorI; i++) {
				r[i] = (int * ) malloc(sizeof (int) * valorJ);
			}
			
			srand(time(NULL));
			
			x = rand() % valorI;
			y = rand() % valorJ;
			r[x][y] = 0;
			
			do{
				cont = 0;
				for(int i = 0; i < valorI; i++) {
		
				for (int j = 0; j < valorJ; j++) {
				
						
						if((x==i)&& (y==j)){
							continue;
						}
						if(cont<=casasuja){
						r[i][j] = rand() % 2;
							if(r[i][j]== 1){
								cont++;
							  }	
						}else
						{
							r[i][j] = 0;
						}
				
					
				}
				
	  	  	  }	
				
			}while(cont!=casasuja);
			
		
		
			printf("Matriz inicial:\n");
			printf("O comeca robo na posicao: (%d)(%d)\n", x, y);
			printMatriz(r, valorI, valorJ);
			
			do {


				if((((y + 1) < valorJ) && ((y + 1) >= 0)) && (r[x][y + 1] > 0)) {
					y += 1;
					printf("O robo esta na posicao: (%d)(%d)\n", x, y);
					r[x][y] = 0;
					printMatriz(r, valorI, valorJ);
					continue;
				}
				if((((x + 1) < valorI) && ((x + 1) >= 0)) && (r[x + 1][y] > 0)) {
					x += 1;
					printf("O robo esta na posicao: (%d)(%d)\n", x, y);
					r[x][y] = 0;
					printMatriz(r, valorI, valorJ);
					continue;
				}
				if((((y - 1) < valorJ) && ((y - 1) >= 0)) && (r[x][y - 1] > 0)) {
					y -= 1;
					printf("O robo esta na posicao: (%d)(%d)\n", x, y);
					r[x][y] = 0;
					printMatriz(r, valorI,valorJ);
					continue;
				}
				if((((x - 1) < valorI) && ((x - 1) >= 0)) && (r[x - 1][y] > 0)) {
					x -= 1;
					printf("O robo esta na posicao: (%d)(%d)\n", x, y);
					r[x][y] = 0;
					printMatriz(r, valorI,valorJ);
					continue;
				}

					break;
	   	   	   	} while(true);
		
		printf("\nAperte a tecla 0 zero para sair: ");
		scanf("%d", &l);
		system("cls");
		
		   	
	}while(l!=0);

	
	return 0;
}