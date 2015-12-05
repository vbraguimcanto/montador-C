#include <stdio.h>
#include <string.h>
typedef struct identificador{
	char nomeIdentificador[20];
	char valor[20];
}identificador;

void selecionaOpcode(char linha[]){
	int p;
	char *inst, *tmp;
	FILE *arquivoSaida;
	arquivoSaida = fopen("saida.opc","a+");
	if(strcmp("HLT",linha)==0 || strcmp("hlt",linha)==0){
		fprintf(arquivoSaida,"f4h\n");
	}
	else if(strcmp("RET",linha)==0 || strcmp("ret",linha)==0){
		fprintf(arquivoSaida,"c3h\n");
	}
	else{
		inst = (char*) strtok(linha," ");
		if(strcmp("MOV", inst)==0 || strcmp("mov", inst)==0){
			inst = (char*) strtok(NULL,",");
			if(inst[0]==91){
				//printf("a2h\n");
				fputs("a2h\n",arquivoSaida);
				for(p=0;p<strlen(inst);p++){
					if(inst[p]!=91 && inst[p]!=93)
						fprintf(arquivoSaida,"%c", inst[p]);
				}
				fprintf(arquivoSaida,"\n");
			}
			else{
				inst = (char*) strtok(NULL,"\0");
				//MOV A,[2]
				if(inst[0]==91){
					//printf("a0h\n");
					fprintf(arquivoSaida,"a0h\n");
					for(p=0;p<strlen(inst);p++){
						if(inst[p]!=91 && inst[p]!=93)
							fprintf(arquivoSaida,"%c", inst[p]);
					}

				}
				//MOV A,2
				else{
					//printf("b0h\n");
					fprintf(arquivoSaida,"b0h\n");
					for(p=0;p<strlen(inst);p++){
						if(inst[p]!=91 && inst[p]!=93)
							fprintf(arquivoSaida,"%c", inst[p]);
					}

				}
			}
		}
		else if(strcmp("ADD", inst)==0 || strcmp("add", inst)==0){
			inst = (char*) strtok(NULL,",");
			inst = (char*) strtok(NULL,"\0");
			if(inst[0]==91){
				fprintf(arquivoSaida,"02h\n");
				for(p=0;p<strlen(inst);p++){
					if(inst[p]!=91 && inst[p]!=93)
						fprintf(arquivoSaida,"%c", inst[p]);
				}
			}
			else{
				fprintf(arquivoSaida,"04h\n");
				for(p=0;p<strlen(inst);p++){
					fprintf(arquivoSaida,"%c", inst[p]);
				}
			}
		}
		else if(strcmp("SUB", inst)==0 || strcmp("sub", inst)==0){
			inst = (char*) strtok(NULL,",");
			inst = (char*) strtok(NULL,"\0");
			if(inst[0]==91){
				fprintf(arquivoSaida,"2ah\n");
				for(p=0;p<strlen(inst);p++){
					if(inst[p]!=91 && inst[p]!=93)
						fprintf(arquivoSaida,"%c", inst[p]);
				}
			}
			else{
				fprintf(arquivoSaida,"2ch\n");
				for(p=0;p<strlen(inst);p++){
					fprintf(arquivoSaida,"%c", inst[p]);
				}
			}
		}
		else if(strcmp("CMP", inst)==0 || strcmp("cmp", inst)==0){
			inst = (char*) strtok(NULL,",");
			inst = (char*) strtok(NULL,"\0");
			if(inst[0]==91){
				fprintf(arquivoSaida,"3ah\n");
				for(p=0;p<strlen(inst);p++){
					if(inst[p]!=91 && inst[p]!=93)
						fprintf(arquivoSaida,"%c", inst[p]);
				}
			}
			else{
				fprintf(arquivoSaida,"3ch\n");
				for(p=0;p<strlen(inst);p++){
					fprintf(arquivoSaida,"%c", inst[p]);
				}
			}
		}
		else if(strcmp("JMP", inst)==0 || strcmp("jmp", inst)==0){
			inst = (char*) strtok(NULL,"\0");
			//printf("ebh\n");
			fprintf(arquivoSaida,"ebh\n");
			fprintf(arquivoSaida,"%s", inst);
		}
		else if(strcmp("JC", inst)==0 || strcmp("jc", inst)==0){
			inst = (char*) strtok(NULL,"\0");
			//printf("72h\n");
			fprintf(arquivoSaida,"72h\n");
			fprintf(arquivoSaida,"%s", inst);
		}
		else if(strcmp("JNC", inst)==0 || strcmp("jnc", inst)==0){
			inst = (char*) strtok(NULL,"\0");
			//printf("73h\n");
			fprintf(arquivoSaida,"73h\n");
			fprintf(arquivoSaida,"%s", inst);
		}
		else if(strcmp("JZ", inst)==0 || strcmp("jz", inst)==0){
			inst = (char*) strtok(NULL,"\0");
			//printf("74h\n");
			fprintf(arquivoSaida,"74h\n");
			fprintf(arquivoSaida,"%s", inst);
		}
		else if(strcmp("JNZ", inst)==0 || strcmp("jnz", inst)==0){
			inst = (char*) strtok(NULL,"\0");
			//printf("75h\n");
			fprintf(arquivoSaida,"75h\n");
			fprintf(arquivoSaida,"%s", inst);
		}
		else if(strcmp("JBE", inst)==0 || strcmp("jbe", inst)==0){
			inst = (char*) strtok(NULL,"\0");
			//printf("76h\n");
			fprintf(arquivoSaida,"76h\n");
			fprintf(arquivoSaida,"%s", inst);
		}
		else if(strcmp("JA", inst)==0 || strcmp("ja", inst)==0){
			inst = (char*) strtok(NULL,"\0");
			//printf("77h\n");
			fprintf(arquivoSaida,"77h\n");
			fprintf(arquivoSaida,"%s", inst);
		}
		else if(strcmp("CALL", inst)==0 || strcmp("call", inst)==0){
			inst = (char*) strtok(NULL,"\0");
			//printf("e8h\n");
			fprintf(arquivoSaida,"e8h\n");
			fprintf(arquivoSaida,"%s", inst);
		}
	}
	fclose(arquivoSaida);	
	return;
}

