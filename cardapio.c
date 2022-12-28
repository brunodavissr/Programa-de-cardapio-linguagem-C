#include<stdio.h>
#include <string.h>
#define imposto 0.17
#include<stdlib.h>
#include<windows.h>
	
char comida[5][30]={"vazio","Hamburguer(es)","Refrigreante(es)","Batata Frita(as)","Milk Shake(es)"};	
float valoricms, hamb=10+10*imposto, refri=3.50+3.50*imposto, batata=7+7*imposto, mshake=10+10*imposto, valorto=0;
int opc, quant, quanth=0, quantr=0, quantb=0, quantm=0, esc;

float cardapio(void)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	printf("\t============== MENU ================\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("\n\t||1-HAMBURGUER(X-TUDO):      %.2f||",hamb);
	printf("\n\t||2-REFRIGERANTE(500ml):      %.2f||",refri);
	printf("\n\t||3-BATATA FRITA(800gramas):  %.2f||",batata);
	printf("\n\t||4-MILK SHAKE(500ml):       %.2f||",mshake);
	SetConsoleTextAttribute(hConsole, saved_attributes);
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	printf("\n\n\t====================================");
	SetConsoleTextAttribute(hConsole, saved_attributes);
}

int main(void)
{	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
	cardapio();
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf("\n\n\t\t   Seja Bem Vindo!");
	SetConsoleTextAttribute(hConsole, saved_attributes);
	printf("\n\nDesseja adicionar algo ao cardapio?\t\n\n1-SIM 2-NAO: ");
	scanf("%d",&esc);
	
	while(esc==1)
	{
		system("cls");
	    cardapio();
		
		printf("\n\nSelecione a opcao que deseja: ");
	    scanf("%d",&opc);
	    system("cls");
	    
	    cardapio();
	    
	    printf("\n\nSelecione a quantidade de %s que deseja: ",comida[opc]);
	    scanf("%d",&quant);
	    system("cls");
	    
	    cardapio();
	    
	    switch(opc)
	    {
	    	case 1:
	    		{
					SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					printf("\n\nVoce adicionou %d hamburguer(es)\n",quant);
	    			valorto=valorto+hamb*quant;
	    			printf("\nSubtotal a pagar: %.2f",valorto);
	    			SetConsoleTextAttribute(hConsole, saved_attributes);
	    			quanth=quanth+quant;
	    			break;
				}
			case 2:
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					printf("\n\nVoce adicionou %d refrigerante(es)\n",quant);
					valorto=valorto+refri*quant;
			        printf("\nSubtotal a pagar: %.2f",valorto);
			        SetConsoleTextAttribute(hConsole, saved_attributes);
			        quantr=quantr+quant;
			        break;
				}
			case 3:
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					printf("\n\nVoce adicionou %d batata frita(as)\n",quant);
					valorto=valorto+batata*quant;
					printf("\nSubtotal a pagar: %.2f",valorto);
					SetConsoleTextAttribute(hConsole, saved_attributes);
					quantb=quantb+quant;
					break;
				}
			case 4:
			    {
			    	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					printf("\n\nVoce adicionou %d Milk Shake(es)\n",quant);
					valorto=valorto+mshake*quant;
					printf("\nSubtotal a pagar: %.2f",valorto);
					SetConsoleTextAttribute(hConsole, saved_attributes);
					quantm=quantm+quant;
					break;
				}
				
		}
		
		
		printf("\n\nDesseja fazer nova escolha de cardapio?\t 1-SIM 2-NAO: ");
	    scanf("%d",&esc);
	    
	}
	
	system("cls");
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("Agradecemos pela escolha! ^^");
	printf("\nAguarde, em breve seu pedido chegara!\n\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);
	printf("Pedidos feitos:\n");
	
	if(quanth!=0)
	{
		printf("\n%d %s ",quanth, comida[1]);
	}
	
	if(quantr!=0)
	{
		printf("\n%d %s ",quantr, comida[2]);
	}
	
	if(quantb!=0)
	{
		printf("\n%d %s ",quantb, comida[3]);
	}
	
	if(quantm!=0)
	{
		printf("\n%d %s ",quantm, comida[4]);
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("\n\nVALOR TOTAL PAGAR: %.2f\n\n\n\n\n\n\n\n\n\n\n\n\n\n",valorto);
	SetConsoleTextAttribute(hConsole, saved_attributes);
	
	system("pause");
	
	return 0;
}
