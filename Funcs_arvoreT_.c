/************************************************************
*            Eric Rodrigues das Chagas                      *
*    [ICMC - Bacharelado em Ciências da Computação - 2021]  *
*    NºUSP: 12623971                                        *
* ||----------------------Contatos----------------------||  *
*            Telegram [ @EricRC_123 ]                       *
*            Email  [ eric.r.c@usp.br ]                     *
*************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include "my_string_.h"
#include "H_arvoreT_.h"





//Criar um novo nó
nodeType* creatNode(int chave, int prioridade)
{
	
    nodeType* new_node = malloc(sizeof(nodeType));
	new_node->chave = chave;
	new_node->prioridade = prioridade;
	
    new_node->filho_esq = NULL;
    new_node->filho_dir = NULL;
	return new_node;
}

//Busca recursiva
nodeType* searchNode(nodeType *node_atual, int chave)
{

    //Caso base: arvore vazia ou a chave da raiz é chave que se busca
	if (node_atual == NULL || node_atual->chave == chave)
	return node_atual;

	//Passo recursivo: chave é maior que a chave do node_atual
	if (node_atual->chave < chave)
	return searchNode(node_atual->filho_dir, chave);

	//Passo recursivo: chave é menor que a chave do node_atual
	return searchNode(node_atual->filho_esq, chave);
}


//Inserção recursiva 
nodeType* insertNode(nodeType* raiz, int chave, int prioridade)
{
	//Caso base: raiz é NULL, criar um novo nó e retorna-lo
	if(raiz == NULL) return creatNode(chave, prioridade);
		

	//Caso: chave é menor que a chave da raiz
	if (chave < raiz->chave){
		//Inserir filho_esq na subarvore
		raiz->filho_esq = insertNode(raiz->filho_esq, chave, prioridade);

		//Caso: prioridade desordenada (reordenar)
		if (raiz->filho_esq->prioridade > raiz->prioridade)
			raiz = rotacaoDir(raiz);
	}
    //Caso: chave é maior
	else if (chave > raiz->chave){
		//Inserir filho_dir na subarvore
		raiz->filho_dir = insertNode(raiz->filho_dir, chave, prioridade);

		//Caso: prioridade desordenada (reordenar)
		if (raiz->filho_dir->prioridade > raiz->prioridade)
			raiz = rotacaoEsq(raiz);
	}
    //Caso: chave é igual
    else if (chave == raiz->chave){
        printf("Elemento ja existente\n");
    }
	return raiz;
}

/* 
    Apagar um nó da arvore
    @param raiz raiz da arvore
    @param chave chave referente ao nó que deseja ser apagado 
*/
nodeType* deleteNode(nodeType* raiz, int chave)
{
	//Caso base
    if (raiz == NULL)
		return raiz;

    //Chamada a esquerda
	if (chave < raiz->chave)
		raiz->filho_esq = deleteNode(raiz->filho_esq, chave);
	
    //Chamada a direita
    else if (chave > raiz->chave)
		raiz->filho_dir = deleteNode(raiz->filho_dir, chave);

	//Caso: filho_esq sej NULL
	else if (raiz->filho_esq == NULL)
	{
		nodeType *node_aux = raiz->filho_dir;
		free(raiz);
		
        // Defnir filho_dir filho de raiz
        raiz = node_aux; 
	}

	//Caso: filho_dir seja NULL
	else if (raiz->filho_dir == NULL)
	{
		nodeType *node_aux = raiz->filho_esq;
		free(raiz);
		
        // Defnir filho_esq filho de raiz
        raiz = node_aux; 
	}

	//Caso: arvore desordenada a esquerda
	else if (raiz->filho_esq->prioridade < raiz->filho_dir->prioridade)
	{
		raiz = rotacaoEsq(raiz);
		raiz->filho_esq = deleteNode(raiz->filho_esq, chave);
	}
	
    //Caso: arvore desordenada a direita
    else
	{
		raiz = rotacaoDir(raiz);
		raiz->filho_dir = deleteNode(raiz->filho_dir, chave);
	}

	return raiz;
}


//Rotacionar no sentido hórario
nodeType *rotacaoDir(nodeType *pai)
{
	nodeType *novo_pai = pai->filho_esq;
    nodeType *nv_filho_d = novo_pai->filho_dir;

	//Rotação
	novo_pai->filho_dir = pai;
	pai->filho_esq = nv_filho_d;

	return novo_pai;
}

//Rotacionar no sentido anti-hórario
nodeType *rotacaoEsq(nodeType *pai)
{
	//Declarações
    nodeType *novo_pai = pai->filho_dir;
    nodeType *nv_filho_d = novo_pai->filho_esq;

	//Rotação
	novo_pai->filho_esq = pai;
	pai->filho_dir = nv_filho_d;

	return novo_pai;
}

//Imprimir arvore da direita para esquerda
void printTreeORD(nodeType *pNode) {

    if(pNode == NULL) return;
        
    printTreeORD(pNode->filho_esq);

    printf("(%d, %d) ",pNode->chave, pNode->prioridade);

    printTreeORD(pNode->filho_dir);

    return;
}



//Imprimir arvore da esquerda para direita
void printTreePRE(nodeType *pNode)
{
    if(pNode != NULL)
		printf("(%d, %d) ",pNode->chave,pNode->prioridade);

	else return;
		
    printTreePRE(pNode->filho_esq);
	printTreePRE(pNode->filho_dir);

    return;
}

//Imprimir arvore da esquerda para direita
void printTreePOS(nodeType *pNode)
{
    if(pNode != NULL){

	    printTreePOS(pNode->filho_esq);

		printTreePOS(pNode->filho_dir);

		printf("(%d, %d) ",pNode->chave,pNode->prioridade);
	}
	
    return;
}



/* Function to print level order traversal a tree*/
void printLevelOrder(nodeType *raiz)
{
	int h = height(raiz);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(raiz, i);
}

/* Print nodes at a current level */
void printCurrentLevel(nodeType *raiz, int level)
{
	if (raiz == NULL)
		return;
	if (level == 1)
		printf("(%d, %d) ", raiz->chave, raiz->prioridade);
	else if (level > 1) {
		printCurrentLevel(raiz->filho_esq, level - 1);
		printCurrentLevel(raiz->filho_dir, level - 1);
	}
}

/* 
	Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.
*/
int height(nodeType *pNode)
{
	if (pNode == NULL)
		return 0;
	else {
		/* compute the height of each subtree */
		int altu_esq = height(pNode->filho_esq);
		int altu_dir = height(pNode->filho_dir);

		/* use the larger one */
		if (altu_esq > altu_dir)
			return (altu_esq + 1);
		else
			return (altu_dir + 1);
	}
}

