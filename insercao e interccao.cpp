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

	

	

int main(void)
{
	char nomes[tf][tf], nomes2[tf][tf], nomes3[tf*2][tf], aux[tf], auxnome[tf], aux2[tf], aux3, del[tf];
	char op,opa,opb,opc,opd,ope,opf,opg; 	
	int i=0, j, k, tl=0, tl2=0, tl3=0, a=0;
		
	 
	 do
	 {
	 	
	 	clrscr();
	 	
		printf("**MENU**\n");
		printf("[A] cadastrar nomes lista 1\n");
		printf("[B] exibir listas\n");
		printf("[C] ordenar listas\n");
		printf("[D] excluir\n");
		printf("[E] cadastro nomes lista 2\n");
		printf("[F] insercao\n");
		printf("[G] interseccao\n");
		printf("[Esc] sair");
		
		op=toupper(getch());
			 
		 switch(op)
		{
			case 'A':	do //cadastro de nomes
						{
							clrscr();
							
							if(tl==tf)
							{
								printf("limite maximo de cadastros atingido\n");
								getch();
							}
							else
							{
								printf("digite um nome: \n");
								fflush(stdin);
								gets(aux);	
								i = buscanome(aux,nomes,tl);								
								if(i != -1)
									printf("nome ja cadastrado\n");
								else
								{
									strcpy(nomes[tl],aux);
									tl++;
									printf("##cadastrado##\n");
									printf("%d cadastros restantes\n\n",tf-tl);
								}
								
								if(tl==tf)
								{
									printf("limite maximo de cadastros atingido\n\n");
									getch();
								}                      
								
								{
									printf("cadastrar novamente ?");
									fflush(stdin);
									opa = getch();
								}		
							}		
						}
						while(opa != 27 && tl < tf);
						break;			
				
			case 'B':	do //exibição da lista de nomes
						{
							clrscr();
	
							if(tl==0)
								printf("lista vazia\n");
							else
							{
								i=0;
								printf("###lista 1###\n");
								while(i<tl)
								{
									printf("lista de nomes: %s\n",nomes[i]);
									i++;
								}
							}
							
							if(tl2==0)
								printf("\nlista 2 vazia\n");
							else
							{
								i=0;
								printf("\n###lista 2###\n");
								while(i<tl2)
								{
									printf("lista de nomes: %s\n",nomes2[i]);
									i++;
								}
							}
							
							if(tl3==0)
								printf("\nlista 3 vazia\n");
							else
							{
								i=0;
								printf("\n###lista 3###\n");
								while(i<tl3)
								{
									printf("lista de nomes: %s\n",nomes3[i]);
									i++;
								}
							}
							
							opb = getch();
						}
						while(opb != 27);	
						break;
	
			case 'C':	do // ordenação da lista de nomes
						{
							clrscr();
							for(int j=tl; j>0; j--)
								for(i=0;i<j;i++)
										if(strcmp(nomes[i],nomes[i+1])>0)
										{
											strcpy(aux,nomes[i]);
											strcpy(nomes[i],nomes[i+1]);
											strcpy(nomes[i+1],aux);
										}
										
							for(int j=tl2; j>0; j--)
								for(i=0;i<j;i++)
										if(strcmp(nomes2[i],nomes2[i+1])>0)
										{
											strcpy(aux2,nomes2[i]);
											strcpy(nomes2[i],nomes2[i+1]);
											strcpy(nomes2[i+1],aux2);
										}
								printf("as listas foram ordenadas\n");
							opc = getch();
						}
						while(opc != 27);
						break;
						
			case 'D':	do // exclusão de nomes
						{
							clrscr();
							i=0;
							printf("digite o nome a ser excluido: ");
							gets(del);
							i = buscanome(del,nomes,tl);
							if(i != -1)
							{
								for(int a=i;a<tl;a++)
									strcpy(nomes[a],nomes[a+1]);
								printf("excluido\n");
								tl--;
							}
							else
								printf("nome nao encontrado\n");

							opd = getch();
						}
						while(opd != 27);
						break;
			
			case 'E':	do // cadastro nomes lista 2
						{
							clrscr();
							
							if(tl2==tf)
							{
								printf("limite maximo de cadastros atingido\n");
								getch();
							}
							else
							{
								printf("digite um nome: \n");
								fflush(stdin);
								gets(aux2);	
								i = buscanome(aux2,nomes2,tl2);								
								if(i != -1)
									printf("nome ja cadastrado\n");
								else
								{
									strcpy(nomes2[tl2],aux2);
									tl2++;
									printf("##cadastrado##\n");
									printf("%d cadastros restantes\n\n",tf-tl2);
								}
								
								if(tl2==tf)
								{
									printf("limite maximo de cadastros atingido\n\n");
									getch();
								}
								else
								{
									printf("cadastrar novamente ?");
									fflush(stdin);
									ope = getch();
								}
							}		
						}
						while(ope != 27);
						break;
			
			case 'F':	do // inserção entre nomes 1 e 2 
						{
							clrscr();
							
							printf("digite uma letra para a insercao\n");
							fflush(stdin);
							scanf("%c",&aux3);
							
							for(i=0; i<tl; i++)
								if(nomes[i][0] == aux3)
								{
									strcpy(nomes3[tl3],nomes[i]);
									tl3++;
								}
							for(j=0; j<tl2; j++)
								if(nomes2[j][0] == aux3)
								{
									{
										strcpy(nomes3[tl3],nomes2[j]);
										tl3++;
									}
										
								}
							
							printf("insercao realizada\n");

							opf = getch();
						}
						while(opf != 27);
						break;
			
			case 'G':	do // intersecção entre nomes 1, 2 e 3 
						{
							clrscr();
							if(tl!=0 && tl2!=0 && tl3!=0)
							{
								for(i=0;i<tl-1;i++)
								{
									for(j=0;j<tl2-1;j++)
									{
										for(k=0;k<tl3;k++)
											if(strcmp(nomes[i],nomes2[j])==0 && strcmp(nomes[i],nomes3[k])==0)	
												puts(nomes[i]);
										
											
											
												
										
									}
								}
							
								
								
							}
							else
								printf("preencha as 3 listas primeiro\n");
						
							opg = getch();
						}
						while(opg != 27);
						break;
						
					}
	}
	while(op != 27);
	
			
	return 0;
}
