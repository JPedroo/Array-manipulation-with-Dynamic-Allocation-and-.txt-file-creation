#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Função ordenar(). Ordena o vetor de forma crescente e cria o arquivo ordenado.txt com os dados do vetor ordenados.
int ordenar (int *vet, int n){

    FILE *arquivo2;
    arquivo2 = fopen("ordenado.txt","w");

    if (arquivo2==NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO DE GRAVAÇÃO DOS DADOS!\n");
        return 0;
    }

    int i,j,aux;

    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if (vet[j]<vet[i]){
                aux = vet[j];
                vet[j]= vet[i];
                vet[i]= aux;

            }
        }
    }

    printf("\n\nVetor crescente:{");
        for (i=0;i<n;i++){
            printf(" %d ",vet[i]);
            fprintf(arquivo2,"   %d",vet[i]);
        }
    printf("}");

    printf("\n\nVALORES ORDENADOS COM SUCESSO NO ARQUIVO ORDENADO.TXT!\n\n");
    fclose(arquivo2);
}

/*Função dados(). Aloca memória do vetor dinamicamente, armazena os dados do vetor e cria o dados.txt com os dados armazenados no mesmo.
Vale ressaltar que a função dados() chama a função ordenar() que organiza os valores do vetor de forma crescente. e grava-os em um .txt*/
int dados (){

    FILE *arquivo;
    arquivo = fopen("dados.txt","w");

    if (arquivo==NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO DE GRAVAÇÃO DOS DADOS!");
        return 0;
    }
    
    int n,i,j,aux;
    int *vet;

    printf("\n\nQual o tamanho do vetor a ser alocado? ");
     scanf("%d",&n);

    if ((vet=(int *) malloc(n)) == NULL){
        printf("\nMEMÓRIA INSUFICIENTE!");
        exit(1);
    }

        for (i=0;i<n;i++){
            printf("\nDigite o valor do vetor na posição %d: ",i+1);
            scanf("%d",&vet[i]);
            fprintf(arquivo,"   %d",vet[i]);
    }

    printf("\n\nVetor:{");
        for (i=0;i<n;i++)
            printf(" %d ",vet[i]);
    printf("}");
        
    printf("\n\nVALORES ARMAZENADOS COM SUCESSO NO ARQUIVO DADOS.TXT!");
    fclose(arquivo);

    ordenar(vet,n); 
    free(vet);
}

//Função main(). Chama a função dados(), essa responsável por alocar a memória dinamicamente e armazenar os dados no vetor e no arquivo.
int main(){

    setlocale (LC_ALL,"Portuguese");
    printf("====================Prova de Lab 2 – Exercício de Alocação Dinâmica e Manipulação de Arquivos====================\nAlunos: Bruno Martins Costa, Gustavo Peres Borges da Silva, João Pedro Pereira de Freitas, Miguel Affiune Carneiro");

    dados();
    
    system("pause");
}


