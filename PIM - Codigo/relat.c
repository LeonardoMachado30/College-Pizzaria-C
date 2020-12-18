/* 	
	TRABALHO PIM
	(PROJETO INTER-MULTIDISCIPLINAR)
	
	CRIADO POR: FLÁVIO LEOANARDO
	SOFTWARE: DEVC++
	SISTEMA OPERACIONAL: WINDOWS 10 PRO
	TESTADO: SIM
	TERMINADO: NÃO
	INFORMAÇÕES:
	
	CRIAR UM PROGRAMA PARA UMA PIZZARIA COM BAIXO CAPITAl
	CONSISTEM EM 3 UNIDADES, CADA UNIDADE POSSUI UMA COMPUTADOR
	CADA COMPUTADOR ESTA CONECTADO NA INTERNET E CONECTANDO ENTRE SI
	UM DESSES COMPUTADORES SERA O SERVIDOR CENTRAL PARA ARMAZENAR DADOS NO FINAL DO DIA;
	REQUISITOS DO PROGRAMA:
	
	LOGIN;  				\OK
	CADASTRO DE BEBIDAS;  	\OK
	SABORES;   				\OK
	PIZZAIOLOS; 			\OK
	PEDIDOS; 				\OK
	CLIENTES;   			\OK
	RECLA\ELOGIOS CLIENTES; \OK
	CONTROLE DO ESTOQUE;	\OK			
	PROMOCOES;	
	BEBIDAS;
	COMPLEMENTOS;
	PREMIUM;
	
OBS: O CODIGO ESTA TODO COMENTADO, AS FUNÇÕES ESTAO CATALOGADAS COM NUMEROS, 
ESSES NUMEROS DIRA ONDE ESTA LOCALIZADA CADA CHAMADA DENTRO DO CÓDIGO;

OBS2: EXISTE UM LOGIN PADRÃO, PARA QUE NÃO PRECISE CADASTRAR
LOGIN: adm
SENHA: adm

DICA: PARA MELHOR VIZUALIZAÇÃO DO CÓDIGO RECOMENDA-SE QUE 
MINIMIZE AS FUNCOES(LADO ESQUEDO '+')CASO ESTEJA USANDO O DEVC++ OU SEMELHANTES;
*/
// CODIGO FONTE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
// Denifir o tamanho dos vetores
#define MAX_ATENDENTES 5
#define MAX_CLIENTES 5
#define MAX_PIZZAS 20
#define MAX_BEBIDAS 20
#define MAX_PIZZAOLOS 5
// Definir as cores
#define ANSI_COLOR_RED     	"\033[31m"// Vermelho
#define ANSI_COLOR_C_GREEN 	"\033[32m" // Verde
#define C_YELLOW			"\033[33m"// Amarelo
#define ANSI_COLOR_RESET   	"\x1b[0m"// Reseta a cor
// Declarando as funcoes
// NOTE: CADA NUMERO REPRESENTA UMA FUNCAO DO CODIGO
void f_Def();// Apresentar o Default dos menus
// 1.
struct s_atendente;
struct s_cliente;
struct s_pizza;
struct s_bebida;
struct s_pizzaiolo;
// 1.3
void cadastraAtendente(struct s_atendente atendente);
void cadastraCliente(struct s_cliente cliente);
void cadastraPizza(struct s_pizza pizza);
void cadastraBebida(struct s_bebida bebida);
void cadastraPizzaiolo(struct s_pizzaiolo pizzaiolo);
// 2.
void main();
// 3
int logar();
// 4.
void Menu_selecao();
// 5.
void Menu_Cadastro();
// 6.
void validaCardapio();
// 6.1
void validaPizzas();
// 7.
int apresentaPizza();
// 8.
int menu_atendente();
int menu_clientes();
int menu_pizzas();
int menu_bebidas();
int menu_pizzaiolo();
// 9.
int menu();
// 10.
struct s_atendente leDados_Atendente();
struct s_cliente leDados();
struct s_pizza leDados_pizza();
struct s_bebida leDados_bebida();
struct s_pizzaiolo leDados_pizzaiolo();
// 11.
void imprimeAtendente();
void imprimeClientes();
void imprimePizzas();
void imprimeBebidas();
void imprimePizzaiolo();
// 12.
void removerAtendente(int posicaoA);
void remover(int posicao);
void removerPizza(int posicao2);
void removerBebida(int posicao3);
void removerPizzaiolo(int posicao4);
// 13.
void pesquisa();
// 14. 
void validaReclamacoes();
// 15.
// NOTE: todas as funcoes de estoque nao estao declaradas
// As funcoes de estoque esta no final do codigo
// Somente a funcao do menu de estoque esta declarada
void estoque();
// A PARTIR DAQUI COMEÇA O CODIGO
//Variavel do Menu Interativo(gotoxy)
int a,b,L,L2;
//Funcao para Interação Linha e coluna
void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}	
// 1. Declarar a estrutura onde sera armazenado cadastros
struct s_atendente
{
    char nome_A[50];
    char sexo_A;
    char endereco_A[100];
    char senha[30];
    int cpf_A[16];
    int idade_A;
    int telefone_A;
}dados;
struct s_cliente
{
    char nome[50];
    char rg[15];
    char cpf[15];
    char sexo;
    int idade;
};
struct s_pizza
{
	char pizza[30];
	char descricao[100];
	char pedido[5];
	float preco;
};
struct s_bebida
{
	char bebidas[30];
	char descricao_b[100];// O '_b' significa Bebida
	float preco_b;
};
struct s_pizzaiolo
{
    char nome_P[50];// O '_P' significa pizzaiolo
    char cpf_P[15];
    char sexo_P;
    int idade_P;
    int telefone;
};
// 1.2 Declarar o vetor de elementos
// elementos dentro de [] estao em DEFINE acima
struct s_atendente atendentes[MAX_ATENDENTES];
struct s_cliente clientes[MAX_CLIENTES];
struct s_pizza pizzas[MAX_PIZZAS];
struct s_bebida bebidas[MAX_BEBIDAS];
struct s_pizzaiolo pizzaiolos[MAX_PIZZAOLOS];
int n_atendentes = 0;
int n_clientes = 0;
int n_pizzas = 0;
int n_bebidas = 0;
int n_pizzaiolos = 0;
int i;// iniciador de loops
// 1.3 Função para cadastrar
//cliente/pizza/pizzaiolo no vetor de elementos (1.2)
// Veja que não tem retorno, apenas armazena no vetor.
void cadastraAtendente(struct s_atendente atendente)
{
    atendentes[n_atendentes] = atendente;// recebe a Struct declarada na funcao
	n_atendentes++;// incrementa o numero de elementos
}
void cadastraCliente(struct s_cliente cliente)
{
    clientes[n_clientes] = cliente;
	n_clientes++;
}
void cadastraPizza(struct s_pizza pizza)
{
    pizzas[n_pizzas] = pizza;
	n_pizzas++;
}
void cadastraBebida(struct s_bebida bebida)
{
    bebidas[n_bebidas] = bebida;
	n_bebidas++;
}
void cadastraPizzaiolo(struct s_pizzaiolo pizzaiolo)
{
    pizzaiolos[n_pizzaiolos] = pizzaiolo;
	n_pizzaiolos++;
}
//funcao para apresentacao BEM VINDO
void logomarca()
{
	system("color 0f");
	gotoxy(36,1);printf ("=========================================");
	gotoxy(36,2);printf ("======          BEM-VINDOS         ======");
	gotoxy(36,3);printf ("======              A              ======");
	gotoxy(36,4);printf ("======       PIZZARIA MEMES        ======");
	gotoxy(36,5);printf ("=========================================");
}
//funcao para todos os menus com nome da pizzaria
void logomenus()
{
	system("color 0f");
	gotoxy(36,1);printf("===========================================");
	gotoxy(36,2);printf("=======       PIZZARIA MEMES        =======");
	gotoxy(36,3);printf("===========================================");
}

