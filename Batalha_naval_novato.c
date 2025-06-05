#include <stdio.h>
//imprimir o tabuleiro 
void imprimirtabuleiro(char tabuleiro[10][10]){
    printf("\n   ");
    for (int c = 0; c < 10 ; c++){//Colunas
        printf(" %d ", c);
    }
    printf("\n");

    for(int l = 0; l < 10; l++){//Linhas
        printf("%2d", l);
        for (int c = 0;c < 10; c++){
            printf(" %c ", tabuleiro[l][c]);
        }
        printf("\n");
    }
}

//ler e validar coordenadas 
int lercoordenadas(char *tipo){
    int valor; 
    do{
        printf("Digite a %s (0 a 9 ): ", tipo);
        scanf("%d", &valor);
        if (valor < 0 || valor > 9 ){
            printf("Valor invalido! Tente novamente. \n");
        }
    } while (valor < 0 || valor > 9);
    return valor;
}

int main(){

    char tabuleiro [10][10];
    int menu1, linha, coluna; 

    //inicializar matriz com '-' "agua"
    for(linha = 0; linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            tabuleiro[linha][coluna]='-';
        }
    }
    
    do{
    printf("\n***BATALHA NAVAL***\n");
    printf("Esolha uma das opções: \n");
    printf("1 - Ver as Regras\n");
    printf("2 - Ver o Mapa \n");
    printf("3 - Esconder os Navios \n");
    printf("4 - Sair\n");
    scanf("%d", &menu1);

    switch(menu1){
        case 1:
            printf("\n***REGRAS***\n");
            printf("Você vai ter que esconder dois navios do mesmo tamanho um na vertical e outro na horizontal.\n");
            printf("Navio na vertical (3 posições na mesma coluna)\n");
            printf("Navio na horizontal (3 posições na mesma linha)\n");
            break;
        case 2: 
            printf("\n***MAPA ATUAL***\n");
            imprimirtabuleiro(tabuleiro);
            break;     
        case 3: {
            printf("\n---POSICIONAL O NAVIO DA VERTICAL---\n");
            int l1 = lercoordenadas ("linha inicial");
            int c1 = lercoordenadas ("coluna");

            //Verificando se há espaço para o navio sem sair da matriz 
            if(l1 > 7){
                printf("Não há espaço para o navio vertical nessa posiseção. Tente uma linha mais acima. \n");
                break;
            }
             tabuleiro[l1][c1]= 'V';
             tabuleiro[l1 + 1][c1]= 'V';
             tabuleiro[l1 + 2][c1]= 'V';

             printf("\n---POSICIONAR NAVIO NA HORIZONTAL---\n");
             int l2 = lercoordenadas ("linnha");
             int c2 = lercoordenadas("coluna inicial");

             if (c2 > 7 ){
                printf("Não jhá espaço para o navio horizontla nessa posição. Tente uma coluna mais à esquerda.\n");
                break;
             }
             tabuleiro[l2][c2]= 'H';
             tabuleiro[l2][c2 + 1]= 'H';
             tabuleiro[l2][c2 + 2]= 'H';

             printf("\nNavios posicionados com sucesso 1\n");
            imprimirtabuleiro(tabuleiro);
            break;
        }

        case 4:
            printf("Saindo do jogo. Foi um prazer até logo :) !\n");
            break;

            default:
            printf("\nOpção Invalida. Tente novamente. \n");
    }

} while (menu1 != 4);

    return 0; 
}
