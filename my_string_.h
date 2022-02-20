




#include <stdio.h>


/*======================== Tipos e Defnições =============================*/

    typedef int BOLL;
    #define TRUE  1
    #define FALSE 0 


/*===========================   Strings     ============================*/
    
    
    /*
        Le até encontrar um: '\ n','\ 0', '\ r' ou EOF
        Aloca dinamicamente. Não esqueça do free
        @param stream 
    */
    char *readline(FILE *stream);

    /* 
        Le uma palavra; para ao encontrar um: '\ n', '\ 0', 'espaço' ou EOF 
        @param stream arquivo de onde será lido  
    */
    char *readword(FILE *stream);

    /*
        Copia uma  string para outra
        @param strDes string destino que será sobreposta
        @param str string que que será copiada
    */
    char *copyStr(char *strDes, char *str);


    /*
        Compara duas strings e verifica a ordem alfabetica delas 
        Retorna: 
        1 se string 1 vem antes
        2 se string 2 vem antes
        0 se strings iguais
        -1 se houver erro na comparação 
    */
    int compareStr(char *string1 ,char *string2);

        
    //Formata o fim de uma linha para liberar a leitura
    char format(FILE *stream);

/*===========================   Matrizes     ============================*/

    //Le e aloca dinamicamente uma matriz de caracteres
    //Retorna por parametro as linhas, colunas e a matriz.
    char **ReadMatChar(FILE *stream, int *linhas, int *colunas,char **matriz);


    //Printa uma matriz de caracteres em um determinado arquivo
    void PrintMatChar(FILE *stream, int n_linhas, int  n_colunas,  char **matriz);