void copyrigt()
{
	system("color 0f");
	gotoxy(36,20);printf("Copyrigt @ Direitos reservados a PIZZARIA MEMES .LTDA");
}
void f_Def()// Funcao Imprime "default" dos Switch case
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf(ANSI_COLOR_RED "\n\t\t");// inserindo a cor Vermelha 
	printf("=========================================================");
	printf("\n\t\t");
	printf("|\tOPCAO DE MENU INCORRETA, TENTE NOVAMENTE\t|");
	printf("\n\t\t");
	printf("=========================================================\n");
	printf("\n\t\t" ANSI_COLOR_RESET); // Resetando para a Cor padrao
	system("pause");
}

int FunGotoxy(){
	int opcao;
    opcao=0;
    L=9;
	L2=2;
	b=2;
	do{
            gotoxy(36,L);
            printf("-->");
            gotoxy(74,L);
            printf("<--");
            gotoxy(0,0);
            if(kbhit){
				a=getch();
			}
            if(a == 80 && b < 8){/*seta p/baixo*/
				L2=L;L++;b++;
			}
            if(a == 72 && b > 2){/*seta p/cima */
				L2=L;L--;b--;
			}
            if(L!=L2){
				gotoxy(36,L2);
				printf("    ");
				gotoxy(74,L2);
				printf("   ");
				L2=L;
			}
            if(a == 13){
				opcao=b-1;
			}
        }while(opcao == 0);
        return opcao;
}
// 2. FUNCAO PRINCIPAL
// Menus de login e Cadastro
// NOTE: existe um login fixo de "administrador"
void main()
{
	char menu;
	system("mode con:cols=126 lines=30");
	system("title PIZZARIA MEMES");
	int opcao;
	opcao=0;
    L=9;
	L2=2;
	b=2;
    do{
        system("cls");
        system("color 0f");
        copyrigt();
        logomarca();
        gotoxy(40,7);printf("=========ESCOLHA O MENU=========");
		gotoxy(40,9);printf("|LOGIN");
		gotoxy(40,10);printf("|CADASTRAR ATENDENTE");
		gotoxy(40,11);printf("|SAIR");
        do{
            gotoxy(36,L);
            printf("-->");
            gotoxy(74,L);
            printf("<--");
            gotoxy(50,25);
            if(kbhit){
				a=getch();
			}
            if(a == 80 && b < 4){/*seta p/baixo*/
				L2=L;L++;b++;
			}
            if(a == 72 && b > 2){/*seta p/cima */
				L2=L;L--;b--;
			}
            if(L!=L2){
				gotoxy(36,L2);
				printf("   ");
				gotoxy(74,L2);
				printf("   ");
				L2=L;
			}
            if(a == 13){
				opcao=b-1;
			}
        }while(opcao == 0);
		switch(opcao){
			case 1:// Funcao para logar
				logar();
				break;
			case 2:// Funcao Menu dos cadastros
				menu_atendente();
				break;
			case 3:
				printf("\n\n");
				exit(0);
				break; 
				default:// Caso nem um menu seja atendido
					f_Def();
		}
	}while(opcao>3);
}
// 3 LOGAR E CADASTRAR
int logar()
{
	char Logar[30];
	char logAdm[14] = "adm";// Login estatico
	char senha[30];
	char senhaAdm[4] = "adm";// Senha estatica
	int j=0;
	char continua;
	
	do{
		system("cls");
		system("color 0f");
		logomenus();
		copyrigt();
		gotoxy(40,7);printf("=========INFORME SEU LOGIN=========");
		gotoxy(40,9);printf("Login: ");
		gotoxy(47,9);scanf(" %[^\n]s", Logar);
		gotoxy(40,10);printf("Senha: ");
		gotoxy(47,10);scanf(" %[^\n]s", senha);
		
		//Logar como "Administrador"
		if(strcmp(logAdm, Logar) == 0 && strcmp(senhaAdm, senha) == 0){
			printf("\n\t\t\t\t\t");
			printf(ANSI_COLOR_C_GREEN "LOGADO!\n" ANSI_COLOR_RESET);// Caso logado, Inserir Cor Verde, Resetar Cor
			printf("\n\t\t\t\t\t");
			system("pause");
			Menu_selecao();// Caso logado, Entra nas Opcoes principais
		}
		//Logar como Atendente cadastrado
		for(j=0; j<n_atendentes; j++){
			if(strcmp(atendentes[j].nome_A, Logar) == 0 && strcmp(atendentes[j].senha, senha) == 0){
				printf("\n\t\t\t\t\t");
				printf(ANSI_COLOR_C_GREEN "LOGADO!" ANSI_COLOR_RESET);// Caso logado, Inserir Cor Verde, Resetar Cor
				printf("\n\t\t\t\t\t");
				system("pause");
				Menu_selecao();// Caso logado, Entra nas Opcoes principais
			}
		}
		printf("\n\t\t\t\t\t");
		printf(ANSI_COLOR_RED "LOGIN OU SENHA INVALIDOS!\n" ANSI_COLOR_RESET);// Caso não logado, Inserir Cor vermelha, Resetar Cor
		printf(C_YELLOW "\n\t\t\t\t\t");printf("DESEJA CONTINUAR LOGANDO?\n\t\t\t\t\t('s' ou 'n'):" ANSI_COLOR_RESET);
		scanf(" %c", &continua);
		if(continua == 'n' || continua == 'N'){
			main();
		}
	}while(continua=='s' || continua=='S');
}

