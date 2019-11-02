#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>
#define MAXMAP 10

/*Prototipos*/
int menu();

int
main(int argc, char const *argv[])
{
    int m; // recebera opcao do menu
    int i = 0;
    char *n[50];
    void *l[MAXMAP];
    
    while(1)
    {
        m = menu();
        if(m == 10)
        {
            l[i] = newMap();
            printf("Mapa criado, %p\n", l[i]);
            if(l == NULL)
                {
                    printf("Erro na criacao do mapa\n");
                    exit(0);
                }
        }
        else if(m == 11)
        {    
            if(l[0] != NULL)
            {
                removeMapa(l[0]);
                printf("mapa %p removido\n", l[0]);
            }
        }
        else if(m == 12)
        {
            printf("Digite o nome da cidade: \n");
            scanf(" %s", &n);
            newCity(n, 2, 2, 5, l[0]);
        }
        else
            printf("opcao invalida\n");
        printf("\n");
        i++;
    }
    
    return 0;
}

int
menu()
{
    char c; //recebe a opcao desejada pelo usuario
    printf("Digite a opcao desejada: \na: Criar Mapa.\nb: Remover Mapa.\nc: Inserir Cidade\nx: Exit.\n");
    setbuf(stdin, NULL);
    scanf(" %c", &c);
    switch(c)
    {
        case 'a':
            return 10;break;
        case 'b':
            return 11;break;
        case 'c':
            return 12;break;
        case 'x':
            exit(0);
    
        default:
            return 50;break;
    }
}