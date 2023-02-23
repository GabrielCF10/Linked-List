#include "contatinho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato
{ // cria um tipo lista 
    char nome[11];
    int numero;
    struct contato *proximo;

} contatinho;

typedef struct lista
{ // Cria um ponteiro para o inicio da lista
    contatinho *inicio;

} tipoLista;

tipoLista *criar_lista()
{ // Cria uma lista(aponta o primeiro elemento pra null)
    tipoLista *lista = malloc(sizeof(tipoLista));
    lista->inicio = NULL;

    return lista;
}

void inserir_contato(tipoLista *lista, char nome[], int numero){ //Recebe a lista, nome do contato e numero, e os insere na lista. Caso não seja possivel retorna uma mensagem
    contatinho *novo = malloc(sizeof(contatinho));
    strcpy(novo->nome, nome);
    novo->numero = numero;
    
    contatinho *aux = lista->inicio;
    while(aux != NULL)
    {
        if (strcmp(aux->nome, nome) == 0){ // confere se já existe este contato
            printf("Contatinho ja inserido\n");
            return;
        }

        aux = aux->proximo;

    }
            novo->proximo = lista->inicio; // se não inserido, insere o novo contatinho no inicio
            lista->inicio = novo;


}


void  pesquisar_contato(tipoLista *lista, char nome[]) { // Recebe a lista e nome do contato e percorre a lista buscando o contato. Caso seja encontrado retorna o telefone, caso não seja encontrado retorna uma mensagem
 
	contatinho *P = lista->inicio;
	if(P == NULL){ 
		printf("Contatinho nao encontrado\n"); // se não existirem elementos na lista
        return;
     }
	while(P != NULL) {
		if (strcmp(P->nome,nome) == 0){ 
			printf("Contatinho encontrado: telefone %d\n", P->numero); // percorre a lista para encontrar o contatinho
                    return;
        } 

		P = P->proximo;
	}
     printf("Contatinho nao encontrado\n"); //se ele saiu do while é porque não existe o contatinho
	
}


void remover_contato(tipoLista *lista, char nome[]) { //Recebe a lista e o nome do usuário e remove, se existir, seu contato. Caso não exista retorna uma mensagem

	contatinho *P = lista->inicio;
	if(P == NULL){ 
        printf("Operacao invalida: contatinho nao encontrado\n"); // se não existirem elementos
		return;
        }
	
   
	if (strcmp(P->nome,nome)==0) { 
        
		lista->inicio = lista->inicio->proximo; // caso seja o primeiro elemento, remove o contatinho ligando o anterior ao proximo
		free(P);
		return ;
	}

	while(P->proximo != NULL) {
		if (strcmp(P->proximo->nome,nome)==0) { //remove o contatinho no meio da lista ligando o anterior ao proximo
			contatinho *aux = P->proximo;
			P->proximo = P->proximo->proximo;
			free(aux);
			return; 
		}
		P = P->proximo;
	}
    printf("Operacao invalida: contatinho nao encontrado\n"); // se ele saiu do while é porque não existe o contatinho
	

}


void alterar_contato(tipoLista *list, char nome[], int numero) //Recebe a lista, o nome do contato e o novo numero e o altera. Caso não exista contato retorna uma mensagem
{ 

    {
        contatinho *P = list->inicio;
    

        if (list->inicio == NULL) // lista vazia
            printf("Operacao invalida: contatinho nao encontrado\n"); // se a lista não possui elementos

        else
        { // lista não esta vazia

            
                while (P != NULL)
                {

                    if (strcmp(P->nome, nome) == 0)
                    { // entrou o contanto
                        P->numero = numero;
                        return;
                    }
                   P = P->proximo;
                }

                    printf("Operacao invalida: contatinho nao encontrado\n"); // se ele saiu do while é porque não existe o contatinho
            
        }
    }
}

