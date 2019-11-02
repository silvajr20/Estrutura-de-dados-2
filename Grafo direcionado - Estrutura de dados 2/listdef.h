/* */ 
// struct mapa representa um grafo
struct list
{
    int c; //quantidade de cidades(vertices)
    int v; //quantidade de vizinhos(arestas)
    void *cidP; //ponteiro para primeira cidade
    void *cidU; //ponteiro para ultima cidade
}; typedef struct list Map; //ponteiro do mapa

/* Os nodos representão as cidades no mapa */ 
struct node
{
    char nome[50]; //nome da cidade
    int x; //coordenada x
    int y; //coordenada y
    struct node *next; //proxima cidade
}; typedef struct node Cidade; //ponteiro da cidade