void verificaDiretivaEqu(char linha[], identificador *id, int *count_id){
	char *inst, *verifica_str, p1[20], tmp[20];
	if(strcmp(linha,"HLT")==0 || strcmp(linha,"hlt")==0){
		return;
	}
	if(strcmp(linha,"RET")==0 || strcmp(linha,"ret")==0){
		return;
	}
	else{
		inst = (char*) strtok(linha," ");
		strcpy(p1,inst); 
		inst = (char*) strtok(NULL,"\0");
		strcpy(tmp,inst);
		if(strlen(tmp)>3 && tmp[3]==' '){
			verifica_str = (char*) strtok(tmp," ");
			if(strcmp(verifica_str,"EQU")==0){
				strcpy(id[*count_id].nomeIdentificador,p1);
				verifica_str = (char*) strtok(NULL,"\0");
				strcpy(id[*count_id].valor,verifica_str);
				(*count_id)++;
			}
		}
	}
}

int main(int argc, char *argv[]){
	FILE *pArquivo = fopen(argv[1],"rt");
	FILE *pArquivo_2 = fopen(argv[1],"rt");
	FILE *pArquivoSaida = fopen("saida.opc","a+");
	char linha[30];
	identificador id[100];
	int count_id=0, i, j=1;

	if(argc!=2){
		printf("use: monta <arquivo_de_entrada>\n");
		return 0;
	}
	while(!feof(pArquivo)){
		fgets(linha, sizeof(linha), pArquivo);
		if(strlen(linha)>1){ 
			verificaDiretivaEqu(linha,id,&count_id);
		}
	}
	// Início da 2ª Verificação no Arquivo - Conversão de Linguagem de Montagem para Opcode
	while(!feof(pArquivo_2)){
		if(j>count_id){
			fgets(linha, sizeof(linha), pArquivo_2);
			if(strlen(linha)>1)  
				selecionaOpcode(linha);
		}
		else
			fgets(linha, sizeof(linha), pArquivo_2);
		j++;
	}
	printf("\n");
	fclose(pArquivo);
	fclose(pArquivo_2);
	fclose(pArquivoSaida);
	printf("Parte 1:\n");
	for(i=0;i<count_id;i++){
		printf("Nome do Identificador: %s\t||\tValor do Identificador: %s", id[i].nomeIdentificador, id[i].valor);
	}
	printf("\n");
	return 0;
}
