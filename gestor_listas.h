#ifndef GESTOR_LISTAS_H
#define GESTOR_LISTAS_H
 
void limpar_tela();
void limpar_buffer();
void aguardar();
 
void linhas(char ch, int tamanho);
void cabecalho(char *texto);
 
int ler_inteiro();
 
void criar_lista();
void remover_lista();
void renomear_lista();
void adicionar_item();
void remover_item();
void ver_lista();
 
int menu();
 
#endif