// 4. Função exibe os menus Principais
// Sem retorno
void Menu_selecao()
{
	setlocale(LC_ALL, "Portuguese");// Codigo entender caracteres especiais
	char confirmar;
    int opcao;
    opcao=0;
    do{
        system("cls");
        system("color 0f");
        logomenus();
        copyrigt();
        gotoxy(38,7);printf("=========ESCOLHA O MENU=========");
		gotoxy(40,9);printf("| CARDAPIO");
		gotoxy(40,10);printf("| CADASTRO");
		gotoxy(40,11);printf("| PESQUISAR");
		gotoxy(40,12);printf("| RECLAMACOES E ELOGIOS");
		gotoxy(40,13);printf("| ESTOQUE");
		gotoxy(40,14);printf("| LOGOUT");
		gotoxy(40,15);printf("| SAIR");
        
        opcao = FunGotoxy();
         
		switch(opcao){
			case 1:// Menu do Cardapio (6.)
			validaCardapio();
				break;
			case 2:// Menu para cadastro (5.)
				Menu_Cadastro();
				break;
			case 3:// Menu para pesquisar(13.)
				pesquisa(); 
				break;
			case 4:// Menu para reclamações (14.)
				validaReclamacoes();
				break;
			case 5:// Menu de estoques (15.)
				estoque();
				break;
			case 6:// Menu de deslogar (2.)
				do{
					system("cls");
					gotoxy(30,5);printf(C_YELLOW "CONFIRMAR LOGOUT?\n");
					gotoxy(30,6);printf("1 - SIM \t2 - NÂO");
					gotoxy(30,7);printf("INFORMAR: "ANSI_COLOR_RESET);
					scanf(" %c", &confirmar);
					switch(confirmar){
						case '1':
							main();
							break;
						case '2':
							Menu_selecao();
							break;
					}
				}while(confirmar != '1' || confirmar != '2');
					break;
			case 7:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				exit(0);
				break;
				default:// Caso nem uma opcao seja atendida
					f_Def();
		}
	}while(opcao>7);
}
// 5. Funcao de menu de cadastros
// Sem retorno
void Menu_Cadastro()
{
	setlocale(LC_ALL, "Portuguese");// Codigo entender caracteres especiais
	int opcao=0;
    do{
        L=9;
		L2=2;
		b=2;
        system("cls");
        system("color 0f");
        logomenus();
        gotoxy(33,7);printf("================MENU DE CADASTRO================");
		gotoxy(40,9);printf("| VOLTAR");
		gotoxy(40,10);printf("| CADASTRAR CLIENTE");
		gotoxy(40,11);printf("| CADASTRAR PIZZA");
		gotoxy(40,12);printf("| CADASTRAR BEBIDA");
		gotoxy(40,13);printf("| CADASTRAR PIZZAIOLO");
        
        do{
            gotoxy(36,L);
            printf("-->");
            gotoxy(74,L);
            printf("<--");
            gotoxy(0,0);
            if(kbhit){
				a=getch();
			}
            if(a == 80 && b < 6){/*seta p/baixo*/
				L2=L;L++;b++;
			}
            if(a == 72 && b > 2){/*seta p/cima */
				L2=L;L--;b--;
			}
            if(L!=L2){
				gotoxy(36,L2);
				printf("   ");
				gotoxy(74,L2);
				printf("   ");
				L2=L;
			}
            if(a == 13){
				opcao=b-1;
			}
        }while(opcao == 0);
        
		switch(opcao){
			case 1:// Retrna a funcao principal (4.)
				Menu_selecao();
				break;
			case 2:// Menu dos clientes (8.)
				menu_clientes();
				break;
			case 3:// Menu das pizzas	(8.)
				menu_pizzas();
				break;
			case 4:// Menu de bebidas	(8.)
				menu_bebidas();
				break;
			case 5:// Menu de pizzaiolos	(8.)
				menu_pizzaiolo();
				break;
				default:// Caso nem uma opcao seja atendida
					f_Def();
		}
	}while(opcao>5);
}
// 6. Funcao exibe categorias de pizzas	/exibir as pizzas
// Note que nao retorna nem um valor
// Sem retorno
void validaCardapio()
{
	setlocale(LC_ALL, "Portuguese");// Codigo entender caracteres especiais
    int opcao;
    do{
        opcao=0;
        L=9;
		L2=2;
		b=2;
        system("cls");
        system("color 0f");
        logomenus();
        gotoxy(40,7);printf("=========ESCOLHA O MENU=========");
		gotoxy(40,9);printf("|\tVOLTAR");
		gotoxy(40,10);printf("|\tPIZZAS");
		gotoxy(40,11);printf("|\tBEBIDAS");
        do{
            gotoxy(36,L);
            printf("-->");
            gotoxy(74,L);
            printf("<--");
            gotoxy(0,0);
            if(kbhit){
				a=getch();
			}
            if(a == 80 && b < 5){/*seta p/baixo*/
				L2=L;L++;b++;
			}
            if(a == 72 && b > 2){/*seta p/cima */
				L2=L;L--;b--;
			}
            if(L!=L2){
				gotoxy(36,L2);
				printf("   ");
				gotoxy(74,L2);
				printf("   ");
				L2=L;
			}
            if(a == 13){
				opcao=b-1;
			}
        }while(opcao == 0);
        
		switch(opcao)
		{
			case 1:// Retrna a funcao principal (4.)
				Menu_selecao();
				break;
				
			case 2:// Entra no menu de pizzas (6.1)
				validaPizzas();
				break;
				
			case 3:// Entra no menu de bebidas
				system("cls");
				printf("\n\t\t\t\t\tNÃO POSSUI BEBIDAS NO MOMENTO\n");
				system("pause");
				validaCardapio();
				break;
				
			case 4:// Entra no menu de complementos
				system("cls");
				printf("\n\t\t\t\t\tNÃO POSSUI COMPELEMENTO NO MOMENTO\n");
				system("pause");
				validaCardapio();
				break;				
			default:// Caso nem uma opcao seja atendida
				f_Def();
		}
	}while(opcao>4);
}
// 6.1
// NAO CONCLUIDO
// Sem retorno
void validaPizzas()
{
	setlocale(LC_ALL, "Portuguese");// Codigo entender caracteres especiais
    int opcao;
    do{
        opcao=0;
        L=9;
		L2=2;
		b=2;
        system("cls");
        system("color 0f");
        logomenus();
        gotoxy(40,7);printf("=========ESCOLHA O MENU=========");
		gotoxy(40,9);printf("|\tVOLTAR");
		gotoxy(40,10);printf("|\tPROMOÇÕES");
		gotoxy(40,11);printf("|\tPIZZAS ESPECIAIS DOS MEMES");
		gotoxy(40,12);printf("|\tPIZZAS PREMIUM");
		gotoxy(40,13);printf("|\tMENU PRINCIPAL");
        do{
            gotoxy(36,L);
            printf("-->");
            gotoxy(74,L);
            printf("<--");
            gotoxy(0,0);
            if(kbhit){
				a=getch();
			}
            if(a == 80 && b < 6){/*seta p/baixo*/
				L2=L;L++;b++;
			}
            if(a == 72 && b > 2){/*seta p/cima */
				L2=L;L--;b--;
			}
            if(L!=L2){
				gotoxy(36,L2);
				printf("   ");
				gotoxy(74,L2);
				printf("   ");
				L2=L;
			}
            if(a == 13){
				opcao=b-1;
			}
        }while(opcao == 0);
        
		switch(opcao)
		{
			case 1:// Voltar a funcao Cardapio (6.)
				validaCardapio();
				break;
			case 2:// Funcao promocoes
				system("cls");
				printf("\n\t\t\t\t\tNÃO POSSUI PROMOÇÃO NO MOMENTO\n");
				system("pause");
				validaPizzas();
				break;
			case 3:// Funcao pizzas tradicionais (7.)
				apresentaPizza();
				break;
			case 4:// Funcao pizza Premium
				system("cls");
				printf("\n\t\t\t\t\tNÃO POSSUI PIZZAS PREMIUM NO MOMENTO\n");
				system("pause");
				validaPizzas();
				break;
			case 5:
				Menu_selecao();//Volta para o menu
				break;
				
			default:// Caso nem uma opcao seja atendida
				f_Def();
		}
	}while(opcao > 5 );
}
// 7. Funcao para aprensetar as Pizzas
// NAO CONCLUIDO
//	NAO FEITO
				//	Falta colocar as pizzas cadastradas pelo
				// atendente fazer o pedido pelo codigo do produto, 
				// pegar o codigo do produto e armazenar,
				// para imprimir depois o pedido do cliente
				// e salvar o pedido no cadastro do cliente (se tiver)
