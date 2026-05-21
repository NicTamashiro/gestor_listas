#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestor_listas.h"

void limpar_tela(){
#ifdef _WIN32 
    system("cls");
#else 
    system("clear");
#endif
}

void linhas(char ch, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%c", ch);
    }
    printf("\n");
}

void cabecalho(char * texto){
    int tamanho = strlen(texto) + 4;

    printf("\n");
    linhas('*', tamanho);
    printf("  %s  \n", texto);
    linhas('*', tamanho);
    printf("\n");

}

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void aguardar(){
    printf("Pressione ENTER para continuar...");
    limpar_buffer();
}

int ler_inteiro(){
    int opcao, valido;
    do {
        valido = (scanf("%d", &opcao) == 1 && opcao >= 0 && opcao <=6);
        limpar_buffer();
        if(!valido){
            printf("Entrada invalida. Digite entre \"0 e 6\"!\n\n");
        }
    } while(!valido);
    return opcao;
}

void criar_lista(){
    FILE * fp;
    char nomearq[50];

    printf("\nQual o nome do arquivo que deseja criar: <nomearq.txt>\n");
    scanf("%s", nomearq);
    limpar_buffer();
    fp = fopen(nomearq, "w");

    if(fp == NULL){
        printf("Erro ao criar o arquivo '%s'\n", nomearq);
        return;
    }

    printf("\nArquivo '%s' criado com sucesso!\n\n", nomearq);

    aguardar();

    fclose(fp);

}

void remover_lista(){
    char nomearq[50];

    printf("\nQual o nome do arquivo que deseja remover: <nomearq.txt>\n");
    scanf("%s", nomearq);
    limpar_buffer();

    if(remove(nomearq) == 0){
        printf("\nArquivo removido com sucesso!\n\n");
    } else {
        printf("\nErro ao apagar arquivos.\n");
    }

    aguardar();

}

void renomear_lista(){
    char nome_antigo[50];
    char nome_novo[50];

    printf("\nQual o nome do arquivo que deseja renomear: <nomearq.txt>\n");
    scanf("%s", nome_antigo);
    limpar_buffer();
    printf("\nQual o sera o novo nome do arquivo '%s': <nomearq.txt>\n", nome_antigo);
    scanf("%s", nome_novo);
    limpar_buffer();

    if(rename(nome_antigo, nome_novo) == 0){
        printf("\nArquivo renomeado com sucesso! ('%s') -> ('%s')\n", nome_antigo, nome_novo);
    } else {
        printf("\nErro ao renomear arquivo '%s'\n", nome_antigo);
    }

    aguardar();
    
}

void adicionar_item(){

    char lista[50];
    char item[150];

    printf("\nQual lista deseja adicionar um item: <nomearq.txt>\n");
    scanf(" %s", lista);
    limpar_buffer();
    printf("\nQual item deseja adicionar? \n");
    scanf(" %149[^\n]", item);
    limpar_buffer();

    FILE * fp;

    if((fp = fopen(lista, "r")) == NULL){
        printf("Erro: arquivo nao encontrado.\n");
        aguardar();
    } else {
        int count = 0;
        char linha[200];
        while(fgets(linha, sizeof(linha), fp) != NULL){
            count++;
        }
        fclose(fp);

        fp = fopen(lista, "a");

        fprintf(fp, "%d. %s\n", count + 1, item);
        fclose(fp);

        printf("\nItem adicionado com sucesso!\n\n");
        aguardar();
    }

}

void remover_item(){
    char lista[50];
    char item[150];
    
    printf("\nQual lista deseja remover um item: <nomearq.txt>\n");
    scanf(" %s", lista);
    limpar_buffer();
    
    FILE * fp;
    
    if((fp = fopen(lista, "r")) == NULL){
        printf("Erro: arquivo nao encontrado.\n");
        aguardar();
    } else {
        int count = 1;
        char linha[200];
        while(fgets(linha, sizeof(linha), fp) != NULL){
            printf("%s\n", linha);
            count++;
        }

        fclose(fp);

        int remover;
        printf("\nQual linha deseja remover: ");
        scanf("%d", &remover);
        limpar_buffer();

        fp = fopen(lista, "r");

        FILE *temp = fopen("temp.txt", "w");

        int contador = 1;
        while(fgets(linha,sizeof(linha), fp) != NULL){
            if(contador != remover){
                fprintf(temp, "%s", linha);
            }
            contador++;
        }
       
        fclose(fp);
        fclose(temp);

        remove(lista);
        rename("temp.txt", lista);

        printf("\nItem removido com sucesso!\n\n");
        aguardar();
    }
}

void ver_lista(){
    char lista[50];
    printf("\nQual lista deseja ver o conteudo? \n");
    scanf("%s", lista);
    limpar_buffer();
    
    FILE * fp;
    
    fp = fopen(lista, "r");
    if(fp == NULL){
        printf("Erro: arquivo nao encontrado.\n");
        return;
    }
    
    char linha[200];
    if(fgets(linha, sizeof(linha), fp) == NULL){
        printf("Lista vazia!\n");
    } else {
        printf("%s", linha);

        while(fgets(linha, sizeof(linha), fp) != NULL){
            printf("%s", linha);
        }
    }

    fclose(fp);

    aguardar();
}


int menu(){
    limpar_tela();
    cabecalho("GESTOR DE LISTAS");
    printf("  [1] Criar Lista\n");
    printf("  [2] Remover Lista\n");
    printf("  [3] Renomear Lista\n");
    printf("  [4] Adicionar item a uma lista\n");
    printf("  [5] Remover item de uma lista\n");
    printf("  [6] Ver conteudo de uma lista\n");
    printf("  [0] Sair\n\n");
    printf("Escolha uma opcao: ");
    int opcao = ler_inteiro();

    return opcao;
}

int main(){
    int opcao;

    do {
        opcao = menu();

        switch (opcao){
            case 1:
                criar_lista();
                break;
            case 2:
                remover_lista();
                break;
            case 3:
                renomear_lista();
                break;
            case 4:
                adicionar_item();
                break;
            case 5:
                remover_item();
                break;
            case 6:
                ver_lista();
                break;
            case 0:
                limpar_tela();
                printf("Encerrando o sistema. Ate logo!\n\n");
                break;
        }
            
    } while (opcao != 0);

    return 0;
}