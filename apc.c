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
        int carrinho[12][2];
    };

    struct Login p1 = {};
    
    for(int i = 0; i < 12; i++) {
        p1.carrinho[i][0] = i + 1;
        p1.carrinho[i][1] = 0;
    }
    
    // Print do login
    printf("Ola, seja bem vindo a loja 'A link to the future' \n");
    printf("Entre com o seu login: \n");
    printf("Nome: ");

    char nome_temp[100] = {};

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
    printf("\n\n===============================\n");
    printf("  Login feito com sucesso!\n");
    printf("===============================\n\n");

    char senha_censurada[50];

    for (int i = 0; i < 50; i++){
        if(p1.senha[i]){
            senha_censurada[i] = '*';
        }
    }

    printf("Nome cadastrado: %s\n", p1.nome);
    printf("Senha cadastrada: %s\n", senha_censurada);
    printf("Idade cadastrada: %d anos\n\n", p1.idade);

    // Print aluguel
    
    int escolha = 0;

    printf("Bem vindo ao alugél de jogos \"A link to the future\"");
    printf("1. Listar Jogos\n");
    printf("2. Cadastrar Jogo\n");
    printf("3. Buscar Jogo por ID\n");
    printf("4. Atualizar Jogo\n");
    printf("5. Remover Jogo\n");
    printf("6. Sair do Sistema\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: 
            printf("Biblioteca de jogos para se alugar: \n");
            printf("1 - Fallout: New Vegas (XBOX 360) \n" );
            printf("2 - The Legend of Zelda: Tiers of The Kingdom (NINTENDO SWITCH 2) \n" );
            printf("3 - Half Life (PC) \n" );
            printf("4 - Paper Mario The Thousand-Year Door (NINTENDO SWITCH 2) \n" );
            printf("5 - Mother 2: Earthbound (SNES) \n" );
            printf("6 - Lego Batman: The legacy of the dark knight \n" );
            printf("7 - Chrono Trigger (SNES) \n" );
            printf("8 - Mario kart World (NINTENDO SWITCH 2) \n" );
            printf("9 - Dark Souls: Remastered (XBOX SERIES S/X)\n" );
            printf("10 - Super Mario Galaxy 1+2 (NINTENDO SWITCH 2) \n" );
            printf("11 - Team Fortress 2 (PC) \n" );
            printf("12 - The Legend of Zelda: Ocarina of Time (NINTENDO SWITCH 2) \n" );
            printf("Escolha um jogo para alugar: \n");
            break;
        case 2: 
            printf("Voce escolheu: The Legend of Zelda: Tears of The Kingdom (NINTENDO SWITCH 2)\n"); 
            break;
        case 3: 
            printf("Voce escolheu: Half Life (PC)\n"); 
            break;
        case 4: 
            printf("Voce escolheu: Paper Mario The Thousand-Year Door (NINTENDO SWITCH 2)\n"); 
            break;
        case 5: 
            printf("Voce escolheu: Mother 2: Earthbound (SNES)\n"); 
            break;
        case 6: 
            printf("Voce escolheu: Lego Batman: The legacy of the dark knight\n"); 
            break;
        case 7: 
            printf("Voce escolheu: Chrono Trigger (SNES)\n"); 
            break;
        case 8: 
            printf("Voce escolheu: Mario kart World (NINTENDO SWITCH 2)\n"); 
            break;
        case 9: 
            printf("Voce escolheu: Dark Souls: Remastered (XBOX SERIES S/X)\n"); 
            break;
        case 10: 
            printf("Voce escolheu: Super Mario Galaxy 1+2 (NINTENDO SWITCH 2)\n"); 
            break;
        case 11: 
            printf("Voce escolheu: Team Fortress 2 (PC)\n"); 
            break;
        case 12: 
            printf("Voce escolheu: The Legend of Zelda: Ocarina of Time (NINTENDO SWITCH 2)\n"); 
            break;
        default: 
            printf("Opcao invalida! Por favor, escolha um numero de 1 a 12.\n"); 
            break;
    }

    // Opção

    return 0;
}