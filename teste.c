#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tam = 0;
int tam2 = 0;
//declaracao da lista encadeada
struct Lista_Palavras{
	char *palavra;
	//int num;
	struct Lista_Palavras *prox;
	struct Lista_Posicao *posicao;
}; 
typedef struct Lista_Palavras node;


struct Lista_Posicao{
	int linha;
	int pos;
	struct Lista_pPosicao *prox2;
};
typedef struct Lista_Posicao node2;



int vazia(node *LISTA){
 	if(LISTA->prox == NULL)
 		return 1;
 	else
  		return 0;
}

int vazia2(node2 *LISTA2){
 	if(LISTA2->prox2 == NULL)
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

void insereFim2(node2 *LISTA2){
	node2 *novo2 = (node2 *) malloc(sizeof(node2));
	printf("Inserindo posição na lista 2\n");

	novo2->prox2 = NULL;

	if (vazia2(LISTA2)){
		LISTA2->prox2 = novo2;
	}else{
		node2 *tmp2 = LISTA2->prox2;
		while(tmp2->prox2 != NULL){
			tmp2 = tmp2->prox2;
		}
		tmp2->prox2 = novo2;
	}
	tam2++;
}




void inicia(node *LISTA){
	LISTA->prox = NULL;
	tam = 0;
}

void inicia2(node2 *LISTA2){
	LISTA2->prox2 = NULL;
	tam2 = 0;
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
	node2 *LISTA2 = (node2 *) malloc(sizeof(node2));
	inicia2(LISTA2);
	inicia(LISTA);
	LISTA2->pos = 0;


	if (arq1 == NULL){
		printf("Arquivo não econtrado");
		
	} else{
		while(!feof(arq1)){
			fgets(linha, sizeof(linha),arq1);
			printf("%s \n",linha);
			
			LISTA->palavra = strtok(linha, " ");
			LISTA2->pos = strlen(linha);
			do{
				LISTA2->linha++;
				printf("%s\n", LISTA->palavra);

				insereFim(LISTA);
				insereFim2(LISTA2);
				LISTA->palavra = strtok(NULL, " ");

			}while(LISTA->palavra != NULL);			
		}
	}

	
	getchar();
	return 0;
}
