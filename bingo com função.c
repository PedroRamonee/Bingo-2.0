#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int gerar(){
	
	int t ;
	
	t = rand() % 60;
	
	if(t == 0){
		
		t = 60;
	}
	
	
	return t;
	
}


int imprimir ( int jogador[]){
	
	int i;
	
	for(i=0; i<16; i++){
		if(i % 4 == 0){
			printf("\n");
		}
		
		printf("%d \t", jogador[i]);
		
	}
	
	printf("\n");
	
	return 0;
}


int pinguim (){	
			printf("            Pedro                                   Gabriel                 \n\n\n");
			printf("          ,888888b.                                  ,888888b.                   \n");
			printf("        .d888888888b                               .d888888888b                  \n");
			printf("    _..-'.`*'_,88888b                          _..-'.`*'_,88888b                 \n");
			printf("  ,'..-..`\"ad88888888b.                      ,'..-..`\"ad88888888b.               \n");
			printf("         ``-. `*Y888888b.                           ``-. `*Y888888b.             \n");
			printf("             \\   `Y888888b.                             \\   `Y888888b.           \n");
			printf("             :     Y8888888b.                           :     Y8888888b.         \n");
			printf("             :      Y88888888b.                         :      Y88888888b.       \n");
			printf("             |    _,8ad88888888.                        |    _,8ad88888888.      \n");
			printf("             : .d88888888888888b.                       : .d88888888888888b.     \n");    // :)
			printf("             \\d888888888888888888                       \\d888888888888888888     \n");
			printf("             8888;'''`88888888888                       8888;ss'`88888888888     \n");
			printf("             888'     Y8888888888                       888'N\"N Y8888888888      \n");
			printf("             `Y8      :8888888888                       `Y8 N  \" :8888888888     \n");
			printf("              |`      '8888888888                        |` N    '8888888888     \n");
			printf("              |        8888888888                        |  N     8888888888     \n");
			printf("              |        8888888888                        |  N     8888888888     \n");
			printf("              |        8888888888                        |  N     8888888888     \n");
			printf("              |       ,888888888P                        |  N    ,888888888P     \n");
			printf("              :       ;888888888'                        :  N    ;888888888'     \n");
			printf("               \\      d88888888'                         :  N    ;888888888'     \n");
			printf("              _.>,    888888P'                            \\ N    d88888888'      \n");
			printf("            <,--''`.._>8888(                             _.>N    888888P'        \n");
			printf("             `>__...--' `''` SSt                       <,--'N`.._>8888(          \n");
			printf("                                                        `>__N..--' `''` SSt      \n");
}


int sorteado(int k, int num[]){
	
	k++;
	int i;
	
	for(i=0 ; i < k; i++){
		
		printf("%d ", num[i]);
	}
}


int main(){
	
	int jogador1[16], jogador2[16], num[60], rec; 
	int i, j, k=0, l, m, cont=1;
	int pont1 = 0, pont2 = 0; 
	int pode = 1; 
	
	srand(time(NULL));
	system("color 03");
	
	for(i=0; i<16; i++){
		
		rec = gerar();
		
		jogador1[i] = rec;
		
		for(l = 0; l < i; l ++){
			
			if(jogador1[l] == rec){
				i--;
			}
		}
	}
	
	for(i=0; i<16; i++){
		
		rec = gerar();
		
		jogador2[i] = rec;
		
		for(l = 0; l < i; l ++){
			
			if(jogador2[l] == rec){
				i--;
			}
		}	
	}
	
	while(pont1 != 16 && pont2 != 16){
		
		pode = 1;
		
		while(pode){
			
			rec = gerar();
			
			num[k] = rec;
			
			pode = 0;
			
			for(l = 0; l < k; l++){
				
				if(num[l] == rec){
					
					pode = 1;
				}
				
			}	
			
		}
		
		for ( i = 0; i < 16; i++){
			
			if(jogador1[i] == rec){
				
				pont1++;
			}
			if(jogador2[i] == rec){
							
				pont2++;
			}
		}
		pinguim();
		
		printf("\nCartela jogador 1: \n");
	
		imprimir(jogador1);
		
		printf("Pontuacao: %d", pont1);
	
		printf("\n");
	
		printf("\nCartela jogador 2: \n");
	
		imprimir(jogador2);
		
		printf("Pontuacao: %d \n", pont2);
		
		printf("\n Total de numeros sorteados: %d \n\n", cont);
		
		sorteado(k, num);
		
		printf("\n\n");
		system("pause");
		system("cls");
		
		cont++;
		k++;
		
	}
	
	if(pont1 == 16 && pont2 == 16){
				
		printf("\n\nEMPATE  !!!!!!!!! \n\n"); 
		system("color 0a");
	}	
			
	else if(pont1 == 16){
	
		printf("\n\n% Jogador 1 VENCEU !!!!!!! \n\n");
		system("color 04");
	}
			
	else if (pont2 == 16){
		
		printf("\n\n Jogador 2 VENCEU !!!!!!! \n\n");
		system("color 0d");	
	}
			
	pinguim();
	system("pause");
	return 0;
}
