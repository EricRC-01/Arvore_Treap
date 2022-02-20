


typedef struct node{
    int chave;
    int prioridade;
    int altura;

    struct node *filho_esq;
    struct node *filho_dir;

}nodeType;

//Criar um novo nó
nodeType* creatNode(int chave, int prioridade);

/* 
    Inseir um nó na arvore
    @param raiz raiz da arvore
    @param chave chave referente ao nó que deseja ser inserido
    @param prioridade 
*/
nodeType* insertNode(nodeType* raiz, int chave, int prioridade);


/* 
    Apagar um nó da arvore
    @param raiz raiz da arvore
    @param chave chave referente ao nó que deseja ser apagado 
*/
nodeType* deleteNode(nodeType* raiz, int chave);

//Rotacionar no sentido hórario
nodeType *rotacaoDir(nodeType *pai);

//Busca recursiva
nodeType* searchNode(nodeType *node_atual, int chave);


//Rotacionar no sentido anti-hórario
nodeType *rotacaoEsq(nodeType *pai);

//Rotacionar no sentido hórario
nodeType *rotacaoDir(nodeType *pai);


//Printar a arvore de diferentes formas
    void printTreePOS(nodeType *pNode);

    void printTreePRE(nodeType *pNode);

    void printTreeORD(nodeType *pNode);

    /* Function to print level order traversal a tree*/
        void printLevelOrder(nodeType *raiz);
        void printCurrentLevel(nodeType *raiz, int level);
        int height(nodeType *pNode);
