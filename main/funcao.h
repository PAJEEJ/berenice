#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED

struct cadastro{
	int codigo;
	char produto[50];
	float valor;
	int quantidade;
};

void cadastrar_estoque(struct cadastro estoque[], int n);

void visualizar_estoque(struct cadastro estoque[], int n);

#endif // FUNCOES_H_INCLUDED