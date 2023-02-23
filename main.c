//Gabriel Vasconcelos de Arruda. nUSP 12676192
//Gabriel Carvalho Fernandes. nUSP 13696662
//Gabriel de Sousa Dalcin. nUSP 13750784

#include "contatinho.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    tipoLista *lista_contatos = criar_lista(); // cria a lista sempre que o programa é iniciado

    char opc, name[11];
    int numb;
    double cont;

    while (opc != '0' || cont <1000000000 )
    {
        scanf("%c", &opc);
        cont++;
        
            
            if(opc == 'I'){  //inserir
                scanf("%s", name);
                scanf("%d", &numb);
                inserir_contato(lista_contatos, name, numb);
                
             }
            else if(opc == 'P'){  // pesquisar
                scanf("%s", name);
                pesquisar_contato(lista_contatos, name);
                
             }
            else if('R'== opc){// remover
                scanf("%s", name);
                remover_contato(lista_contatos, name);
            }

            else if(opc == 'A'){  // alterar
                scanf("%s", name);
                scanf("%d", &numb);
                alterar_contato(lista_contatos, name, numb);
                
                }

                else if (opc == '0')
            {                       
                return 0; // caso opc==0 o programam se encerra
        }
            }
         return 0;
    }

   

