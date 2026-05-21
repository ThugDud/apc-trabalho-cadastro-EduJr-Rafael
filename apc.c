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

    struct Jogo {
        int id;
        char nome[100];
    };

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

    struct Jogo biblioteca[12] = {
        {1, "Fallout: New Vegas (XBOX 360)"},
        {2, "The Legend of Zelda: Tears of The Kingdom (NINTENDO SWITCH 2)"},
        {3, "Half Life (PC)"},
        {4, "Paper Mario The Thousand-Year Door (NINTENDO SWITCH 2)"},
        {5, "Mother 2: Earthbound (SNES)"},
        {6, "Lego Batman: The legacy of the dark knight"},
        {7, "Chrono Trigger (SNES)"},
        {8, "Mario kart World (NINTENDO SWITCH 2)"},
        {9, "Dark Souls: Remastered (XBOX SERIES S/X)"},
        {10, "Super Mario Galaxy 1+2 (NINTENDO SWITCH 2)"},
        {11, "Team Fortress 2 (PC)"},
        {12, "The Legend of Zelda: Ocarina of Time (NINTENDO SWITCH 2)"}
    };
    
    // Print do login
    printf("Ola, seja bem vindo a loja 'A link to the future' \n");
    printf("Entre com o seu login: \n");
    printf("Nome: ");

    char nome_temp[100] = {};

    scanf("%[^\n]", nome_temp);
    while(getchar() != '\n');
    strcpy(p1.nome, nome_temp);

    printf("Senha: ");

    char senha_temp[50] = {};

    scanf("%s", senha_temp);
    while(getchar() != '\n');
    strcpy(p1.senha, senha_temp);

    printf("Idade: ");
    scanf("%d", &p1.idade);
    while(getchar() != '\n');
    printf("\n\n===============================\n");
    printf("  Login feito com sucesso!\n");
    printf("===============================\n\n");

    char senha_censurada[50];

    for (int i = 0; p1.senha[i] != '\0'; i++){
        senha_censurada[i] = '*';
        senha_censurada[i+1] = '\0';
    }

    printf("Nome cadastrado: %s\n", p1.nome);
    printf("Senha cadastrada: %s\n", senha_censurada);
    printf("Idade cadastrada: %d anos\n\n", p1.idade);

    // menu principal
    
    int escolha = 0;

    while(escolha != -1){
        printf("Bem vindo ao alugel de jogos \"A link to the future\"\n");
        printf("1. Listar Jogos\n");
        printf("2. Cadastrar Jogo\n");
        printf("3. Buscar Jogo por ID\n");
        printf("4. Atualizar Jogo\n");
        printf("5. Remover Jogo\n");
        printf("-1. Sair do Sistema\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        //menu listar jogos

        switch (escolha) {
            case 1: // Listar jogos

                printf("\nBiblioteca de jogos para se alugar: \n");

                for(int i = 0; i < 12; i++) {
                    printf("%d - %s\n", biblioteca[i].id, biblioteca[i].nome);
                }
                break;
                
            case 2: //cadastrar jogo
                
            printf("Escolha um jogo para alugar: \n");
               
                int escolher_jogo;
                scanf("%d", &escolher_jogo);
                    
                switch (escolher_jogo) {
                        
                    case 1:
                        printf("Você escolheu: Fallout: New Vegas (XBOX 360)\n");
                        if(p1.carrinho[0][1] > 0){
                            int sobrescrever;
                            printf("Você ja tem esse jogo no carrinho, sobrescrever? (0 ou 1): ");
                            scanf("%d", &sobrescrever);
                            
                            if (sobrescrever == 1){
                                printf("Escolha de sobrescrever!\n");
                            } else if(sobrescrever == 0){
                                break;
                            } else {
                                printf("Input invalido");
                                break;
                            }
                        }
                        int unidades;
                        printf("Quantas unidades você quer: ");
                        scanf("%d", &unidades);
                        p1.carrinho[0][1] = unidades;

                }
                break;
            case 3: //buscar jogo

                break;
            case 4: //atualizar jogo
                printf("Voce escolheu: Paper Mario The Thousand-Year Door (NINTENDO SWITCH 2)\n"); 
                break;
            case 5: //remover jogo
                printf("Voce escolheu: Mother 2: Earthbound (SNES)\n"); 
                break;
            default:
                printf("Escolha inexistente\n");
                break;
        }
    }

    return 0;
}