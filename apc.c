#include <stdio.h>
#include <string.h>
#include <math.h>

    // struct Pessoa {
    //     char nome[50];
    //     int idade;
    //     float altura;
    // };

    // struct Pessoa p1;

    // p1.idade = 12;
    // p1.altura = 1.70;
    // strcpy(p1.nome, "Carlos");

    // printf("Nome: %s\n", p1.nome);
    // printf("idade: %d\n", p1.idade);
    // printf("altura: %f\n", p1.altura);
   

int main() {

    // Variaveis
    struct Login {
        char nome[100];
        char senha[50];
        int idade;
    };

    struct Login p1;

    // Print do login
    printf("Ola, seja bem vindo a loja 'A link to the future' \n");
    printf("Entre com o seu login: \n");
    printf("Nome: ");

    char nome_temp[50] = {};

    scanf("%[^\n]s", nome_temp);
    while(getchar() != '\n');
    strcpy(p1.nome, nome_temp);

    printf("Senha: ");

    char senha_temp[50] = {};

    scanf("%[^\n]s", senha_temp);
    while(getchar() != '\n');
    strcpy(p1.senha, senha_temp);

    printf("Idade: ");
    scanf("%d", &p1.idade);
    while(getchar() != '\n');
    printf("\nLogin feito com sucesso!\n\n");

    printf("nome = %s\nsenha = %s\n idade = %d", p1.nome, p1.senha, p1.idade);

    // Print aluguel

    // Opção

    return 0;
}