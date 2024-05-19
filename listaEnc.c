#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//estrutura
struct no{
    int valor;
    struct no *prox;
};
typedef struct no No;

typedef struct{
    No *inicio;
}Lista;

//metodos da lista.

void PrintLista(Lista *l)
{
    No *aux;
    aux=l->inicio;
    if( aux == NULL ){
        printf("Lista vazia...\n");
    }
    else
    {
        printf("\nValor: ");
        while( aux !=NULL){
            printf("%d -> ",aux->valor);
            aux=aux->prox;
        }
        printf("\n");
    }
}

void BuscarNo(Lista *l)
{
    No *aux;
    aux=l->inicio;
    int valorBuscado,encontrou=0;
    printf("Digite o valor buscado: ");
    scanf("%d",&valorBuscado);
    printf("\n");
    if(aux==NULL)
    {
        printf("Lista vazia - Valor não encontrado.\n");
    }
    else
    {
        while(aux!=NULL && encontrou!=1)
        {
            if(valorBuscado==aux->valor){
                printf("Valor encontrado!\n");
                encontrou=1;
            }
            else
            {
                aux=aux->prox;
            }
        }
        if(encontrou==0)
        {
            printf("Valor não encontrado na lista...\n");
        }
    }
}

void AddLista(Lista *l){
    No *aux, *novoNo;
    aux=l->inicio;
    int valor;
    printf("Digite o novo valor a ser inserido: ");
    scanf("%d",&valor);

    novoNo=malloc(sizeof(No));
    novoNo->valor=valor;
    novoNo->prox=NULL;

    if(aux==NULL)
    { //Lista está vazia
        l->inicio=novoNo;
    }
    else //Lista não esta vazia.
    {
        while(aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        aux->prox=novoNo;
    }

}

void DelNo(Lista *l)
{
    No *aux, *anterior;
    aux= anterior = l->inicio;

    if(aux==NULL)
    {
        printf("Lista Vazia...\n");
    }
    else
    {
        int valorRemover,encontrado=0;
        printf("Digite o valor a ser removido:");
        scanf("%d",&valorRemover);

        while(aux!=NULL && encontrado!=1)
        {
            if(valorRemover==aux->valor)
            {
                if(aux == l->inicio)//Esta na primeira posição.
                {
                    l->inicio=aux->prox;
                    free(aux);
                    encontrado=1;
                }
                else
                {
                    anterior->prox=aux->prox;
                    free(aux);
                    encontrado=1;
                }
            }
            else
            {
                anterior= aux;
                aux = aux->prox;
            }
        }
        if(encontrado==0)
        {
            printf("Valor não encontrado na lista...\n");
        }
    }
}



//main
void main()
{
    Lista l;

    AddLista(&l);
    AddLista(&l);
    AddLista(&l);
    AddLista(&l);

    PrintLista(&l);
    DelNo(&l);
    PrintLista(&l);

}
