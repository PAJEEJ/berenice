#include <stdio.h>
#include "funcao.h"

void cadastrar_estoque(struct cadastro estoque[], int n)
{
     int codigo, quantidade;
                printf("Codigo\t   Produto\t\tEstoque\n\n");
                printf("1\t   Pao de forma\t\t%i\n", estoque[0].quantidade);
                printf("2\t   Pao de centeio\t%i\n", estoque[1].quantidade);
                printf("3\t   Broa de milho\t%i\n", estoque[2].quantidade);
                printf("4\t   Sonho\t\t%i\n", estoque[3].quantidade);
                printf("5\t   Tubaina\t\t%i\n", estoque[4].quantidade);
                printf("\nDigite o codigo do produto que deseja cadastrar: ");
                scanf("%d", &codigo);

                if (codigo < 1 || codigo > 5) {
                    printf("\nCodigo invalido\n");
                     return;
                }


                printf("Quantidade que deseja cadastrar: ");
                scanf("%d", &quantidade);
                if (quantidade <= 0){
                     printf("\nQuantidade invalida\n");
                     return;
                }

                estoque[codigo-1].codigo = codigo;
                estoque[codigo-1].quantidade += quantidade;

                printf("Produto cadastrado!\n");
                return;
}
void visualizar_estoque(struct cadastro estoque[], int n)
{
     printf("Codigo\t   Produto\t\t Valor(unidade)\t Estoque\n\n");
                 printf("1\t   Pao de forma\t\t R$7.50\t\t   %i\n", estoque[0].quantidade);
                 printf("2\t   Pao de centeio\t R$8.69\t\t   %i\n", estoque[1].quantidade);
                 printf("3\t   Broa de milho\t R$5.00\t\t   %i\n", estoque[2].quantidade);
                 printf("4\t   Sonho\t\t R$4.50\t\t   %i\n", estoque[3].quantidade);
                 printf("5\t   Tubaina\t\t R$3.25\t\t   %i\n", estoque[4].quantidade);
}

