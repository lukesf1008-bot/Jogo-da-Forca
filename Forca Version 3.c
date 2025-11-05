#include <stdio.h>
#include <string.h>
#include <ctype.h>   // Para converter letras
#include <stdlib.h>  // Para aleatoriedade
#include <time.h>    // Para aleatoriedade

int main()
{
    srand(time(NULL)); // Inicializa gerador de números aleatórios
    int indice_aleatorio = rand() % 10; // Sorteia índice de 0 a 9

    // ⚠️ As palavras precisam estar entre aspas duplas (" "), não simples (' ')
    char palavras[10][15] = {
        "CASA", "BOLA", "NAVIO", "FLAMINGO", "PARAFUSO",
        "PINGUIM", "PATO", "CHARRETE", "FORMULA", "TRENA"
    };

    int z = 0;
    int erros = 0;
    int max_tentativas = 6;
    int fim = 0; // Flag de controle do jogo

    char *palavra_secreta = palavras[indice_aleatorio];
    char tentativas;
    char LetrasErradas[7] = ""; // até 6 tentativas erradas + '\0'
    int tamanho = strlen(palavra_secreta);
    char display[tamanho + 1]; // +1 para o caractere nulo

    // Inicializa o display com underscores
    for (int i = 0; i < tamanho; i++) {
        display[i] = '_';
    }
    display[tamanho] = '\0';

    while (!fim)
    {
        printf("\nPalavra: %s\n", display);
        printf("Letras erradas: %s\n", LetrasErradas);

        printf("Escolha uma letra: ");
        scanf(" %c", &tentativas);
        tentativas = toupper(tentativas); // Converte para maiúscula

        int acertos = 0;

        for (int i = 0; i < tamanho; i++)
        {
            if (palavra_secreta[i] == tentativas)
            {
                display[i] = tentativas;
                acertos++;
            }
        }

        if (acertos == 0)
        {
            // Letra errada
            if (strchr(LetrasErradas, tentativas) == NULL) {
                LetrasErradas[z++] = tentativas;
                LetrasErradas[z] = '\0';
                erros++;
            } else {
                printf("Você já tentou essa letra!\n");
            }
        }
        
        printf("Tentativas: %s\n", LetrasErradas);
        
        printf("Erros: ");
        for(int i = 0; i < erros; i++)
        {
            printf("*");
        }
        printf("\n");

        // Verifica se perdeu
        if (erros >= max_tentativas)
        {
            printf("\nVocê foi enforcado! A palavra era: %s\n", palavra_secreta);
            fim = 1;
        }
        // Verifica se ganhou
        else if (strcmp(display, palavra_secreta) == 0)
        {
            printf("\nParabéns! Você acertou a palavra: %s\n", palavra_secreta);
            fim = 1;
        }
    }

    return 0;
}