struct pedidos {
	int	mussarela;
	int	calabresa;
	int	queijo;
	int	portuguesa;
	int quant;
};
char s_mussa[11] = "Mussarela";
char s_cala[11]  = "Calabresa";
char s_quei[10] = "Queijo";
char s_port[11] = "Portuguesa";
int apresentaPizza()
{
	int oppizza;
	int i=0;
	int soma = 0;
	int soma2 = 0;
	int soma3 = 0;
	int soma4 = 0;
	int soma5 = 0;
	int soma6 = 0;
	int total = 0;
	char contador;
	struct pedidos auxiliar;
	auxiliar.quant = 0;
	
	do{
		system("cls");
		printf ("\n\n\n\t\t\t\t0 - Voltar \n\t\t\t\t");
	    printf ("1 - Pizza Mussarela com formato de meme- 18,00 R$ \n\t\t\t\t");
	    printf ("2 - Pizza Calabresa - 18,00 R$ \n\t\t\t\t");
	    printf ("3 - Pizza Queijo com formato de meme- 22,00 R$ \n\t\t\t\t");
	    printf ("4 - Pizza Portugesa - 22,00 R$ \n\t\t\t\t");
	    printf ("INFORMAR: ");
	    scanf ("%d", &oppizza);
	    
	    if(oppizza == 0){
	    	validaPizzas();
		}
	    printf("\n\t\t\t\tQuantidade: ");
		scanf("%d", &auxiliar.quant);
	    switch (oppizza){
	      	case 1:
		        printf ("\n\t\t\t\tVocê adicionou pizza de %s a sua bandeja!\n",  s_mussa);
		        auxiliar.mussarela = 18;
	          	break;
	      	case 2:
		        printf ("\n\t\t\t\tVocê adicionou pizza de %s a sua bandeja!\n", s_cala);
		        auxiliar.calabresa = 18;
	        	break;
	      	case 3:
			    printf ("\n\t\t\t\tVocê adicionou pizza de Quatro %s a sua bandeja!\n", s_quei);
			    auxiliar.queijo = 22;
	          	break;
	      	case 4:
		        printf ("\n\t\t\t\tVocê adicionou pizza de %s a sua bandeja!\n", s_port);
		        auxiliar.portuguesa = 22;
	          	break;
	      default:
	        f_Def();
		}
		if(oppizza == 1){
			soma = soma + auxiliar.mussarela * auxiliar.quant;
		}
		if(oppizza == 2){
			soma2 = soma2 + auxiliar.calabresa * auxiliar.quant;
		}
		if(oppizza == 3){
			soma3 = soma3 + auxiliar.queijo * auxiliar.quant;
		}
		if(oppizza == 4){
			soma4 = soma4 + auxiliar.portuguesa * auxiliar.quant;
		}
		printf("\n\t\t\t\tDeseja continuar fazendo o pedido?\n\t\t\t\t (s - n)");
		printf("\n\t\t\t\tINFORMAR: ");
		scanf(" %c", &contador);
		if(contador == 'n' || contador == 's'){
			soma5 = soma + soma2 + soma3 + soma4;
		}
	    total = soma5;
		printf ("\n\t\t\t\tO total de seu pedido é: R$ %d\n", total);
		printf("\n\t\t\t\t");
		system("pause");
	}while(contador == 's');
	Menu_selecao();
	return 0;
}
// 8. Funcao menu de Atendente
// Menu esta no (9.)
//Cliente /Pizza /Bebidas /Pizzaiolo
// Retorno 0
int menu_atendente()
{
    char opcao_selecionada;
    struct s_atendente novo_atendente;
    int r;
	setlocale(LC_ALL, "Portuguese");// Codigo entender caracteres especiais
    do {
    	system("cls");// LIMPAR TELA
    	logomenus();
    	gotoxy(33,6);printf("============CADASTRAR ATENDENTES============");
        opcao_selecionada = menu();// Recebe o menu digitado pelo cliente (9.)
        switch(opcao_selecionada){
            case 1:
				main();// Volta para o Menu cadastro (5.)
				break;
            case 2: // código para inserir
                if (n_atendentes == MAX_ATENDENTES) {
                    printf(ANSI_COLOR_RED "\nBANCO DE DADOS LOTADO!\n" ANSI_COLOR_RESET);// Cor Vermelha, Reseta cor
                    break;
                }
                novo_atendente = leDados_Atendente();// Recebe o retorno dos dados do atendente (10.)
                cadastraAtendente(novo_atendente);// Chama a Funcao Atendente, Armazena os dados do atendente no vetor (3.)
                printf("\n\t\t");
              	system("pause");
                break;
            case 3: // código para exibir
              	imprimeAtendente();
              	printf("\t\t");
              	system("pause");
                break;
            case 4: // código para excluir
    			do{
	          		imprimeAtendente();// improme os cadastros para remover
	                printf("\n\t\tDIGITE O CÓDIGO A SER EXCLUIDO: ");
	                scanf("%d", &r);// Informa a posicao
	                removerAtendente(r);// Manda a posicao informada para a funcao "remover"
                }while(r == getchar());
                break;
            default:// Caso nem uma opcao seja atendida
                	f_Def();
        }
    }while (opcao_selecionada!='1' || opcao_selecionada!='2' || opcao_selecionada!='3');
    return 0;
}
int menu_clientes()
{
    char opcao_selecionada;
    struct s_cliente novo_cliente;
    int r;
	setlocale(LC_ALL, "Portuguese");
    do {
    	system("cls");
    	gotoxy(33,6);printf("==========CADASTRAR CLIENTE============");
        opcao_selecionada = menu();
        switch(opcao_selecionada){
            case 1:
				Menu_Cadastro();// Volta para o Menu cadastro (5.)
				break;
            case 2: // código para inserir
                if (n_clientes == MAX_CLIENTES){// Verifica se cabe mais cadastro
                    printf(ANSI_COLOR_RED "\nBANCO DE DADOS LOTADO!\n" ANSI_COLOR_RESET);// Cor Vermelha,Reseta cor
                    break;
                }
                novo_cliente = leDados();// Recebe o retorno dos dados do cliente (10.)
                cadastraCliente(novo_cliente);// Chama a Funcao Cleinte, Armazena os dados do cliente no vetor (3.)
                printf("\n\t\t");
              	system("pause");
                break;
            case 3: // código para exibir (11.)
                imprimeClientes();
                printf("\n\t\t");
                system("pause");
                break;
            case 4: // código para excluir (12.)
    			do{
	          		imprimeClientes();// imprime os cadastros para remover
	                printf("\nDIGITE O CODIGO A SER EXCLUIDO: ");
	                scanf("%d", &r);// Informa a posicao
	                remover(r);// Manda a posicao informada para a funcao "remover" (12.)
                }while(r == getchar());
                break;
            default:// Caso nem uma opcao seja atendida
                	f_Def();
        }
    }while (opcao_selecionada!='1' || opcao_selecionada!='2' || opcao_selecionada!='3');
    return 0;
}
int menu_pizzas()
{
    char opcao_selecionada2;
    struct s_pizza nova_pizza;
    int r;
	setlocale(LC_ALL, "Portuguese");
    do {
    	system("cls");
    	gotoxy(33,6);printf("==========CADASTRAR PIZZAS============");
    	
        opcao_selecionada2 = menu();
        switch(opcao_selecionada2) {
            case 1:
				Menu_Cadastro();// Volta para o Menu cadastro (5.)
				break;

            case 2: // código para inserir
                if (n_pizzas == MAX_PIZZAS) {// Verifica se cabe mais cadastro
                    printf(ANSI_COLOR_RED "\nBANCO DE DADOS LOTADO!\n" ANSI_COLOR_RESET);// Cor Vermelha/ Reseta cor
                    break;
                }
                nova_pizza = leDados_pizza();// Recebe o retorno dos dados da pizza (10.)
                cadastraPizza(nova_pizza);// Chama a Funcao Pizza, Armazena os dados da pizza no vetor (3.)
                printf("\n\t\t");
              	system("pause");
				break;
            case 3: // código para exibir (11.)
                imprimePizzas();
                printf("\n\t\t");
                system("pause");
                break;
            case 4: // código para excluir (12.)
					imprimePizzas();// improme os cadastros para remover
	                printf("\nDIGITE O CODIGO A SER EXCLUIDO: ");
	                scanf("%d", &r);// Informa a posicao
	                removerPizza(r);// Manda a posicao informada para a funcao "remover" (12.)
                break;
            default:// Caso nem uma opcao seja atendida
              		f_Def();
        }
	}while (opcao_selecionada2!='1' || opcao_selecionada2!='2' || opcao_selecionada2!='3');
    return 0;
}
int menu_bebidas()
{
    char opcao_selecionada3;
    struct s_bebida nova_bebida;
    int r;
	setlocale(LC_ALL, "Portuguese");
    do {
    	system("cls");
    	gotoxy(33,6);printf("==========CADASTRAR BEBIDAS============");
    	
        opcao_selecionada3 = menu();
        switch(opcao_selecionada3) {
            case 1:
				Menu_Cadastro();// Volta para o Menu cadastro (5.)
				break;

            case 2: // código para inserir
                if (n_bebidas == MAX_BEBIDAS) {// Verifica se cabe mais cadastro
                    printf(ANSI_COLOR_RED "\nBANCO DE DADOS LOTADO!\n" ANSI_COLOR_RESET);// Cor Vermelha/ Reseta cor
                    break;
                }
                nova_bebida = leDados_bebida();// Recebe o retorno dos dados da bebidas (10.)
                cadastraBebida(nova_bebida);// Chama a Funcao Bebidas, Armazena os dados da bebida no vetor (3.)
                printf("\n\t\t");
              	system("pause");
				break;
            case 3: // código para exibir (11.)
                imprimeBebidas();
                printf("\n\t\t");
                system("pause");
                break;
            case 4: // código para excluir (12.)
					imprimeBebidas();// improme os cadastros para remover
	                printf("\nDIGITE O CODIGO A SER EXCLUIDO: ");
	                scanf("%d", &r);// Informa a posicao
	                removerBebida(r);// Manda a posicao informada para a funcao "remover" (12.)
                break;
            default:// Caso nem uma opcao seja atendida
              		printf("----- OPCAO INVALIDA -----");
					printf("\n");
					system("pause");
        }
	}while (opcao_selecionada3!='1' || opcao_selecionada3!='2' || opcao_selecionada3!='3');
    return 0;
}
int menu_pizzaiolo()
{
	char opcao_selecionada4;
    struct s_pizzaiolo novo_pizzaiolo;
    int r;
	setlocale(LC_ALL, "Portuguese");
    do {
    	system("cls");
    	gotoxy(33,6);printf("==========CADASTRAR PIZZAIOLOS============");
    	
        opcao_selecionada4 = menu();
        switch(opcao_selecionada4) {
            case 1:
				Menu_Cadastro();// Volta para o Menu cadastro (5.)
				break;

            case 2: // código para inserir
                if (n_pizzaiolos == MAX_BEBIDAS) {// Verifica se cabe mais cadastro
                    printf(ANSI_COLOR_RED "\nBANCO DE DADOS LOTADO!\n" ANSI_COLOR_RESET);// Cor Vermelha/ Reseta cor
                    break;
                }
                novo_pizzaiolo = leDados_pizzaiolo();// Recebe o retorno dos dados do pizzaiolo (10.)
                cadastraPizzaiolo(novo_pizzaiolo);// Chama a Funcao Pizzaiolo, Armazena os dados do pizzaiolo no vetor (3.)
               	printf("\n\t\t");
              	system("pause");
			    break;
            case 3: // código para exibir (11.)
                imprimePizzaiolo();
                printf("\n\t\t");
                system("pause");
                break;
            case 4: // código para excluir (12.)
					imprimePizzaiolo();// improme os cadastros para remover
	                printf("\nDIGITE O CODIGO A SER EXCLUIDO: ");
	                scanf("%d", &r);// Informa a posicao
	                removerBebida(r);// Manda a posicao informada para a funcao "removerPizza"
                break;
            default:// Caso nem uma opcao seja atendida
              		printf("----- OPCAO INVALIDA -----");
					printf("\n");
					system("pause");
        }
	}while (opcao_selecionada4!='1' || opcao_selecionada4!='2' || opcao_selecionada4!='3');
    return 0;	
}
// 9. Função para exibir o menu de opções
// para qualquer cadastro
// Note que retorna um valor int, que é o
// número digitado pelo usuário.
int menu()
{
    int opcao;
        opcao=0;
        L=9;
		L2=2;
		b=2;
        system("color 0f");
        logomenus();
        gotoxy(39,7);printf("=========ESCOLHA O MENU=========");
		gotoxy(40,9);printf("|\tVOLTAR");
		gotoxy(40,10);printf("|\tCADASTRA");
		gotoxy(40,11);printf("|\tEXIBIR TODOS");
		gotoxy(40,12);printf("|\tEXLUIR");
        do{
            gotoxy(36,L);
            printf("-->");
            gotoxy(74,L);
            printf("<--");
            gotoxy(0,0);
            if(kbhit){
				a=getch();
			}
            if(a == 80 && b < 5){/*seta p/baixo*/
				L2=L;L++;b++;
			}
            if(a == 72 && b > 2){/*seta p/cima */
				L2=L;L--;b--;
			}
            if(L!=L2){
				gotoxy(36,L2);
				printf("   ");
				gotoxy(74,L2);
				printf("   ");
				L2=L;
			}
            if(a == 13){
				opcao=b-1;
			}
        }while(opcao == 0);
    
    return opcao;
}
// 10. Função para ler as informações e armazenar nos vetores
// Retorna um cliente com os dados preenchidos.
// POSSIVEL ALTERACAO
struct s_atendente leDados_Atendente()
{
    struct s_atendente atendente;
    char opA;
    setlocale(LC_ALL, "Portuguese");
    do{
    	system("cls");
	    printf("\n\n\t\t\t\t");printf("===========INFORME DADOS DO ATENDENTE===========");printf("\n\n");
	    do{
		    printf("\t\t\t\t\t");printf("Nome e Sobrenome: ");
		    scanf(" %[^\n]s", atendente.nome_A);
		    if(strlen(atendente.nome_A) < 5){
		    	printf("\n\t\t\t\t\tNome Invalido!\n");
			}
	    }while(strlen(atendente.nome_A) < 5);
		printf("\t\t\t\t\t");
		printf("CPF: ");
		scanf("%d", &atendente.cpf_A);
	    do{
			printf("\t\t\t\t\t");
			printf("Sexo(h - homem/ m - mulher): ");
			scanf(" %c", &atendente.sexo_A);
			if(atendente.sexo_A == 'h' || atendente.sexo_A == 'm'){
				break;
			}else if(atendente.sexo_A != 'h' || atendente.sexo_A != 'm'){
				printf("\n\t\t\t\t\tSexo Invalido!\n");
			}
		}while(atendente.sexo_A != 'h' || atendente.sexo_A != 'm');
	    do{
		    printf("\t\t\t\t\t");
		    printf("Idade: ");
		    scanf("%d", &atendente.idade_A);
	    }while(atendente.idade_A >60);
	    
	    printf("\t\t\t\t\t");
	    printf("Telefone: ");
	    scanf("%d", &atendente.telefone_A);
	    
		printf("\t\t\t\t\t");
		printf("Senha: ");
		scanf(" %[^\n]s", &atendente.senha);
	    printf("\n\n\t\t\t\t\t");
	    printf(C_YELLOW "OS DADOS ESTÃO CORRETOS?\n\t\t\t\t\t 's' - continuar ou 'n' - editar");
	    printf("\n\n\t\t\t\t\tCaso haja algum dado errado, tera que refazer o cadastro");
	    printf("\n\t\t\t\t\tINFORMAR: " ANSI_COLOR_RESET);
	    scanf(" %c", &opA);
	}while(opA == 'n' || opA == 'N');
	printf(ANSI_COLOR_C_GREEN "\n\t\t\t\t\tCADASTRO REALIZADO COM SUCESSO!\n" ANSI_COLOR_RESET);// Cor verde, Reseta Cor
    return atendente;
}
struct s_cliente leDados()
{
    struct s_cliente auxiliar;
    char opC;
	setlocale(LC_ALL, "Portuguese");
	do{
	    system("cls");
	    printf("\n\n");
	    printf("\t\t\t\t");
	    printf("===========INFORME DADOS DO CLIENTE===========");
	    printf("\n\n");
	    printf("\t\t\t\t\t");
	    printf("Nome: ");
	    scanf(" %[^\n]s", &auxiliar.nome);
	    printf("\t\t\t\t\t");
	    printf("RG: ");
	    scanf(" %[^\n]s", &auxiliar.rg);
	    printf("\t\t\t\t\t");
	    printf("CPF: ");
	    scanf(" %[^\n]s", &auxiliar.cpf);
	    printf("\t\t\t\t\t");
	    printf("Sexo(h/m): ");
	    scanf(" %c", &auxiliar.sexo);
	    printf("\t\t\t\t\t");
	    printf("Idade: ");
	    scanf("%d", &auxiliar.idade);
	    printf("\n\n\t\t\t\t\t");
	    printf(C_YELLOW "OS DADOS ESTÃO CORRETOS?\n\t\t\t\t\t 's' - continuar ou 'n' - editar");
	    printf("\n\n\t\t\t\t\tCaso haja algum dado errado, tera que refazer o cadastro");
	    printf("\n\t\t\t\t\tINFORMAR: " ANSI_COLOR_RESET);
	    scanf(" %c", &opC);
	}while(opC == 'n' || opC == 'N');
    printf(ANSI_COLOR_C_GREEN "\n\t\t\t\t\tCADASTRO REALIZADO COM SUCESSO!\n" ANSI_COLOR_RESET);// Cor verde, Reseta Cor
    return auxiliar;
}
struct s_pizza leDados_pizza()
{
    struct s_pizza auxiliar2;
    char opP;
    setlocale(LC_ALL, "Portuguese");
    do{
	    system("cls");
	    printf("\n\n");
	    printf("\t\t\t\t");
	    printf("===========INFORME DADOS DA PIZZA===========");
	    printf("\n\n");
	    printf("\t\t\t\t\t");
		printf("PIZZA: ");
		scanf(" %[^\n]s", &auxiliar2.pizza);
		printf("\t\t\t\t\t");
		printf("PRECO: ");
		scanf("%f", &auxiliar2.preco);
		printf("\t\t\t\t\t");
		printf("DESCRICAO: ");
		scanf(" %[^\n]s", &auxiliar2.descricao);
		printf("\n\n\t\t\t\t\t");
	    printf(C_YELLOW "OS DADOS ESTÃO CORRETOS?\n\t\t\t\t\t 's' - continuar ou 'n' - editar");
	    printf("\n\n\t\t\t\t\tCaso haja algum dado errado, tera que refazer o cadastro");
	    printf("\n\t\t\t\t\tINFORMAR: " ANSI_COLOR_RESET);
	    scanf(" %c", &opP);
	}while(opP== 'n' || opP == 'N');
    printf(ANSI_COLOR_C_GREEN "\n\t\t\t\t\tCADASTRO REALIZADO COM SUCESSO!\n" ANSI_COLOR_RESET);// Cor verde, Reseta Cor
    return auxiliar2;
}
struct s_bebida leDados_bebida()
{
    struct s_bebida auxiliar3;
    char opB;
    setlocale(LC_ALL, "Portuguese");
    do{
	    system("cls");
	    printf("\n\n");
	    printf("\t\t\t\t");
	    printf("===========INFORME DADOS DA BEBIDA===========");
	    printf("\n\n");
	    printf("\t\t\t\t\t");
		printf("BEBIDA: ");
		scanf(" %[^\n]s", &auxiliar3.bebidas);
		printf("\t\t\t\t\t");
		printf("PRECO: ");
		scanf("%f", &auxiliar3.preco_b);
		printf("\t\t\t\t\t");
		printf("DESCRICAO: ");
		scanf(" %[^\n]s", &auxiliar3.descricao_b);
		printf("\n\n\t\t\t\t\t");
	    printf(C_YELLOW "OS DADOS ESTÃO CORRETOS?\n\t\t\t\t\t 's' - continuar ou 'n' - editar");
	    printf("\n\n\t\t\t\t\tCaso haja algum dado errado, tera que refazer o cadastro");
	    printf("\n\t\t\t\t\tINFORMAR: " ANSI_COLOR_RESET);
	    scanf(" %c", &opB);
	}while(opB == 'n' || opB == 'N');
    printf(ANSI_COLOR_C_GREEN "\n\t\t\t\t\tCADASTRO REALIZADO COM SUCESSO!\n" ANSI_COLOR_RESET);// Cor verde, Reseta Cor
 
