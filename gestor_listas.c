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
        printf("Arquivo removido com sucesso!\n\n");
    } else {
        printf("Erro ao apagar arquivos.\n");
    }

    aguardar();

}

void renomear_lista(){
    return;
}

void adicionar_item(){
    return;
}

void remover_item(){
    return;
}

void ver_lista(){
    return;
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