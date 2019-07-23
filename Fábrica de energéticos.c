#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXNOME 500
#define MAXVET 500

typedef struct {
	char nome[MAXNOME];
	int pedido;
	double ICMS;
	double IPI;
	double PIS;
	double COFINS;
	double impostos;
	double total;
}EMPRESA;
EMPRESA ficha[MAXVET];

int cadastro(EMPRESA *ficha,int qtd){
	int i;
	for(i=0;i<qtd;i++){
		printf("Digite o nome da empresa:\n");
		fflush(stdin);
		fgets(ficha[i].nome,MAXNOME,stdin);
		printf("Digite o tamanho do pedido:\n");
		scanf("%d",&ficha[i].pedido);
	}
}

int calculaimposto(EMPRESA *ficha,int qtd,double uni){
	int i,pedido;
	double imposto=0.0,total=0.0;
	for(i=0;i<qtd;i++){
		pedido=ficha[i].pedido;
		total=uni*pedido;
		imposto=((uni*1.18)+uni)*pedido;
		total=total+imposto;
		ficha[i].impostos=ficha[i].impostos+imposto;
		ficha[i].ICMS=imposto;
		imposto=((uni*0.04)+uni)*pedido;
		total=total+imposto;
		ficha[i].impostos=ficha[i].impostos+imposto;
		ficha[i].IPI=imposto;
		imposto=((uni*0.0186)+uni)*pedido;
		total=total+imposto;
		ficha[i].impostos=ficha[i].impostos+imposto;
		ficha[i].PIS=imposto;
		imposto=((uni*0.0854)+uni)*pedido;
		total=total+imposto;
		ficha[i].impostos=ficha[i].impostos+imposto;
		ficha[i].COFINS=imposto;
		ficha[i].total=total;
	}
}

int imprimecadastro(EMPRESA *ficha, int qtd){
	int i;
	for(i=0;i<qtd;i++){
		printf("\nCliente: %s",ficha[i].nome);
		printf("ICMS:R$%lf \t",ficha[i].ICMS);
		printf("IPI:R$%lf \t",ficha[i].IPI);
		printf("PIS:R$%lf \t",ficha[i].PIS);
		printf("COFINS:R$%lf \t",ficha[i].COFINS);
		printf("TOTAL:R$%lf", ficha[i].total);
	}
}

int totalimpostos(EMPRESA *ficha,int qtd){
	double impostos=0.0;
	int i;
	for(i=0;i<qtd;i++){
		impostos=impostos+ficha[i].impostos;
	}
	return(impostos);
}
int totalmercadoria(EMPRESA *ficha,int qtd,double uni){
	double mercadoria=0.0;
	int i;
	for(i=0;i<qtd;i++){
		mercadoria=mercadoria+(uni*ficha[i].pedido);
	}
	return(mercadoria);
}

int calculadesconto(EMPRESA *ficha,int qtd,double uni){
	int i,pedido;
	double desconto;
	for(i=0;i<qtd;i++){
		pedido=ficha[i].pedido;
		if(pedido>=100 && pedido<=499){
			desconto=((uni*0.05)-uni)*pedido;
			ficha[i].total=ficha[i].total-desconto;
		}
		if(pedido>=500){
			desconto=((uni*1.1)-uni)*pedido;
			ficha[i].total=ficha[i].total-desconto;
		}
	}
}

int imprimetotais(double totimp,double totmerc, double totger){
	printf("\n \nTotal impostos:R$%lf\n",totimp);
	printf("Total mercadorias:R$%lf\n",totmerc);
	printf("Total geral:R$%lf\n",totger);
	}

int main(){
	int qtd;
	double unidade=4.50	,totimp=0.0,totmerc=0.0,totalgeral=0.0;
	printf("Quantos pedidos deseja cadastrar?\n");
	scanf("%d",&qtd);
	cadastro(ficha,qtd);
	calculaimposto(ficha,qtd,unidade);
	calculadesconto(ficha,qtd,unidade);
	imprimecadastro(ficha,qtd);
	totimp=totalimpostos(ficha,qtd);
	totmerc=totalmercadoria(ficha,qtd,unidade);
	totalgeral=totimp+totmerc;
	imprimetotais(totimp,totmerc,totalgeral);
	getch();
}
