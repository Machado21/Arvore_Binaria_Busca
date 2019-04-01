#include "Arvore_Bin_Busca.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main() {

    Arv_bin *arv_bin1 = arv_cria(NULL);
    int x = 0;
    printf("\nQuais das Opcoes deseja Fazer:\n");
    do {
        printf("=================================\n"
               "| 1 - Inserir Valor na Arvore   |\n"
               "| 2 - Remover Valor da Arvore   |\n"
               "| 3 - Imprimir Arvore           |\n"
               "| 4 - Liberar Arvore            |\n"
               "| 0 - Sair                      |\n"
               "=================================\n");
        scanf("%d", &x);
        switch (x) {
            case 1:
                printf("\n1 - Inserir Valor na Arvore.\n");
                printf("Caso queira sair Digite um Espaço\n");
                char a;
                do {
                    scanf("%c", &a);
                    insere(arv_bin1, a);
                } while (a!=' ');
                break;
            case 2:
                printf("\n2 - Remover Valor na Arvore.\n");
                char r;
                scanf("%c", &r);
                arv_remove(arv_bin1, r);
                break;
            case 3:
                printf("\n3 - Imprimir Arvrore.\n");
                inprime_escolhendo_ordem(arv_bin1);
                break;
            case 4:
                printf("\n4 - Liberar Arvore.\n");
                arv_libera(arv_bin1);
                break;
            default:
                printf("Opcao invalida, Tente de 1 a 4 : \n");
                Sleep(3000);
                system("cls");
                break;
        }
    } while (x != 0);

    printf("\n");

    return 0;
}