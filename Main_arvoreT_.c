/*******************************************************************************
*                       USP - Universidade de São Paulo                        *
*            ICMC - Instituto de Ciências Matemáticas e de Computação          *
********************************************************************************
*                 Eric Rodrigues das Chagas  NºUSP: 12623971                   *
*                  Bacharelado em Ciências de Computação 2021                  *
********************************************************************************
*                         Projeto 2 - Árvores Treaps                           *             
*                 Algoritmos e Estruturas de Dados I    SCC0502                * 
********************************************************************************/




#include <stdio.h>
#include <stdlib.h>
#include "my_string_.h"
#include "H_arvoreT_.h"



int main(){

    //Declarações iniciais
    int qnt_linhas = 0;
    char *comando = NULL;
    nodeType *arvore = NULL;
    scanf("%i",&qnt_linhas);
    

    format(stdin); //Retirar qualquer caractere em branco  
    
    for (int i = 0; i < qnt_linhas; i++)
    {
        comando = readword(stdin);
        
        if(compareStr(comando,"insercao") == 0){
            int chave = 0, prioridade = 0;
            scanf("%i",&chave); 
            scanf("%i",&prioridade);
            
            arvore = insertNode(arvore,chave,prioridade);
            
        }
        
        else if(compareStr(comando,"remocao") == 0){
            int chave = 0;
            scanf("%i",&chave); 

            if(searchNode(arvore,chave) == NULL)
                printf("Chave nao localizada\n");
            
            else arvore = deleteNode(arvore,chave);
                
        }
        else if(compareStr(comando,"buscar") == 0){
            int chave_buscada = 0;
            scanf("%d",&chave_buscada);
            if( searchNode(arvore,chave_buscada) != NULL){
                printf("1\n");
            }
            else printf("0\n");
        }


        else if(compareStr(comando,"impressao") == 0){
            char *modo_imp = NULL;
            modo_imp = readword(stdin);
            
            if(arvore == NULL){
                printf("VAZIA\n");
            }

            else if(compareStr(modo_imp,"ordem") == 0){
                printTreeORD(arvore);   printf("\n");
            }
            else if(compareStr(modo_imp,"preordem") == 0){
                printTreePRE(arvore); printf("\n");
            }
            else if(compareStr(modo_imp,"posordem") == 0){
                printTreePOS(arvore); printf("\n");
            }
            else if(compareStr(modo_imp,"largura") == 0){
                printLevelOrder(arvore);  printf("\n");
            }
            else{
                printf("Erro na leitura do modo_imp (%s)\n",modo_imp);
                return 1;
            }    
        
            free(modo_imp);
        }
        
        else{
            printf("Erro na leitura do comando (%s)\n",comando);
            return 1;
        }


        format(stdin);
        free(comando);    
    }

    return 0;
}

