// SUMULAÇÃO DE BANCO - DARM LAB'S
// Obs1: Programa Feito em 3 dias, pois o email estava em spam então não recebi o link do projeto no começo
// Obs2: Programa não funciona muito bem em compiladores de site (avisando caso ele seja testado em um)
// Obs3: Programa testado apenas em Linux

// versão 3.0
// • Default (feito)
// • case 4 (feito)
// • case 3 (base feita - improvisada; detalhes em processo)


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 

typedef struct {
	char nome [60+1];
	char numero [19+1];
	char cvc [3+1];
	char valid [6+1];	
	char tipo_cartao [19+1];
	char bandeira [16+1];
} cartao;
cartao cartoes [6];

typedef struct {
    char nome [60+1];
    char email [40+1];
    char cpf [11+1];
    char telefone [11+1];
    char senha [6+1];
    char tipo_conta [8+1];
} cadastro;
cadastro cadastros [20];

void listar_cartoes (int qtd_cartoes) {
	for (int cont = 0; cont < qtd_cartoes; cont++) {
		system ("clear");
		printf ("\nCartão n°%d \n", cont+1);
		printf (" Nome: %s \n Número: %s \n CVC: %s \n Valid: %s \n Tipo: %s \n Bandeira: %s \n", cartoes [cont].nome, cartoes [cont].numero, cartoes [cont].cvc, cartoes [cont].valid, cartoes [cont].tipo_cartao, cartoes [cont].bandeira);		
	}
}

int main() {
    int opcao;
    int qtd_contas = 0;
    int qtd_cartoes = 0;
    
    //qtd_contas = 2;
    
    while (opcao != 5) { // MENU PRINCIPAL //
    	system ("clear");
    	
    	printf ("[ BANCO - DARM LAB'S ]\n\n");
        printf ("[1] Nova conta \n[2] Login \n[3] Criar cartão \n[4] Listar cartões \n[5] Sair \nEscolha a opção que deseja: ");
        scanf ("%d", &opcao);
        
        system ("clear");
        
        switch (opcao) {
        	case 1: {
        		strcpy (cadastros [0].nome, "teste");
			    strcpy (cadastros [0].email, "teste@gmail.com");
			    strcpy (cadastros [0].cpf, "12312312345");
			    strcpy (cadastros [0].telefone, "85912341234");
			    strcpy (cadastros [0].senha, "123456");
			    strcpy (cadastros [0].tipo_conta, "Corrente");
        		
        		break;
        	} case 2: {
        		
        		
        		break;
        	} case 3: { // CRIA CARTÃO //
        		char scan_nome [60+1];
				char scan_numero [19+1];
				char scan_cvc [3+1];
				int scan_valid;
				int scan_tipo_cartao;
				int scan_bandeira;
				
				char valids [4][6+1] = {"2 anos", "4 anos", "5 anos", "6 anos"};
				char tipos_cartao [5][19+1] = {"Crédito", "Débito", "Poupança", "Crédito e débito", "Poupança e débito"};
				char bandeiras [5][16+1] = {"Visa", "MasterCard", "Elo", "HiberCard", "American Express"};				
				
        		while (opcao != 0) {                    
                    if (qtd_cartoes > 5) {                                                                        
                        printf ("Você só pode cadastrar até 6 cartões");
                        
                        printf ("\n |Digite qualquer coisa para sair \n |");
                    	//scanf ("%d", &opcao);
                    	getchar ();
                    	
                    	system ("clear");
                        break;
                    }                                       
                    printf ("|Nome completo \n|");
                    scanf ("%60[^\n]s", scan_nome);
                    setbuf (stdin, NULL);
                    
                    printf ("\n|Número da conta (Digite sem espaços) \n|");
                    scanf ("%16s", scan_numero);           
                    setbuf (stdin, NULL);
                    
                    printf ("\n|CVC (3 dígitos) \n|");             
                    scanf ("%3s", scan_cvc);
                    setbuf (stdin, NULL);  
                    
                    printf ("\n|Validade (Escolha uma das opções) \n|[1] 2 anos \n|[2] 4 anos \n|[3] 5 anos \n|[4] 6 anos \n|");
                    scanf ("%d", &scan_valid);
                    setbuf (stdin, NULL);
                    
                    printf ("\n|Tipo do cartão (Escolha uma das opções) \n|[1] Crédito \n|[2] Débito \n|[3] Poupança \n|[4] Crédito e débito \n|[5] Poupança e débito \n|");
                    scanf ("%d", &scan_tipo_cartao);
                    setbuf (stdin, NULL);
                    
                    printf ("\n|Identificação/bandeira (Escolha uma das opções) \n|[1] Visa \n|[2] MasterCard \n|[3] Elo \n|[4] HiberCard \n|[5] American Express \n|");
                    scanf ("%d", &scan_bandeira);                    
                    setbuf (stdin, NULL);
                    
                    //printf ("\n%s \n%s \n%s \n%d \n%d \n%d \n", scan_nome, scan_numero, scan_cvc, scan_valid, scan_tipo_cartao, scan_bandeira);                                     
                    
                    strcpy (cartoes [qtd_cartoes].nome, scan_nome);
                    strcpy (cartoes [qtd_cartoes].numero, scan_numero);
                    strcpy (cartoes [qtd_cartoes].cvc, scan_cvc);
                    strcpy (cartoes [qtd_cartoes].valid, valids [scan_valid-1]);
                    strcpy (cartoes [qtd_cartoes].tipo_cartao, tipos_cartao [scan_tipo_cartao-1]);
                    strcpy (cartoes [qtd_cartoes].bandeira, bandeiras [scan_bandeira-1]);                                    
                                       
                    //printf ("\nCartão n°%d \n", qtd_cartoes+1);
                    //printf (" Nome: %s \n Número: %s \n CVC: %s \n Valid: %s \n Tipo: %s \n Bandeira: %s \n", cartoes [qtd_cartoes].nome, cartoes [qtd_cartoes].numero, cartoes [qtd_cartoes].cvc, cartoes [qtd_cartoes].valid, cartoes [qtd_cartoes].tipo_cartao, cartoes [qtd_cartoes].bandeira);
                    
                    qtd_cartoes++; // Aumenta até 6 //
                    
                    listar_cartoes (qtd_cartoes);
                    
                    printf ("\n| Digite 0 para voltar \n| Ou outro valor para criar outro cartão \n| ");
                    scanf ("%d", &opcao);
                    
                    if (opcao != 0) {	    				
	    				system ("clear");	    				
	    			}
            	}
                break;            
            } case 4: {
            	if (qtd_cartoes != 0) {
            		listar_cartoes (qtd_cartoes);
            	}
            	else {
            		printf (" - Lista vazia -\n");    		
            	}
            	printf ("\n| Digite qualquer coisa para voltar ao menu \n| ");
            	getchar ();
            	
            	break;
            } case 5: {
            	
            	break;
            } default: {
            	printf (" - OPÇÃO INVÁLIDA -\n");
            	printf ("\n| Digite qualquer coisa para voltar ao menu \n| ");
            	getchar ();
            	
            	break;
            }
        }
    }    
    return 0;
}
