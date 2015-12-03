#include <stdio.h>
#include <string.h>
typedef struct identificador{
	char nomeIdentificador[20];
	char valor[20];
}identificador;

void verificaDiretivaEqu(char linha[], identificador *id, int *count_id){
	char *inst, *verifica_str, p1[20], tmp[20];
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
		else
			printf("Instrucao nao reconhecida!\n");
	}
}

int main(int argc, char *argv[]){
	FILE *pArquivo = fopen(argv[1],"rt");
	char linha[30];
	identificador id[100];
	int count_id=0, i;

	if(argc!=2){
		printf("use: monta <arquivo_de_entrada>\n");
		return 0;
	}
	while(!feof(pArquivo)){
		fgets(linha, sizeof(linha), pArquivo);
		verificaDiretivaEqu(linha,id,&count_id);
	}
	for(i=0;i<count_id;i++){
		printf("Nome do Identificador: %s\t|Valor do Identificador: %s", id[i].nomeIdentificador, id[i].valor);
	}
	fclose(pArquivo);
	printf("\n");
	return 0;
}