    return auxiliar3;
}
struct s_pizzaiolo leDados_pizzaiolo()
{
    struct s_pizzaiolo auxiliar4;
    char opPl;
	setlocale(LC_ALL, "Portuguese");
	do{
		system("cls");
	   	printf("\n\n");
	   	printf("\t\t\t\t");
	    printf("===========INFORME DADOS DO PIZZAIOLO===========");
	    printf("\n\n");
	    printf("\t\t\t\t\t");
	    printf("Nome pizzaiolo: ");
	    scanf(" %[^\n]s", &auxiliar4.nome_P);
	    printf("\t\t\t\t\t");
	    printf("CPF: ");
	    scanf(" %[^\n]s", &auxiliar4.cpf_P);
	    printf("\t\t\t\t\t");
	    printf("Sexo(h/m): ");
	    scanf(" %c", &auxiliar4.sexo_P);
	    printf("\t\t\t\t\t");
	    printf("Idade: ");
	    scanf("%d", &auxiliar4.idade_P);
	    printf("\t\t\t\t\t");
	    printf("Telefone: ");
	    scanf("%d", &auxiliar4.telefone);
	    printf("\n\n\t\t\t\t\t");
	    printf(C_YELLOW "OS DADOS ESTÃO CORRETOS?\n\t\t\t\t\t's' - continuar ou 'n' - editar");
	    printf("\n\n\t\t\t\t\tCaso haja algum dado errado, tera que refazer o cadastro");
	    printf("\n\t\t\t\t\tINFORMAR: " ANSI_COLOR_RESET);
	    scanf(" %c", &opPl);
	}while(opPl == 'n' || opPl == 'N');
    printf(ANSI_COLOR_C_GREEN "\n\t\t\t\t\tCADASTRO REALIZADO COM SUCESSO!\n" ANSI_COLOR_RESET);// Cor verde, Reseta Cor
    return auxiliar4;
}
// 11. Função para imprimir na tela
// Note que não tem retorno, apenas imprime
void imprimeAtendente()
{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	printf("\n\n\n\t\t\t\t===========DADOS DOS ATENDENTES===========\n");
    for (i=0; i<n_atendentes; i++) {
        printf("\n\t\t\t\t\tCódigo..: %d", i+1);
        printf("\n\t\t\t\t\tNome....: %s", atendentes[i].nome_A);
        printf("\n\t\t\t\t\tCPF.....: %d", atendentes[i].cpf_A);
        printf("\n\t\t\t\t\tSexo....: %c", atendentes[i].sexo_A);
        printf("\n\t\t\t\t\tIdade...: %d", atendentes[i].idade_A);
        printf("\n\t\t\t\t\tTelefone: %d", atendentes[i].telefone_A);
        printf("\n\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n");
    }
}
void imprimeClientes()
{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	printf("\n\n\n\t\t\t\t===========DADOS DOS CLIENTES===========\n");
    for (i=0; i<n_clientes; i++) {
        printf("\n\t\t\t\t\tCódigo: %d", i+1);
        printf("\n\t\t\t\t\tNome..: %s", clientes[i].nome);
        printf("\n\t\t\t\t\tRG....: %s", clientes[i].rg);
        printf("\n\t\t\t\t\tCPF...: %s", clientes[i].cpf);
        printf("\n\t\t\t\t\tSexo..: %c", clientes[i].sexo);
        printf("\n\t\t\t\t\tIdade.: %d", clientes[i].idade);
        printf("\n\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n");
    }
}
void imprimePizzas()
{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	printf("\n\n\n\t\t\t\t===========DADOS DAS PIZZAS===========\n");
    for (i=0; i<n_pizzas; i++) {
        printf("\n\t\t\t\t\tCódigo...: %d", i+1);
        printf("\n\t\t\t\t\tPizza....: %s", pizzas[i].pizza);
        printf("\n\t\t\t\t\tPreco....: R$%.2f", pizzas[i].preco);
        printf("\n\t\t\t\t\tDescricao: %s", pizzas[i].descricao);
        printf("\n\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n");
    }
}
void imprimeBebidas()
{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	printf("\n\n\n\t\t\t\t===========DADOS DAS BEBIDAS===========\n");
    for (i=0; i<n_bebidas; i++) {
        printf("\n\t\t\t\t\tCódigo...: %d", i+1);
        printf("\n\t\t\t\t\tBebidas..: %s", bebidas[i].bebidas);
        printf("\n\t\t\t\t\tPreco....: R$%.2f", bebidas[i].preco_b);
        printf("\n\t\t\t\t\tDescricao: %s", bebidas[i].descricao_b);
        printf("\n\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n");
    }
}
void imprimePizzaiolo()
{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	printf("\n\n\n\t\t\t\t===========DADOS DOS PIZZAIOLOS===========\n");
    for (i=0; i<n_pizzaiolos; i++) {
        printf("\n\t\t\t\t\tCódigo...: %d", i+1);
        printf("\n\t\t\t\t\tNome.....: %s", pizzaiolos[i].nome_P);
        printf("\n\t\t\t\t\tCPF......: %s", pizzaiolos[i].cpf_P);
        printf("\n\t\t\t\t\tSexo.....: %c", pizzaiolos[i].sexo_P);
        printf("\n\t\t\t\t\tIdade....: %d", pizzaiolos[i].idade_P);
        printf("\n\t\t\t\t\tTelefone.: %d", pizzaiolos[i].telefone);
        printf("\n\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n");
    }
}
// 12. Função para remover elemento do vetor
// Note que não há retorno, apenas remove.
void removerAtendente(int posicaoA)
{
    int indice = posicaoA - 1;
    int i = 0;
	setlocale(LC_ALL, "Portuguese");
    if ((posicaoA < 1) || (posicaoA > n_atendentes)) {
        printf("\nPosiçao invalida!\n");
        return;
    }

    // 1. caso - remover no final do vetor
    if (posicaoA == n_atendentes) {
        n_atendentes--;
        return;
    }

    // 2. remove qualquer outra posicao
    for (i=indice; i<n_atendentes; i++) {
        atendentes[i] = atendentes[i+1];
    }
    n_atendentes--;
}
void remover(int posicao)// Remover o cliente
{
    int indice = posicao - 1;
    int i = 0;
	setlocale(LC_ALL, "Portuguese");
    if ((posicao < 1) || (posicao > n_clientes)) {
        printf("\nPosiçao invalida!\n");
        return;
    }

    // 1. caso - remover no final do vetor
    if (posicao == n_clientes) {
        n_clientes--;
        return;
    }

    // 2. remove qualquer outra posicao
    for (i=indice; i<n_clientes; i++) {
        clientes[i] = clientes[i+1];
    }
    n_clientes--;
}
void removerPizza(int posicao2)
{

    int indice = posicao2 - 1;
    int i = 0;
	setlocale(LC_ALL, "Portuguese");
    if ((posicao2 < 1) || (posicao2 > n_pizzas)) {
        printf("\nPosiçao invalida!\n");
        return;
    }

    // 1. caso - remover no final do vetor
    if (posicao2 == n_pizzas) {
        n_pizzas--;
        return;
    }

    // 2. remove qualquer outra posicao
    for (i=indice; i<n_pizzas; i++) {
        pizzas[i] = pizzas[i+1];
    }
    n_pizzas--;
}
void removerBebida(int posicao3)
{

    int indice = posicao3 - 1;
    int i = 0;

    if ((posicao3 < 1) || (posicao3 > n_bebidas)) {
        printf("\nPosiçao invalida!\n");
        return;
    }

    // 1. caso - remover no final do vetor
    if (posicao3 == n_bebidas) {
        n_bebidas--;
        return;
    }

    // 2. remove qualquer outra posicao
    for (i=indice; i<n_bebidas; i++) {
        bebidas[i] = bebidas[i+1];
    }
    n_bebidas--;
}
void removerPizzaiolo(int posicao4)
{

    int indice = posicao4 - 1;
    int i = 0;
	setlocale(LC_ALL, "Portuguese");
    if ((posicao4 < 1) || (posicao4 > n_pizzaiolos)) {
        printf("\nPosiçao invalida!\n");
        return;
    }

    // 1. caso - remover no final do vetor
    if (posicao4 == n_pizzaiolos) {
        n_pizzaiolos--;
        return;
    }

    // 2. remove qualquer outra posicao
    for (i=indice; i<n_pizzaiolos; i++) {
        pizzaiolos[i] = pizzaiolos[i+1];
    }
    n_pizzaiolos--;
}
// 13. Funcao para pesquisar pelo cliente/pizza
// Sem retorno
// POSSIVEL MELHORIA
void pesquisa()
{
    char cpfPesquisa[15];
    char nomePesquisa[50];
    char pizzaPesquisa[30];
    char bebidaPesquisa[30];
    char pizzaioloPesquisa[50];
    int j=0;
	setlocale(LC_ALL, "Portuguese");
    int opcao;
    int cont;
    do{
        opcao=0;
        L=9;
		L2=2;
		b=2;
        system("cls");
        system("color 0f");
        logomenus();
        gotoxy(38,7);printf("===============MENU DE PESQUISA===============");
		gotoxy(40,9);printf("|\tVOLTAR");
		gotoxy(40,10);printf("|\tCPF CLIENTE");
		gotoxy(40,11);printf("|\tNOME CLIENTE");
		gotoxy(40,12);printf("|\tNOME PIZZA");
		gotoxy(40,13);printf("|\tNOME BEBIDAS");
		gotoxy(40,14);printf("|\tNOME PIZZAIOLO");
        do{
            gotoxy(36,L);
            printf("-->");
            gotoxy(74,L);
            printf("<--");
            gotoxy(0,0);
            if(kbhit){
				a=getch();
			}
            if(a == 80 && b < 7){/*seta p/baixo*/
				L2=L;L++;b++;
			}
            if(a == 72 && b > 2){/*seta p/cima */
				L2=L;L--;b--;
			}
            if(L!=L2){
				gotoxy(36,L2);
				printf("   ");
				gotoxy(74,L2);
				printf("   ");
				L2=L;
			}
            if(a == 13){
				opcao=b-1;
			}
        }while(opcao == 0);   
        switch(opcao){
        	case 1:
        		Menu_selecao();
        		break;
            case 2:// Pesquisar por CPF do Cliente
            	system("cls");
                printf("\n\t\t\t\tDigite o CPF: ");
                scanf(" %[^\n]s", &cpfPesquisa);

                for(j=0; j<n_clientes; j++){
                    if(cpfPesquisa == clientes[j].cpf){
                    		printf("\n\t\t\t\tCodigo: %d", j+1);
                            printf("\n\t\t\t\tNome..: %s", clientes[j].nome);
					        printf("\n\t\t\t\tRG....: %s", clientes[j].rg);
					        printf("\n\t\t\t\tCPF...: %s", clientes[j].cpf);
					        printf("\n\t\t\t\tSexo..: %c", clientes[j].sexo);
					        printf("\n\t\t\t\tIdade.: %d", clientes[j].idade);
                    }
                }
                break;
            case 3:// Pesquisar pelo nome do Cliente
            	system("cls");
                printf("\n\t\t\t\tDigite o nome: ");
                scanf("%s", &nomePesquisa);

                for(j=0; j<n_clientes; j++){
                    if(strcmp(clientes[j].nome, nomePesquisa) == 0){
                    		printf("\n\t\t\t\tCodigo: %d", j+1);
                            printf("\n\t\t\t\tNome..: %s", clientes[j].nome);
					        printf("\n\t\t\t\tRG....: %s", clientes[j].rg);
					        printf("\n\t\t\t\tCPF...: %s", clientes[j].cpf);
					        printf("\n\t\t\t\tSexo..: %c", clientes[j].sexo);
					        printf("\n\t\t\t\tIdade.: %d", clientes[j].idade);
                    }
                }
                break;
            case 4:// Pesquisar pelo nome da pizza
            	system("cls");
                printf("\n\t\t\t\tDigite o nome da Pizza: ");
                scanf("%s", &pizzaPesquisa);

                for(j=0; j<n_pizzas; j++){
                    if(strcmp(pizzas[j].pizza, pizzaPesquisa) == 0){
                    		printf("\n\t\t\t\tCodigo...: %d", j+1);
                            printf("\n\t\t\t\tPizza....: %s", pizzas[j].pizza);
					        printf("\n\t\t\t\tPreco....: R$%.2f", pizzas[j].preco);
					        printf("\n\t\t\t\tDescricao: %s", pizzas[j].descricao);
					        printf("\n\t\t\t\t+++++++++++++++++++\n");
                    }
                }
                break;
            case 5:// Pesquisar pelo nome da pizza
            	system("cls");
            	printf("\n\t\t\t\tDigite o nome da Pizza: ");
                scanf("%s", &bebidaPesquisa);

                for(j=0; j<n_bebidas; j++){
                    if(strcmp(bebidas[j].bebidas, bebidaPesquisa) == 0){
                    		printf("\n\t\t\t\tCodigo...: %d", j+1);
                            printf("\n\t\t\t\tBebidas..: %s", bebidas[j].bebidas);
					        printf("\n\t\t\t\tPreco....: R$%.2f", bebidas[j].preco_b);
					        printf("\n\t\t\t\tDescricao: %s", bebidas[j].descricao_b);
					        printf("\n\t\t\t\t+++++++++++++++++++\n");
                    }
                }
                break;
           case 6:// Pesquisar pelo nome do Cliente
           		system("cls");
                printf("\n\t\t\t\tDigite o nome: ");
                scanf("%s", &pizzaioloPesquisa);

                for(j=0; j<n_pizzaiolos; j++){
                    if(strcmp(pizzaiolos[j].nome_P, pizzaioloPesquisa) == 0){
                    		printf("\n\t\t\t\tCodigo..: %d", j+1);
                            printf("\n\t\t\t\tNome....: %s", pizzaiolos[j].nome_P);
					        printf("\n\t\t\t\tCPF.....: %s", pizzaiolos[j].cpf_P);
					        printf("\n\t\t\t\tSexo....: %c", pizzaiolos[j].sexo_P);
					        printf("\n\t\t\t\tIdade...: %d", pizzaiolos[j].idade_P);
					        printf("\n\t\t\t\tTelefone: %d", pizzaiolos[j].telefone);
                    }
                }
                break;            
		            default:
                	f_Def();
            }
            printf("\nDigite 1 para outra pesquisa, eh outro valor para sair: ");
            scanf("%d", &cont);
    }while (opcao == 1);
}
// 14. Funcao para Criticas e Elogios
// Nao a retorno, imprimi no momento que inserir algo
void validaReclamacoes()
{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	char critica[100];
	int opcao;
	
	printf("\n\n\n\t\t\t\tINFORME SUA RECLAMAÇÃO/ELOGIO: ");
	scanf(" %[^\n]s", &critica);
	printf("\n\t\t\t\tO COMENTARIO É: %s\n", critica);
	do{
		printf("\n\n\n\n\t\t\t\tPRESSIONE 'ENTER' PARA CONTINUAR!");
		opcao = getch();
		
		if(opcao == 13){
			Menu_selecao();
		}
	}while(opcao != 13);
}
// APARTIR DAQUI ENTRAREMOS NO CODIGO DO ESTOQUE
// Estrutura para estoque
struct estocagem{
		char nome[20];
		float preco;
		int quant;
	};
