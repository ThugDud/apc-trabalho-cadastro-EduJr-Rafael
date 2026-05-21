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
                 
                printf("\nEscolha um jogo para alugar: ");
               
                int escolher_jogo;
                int encontrado = 0;

                scanf("%d", &escolher_jogo);
                while(getchar() != '\n');
                
                for (int i = 0; i < 12; i++) {
                    if (biblioteca[i].id == escolher_jogo) {
                        printf("Voce escolheu %s!\n", biblioteca[i].nome);
                        
                        if(p1.carrinho[i][1] > 0){
                            int substituir;
                            printf("Voce ja possui esse jogo no carrinho, quer sobrescrever? (1 ou 0): ");
                            scanf("%d", &substituir);
                            while(getchar() != '\n');

                            if(substituir == 1){
                                printf("Voce escolheu substituir!\n\n");
                            } else if(substituir == 0) {
                                break;
                            } else {
                                printf("Comando invalido\n");
                                break;
                            }
                        }
                        
                        int holder_quantidade;
                        printf("\nescolha a quantidade de unidades para %s: ", biblioteca[i].nome);
                        scanf("%d", &holder_quantidade);
                        while(getchar() != '\n');

                        if(holder_quantidade < 0){
                            printf("ta tentando comprar unidades negativas?\n");
                            break;
                        }

                        p1.carrinho[i][1] = holder_quantidade;
                        encontrado = 1;

                        printf("\nID: %d\n", biblioteca[i].id);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Carrinho: %d\n", p1.carrinho[i][1]);
                        

                        break; 
                    } else {
                        continue;
                    }
                }

                if (encontrado == 1) {
                    printf("\nBusca finalizada com sucesso.\n\n");
                }
                else {
                    printf("\nErro: Jogo com o ID %d nao foi encontrado. :(\n", escolher_jogo);
                }

                break;

            case 3: // buscar jogo
                { 
                    int id_busca;
                    int encontrado = 0;
                    
                    printf("Digite o ID do jogo que deseja buscar: ");
                    scanf("%d", &id_busca);
                    while(getchar() != '\n'); 

                    for (int i = 0; i < 12; i++) {
                        if (biblioteca[i].id == id_busca) {
                            printf("\nJogo Encontrado.\n");
                            printf("ID: %d\n", biblioteca[i].id);
                            printf("Nome: %s\n", biblioteca[i].nome);
                            printf("Carrinho: %d\n", p1.carrinho[i][1]);
                            encontrado = 1; 
                            break; 
                        }
                        else {
                            continue;
                        }
                    }

                    if (encontrado == 1) {
                        printf("\nBusca finalizada com sucesso.\n");
                    }
                    else {
                        printf("\nErro: Jogo com o ID %d nao foi encontrado. :(\n", id_busca);
                    }
                } 
                break;

            case 4: //atualizar jogo
                printf("Voce escolheu: Paper Mario The Thousand-Year Door (NINTENDO SWITCH 2)\n"); 
                break;

            case 5: // remover jogo
                { 
                    int id_delete;
                    int removido = 0;
                    
                    printf("Digite o ID do jogo que deseja remover: ");
                    scanf("%d", &id_delete);
                    while(getchar() != '\n'); 

                    for (int i = 0; i < 12; i++) {
                        if (biblioteca[i].id == id_delete) {
                            printf("ID: %d\n", biblioteca[i].id);
                            printf("Nome: %s\n", biblioteca[i].nome);
                            p1.carrinho[i][1] = 0;
                            printf("Carrinho: %d\n", p1.carrinho[i][1]);
                            removido = 1; 
                            break; 
                        }
                    }

                    if (removido == 1) {
                        printf("\nJogo removido da sua biblioteca.\n");
                    }
                    else {
                        printf("\nErro: Jogo com o ID %d nao foi encontrado na sua biblioteca. :(\n", id_delete);
                    }
                } 
                break; 

            default:
                printf("Escolha inexistente\n");
                break;
        }
    }

    return 0;
}