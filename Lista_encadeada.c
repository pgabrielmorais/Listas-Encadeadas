#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tam = 0;
int tam2 = 0;
//declaracao da lista encadeada
struct Lista_Palavras{
	char *palavra;
	int linha_pos [][];
	struct Lista_Palavras *prox;
	
}; 
typedef struct Lista_Palavras node;





int vazia(node *LISTA){
 	if(LISTA->prox == NULL)
 		return 1;
 	else
  		return 0;
}



void insereFim(node *LISTA){
	node *novo = (node *) malloc(sizeof(node));
	printf("passou por aqui \n");

 	novo->prox = NULL;
 
 	if(vazia(LISTA))
  		LISTA->prox=novo;
 	else{
  		node *tmp = LISTA->prox;
  		while(tmp->prox != NULL){
   			tmp = tmp->prox;
  		}
  		tmp->prox = novo;
 	}
 	tam++;
}





void inicia(node *LISTA){
	LISTA->prox = NULL;
	tam = 0;
}




int main(){
	//declaração de variáveis
	char linha[100];
	FILE *arq1;
	FILE *arq2;
	//char *palavra;
	



	//abertura dos arquivos de entrada
	arq1 = fopen("entrada.txt", "r");
	arq2 = fopen("saida.bin", "w+");

	//alocação de memória para a lista
	node *LISTA = (node *) malloc(sizeof(node));
	inicia(LISTA);

	if (arq1 == NULL){
		printf("Arquivo não econtrado");
		
	} else{
		while(!feof(arq1)){
			fgets(linha, sizeof(linha),arq1);
			printf("%s \n",linha);
			
			LISTA->palavra = strtok(linha, " ");
			do{
				printf("%s\n", LISTA->palavra);

				insereFim(LISTA);
				LISTA->palavra = strtok(NULL, " ");

			}while(LISTA->palavra != NULL);			
		}
	}

	
	getchar();
	return 0;
}
