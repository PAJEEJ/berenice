# berenice
codigo berenice

#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"


struct cadastro estoque[5] = {
   {1, "Pao de forma", 7.50, 0},
   {2, "Pao de centeio", 8.69, 0},
   {3, "Broa de milho", 5.00, 0},
   {4, "Sonho", 4.50, 0},
   {5, "Tubaina", 3.25, 0}
};

void cadastrar_estoque();


int main()
{
    int quantidade, item, pagamento, parcelas, i;//Declaracao de variaveis inteiras.
    float valor, total, totalpagamento, valorcliente, troco, falta, vparcela;//Declaracao de variaveis reais.
    printf("Valores dos produtos\n");//Mostrar no display.


	int loja;
	do{
        printf("\n   MENU PRINCIPAL\n");
        printf("\n1\t Cadastrar estoque\n2\t Visualizar estoque \n3\t Efetuar venda\n4\t Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%i", &loja);

        switch(loja){
            case 1: {
                cadastrar_estoque(estoque, 5);
            break;
            }
            case 2:{
                 visualizar_estoque(estoque, 5);
            break;

            }




    case 3:
        do{
             printf("Codigo:\t   Produto:\t         Valor: \n\n");
    printf("1\t   Pao de forma\t\t R$7.50\n2\t   Pao de centeio\t R$8.59\n3\t   Broa de milho\t R$5.00\n4\t   Sonho\t\t R$4.50\n5\t   Tubaina\t\t R$3.25\n");    //mostrar no display os codigos e valores dos produtos
    printf("\nDigite o codigo do produto: ");//Mostrar no display para digitar o codigo do produto.
    scanf("%i", &item); //Ler a variavel item, %i ou %d para numeros inteiros.
    getchar();//Ler um caracter do teclado.
    if ((item >= 1) && (item <= 5)){//Caso o item seja maior ou igual a 1 e caso o item seja menor ou igual a 5.
    printf("\nDigite a quantidade: ");//Mostrar no display para digitar a quantidade.
    scanf("%i", &quantidade);//Ler a variavel quantidade.
    getchar();//Ler um caracter do teclado.
    if (quantidade <= 0) {//Caso a quantidade seja menor ou igual a zero.
        printf("\nQuantidade invalida\n");//Mostrar no display quantidade invalida.
    }else//Caso a quantidade seja válida.
     {
    switch(item){//Switch usado para testes de condições, acompanhado da variável.
        case 1://"Casos" acompanhados de suas variaveis e valores.
            valor = 7.50;
            if (quantidade <= estoque[0].quantidade) { //Verifica se o estoque esta disponivel
                estoque[0].quantidade -= quantidade; //Atualiza o estoque
            } else {
                printf("\nEstoque indisponivel\n");
                break;
            }
            break;//Break encerra a execucao da instrucao, pulando para proxima instrucao.
        case 2:
            valor = 8.69;
            if (quantidade <= estoque[1].quantidade) {
                estoque[1].quantidade -= quantidade;
            } else {
                printf("\nEstoque indisponivel\n");
                break;
            }
            break;
        case 3:
            valor = 5.00;
            if (quantidade <= estoque[2].quantidade) {
                estoque[2].quantidade -= quantidade;
            } else {
                printf("\nEstoque indisponivel\n");
                break;
            }
            break;
        case 4:
            valor = 4.50;
            if (quantidade <= estoque[3].quantidade) {
                estoque[3].quantidade -= quantidade;
            } else {
                printf("\nEstoque indisponivel\n");
                break;
            }
            break;
        case 5:
            valor = 3.25;
            if (quantidade <= estoque[4].quantidade) {
                estoque[4].quantidade -= quantidade;
            } else {
                printf("\nEstoque indisponivel\n");
                break;
            }
            break;
        default://Caso nenhuma das alternativas seja possivel/válida.
            printf("Opcao nao encontrada\n");//Mostrar no display opção nao encontrada.
            break;//Encerra a execução da instruçao e pula para próxima instrução.
    }
    total = valor * quantidade;//Variaveis total = valor * quantidade, operacao matematica para calculo do valor total (sem desconto).
    printf("\nValor total: R$%.2f\n", total); //%.2f arredonda o numero na segunda casa decimal.

    printf("\nFormas de pagamento\n");
    printf("\n1\t A vista");
    printf("\n2\t A prazo\n");
    printf("\nSelecione a forma de pagamento: ");
    scanf("%i", &pagamento);
    getchar();
    switch(pagamento){
        case 1:{ //Se o valor de compra do cliente for entre R$1 e maior/igual a R$50, terá 5% de desconto.
            if((total <= 50.00) && (total > 0)){
                totalpagamento = total * 0.95;
        }else
        {
            if((total > 50.00) && (total < 100.00)){ //Caso o valor de compra do cliente for maior que R$50 e menor que 100, terá 10% de desconto.
               totalpagamento = total * 0.90;
            }else
            {
              if(total >= 100.00){ //Uma vez que o cliente compre R$100 ou mais em produtos, terá 18% de desconto.
                totalpagamento = total * 0.82;
              }
            }
        }
        }
            printf("\nValor da compra: R$%.2f\n", totalpagamento); //%.2f arredonda para duas casas decimais após a vírgula.
            printf("\nDigite o valor recebido do cliente: ");
            scanf("%f", &valorcliente);
            getchar();
            if(valorcliente > totalpagamento){
                troco = valorcliente - totalpagamento;
                printf("\n\nTroco: R$%.2f\n", troco);
            }else
            {
                troco = valorcliente - totalpagamento;
                falta = troco * -1; //Se o valor recebido do cliente for menor que o valor do(s) produto(s), o cliente não pagou dinheiro suficiente.
                printf("\nFaltam: R$%.2f\n", falta);
            }
        break;
        case 2:{
            printf("\nParcelamento em ate 12 vezes\n");
            printf("\nDigite o numero de parcelas: ");
            scanf("%i", &parcelas);
            getchar();
            if((parcelas > 1) && (parcelas <= 3)){ //Para parcelas entre 1 a 3, deverá ser acrescentado 5% no valor final.
                totalpagamento = total * 1.05;
                vparcela = totalpagamento / parcelas;
                printf("\n\nValor das parcelas: %ix R$%.2f\n", parcelas, vparcela);//"%i x %f" é a quantidade de parcelas pelo valor de uma única parcela.
                printf("\nValor Final: R$%.2f\n", totalpagamento);
            }else
            {
                if((parcelas > 3) && (parcelas <= 12)){ //Para parcelas maiores que 3 e menores/iguais a 12, téra acrescimo de 8% no valor final.
                totalpagamento = total * 1.08;
                vparcela = totalpagamento / parcelas;
                printf("\nValor das parcelas: %i x R$%.2f\n", parcelas, vparcela);//"%i x R$%.2f" é a quantidade de parcelas pelo valor de uma única parcela, com arredondamento de duas casas decimais.
                printf("\nValor Final: R$%.2f\n", totalpagamento);
                }else
                {printf("\nNumero de parcelas invalido\n"); //Caso o número de parcelas informado for diferente do intervalo (1<parcelas<=), o programa irá imprimir: "Numero de parcelas invalido".
                }
            }

        }
        break;
        default:
            printf("\nPagamento invalido\n"); //Se o usuário informar um numero diferente de 1 e 2 (à vista e à prazo, respectivamente), será impresso na tela: "Pagamento invalido"
    }
     }

    }else
    {
         printf("\nCodigo invalido\n"); //Se o usuário informar um numero diferente de 1, 2, 3, 4 e 5 (referente aos itens) será impresso na tela: "codigo invalido".

    }
    printf("\nSelecione uma opcao\n");
    printf("1\tVoltar ao menu principal\n2\tVender outro produto\n");
    printf("Digite a opcao desejada: ");
    scanf("%i", &i);
        }while(i != 1);

        }


	}while(loja != 4);

    return 0;
}
