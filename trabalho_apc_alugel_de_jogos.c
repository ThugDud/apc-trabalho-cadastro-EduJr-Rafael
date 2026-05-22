#include <stdio.h>
#include <string.h>


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
        int carrinho[100][2];
    };

    struct Login p1 = {};
    
    for(int i = 0; i < 100; i++) {
        p1.carrinho[i][0] = i + 1;
        p1.carrinho[i][1] = 0;
    }

    struct Jogo biblioteca[100] = {
        {1, "Fallout: New Vegas "},
        {2, "The Legend of Zelda: Tears of The Kingdom "},
        {3, "Half Life "},
        {4, "Paper Mario The Thousand-Year Door "},
        {5, "Mother 2: Earthbound "},
        {6, "Lego Batman: The legacy of the dark knight"},
        {7, "Chrono Trigger "},
        {8, "Mario kart World "},
        {9, "Dark Souls: Remastered "},
        {10, "Super Mario Galaxy 1+2 "},
        {11, "Team Fortress 2 "},
        {12, "The Legend of Zelda: Ocarina of Time "}
    };

    int qtd_jogos = 12;
    
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

    while(1){
        printf("Idade: ");
        scanf("%d", &p1.idade);
        while(getchar() != '\n');
        
        if(p1.idade < 1){
            printf("\nIdade invalida\n\n");
        } else {
            break;
        }

    }
 
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
        printf("\nBem vindo ao alugel de jogos \"A link to the future\"\n");
        printf("1. Listar Jogos\n");
        printf("2. Cadastrar Jogo no carrinho\n");
        printf("3. Buscar Jogo por ID\n");
        printf("4. Ver carrinho\n");
        printf("5. Remover Jogo do carrinho\n"); 
        printf("6. [ADMIN] Adicionar jogo na biblioteca da loja\n"); 
        printf("7. [ADMIN] Remover jogo na biblioteca da loja\n"); 
        printf("8. [ADMIN] Atualizar jogo na biblioteca da loja\n"); 
        printf("-1. Sair do Sistema\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        while(getchar() != '\n');

        //menu listar jogos

        switch (escolha) {
            case 1: // Listar jogos

                printf("\nBiblioteca de jogos para se alugar: \n");

                for(int i = 0; i < qtd_jogos; i++) {
                    printf("%d - %s\n", biblioteca[i].id, biblioteca[i].nome);
                }
                break;
                
            case 2: //cadastrar jogo
                 
                printf("\nEscolha um jogo para alugar: ");
               
                int escolher_jogo;
                int encontrado = 0;

                scanf("%d", &escolher_jogo);
                while(getchar() != '\n');
                
                for (int i = 0; i < qtd_jogos; i++) {
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

                    for (int i = 0; i < qtd_jogos; i++) {
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

            case 4: //Ver carrinho
                
                printf("\n======== carrinho =============");

                for (int i = 0; i < qtd_jogos; i++){
                    if(p1.carrinho[i][1] > 0){
                        printf("\n%d - %s: %d", biblioteca[i].id, biblioteca[i].nome, p1.carrinho[i][1]);
                    }
                }

                printf("\n===============================\n\n");
                break;
             

             case 5: // remover jogo do carrinho
                { 
                    int id_delete;
                    int removido = 0;
                    
                    printf("Digite o ID do jogo que deseja remover: ");
                    scanf("%d", &id_delete);
                    while(getchar() != '\n'); 

                    for (int i = 0; i <qtd_jogos; i++) {
                        if (biblioteca[i].id == id_delete) {
                            printf("ID: %d\n", biblioteca[i].id);
                            printf("Nome: %s\n", biblioteca[i].nome);
                            
                            int quantidade_remover;
                            printf("Quantidade atual no carrinho: %d\n", p1.carrinho[i][1]);
                            printf("Quantas unidades deseja remover: ");
                            scanf("%d", &quantidade_remover);
                            while(getchar() != '\n');

                            if (quantidade_remover < 0) {
                                printf("Nao eh possivel remover uma quantidade negativa!\n");
                                break; // Sai do loop sem alterar nada
                            }

                            p1.carrinho[i][1] = p1.carrinho[i][1] - quantidade_remover;

                            if (p1.carrinho[i][1] < 0) {
                                p1.carrinho[i][1] = 0;
                                printf("Nota: Voce removeu mais unidades do que tinha. O carrinho foi zerado.\n");
                            }

                            printf("Carrinho atualizado: %d\n", p1.carrinho[i][1]);
                            removido = 1; 
                            break; 
                        }
                    }

                    if (removido == 1) {
                        printf("\nJogo removido do carrinho.\n");
                    }
                    else {
                        printf("\nErro: Jogo com o ID %d nao foi encontrado no carrinho. :(\n", id_delete);
                    }
                } 
                break;

            case 6: // [ADMIN] Adicionar jogo na biblioteca da loja
                if (qtd_jogos >= 100) {
                    printf("\nErro: Limite de armazenamento da loja atingido (Max: 100).\n");
                    break;
                }

                char novo_nome[100];
                int nome_duplicado = 0;

                printf("\n--- [ADMIN] Cadastrar Novo Jogo na Loja ---\n");
                printf("Digite o nome do jogo: ");
                scanf("%[^\n]", novo_nome);
                while(getchar() != '\n');

                for (int i = 0; i < qtd_jogos; i++) {
                    if (strcasecmp(biblioteca[i].nome, novo_nome) == 0) {
                        nome_duplicado = 1;
                        break;
                    }
                }

                if (nome_duplicado) {
                    printf("Erro: Ja existe um jogo cadastrado com o nome '%s'.\n", novo_nome);
                } else {
                    int novo_id = qtd_jogos + 1;
                    
                    biblioteca[qtd_jogos].id = novo_id;
                    strcpy(biblioteca[qtd_jogos].nome, novo_nome);

                    p1.carrinho[qtd_jogos][0] = novo_id;
                    p1.carrinho[qtd_jogos][1] = 0;

                    qtd_jogos++;
                    printf("\nNovo jogo adicionado na loja com sucesso.\n");
                }
                break;

 case 7: // [ADMIN] Remover jogo na biblioteca da loja 
                if (qtd_jogos == 0) {
                    printf("\nErro: Nao ha jogos cadastrados para remover.\n");
                    break;
                }

                int id_remover_loja;
                int remover_da_loja = 0;
                printf("\n--- [ADMIN] Remover Jogo da Loja ---\n");
                printf("Digite o ID do jogo que dejesa remover do sistema: ");
                scanf("%d", &id_remover_loja);
                while(getchar() != '\n');

                for (int i = 0; i < qtd_jogos; i++) {
                    if (biblioteca[i].id == id_remover_loja) {
                        remover_da_loja = 1;
                        printf("Removendo o jogo: %s\n", biblioteca[i].nome);

                        for (int j = i; j < qtd_jogos - 1; j++) {
                            biblioteca[j] = biblioteca[j + 1];
                            p1.carrinho[j][0] = p1.carrinho[j + 1][0];
                            p1.carrinho[j][1] = p1.carrinho[j + 1][1];
                        }    

                        qtd_jogos--; 

                        for (int k = 0; k < qtd_jogos; k++) {
                            biblioteca[k].id = k + 1;
                            p1.carrinho[k][0] = k + 1;
                        }
                        
                        p1.carrinho[qtd_jogos][1] = 0;
                        
                        printf("Jogo deletado do sistema com sucesso!\n");
                        break;
                    }
                }

                if(!remover_da_loja) {
                    printf("Erro: Jogo com o ID %d nao foi encontrado na loja.\n", id_remover_loja);
                }
                break;

            case -1: //sair do sistema
                printf("\nVoce esta saindo do sistema, muito obrigado por usar 'A link to the future'!\n");
                break;

            default:
                printf("Escolha inexistente\n");
                break;
        }
    }

    printf("\nPrograma encerrado com sucesso\n");

    return 0;
}