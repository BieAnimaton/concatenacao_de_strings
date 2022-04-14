#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char *concatena(char *primeira_string, char *segunda_string) {
    char *frase_final = NULL;
    int tamanho1, tamanho2, i;

    tamanho1 = strlen(primeira_string);
    tamanho2 = strlen(segunda_string);

    frase_final = malloc((tamanho1 + tamanho2 + 1) * sizeof(char));

    for (i = 0; i < tamanho1; i++) {
        frase_final[i] = primeira_string[i];
    }
    for (i = 0; i < tamanho2; i++) {
        frase_final[i + tamanho1] = segunda_string[i];
    }

    frase_final[tamanho1 + tamanho2] = '\0';
    return frase_final;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    char primeira_string[100], segunda_string[100], *frase_final;

    fgets(primeira_string, 100, stdin);
    primeira_string[strlen(primeira_string)-1] = ' ';

    fgets(segunda_string, 100, stdin);
    segunda_string[strlen(segunda_string)-1] = ' ';

    frase_final = concatena(primeira_string, segunda_string);

    printf("\n%s\n", frase_final);
    free(frase_final);

    return 0;
}
