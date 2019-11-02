#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listdef.h"

void
* newMap()
{
    Map *m = (Map *) malloc(sizeof(Map));

    if(m != NULL)
    {
        m->cidP = NULL;
        m->c = m->v = 0;
        return m;
    }
    
    else
    {
        free(m);
        return NULL;
    }
}

void
removeMapa(void *c)
{
	Map *x = (Map *) c;
	Cidade *aux = x->cidP;

	if(x!=NULL)
	{
		while(x->cidP!=NULL)
		{
			x->cidP = aux->next;
			free(aux);
		}
	}
	
	x->c = x->v = 0;
	free(x->cidP);
	free(x->cidU);
	free(x);
}
 int
newCity (char *a, int p, int x, int y, void *l)
{
	Map *mp = (Map *) l; //recebe endereco de mapa
	Cidade *Cid = (Cidade *)malloc(sizeof(Cidade)); //cria cidade
	Cidade *aux = NULL; //auxiliar
	Cidade *aux2 = NULL; //auxiliar
	int j = 0;
	
	if(mp == NULL)
		return 100; //mapa nao foi criado
	if(Cid == NULL)
	{
		free(Cid);
		return 101;//cidade nao foi criadaa
	}
	else
	{	
		strcpy(Cid->nome, a);
		Cid->x = x;
		Cid->y = y;
		Cid->next = NULL;
		printf("x:%d y:%d nome:%s", Cid->x, Cid->y, Cid->nome);
	}

	
	if(mp->c == 0) //lista vazia
	{
		mp->cidP = Cid;
		mp->cidU = Cid;
		mp->c++;
		return 0;
	}
	
	if(p > mp->c) //se p > c, insere na cauda.
	{
		Cid->next = NULL;
		aux = mp->cidU;
		aux->next = Cid;
		mp->cidU = Cid;
		mp->c++;
		return 0;
	}
	else // insere em qualquer posicao < n.
	{
		aux = mp->cidP;
		
		for(j = 1; j < p; j++)
		{
			if(j == p-1)
				break;
			aux = aux->next;
		}
		
		Cid->next = aux->next;
		aux->next = Cid;
		mp->c++;
		return 0;
	}

}
