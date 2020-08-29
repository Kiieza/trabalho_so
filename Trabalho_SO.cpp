#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int quant = 30;
int contador = 9;
int prioridade = 10;
int inicio = 0;

struct processo
{
    int prioridadeOriginal = 0;
    int prioridadeDinamica = 0;
    int tempo = 0;
    int status = 1;
};
struct processo p[9];

int inicializa()
{
    int pri[] = {3, 2, 5, 8, 3, 1, 1, 4, 6, 1};
    int temp[] = {300, 250, 100, 200, 250, 150, 100, 200, 300, 200};

    for (int x = 0; x < 10; x++)
    {

        p[x].prioridadeOriginal = pri[x];
        p[x].prioridadeDinamica = pri[x];
        p[x].tempo = temp[x];
    }
    return 0;
}
void round_robbin()
{
    int contador = 9;
    int inicio = 0;
    while (contador != 0)
    {
        while (&p[inicio] <= 0)
        {
            inicio++;
            if (inicio >= 9)
            {
                inicio = 0;
            }
        }
        if (p[inicio].tempo > 0 && p[inicio].status == 1)
        {
            printf("\n\nO processo %d vai para o inicio da fila com %d ms", inicio, p[inicio].tempo);
            printf("\nExecuta ate %d ms", quant);
            p[inicio].tempo = p[inicio].tempo - quant;
            if (p[inicio].tempo <= 0)
            {
                p[inicio].status = 2;
                printf("\nE sai da fila.\n");
                contador--;
            }
            else
            {
                printf("\nE vai para o final da fila com %d ms.\n\n", p[inicio].tempo);
            }
            system("pause");
        }
        inicio++;
        if (inicio > 9)
        {
            inicio = 0;
        }
    }
}
void processa()
{
    printf("\n\nO processo %d vai para o inicio da fila com %d ms", inicio, p[inicio].tempo);
    printf("\nExecuta ate %d ms", quant);
    p[inicio].tempo = p[inicio].tempo - quant;
    if (p[inicio].tempo <= 0)
    {
        p[inicio].status = 2;
        printf("\nE sai da fila.\n");
        contador--;
    }
    else
    {
        printf("\nE vai pro final da fila com %d ms.\n\n", p[inicio].tempo);
    }
}
void priord()
{
    while (contador != 0)
    {
        while (&p[inicio] <= 0)
        {
            inicio++;
            if (inicio >= 9)
            {
                inicio = 0;
            }
        }
        if (p[inicio].tempo > 0 && p[inicio].status == 1)
        {
            if (p[inicio].prioridadeDinamica == 10)
            {
                processa();
                p[inicio].prioridadeDinamica == p[inicio].prioridadeOriginal;
            }
            else
            {
                p[inicio].prioridadeDinamica++;

                printf("\n\nProcesso %d", inicio);

                printf("\nIgnorando processo, sua prioridade vai para: %d\n\n", p[inicio].prioridadeDinamica);

                inicio++;
                if (inicio > 9)
                {
                    inicio = 0;
                }
            }
            system("pause");
        }
        inicio++;
        if (inicio > 9)
        {
            inicio = 0;
        }
    }
    cout << "\n\n :::: Fim :::: \n";
}
int main()
{
    int op = 10;
    inicializa();
    do
    {
        cout << "Metodos para escalonamento:";
        cout << "\n[1] - Escalonamento Round-Robbin";
        cout << "\n[2] - Escalonamento de Prioridade Dinamica\n";
        cout << "\n\nEscolha o metodo = ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "\nVoce selecionou = Round-Robbin";
            round_robbin();
            break;
        case 2:
            cout << "\nVoce selecionou = Prioridade Dinamica";
            priord();
            break;
        case 0:
            break;
        }
    } while (op != 0);
    getchar();
    return 0;
}
