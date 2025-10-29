#include <stdio.h>
#include <string.h>

int main()
{
    int z = 0;
    int erros = 0;
    int max_tentativas = 6;
    int acertou = 0; // Flag booleana (0 ou 1)
    int enforcou = 0; // Flag booleana (0 ou 1)
    
    char tentativas;
    char LetrasErradas[20];
    char palavra_secreta[7] = "LOGICA";
    char display[7] = "______";
    int tamanho = strlen(palavra_secreta);

    while (!acertou && !enforcou)
    {
        display[tamanho] = '\0';
        printf("%s\n", display);
    
        printf("Escolhe uma letra: ");
        scanf(" %c", &tentativas);
        
        int x = 0;
        for(int i = 0; i < tamanho; i++)
        {
            if(palavra_secreta[i] == tentativas)
            {
                display[i] = tentativas;
                x++;
            }
        }
        
        if(x == 0)
        {
            erros++;
        
            LetrasErradas[z] = tentativas;
            z++;
            LetrasErradas[z] = '\0';
        }
        
        printf("Tentativas: %s\n", LetrasErradas);
        
        printf("Erros: ");
        for(int i = 0; i < erros; i++)
        {
            printf("*");
        }
        printf("\n");
        
        if(erros == tamanho)
        {
            printf("Enforcou!");
            enforcou = 1;
        } else if(strcmp(display, palavra_secreta) == 0)
        {
            printf("Você Ganhou!");
            acertou = 1;
        }
        
        // 1. Mostrar estado (forca, display, letras tentadas)
        // 2. Pedir entrada (chute do usuário)
        // 3. Processar entrada (verificar acerto, erro ou repetição)
        // 4. Atualizar estado (incrementar erros, atualizar display)
        // 5. Verificar condições de término (acertou = 1? enforcou = 1?)
    }

    return 0;
}
