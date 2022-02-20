/************************************************************
*            Eric Rodrigues das Chagas                      *
*    [ICMC - Bacharelado em Ciências da Computação - 2021]  *
*    NºUSP: 12623971                                        *
*||----------------------Contatos-------------------------||*
*            Telegram [ @EricRC_123 ]                       *
*            Email  [ eric.r.c@usp.br ]                     *
*************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "my_string_.h"


/*
    Copia uma  string para outra
    @param strDes string destino que será sobreposta
    @param str string que que será copiada
*/
char *copyStr(char *strDes, char *str) {
    if(str == NULL){
        printf("Error em copyStr: string não existe\n");
        return NULL;
    }
    if(strDes == NULL){
        strDes = malloc(sizeof(char));
        strDes[0] = '\0';
    }
    
    
    //printf("ENTROU: copyStr\n");

    char verification = 'X';
    int i = 0;

    while (verification != '\0'){
        //printf("Char D = (%c) - Char C = (%c)\n",strDes[i],str[i]);
        
        //Caso: Fim do strDes
        if(strDes[i] == '\0'){
            //printf("Fim do strDes\n");
            while (verification != '\0'){
                //printf("Char D = (%c) - Char C = (%c)\n",strDes[i],str[i]);

                strDes = realloc(strDes, (i+1)*sizeof(char));

                strDes[i] = str[i];

                verification = str[i];
                i++;    
            }
            break;
        } 
        //Atribuição e iteração
        strDes[i] = str[i];
        verification = str[i];
        i++;
    }

  return strDes;
}

/*
    Le até encontrar um: '\ n','\ 0', '\ r' ou EOF
    Aloca dinamicamente. Não esqueça do free
    @param stream 
*/
char *readline(FILE *stream) {
    
    char *string = NULL;
    string = malloc(sizeof(char));

    int i=0;
    char caractere='X';
    while( 
           (caractere=getc(stream)) != '\n' && 
            caractere != EOF  && 
            caractere != '\0' &&
            caractere != '\r'
        )
    {
        
        string=realloc(string, (i+1)*sizeof(char));

        string[i]=caractere;

        i++;
    }

    string[i]='\0';

    return string;
}

/* 
    Le uma palavra; para ao encontrar um: '\ n', '\ 0', 'espaço' ou EOF 
    @param stream arquivo de onde será lido  
*/
char *readword(FILE *stream) {
    //printf("ENTROU: ReadWord\n");

    char *string = NULL;
    string = malloc(sizeof(char));

    int i=0;
    char caractere='X';
    while( (caractere=getc(stream)) >= 97 &&
            caractere <= 122 
        )
    {
        string=realloc(string, (i+1)*sizeof(char));

        string[i]=caractere;
        //printf("Char lido: (%c) - Pos (%d)\n",caractere,i);

        i++;
    }
    string=realloc(string, (i+1)*sizeof(char));
    //printf("Ultimo char lido: (%c)\n\n",caractere); 

    string[i]='\0';
    //printf("Palavra lida (%s)\n",string); 
    
    //if(caractere == '\?') printf("Ultimo char lido: (Barra ?)\n\n");
    

    return string;
}


/*
    Compara duas strings e verifica a ordem alfabetica delas 
    1 se string 1 vem antes
    2 se string 2 vem antes
    0 se strings iguais
    -1 se houver erro na comparação 
*/
int compareStr(char *string1 ,char *string2) {
    //printf("ENTROU: comparar strings\n");
    
    int i = 0;
    char caractere1 = string1[i]; 
    char caractere2 = string2[i];

    while (caractere1 == caractere2)
    {

        caractere1=string1[i];
        caractere2=string2[i];


        if(caractere1 == '\0'){
            if(caractere2 == '\0') return 0;
            
            caractere1 = string1[i-1];

            int comp1 = caractere1;
            int comp2 = caractere2;

            if(comp1 < comp2) return 1;
            else if(comp2 < comp1) return 2;
            else return -1;

        }
        
        if(caractere2 == '\0'){
            if(caractere1 == '\0') return 0;
            caractere2 = string2[i-1];
 
            int comp1 = caractere1;
            int comp2 = caractere2;

            if(comp1 < comp2) return 1;
            else if(comp2 < comp1) return 2;
            else return -1;
            
        }
        i++;
    }
    
    int comp1 = caractere1;
    int comp2 = caractere2;

    if(comp1 < comp2) return 1;
    else if(comp2 < comp1) return 2;
    else return -1;

}

//Formata o fim de uma linha para liberar a leitura
char format(FILE *stream) {
    //printf("ENTROU: format\n");
    char c = '\n';
    int controle = 0;
    
    while ( c < 32 && c != EOF && controle < 4)
    {
        c = getc(stream);
        controle++;

        //printf("c: num(%i) char(%c)\n",c,c);
    }
    ungetc(c,stream);

    return c;
}


//Le e aloca dinamicamente uma matriz de caracteres
//Retorna por parametro as linhas, colunas e a matriz.
char **ReadMatChar(FILE *stream, int *linhas, int *colunas,char **matriz) {
    char caractere='X';
    int i=0, j=0;

    //Alocação inicial
    matriz=malloc(sizeof(char*));
    matriz[i]=malloc(sizeof(char));

    while(caractere != EOF){

        matriz=realloc(matriz, (i+1)*sizeof(char*));

        while( (caractere = getc(stream)) != '\n' && caractere != EOF){

            matriz[i]=realloc(matriz[i], (j+1)*sizeof(char) + 1);
            matriz[i][j] = caractere;
            j++; 
        }
        
        //Retorno da quantidade de colunas
        if(i==0) *colunas = (j-1); 

        i++; j=0;
        if(caractere=='\n') caractere='X';    
    }
    
    //Retorno da quantidade de linhas
    *linhas  = (i-1);

    return matriz;
}



//Printa uma matriz de caracteres em um determinado arquivo
void PrintMatChar(FILE *stream, int n_linhas, int  n_colunas,  char **matriz) {
    
    for(int i=0; i <= n_linhas; i++){
        for(int j=0; j <= n_colunas; j++){
            
            fprintf(stream,"%c", matriz[i][j]);
        }
        fprintf(stream,"\n");
    }

}