// Declarando Variaveis
int n_estoques=0;
struct estocagem Estoque[5];
// Adiciona estoque a um vetor
void cadastraEstoque(struct estocagem estoques)
{
    Estoque[n_estoques] = estoques;
	n_estoques++;
}
// Le os Estoques
struct estocagem leDados_estoque()
{
	struct estocagem auxilia;
	system("cls");
	printf("\n\n\t\t==============ESTOQUE==============\n");
	printf("\n\t\tNOME: ");
	scanf("%s", &auxilia.nome);
	printf("\n\t\tPRECO: R$ ");
	scanf("%f", &auxilia.preco);
	printf("\n\t\tQUANTIDADE: ");
	scanf("%d", &auxilia.quant);
	printf(ANSI_COLOR_C_GREEN "\t\tCADASTRO REALIZADO COM SUCESSO!\n" ANSI_COLOR_RESET);// Cor verde, Reseta Cor
	system("pause");
	return auxilia;
}
// Imprimir Estoque
void imprimireEstoque(){
	system("cls");
	printf("\n\n\t\t==============ESTOQUE==============\n");
	printf("\tCODIGO\t|\tNOME\t|\tPRECO\t|\tQUANT.\n\n");
	for (i=0; i<n_estoques; i++) {
        printf("\t|%d\t", i+1);
	    printf("|%s\t\t", Estoque[i].nome);
	    printf("|%.2f\t\t", Estoque[i].preco);
	    printf("|%d\n", Estoque[i].quant);
   	}
}
// Remover estoque
void removerEstoque(){
	int posicao;
	int indice = posicao;
	
	printf("\n\t\tPosicao a ser excluida: ");
	scanf("%d", &posicao);
	
    if ((posicao < 1) || (posicao > n_estoques)) {
        printf("\nPosiçao invalida!\n");
        return;
    }

    // 1. caso - remover no final do vetor
    if (posicao == n_estoques) {
        n_estoques--;
        return;
    }
	
    // 2. remove qualquer outra posicao
    for (i=indice; i<n_estoques; i++) {
        Estoque[i] = Estoque[i+1];
    }
   n_estoques--;
}
// 15. Funcao Menus do estoque
void estoque()
{
	setlocale(LC_ALL, "Portuguese");
	struct estocagem novo_estoque;
	system("cls");
	int opcao;
	do{
        opcao=0;
        L=9;
		L2=2;
		b=2;
        system("color 0f");
        logomenus();
        gotoxy(38,7);printf("=========ESCOLHA O MENU=========");
		gotoxy(40,9);printf("|\tVOLTAR");
		gotoxy(40,10);printf("|\tCADASTRA ESTOQUE");
		gotoxy(40,11);printf("|\tEXIBIR ESTOQUE");
		gotoxy(23,12);printf("|\tEXLUIR ESTOQUE");
        do{
            gotoxy(36,L);
            printf("-->");
            gotoxy(74,L);
            printf("<--");

            gotoxy(0,0);
            if(kbhit){
				a=getch();
			}
            if(a == 80 && b < 5){/*seta p/baixo*/
				L2=L;L++;b++;
			}
            if(a == 72 && b > 2){/*seta p/cima */
				L2=L;L--;b--;
			}
            if(L!=L2){
				gotoxy(36,L2);
				printf("   ");
				gotoxy(74,L2);
				printf("   ");
				L2=L;
			}
            if(a == 13){
				opcao=b-1;
			}
        }while(opcao == 0);
		switch(opcao){
			case 1:
				Menu_selecao();
				break;
			case 2:
				novo_estoque = leDados_estoque();
				cadastraEstoque(novo_estoque);
				estoque();
				break;
			case 3:
				imprimireEstoque();
				printf("\n\t\t");
                system("pause");
                estoque();
				break;
			case 4:
				imprimireEstoque();
				removerEstoque();
				break;
				default:
					f_Def();
		}
	}while(opcao>4);
}
