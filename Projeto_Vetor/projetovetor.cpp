/*  Projeto Vetor - Fixar Operações Básicas entre Vetores

    Opções Disponíveis:

    1- Buscar pela primeira ocorrência de um valor (retornar a posição) - FEITO;
    2- Busca para contar a quantidade de ocorrências que um valor aparece - FEITO;
    3- Busca para contar a quantidade de ocorrências de valores de um intervalo - FEITO;
    4- Inverter os valores de um vetor - FEITO;
    5- Excluir um valor informado pelo usuário (se existir) deslocando os valores para à esquerda (“não deixar buracos”);
    6- Retirar todos os valores repetidos.
    
    *É importante que o programa tenha um menu que possibilite ao usuário realizar qualquer uma dessas operações conforme sua vontade
*/

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

const int TAM = 10;

int main(){
    int vet[TAM], i = 0, j = 0, aux = 0, num_escolhido;

    srand(time(NULL));

    //Gerar Vetor Original
    for(i = 0; i < TAM; i++){
        vet[i] = 1 + rand() %10;
    }

    cout << endl;

    //Exibir Vetor Original
    for(i = 0; i < TAM; i++){
        cout << " " << vet[i];
    }

    //Inverter Vetor
    for(i = 0; i < TAM / 2; i++){
        j = TAM - i - 1;
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        
    }
    

    cout << endl;

    //Exibir Vetor Invertido
    for(i = 0; i < TAM; i++){
        cout << " " << vet[i];
    }

    //Buscar a primeira ocorrência de um valor no Vetor
    int num_pos = 0;
    cout << endl << "Digite o número cujo quer encontrar a 1º ocorrência no vetor: ";
    cin >> num_escolhido;

    //Tomei a liberdade de somar 1 a posição com o intuito de facilitar a experiência do usuário final, trocando a exibição posição 0 para posição 1
    for(i = 0; i < TAM; i++){
        if(num_escolhido == vet[i]){
            
            num_pos = i + 1;
            break;
        }
    }
    
    //Exibir a posição onde ocorre a primeira apraição do número escolhido no vetor (caso ele apareça)
    if(num_pos != 0){
        cout << endl << "O número " << num_escolhido << " apareceu pela primeira vez na " << num_pos << "º posição do vetor";
    }else{
        cout << endl << "O número escolhido não apareceu nenhuma vez no vetor";
    }
    
    //Buscar a quantidade de vezes que um determinado valor aparece no vetor
    int qtd_num = 0;
    cout << endl << "Insira o número que deseja conferir as aparições dentro do vetor: ";
    cin >> num_escolhido;

    for(i = 0; i < TAM; i++){
        if(num_escolhido == vet[i]){
            qtd_num++;
        }
    }

    //Exibir a quantidade de vezes que um valor aparece dentro do vetor (se ele aparecer)
    if(qtd_num > 0){
        cout << "O valor " << num_escolhido << " apareceu " << qtd_num << " vezes no vetor";
    }else{
        cout << "O valor escolhido não apareceu no vetor";
    }

    //Busca para contar a quantidade de ocorrências de valores de um intervalo dentro do vetor
    int i_intervalo = 0;
    int f_intervalo = 0;
    int qtd_i = 0;

    cout << endl << "Digite o início do intervalo desejado: ";
    cin >> i_intervalo;
    cout << endl << "Digite o fim do intervalo: ";
    cin >> f_intervalo;

    for(i = 0; i < TAM; i++){
        if(vet[i] >= i_intervalo && vet[i] <= f_intervalo){
            qtd_i++;
        }
    }

    //Exibir a quantidade de vezes que números dentro do intervalo selecionado aparecem no vetor (caso apareçam)
    if(qtd_i > 0){
        cout << endl << "Números dentro do intervalo selecionado aparecem " << qtd_i << " vezes no vetor";
    }else{
        cout << endl << "Nenhum número dentro do intervalo selecionado aparece no vetor";
    }

    return 0;
}