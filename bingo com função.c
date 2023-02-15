#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função que gera o numero aleatório
int gerar(){
	// variavel que recebe o numero
	int t ;
	//geração do numero
	t = rand() % 60;
	// caso seja 0 vira 60
	if(t == 0){
		
		t = 60;
	}
	
	//retorna o valor do numero
	return t;
	
}

// Função que imprime as cartelas
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

//pinguim
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

// Função dos numeros sorteados
int sorteado(int k, int num[]){
	
	k++;
	int i;
	
	for(i=0 ; i < k; i++){
		
		printf("%d ", num[i]);
	}
}


int main(){
	// Variáveis dos jogadores e dos numeros sorteados
	int jogador1[16], jogador2[16], num[60], rec; 
	// Variaveis contadoras e armazenadoras
	int i, j, k=0, l, m, cont=1;
	// Pontução dos jogadores
	int pont1 = 0, pont2 = 0;
	// Variavel Booleana "Improvisada" (true e false) 
	int pode = 1; 
	
	// Colocar como null a seed do gerador random
	srand(time(NULL));
	// Mudando a cor do programa
	system("color 03");
	
	// Gerar cartela do jogador 1
	for(i=0; i<16; i++){
		// Colocando o numero aleatorio na variavel armazenadora
		rec = gerar();
		// Jogando o numero sorteado na cartela
		jogador1[i] = rec;
		
		for(l = 0; l < i; l ++){
			//caso o numero sorteado ja tenha sido sorteado ele volta um passo e sorteia outro numero
			if(jogador1[l] == rec){
				i--;
			}
		}
	}
	
	// Gerar cartela do jogador 2
	for(i=0; i<16; i++){
		// Colocando o numero aleatorio na variavel armazenadora
		rec = gerar();
		// Jogando o numero sorteado na cartela
		jogador2[i] = rec;
		
		for(l = 0; l < i; l ++){
			//caso o numero sorteado ja tenha sido sorteado ele volta um passo e sorteia outro numero
			if(jogador2[l] == rec){
				i--;
			}
		}	
	}
	
	// Inicio do jogo propriamente dito, quando qualquer uma das pontuações chegar a 16 o loop encerra
	while(pont1 != 16 && pont2 != 16){
		
		//Colocando pode como verdadeiro
		pode = 1;
		
		/*Enquanto "pode" for verdade o jogo não continua, ja que o numero sorteado ja foi sorteado antes
		quando o numero sorteado for completamente novo o loop acaba*/
		while(pode){
			
			//Gerando o numero aleatorio e salvando o mesmo na variavel armazenadora
			rec = gerar();
			//Gravando o numero sorteado no vetor
			num[k] = rec;
			// Colocando "pode" como falso
			pode = 0;
			
			for(l = 0; l < k; l++){
				//Caso o numero ja tenha sido sorteado, "pode" fica verdadeiro e o loop reinicia
				if(num[l] == rec){
					
					pode = 1;
				}
				
			}	
			
		}
		
		// Loop que grava a pontuação dos jogadores
		for ( i = 0; i < 16; i++){
			
			if(jogador1[i] == rec){
				
				pont1++;
			}
			if(jogador2[i] == rec){
							
				pont2++;
			}
		}
		//pinguim
		pinguim();
		// Impressão da cartela do jogador 1
		printf("\nCartela jogador 1: \n");
	
		imprimir(jogador1);
		
		// Impressão da pontuação do jogador 1
		printf("Pontuacao: %d", pont1);
	
		printf("\n");
		
		// Impressão da cartela do jogador 2
		printf("\nCartela jogador 2: \n");
	
		imprimir(jogador2);
		
		// Impressão da pontuação do jogador 2
		printf("Pontuacao: %d \n", pont2);
		
		
		//Impressão dos numeros sorteados
		printf("\n Total de numeros sorteados: %d \n\n", cont);
		
		sorteado(k, num);
		// Coisas pra deixar o jogo mais fluido, como o pausamento do sistema e a limpagem de tela
		printf("\n\n");
		system("pause");
		system("cls");
		// Adiciona-se +1 as variaveis toda vez que o loop roda
		cont++;
		k++;
		
	}
	
	//Caso haja empate o sistema proclama o empate e muda de cor
	if(pont1 == 16 && pont2 == 16){
				
		printf("\n\nEMPATE  !!!!!!!!! \n\n"); 
		system("color 0a");
	}	
	//se o jogador 1 ganhar o sistema proclama e muda de cor		
	else if(pont1 == 16){
	
		printf("\n\n% Jogador 1 VENCEU !!!!!!! \n\n");
		system("color 04");
	}
	//se o jogador 1 ganhar o sistema proclama e muda de cor			
	else if (pont2 == 16){
		
		printf("\n\n Jogador 2 VENCEU !!!!!!! \n\n");
		system("color 0d");	
	}
	//pinguim		
	pinguim();
	system("pause");
	return 0;
}
