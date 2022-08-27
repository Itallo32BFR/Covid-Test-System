#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200
void leValidaNome(char nome[][20], int ind);
int leValidaCartao(int ind, int cartaoSUS[]);
int leValidaIdade(int ind);
char leValidaSexo(int ind);
char leValidaTeste(int ind);
char leValidaResult(int ind);
void leValidaCidade(char cidade[][20], int ind);
void exibeDados(char nome[], int cartaoSUS, int idade, char sexo, char tipoTeste, char result, char cidade[]);
void exibeDadosMascMenor(char nome[], int idade, int cartaoSUS, char sexo, char tipoTeste, char result, char cidade[]);
void exibeDadosFemMenor(char nome[], int idade, int cartaoSUS, char sexo, char tipoTeste, char result, char cidade[]);
void exibeDadosMascIdoso(char nome[], int idade, int cartaoSUS, char sexo, char tipoTeste, char result, char cidade[]);
void exibeDadosFemIdoso(char nome[], int idade, int cartaoSUS, char sexo, char tipoTeste, char result, char cidade[]);
void exibeQuantitativoCidades(int contAc,int contAn,int contAs,int contBr,int contCe,int contCr,int contEs,int contGa,int contGu,int contLn,int contLs,int contNo,int contNb,int contPa,int contPlint,int contRe,int contR1,int contR2,int contSa,int contSm,int contSs,int contSo,int contSu,int contTa,int contVp);
void exibeTipoTeste(char tipoTeste, int contS, int contR, int contT);
main(){
	char nome[MAX][20], sexo[MAX], tipoTeste[MAX], result[MAX];
	int cartaoSUS[MAX], idade[MAX];
	int op, ind=0, opRelatorio, qtde;
	char cidade[MAX][20];
	int contAc=0, contAn=0, contAs=0, contBr=0, contCe=0;
	int contCr=0, contEs=0, contGa=0, contGu=0, contLn=0;
	int contLs=0, contNo=0, contNb=0, contPa=0, contPl=0;
	int contRe=0, contR1=0, contR2=0, contSa=0, contSm=0;
	int contSs=0, contSo=0, contSu=0, contTa=0, contVp=0;
	int contS=0, contR=0, contT=0;
	int contMm=0, contFm=0, contMi=0, contFi=0, contPos=0;
	float porcent=0, total=0;
	
	do{
		do{
			system("cls");
			puts("  MENU PRINCIPAL");
			puts("Escolha uma opcao:");
			puts("1 - Cadastro.");
			puts("2 - Relatorios.");
			puts("3 - Sair.");
			scanf("%i", &op);
			switch(op){
				case 1:
					system("cls");
					leValidaNome(nome, ind);
					cartaoSUS[ind]=leValidaCartao(ind, cartaoSUS);
					idade[ind]=leValidaIdade(ind);
					sexo[ind]=leValidaSexo(ind);
					tipoTeste[ind]=leValidaTeste(ind);
					result[ind]=leValidaResult(ind);
					leValidaCidade(cidade, ind);
					ind++;
					total++;
					break;
				case 2:
					qtde=ind;
					do{
						system("cls");
						printf("Escolha o relatorio que deseja visualizar:\n");
						puts("1 - Todos os dados das pessoas que testaram positivo e a porcentagem em relacao ao total de testes realizados.");
						puts("2 - Pessoas do sexo masculino menores de idade e o total de pessoas com esta caracteristica.");
						puts("3 - Pessoas do sexo feminino menores de idade e o total de pessoas com esta caracteristica.");
						puts("4 - Pessoas do sexo masculino idosas e o total de pessoas com esta caracteristica.");
						puts("5 - Pessoas do sexo feminino idosas e o total de pessoas com esta caracteristica.");
						puts("6 - Quantitativo total de pessoas que testaram positivo por cidade satelite.");
						puts("7 - Tipo de teste mais solicitado pelas pessoas.");
						puts("8 - Voltar ao menu principal.");
						scanf("%i", &opRelatorio);
						switch(opRelatorio){
							case 1:
								system("cls");
								puts("Todos os dados das pessoas que testaram positivo e a porcentagem em relacao ao total de testes realizados:");
								for(ind=0;ind<qtde;ind++){
									if(result[ind]=='P'){
										exibeDados(nome[ind], cartaoSUS[ind], idade[ind], sexo[ind], tipoTeste[ind], result[ind], cidade[ind]);
										contPos++;
									}
								}
								porcent=(contPos*100/total);
								printf("Porcentagem de pessoas que testaram positivo em relacao ao total de testes: %.2f%%\n", porcent);			
								system("pause");
								break;
							case 2:
								system("cls");
								puts("Pessoas do sexo masculino menores de idade e o total de pessoas com esta caracteristica:");
								for(ind=0;ind<qtde;ind++){
									if(sexo[ind]=='M' && idade[ind]<18){
										contMm++;
										exibeDadosMascMenor(nome[ind], idade[ind], cartaoSUS[ind], sexo[ind], tipoTeste[ind], result[ind], cidade[ind]);
									}
								}
								printf("Total de pessoas com esta caracteristica: %i\n", contMm);
								system("pause");
								break;
							case 3:
								system("cls");
								puts("Pessoas do sexo feminino menores de idade e o total de pessoas com esta caracteristica:");
								for(ind=0;ind<qtde;ind++){
									if(sexo[ind]=='F' && idade[ind]<18){
										contFm++;
										exibeDadosFemMenor(nome[ind], idade[ind], cartaoSUS[ind], sexo[ind], tipoTeste[ind], result[ind], cidade[ind]);
									}
								}
								printf("Total de pessoas com esta caracteristica: %i\n", contFm);
								system("pause");
								break;
							case 4:
								system("cls");
								puts("Pessoas do sexo masculino idosas e o total de pessoas com esta caracteristica:");
								for(ind=0;ind<qtde;ind++){
									if(sexo[ind]=='M' && idade[ind]>=60){
										contMi++;
										exibeDadosMascIdoso(nome[ind], idade[ind], cartaoSUS[ind], sexo[ind], tipoTeste[ind], result[ind], cidade[ind]);
									}
								}
								printf("Total de pessoas com esta caracteristica: %i\n", contMi);
								system("pause");
								break;
							case 5:
								system("cls");
								puts("Pessoas do sexo feminino idosas e o total de pessoas com esta caracteristica:");
								for(ind=0;ind<qtde;ind++){
									if(sexo[ind]=='F' && idade[ind]>=60){
										contFi++;
										exibeDadosFemIdoso(nome[ind], idade[ind], cartaoSUS[ind], sexo[ind], tipoTeste[ind], result[ind], cidade[ind]);
									}
								}
								printf("Total de pessoas com esta caracteristica: %i\n", contFi);
								system("pause");
								break;
							case 6:
								system("cls");
								puts("Quantitativo total de pessoas que testaram positivo por cidade satelite:");
								for(ind=0;ind<qtde;ind++){
									if(result[ind]=='P'){
										if(strcmp(cidade[ind],"Aguas Claras")==0){
											contAc++;
										}else{
											if(strcmp(cidade[ind],"Asa Norte")==0){
												contAn++;
											}else{
												if(strcmp(cidade[ind],"Asa Sul")==0){
													contAs++;
												}else{
													if(strcmp(cidade[ind],"Brazlandia")==0){
														contBr++;
													}else{
														if(strcmp(cidade[ind],"Ceilandia")==0){
															contCe++;
														}else{
															if(strcmp(cidade[ind], "Cruzeiro")==0){
																contCr++;
															}else{
																if(strcmp(cidade[ind], "Estrutural")==0){
																	contEs++;
																}else{
																	if(strcmp(cidade[ind], "Gama")==0){
																		contGa++;
																	}else{
																		if(strcmp(cidade[ind], "Guara")==0){
																			contGu++;
																		}else{
																			if(strcmp(cidade[ind], "Lago Norte")==0){
																				contLn++;
																			}else{
																				if(strcmp(cidade[ind], "Lago Sul")==0){
																					contLs++;
																				}else{
																					if(strcmp(cidade[ind], "Noroeste")==0){
																						contNo++;
																					}else{
																						if(strcmp(cidade[ind], "Nucleo Bandeirante")==0){
																							contNb++;
																						}else{
																							if(strcmp(cidade[ind], "Paranoa")==0){
																								contPa++;
																							}else{
																								if(strcmp(cidade[ind], "Planaltina")==0){
																									contPl++;
																								}else{
																									if(strcmp(cidade[ind], "Recanto das Emas")==0){
																										contRe++;
																									}else{
																										if(strcmp(cidade[ind], "Riacho Fundo I")==0){
																											contR1++;
																										}else{
																											if(strcmp(cidade[ind], "Riacho Fundo II")==0){
																												contR2++;
																											}else{
																												if(strcmp(cidade[ind], "Samambaia")==0){
																													contSa++;
																												}else{
																													if(strcmp(cidade[ind], "Santa Maria")==0){
																														contSm++;
																													}else{
																														if(strcmp(cidade[ind], "Sao Sebastiao")==0){
																															contSs++;
																														}else{
																															if(strcmp(cidade[ind], "Sobradinho")==0){
																																contSo++;
																															}else{
																																if(strcmp(cidade[ind], "Sudoeste")==0){
																																	contSu++;
																																}else{
																																	if(strcmp(cidade[ind], "Taguatinga")==0){
																																		contTa++;
																																	}else{
																																		contVp++;
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
								exibeQuantitativoCidades(contAc,contAn,contAs,contBr,contCe,contCr,contEs,contGa,contGu,contLn,contLs,contNo,contNb,contPa,contPl,contRe,contR1,contR2,contSa,contSm,contSs,contSo,contSu,contTa,contVp);
								system("pause");
								break;
							case 7:
								system("cls");
								puts("Tipo de teste mais solicitado pelas pessoas:");
								for(ind=0;ind<qtde;ind++){
									if(tipoTeste[ind]=='S'){
										contS++;
									}else{
										if(tipoTeste[ind]=='R'){
											contR++;
										}else{
											contT++;
										}
									}
								}
								exibeTipoTeste(tipoTeste[ind], contS, contR, contT);
								system("pause");
								break;
							default:
								printf("Opcao de relatorio invalida.\n");
							}
					}while(opRelatorio!=8);
					break;
				case 3:
					exit(1);
					break;
				default:
					puts("Opcao invalida.");
			}
		}while(ind<MAX);
	}while(op<=0 || op>3);
}

void leValidaNome(char nome[][20], int ind){
	do{
		printf("Digite o nome da %i%c pessoa:\n", ind+1, 166);
		fflush(stdin);
		gets(nome[ind]);
		if(strcmp(nome[ind],"")==0){
			printf("Campo obrigatorio.\n");
		}
	}while(strcmp(nome[ind],"")==0);
}

int leValidaCartao(int ind, int cartaoSUS[]){
	int cartao, ind2, validador;
	do{
		validador=0;
		printf("Digite o numero do cartao do SUS da %i%c pessoa:\n", ind+1, 166);
		scanf("%i", &cartao);
		if(cartao<=0){
			printf("Numero de cartao invalido.\n");
			validador=1;
		}else{
			for(ind2=0;ind2<ind;ind2++){
				if(cartaoSUS[ind2]==cartao){
					validador=1;
					printf("O numero do cartao do SUS nao pode ser repetido.\n");
					break;
				}
			}
		}
	}while(validador==1);
	return cartao;
}

int leValidaIdade(int ind){
	int idade;
	do{
		printf("Digite a idade da %i%c pessoa:\n", ind+1, 166);
		scanf("%i", &idade);
		if(idade<0){
			printf("Idade invalida.\n");
		}
	}while(idade<0);
	return idade;
}

char leValidaSexo(int ind){
	char sexo;
	do{
		printf("Digite o sexo da %i%c pessoa: M - Masculino ou F - Feminino\n", ind+1, 166);
		sexo=getche();
		sexo=toupper(sexo);
		if(sexo!='M' && sexo!='F'){
			printf("\nSexo invalido.\n");
		}
	}while(sexo!='M' && sexo!='F');
	return sexo;
}

char leValidaTeste(int ind){
	char tipoTeste;
	do{
		printf("\nDigite o tipo de teste realizado pela %i%c pessoa:\n", ind+1, 166);
		puts("S - Sorologia");
		puts("R - RT-PCR");
		puts("T - Teste Rapido");
		tipoTeste=getche();
		tipoTeste=toupper(tipoTeste);
		if(tipoTeste!='S' && tipoTeste!='R' && tipoTeste!='T'){
			printf("\nTipo de teste invalido.\n");
		}
	}while(tipoTeste!='S' && tipoTeste!='R' && tipoTeste!='T');
	return tipoTeste;
}

char leValidaResult(int ind){
	char result;
	do{
		printf("\nDigite o resultado do teste realizado pela %i%c pessoa: P - Positivo ou N - Negativo\n", ind+1, 166);
		result=getche();
		result=toupper(result);
		if(result!='P' && result!='N'){
			printf("\nResultado invalido.\n");
		}
	}while(result!='P' && result!='N');
	return result;
}

void leValidaCidade(char cidade[][20], int ind){
	int op;
	do{
		printf("\nSelecione a cidade satelite onde o teste foi realizado:\n");
		puts("1 - Aguas Claras");
		puts("2 - Asa Norte");
		puts("3 - Asa Sul");
		puts("4 - Brazlandia");
		puts("5 - Ceilandia");
		puts("6 - Cruzeiro");
		puts("7 - Estrutural");
		puts("8 - Gama");
		puts("9 - Guara");
		puts("10 - Lago Norte");
		puts("11 - Lago Sul");
		puts("12 - Noroeste");
		puts("13 - Nucleo Bandeirante");
		puts("14 - Paranoa");
		puts("15 - Planaltina");
		puts("16 - Recanto das Emas");
		puts("17 - Riacho Fundo I");
		puts("18 - Riacho Fundo II");
		puts("19 - Samambaia");
		puts("20 - Santa Maria");
		puts("21 - Sao Sebastiao");
		puts("22 - Sobradinho");
		puts("23 - Sudoeste");
		puts("24 - Taguatinga");
		puts("25 - Vicente Pires");
		scanf("%i", &op);
		switch(op){
			case 1:
				strcpy(cidade[ind], "Aguas Claras");
				break;
			case 2:
				strcpy(cidade[ind], "Asa Norte");
				break;
			case 3:
				strcpy(cidade[ind], "Asa Sul");
				break;
			case 4:
				strcpy(cidade[ind], "Brazlandia");
				break;
			case 5:
				strcpy(cidade[ind], "Ceilandia");
				break;
			case 6:
				strcpy(cidade[ind], "Cruzeiro");
				break;
			case 7:
				strcpy(cidade[ind], "Estrutural");
				break;
			case 8:
				strcpy(cidade[ind], "Gama");
				break;
			case 9:
				strcpy(cidade[ind], "Guara");
				break;
			case 10:
				strcpy(cidade[ind], "Lago Norte");
				break;
			case 11:
				strcpy(cidade[ind], "Lago Sul");
				break;
			case 12:
				strcpy(cidade[ind], "Noroeste");
				break;
			case 13:
				strcpy(cidade[ind], "Nucleo Bandeirante");
				break;
			case 14:
				strcpy(cidade[ind], "Paranoa");
				break;
			case 15:
				strcpy(cidade[ind], "Planaltina");
				break;
			case 16:
				strcpy(cidade[ind], "Recanto das Emas");
				break;
			case 17:
				strcpy(cidade[ind], "Riacho Fundo I");
				break;
			case 18:
				strcpy(cidade[ind], "Riacho Fundo II");
				break;
			case 19:
				strcpy(cidade[ind], "Samambaia");
				break;
			case 20:
				strcpy(cidade[ind], "Santa Maria");
				break;
			case 21:
				strcpy(cidade[ind], "Sao Sebastiao");
				break;
			case 22:
				strcpy(cidade[ind], "Sobradinho");
				break;
			case 23:
				strcpy(cidade[ind], "Sudoeste");
				break;
			case 24:
				strcpy(cidade[ind], "Taguatinga");
				break;
			case 25:
				strcpy(cidade[ind], "Vicente Pires");
				break;
			default:
				printf("Cidade invalida.\n");
		}	
	}while(op<=0 || op>25);
}

void exibeDados(char nome[], int cartaoSUS, int idade, char sexo, char tipoTeste, char result, char cidade[]){
	printf("Nome: %s\n", nome);
	printf("Numero do cartao do SUS: %i\n", cartaoSUS);
	printf("Idade: %i anos\n", idade);
	if(sexo=='M'){
		printf("Sexo: Masculino\n");
	}else{
		printf("Sexo: Feminino\n");
	}
	if(tipoTeste=='S'){
		printf("Tipo de teste realizado: Sorologia.\n");
	}else{
		if(tipoTeste=='R'){
			printf("Tipo de teste realizado: RT-PCR.\n");
		}else{
			printf("Tipo de teste realizado: Teste Rapido.\n");
		}
	}
	printf("Cidade onde o teste foi realizado: %s\n\n", cidade);
}

void exibeDadosMascMenor(char nome[], int idade, int cartaoSUS, char sexo, char tipoTeste, char result, char cidade[]){
	printf("Nome: %s\n", nome);
	printf("Numero do cartao do SUS: %i\n", cartaoSUS);
	printf("Idade: %i anos\n", idade);
	if(tipoTeste=='S'){
		printf("Tipo de teste realizado: Sorologia.\n");
	}else{
		if(tipoTeste=='R'){
			printf("Tipo de teste realizado: RT-PCR.\n");
		}else{
			printf("Tipo de teste realizado: Teste Rapido.\n");
		}
	}
	if(result=='P'){
		printf("Resultado do teste: Positivo.\n");
	}else{
		printf("Resultado do teste: Negativo.\n");
	}
	printf("Cidade onde o teste foi realizado: %s\n\n", cidade);
}

void exibeDadosFemMenor(char nome[], int idade, int cartaoSUS, char sexo, char tipoTeste, char result, char cidade[]){
	printf("Nome: %s\n", nome);
	printf("Numero do cartao do SUS: %i\n", cartaoSUS);
	printf("Idade: %i anos\n", idade);
	if(tipoTeste=='S'){
		printf("Tipo de teste realizado: Sorologia.\n");
	}else{
		if(tipoTeste=='R'){
			printf("Tipo de teste realizado: RT-PCR.\n");
		}else{
			printf("Tipo de teste realizado: Teste Rapido.\n");
		}
	}
	if(result=='P'){
		printf("Resultado do teste: Positivo.\n");
	}else{
		printf("Resultado do teste: Negativo.\n");
	}
	printf("Cidade onde o teste foi realizado: %s\n\n", cidade);
}

void exibeDadosMascIdoso(char nome[], int idade, int cartaoSUS, char sexo, char tipoTeste, char result, char cidade[]){
	printf("Nome: %s\n", nome);
	printf("Numero do cartao do SUS: %i\n", cartaoSUS);
	printf("Idade: %i anos\n", idade);
	if(tipoTeste=='S'){
		printf("Tipo de teste realizado: Sorologia.\n");
	}else{
		if(tipoTeste=='R'){
			printf("Tipo de teste realizado: RT-PCR.\n");
		}else{
			printf("Tipo de teste realizado: Teste Rapido.\n");
		}
	}
	if(result=='P'){
		printf("Resultado do teste: Positivo.\n");
	}else{
		printf("Resultado do teste: Negativo.\n");
	}
	printf("Cidade onde o teste foi realizado: %s\n\n", cidade);
}

void exibeDadosFemIdoso(char nome[], int idade, int cartaoSUS, char sexo, char tipoTeste, char result, char cidade[]){
	printf("Nome: %s\n", nome);
	printf("Numero do cartao do SUS: %i\n", cartaoSUS);
	printf("Idade: %i anos\n", idade);
	if(tipoTeste=='S'){
		printf("Tipo de teste realizado: Sorologia.\n");
	}else{
		if(tipoTeste=='R'){
			printf("Tipo de teste realizado: RT-PCR.\n");
		}else{
			printf("Tipo de teste realizado: Teste Rapido.\n");
		}
	}
	if(result=='P'){
		printf("Resultado do teste: Positivo.\n");
	}else{
		printf("Resultado do teste: Negativo.\n");
	}
	printf("Cidade onde o teste foi realizado: %s\n\n", cidade);
}

void exibeQuantitativoCidades(int contAc,int contAn,int contAs,int contBr,int contCe,int contCr,int contEs,int contGa,int contGu,int contLn,int contLs,int contNo,int contNb,int contPa,int contPl,int contRe,int contR1,int contR2,int contSa,int contSm,int contSs,int contSo,int contSu,int contTa,int contVp){
	printf("Aguas Claras: %i pessoas.\n", contAc);	
	printf("Asa Norte: %i pessoas.\n", contAn);
	printf("Asa Sul: %i pessoas.\n", contAs);
	printf("Brazlandia: %i pessoas.\n", contBr);
	printf("Ceilandia: %i pessoas.\n", contCe);
	printf("Cruzeiro: %i pessoas.\n", contCr);
	printf("Estrutural: %i pessoas.\n", contEs);
	printf("Gama: %i pessoas.\n", contGa);
	printf("Guara: %i pessoas.\n", contGu);
	printf("Lago Norte: %i pessoas.\n", contLn);
	printf("Lago Sul: %i pessoas.\n", contLs);
	printf("Noroeste: %i pessoas.\n", contNo);
	printf("Nucleo Bandeirante: %i pessoas.\n", contNb);
	printf("Paranoa: %i pessoas.\n", contPa);
	printf("Planaltina: %i pessoas.\n", contPl);
	printf("Recanto das Emas: %i pessoas.\n", contRe);
	printf("Riacho Fundo I: %i pessoas.\n", contR1);
	printf("Riacho Fundo II: %i pessoas.\n", contR2);
	printf("Samambaia: %i pessoas.\n", contSa);
	printf("Santa Maria: %i pessoas.\n", contSm);
	printf("Sao Sebastiao: %i pessoas.\n", contSs);
	printf("Sobradinho: %i pessoas.\n", contSo);
	printf("Sudoeste: %i pessoas.\n", contSu);
	printf("Taguatinga: %i pessoas.\n", contTa);
	printf("Vicente Pires: %i pessoas.\n", contVp);
}

void exibeTipoTeste(char tipoTeste, int contS, int contR, int contT){
	if(contS>contR && contS>contT){
		printf("Sorologia.\n");
		printf("Realizada %i vezes.\n", contS);
	}else{
		if(contS==contR && contR>contT){
			printf("Sorologia e RT-PCR foram os mais solicitados.\n");
			printf("Ambos foram realizados %i vezes.\n", contS);
		}else{
			if(contS==contT && contT>contR){
				printf("Sorologia e Teste Rapido foram os mais solicitados.\n");
				printf("Ambos foram realizados %i vezes.\n", contS);
			}else{
				if(contR>contS && contR>contT){
					printf("RT-PCR.\n");
					printf("Realizado %i vezes.\n", contR);
				}else{
					if(contR==contT && contT>contS){
						printf("RT-PCR e Teste Rapido foram os mais solicitados.\n");
						printf("Ambos foram realizados %i vezes.\n", contR);
					}else{
						if(contT>contS && contT>contR){
							printf("Teste Rapido.\n");
							printf("Realizado  %i vezes.\n", contT);
						}else{
							printf("Todos os testes foram solicitados na mesma quantidade.\n");
							printf("Foram realizados %i vezes.\n", contS);
						}
					}
				}
			}
		}
	}
}
