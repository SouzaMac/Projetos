






/* esse é um sistema basico de cadastros e alterações, o sistema já cadastra ordenadamente e 
voce tem a opcão de excluir nomes da lista 1*/


#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>

#define tf 10

int buscanome(char aux[tf],char nomes[tf][tf], int tl)
{
	int i=0;
			
	while(i<tl && strcmp(aux,nomes[i])!= 0)
		i++;
	
	if(i<tl)
		return i; //achou
	else
		return -1; //não achou
}

void moldura(int ci, int li, int cf, int lf)
{
	gotoxy(ci,li);
	printf("%c", 201);
	gotoxy(cf,li);
	printf("%c", 187);
	gotoxy(ci,lf);
	printf("%c", 200);
	gotoxy(cf,lf);
	printf("%c", 188);
	
	
	for(int c=ci+1; c < cf; c++)
	{
		gotoxy(c,li);
		printf("%c", 205);
		gotoxy(c,lf);
		printf("%c", 205);
	}
	
	for(int l=li+1; l < lf; l++)
	{
		gotoxy(ci,l);
		printf("%c", 186);
		gotoxy(cf,l);
		printf("%c", 186);
	}
	
}

void limpatela(int ci, int li, int cf, int lf)
{
	int x, y;
	
	for(x=ci+1; x<cf-1; x++)
	{
		for(y=li+1; y<lf-1; y++)
		{
			gotoxy(x,y);
			printf(" ");
		}
	}
		
}

int main(void)
{
	char nomes[tf][tf], aux[tf], del[tf];
	char op, opa, opb, opc; 	
	int i=0, tl=0, a=0;
	int ci=15, li=2, cf=100, lf=26, x=ci+2, y=li+1, y2;
	
	moldura(ci,li,cf,lf);
	 do
	 {
	 	limpatela(ci,li,cf,lf);
	 	
	 	gotoxy(x,y);
		printf("**MENU**\n");
		gotoxy(x,y+2);
		printf("[A] cadastro de nomes\n");
		gotoxy(x,y+4);
		printf("[B] exibir nomes\n");
		gotoxy(x,y+6);
		printf("[C] excluir\n");
		gotoxy(x,y+8);
		printf("[Esc] sair");
		gotoxy(x,y+10);
		printf("opcao: ");
		
		op=toupper(getch());
			 
		 switch(op)
		{
			case 'A':	do //cadastro de nomes
						{
							limpatela(ci,li,cf,lf);
							
							if(tl==tf)
							{
								gotoxy(x,y);
								printf("limite maximo de cadastros atingido");
								gotoxy(x,y+2);
								printf("esc p/ sair");
								opa = getch();
							}
							else
							{
								gotoxy(x,y);
								printf("digite um nome: ");
								fflush(stdin);
								gets(aux);	
								i = buscanome(aux,nomes,tl);								
								if(i != -1)
								{
									limpatela(ci,li,cf,lf);
									gotoxy(x,y+1);
									printf("nome ja cadastrado\n");
								}
									
								else
								{
									strcpy(nomes[tl],aux);
									tl++;
									limpatela(ci,li,cf,lf);
									for(int j=tl; j>0; j--)
									{
										for(int k=0;k<j;k++)
										{
											if(strcmp(nomes[k],nomes[k+1])>0)
											{
												strcpy(aux,nomes[k]);
												strcpy(nomes[k],nomes[k+1]);
												strcpy(nomes[k+1],aux);
											}
										}
											
									}
								
									limpatela(ci,li,cf,lf);
									gotoxy(x,y);
									printf("##cadastrado##");
									gotoxy(x,y+1);
									printf("%d cadastros restantes",tf-tl);
								}
								
								if(tl==tf)
								{
									gotoxy(x,y+3);
									printf("limite maximo de cadastros atingido");
									gotoxy(x,y+5);
									printf("esc p/ sair");
									opa = getch();
								}                      
								else
								{
									gotoxy(x,y+3);
									printf("enter p/ cadastrar novamente ?");
									fflush(stdin);
									gotoxy(x,y+5);
									printf("esc p/ sair");
									opa = getch();
								}		
							}		
						}
						while(opa != 27 && tl < tf);
						break;			
				
			case 'B':	do //exibição da lista de nomes
						{
							limpatela(ci,li,cf,lf);
							
							y2=y;
	
							if(tl==0)
							{
								gotoxy(x,y);
								printf("lista vazia\n");
								gotoxy(x,y+2);
								printf("esc p/ sair");
							}
								
							else
							{
								i=0;
								gotoxy(x,y);
								printf("###lista de nomes###\n\n");
								while(i<tl)
								{
									gotoxy(x,y2+2);
									printf("%s\n",nomes[i]);
									i++;
									y2++;
									
								}
							}
							
							opb = getch();
						}
						while(opb != 27);	
						break;
	
						
			case 'C':	do // exclusão de nomes
						{
							limpatela(ci,li,cf,lf);
							
							if(tl == 0)
							{
								gotoxy(x,y);
								printf("nao ha nomes na lista");
								gotoxy(x,y+2);
								printf("esc p/ sair");
							}
							else
							{
								i=0;
								gotoxy(x,y);
								printf("digite o nome a ser excluido: ");
								gets(del);
								i = buscanome(del,nomes,tl);
								if(i != -1)
								{
									for(int a=i;a<tl;a++)
										strcpy(nomes[a],nomes[a+1]);
									limpatela(ci,li,cf,lf);
									gotoxy(x,y);
									printf("excluido");
									gotoxy(x,y+2);
									printf("esc p/ sair");
									tl--;
								}
								else
								{
									gotoxy(x,y+2);
									printf("nome nao encontrado");
									gotoxy(x,y+4);
									printf("esc p/ sair");
									
								}
							}
							
							

							opc = getch();
						}
						while(opc != 27);
						break;
			
						
		}
	}
	while(op != 27);
	
			
	return 0;
}
