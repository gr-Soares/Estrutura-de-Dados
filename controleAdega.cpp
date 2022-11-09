#include <iostream>
#include <iomanip>
#include <locale.h>

#if defined(__MINGW32__) || defined(_MSC_VER)
#define limparBuffer() fflush(stdin)
#define limparTela() system("cls")
#define pause() system("pause")
#else
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#define limparTela() system("clear")
#define limparBuffer() __fpurge(stdin)
#define pause() system("read")
#endif

using namespace std;

const int N = 50;

struct node
{
    int id;
    string nome;
    int ano;
    int qtde;
    float valor;
};

node list[N];

int final;
node val;
bool sinal;
char conf;

void populate();
node leitura();
void insFim(node novoNode);
void insCom(node novoNode);
void insPosK(int k, node novoNode);
void remFim();
void remIni();
void remPosK(int k);
void editar(int k);
node buscaId(int id);
node buscaNome(string nome);
node buscaValor(float valor);
int posPorId(int id);
void imprime();
void imprimeNode(node nodeImpr);
void ordenaId();
void ordenaAno();
void ordenaValor();
void ordenaQtde();
void consultaId();
void consultaNome();
void imprimeValor();
void imprimeQuantidade();
void imprimeAno();
void menu();
void menuInserir();
void menuRemover();
void menuBusca();
void menuOrdenar();
void menuConsulta();
void menuImprimir();
void menuOutros();
void noAntPosK(int k);
void buscaNomeInsAnt(string nome);
void altPosK2(int k);
void altAnt(int id);
void buscaValorRem(float valor);

int main()
{
    setlocale(LC_ALL,"");
    populate();
    menu();
}

void populate()
{
    final = -1;
    sinal = false;
    int qtde = 5;
    node produtos[qtde] = {
        1, "Coppo Barbera d'Asti Camp du Rouss", 2017, 6, 331.09,
        2, "Masi Masianco Pinot Grigio e Verduzzo delle Venezie", 2020, 12, 233.00,
        3, "Salentein Reserve Merlot", 2019, 10, 159.00,
        4, "Boya Syrah", 2017, 4, 179.64,
        5, "Condado de Haza Crianza", 2018, 4, 331.12};
    for (int i = 0; i < qtde; i++)
    {
        conf = 'S';
        insFim(produtos[i]);
    }
    if (sinal)
    {
        cout << "Lista iniciada com sucesso!" << endl;
    }
    else
    {
        cout << "Ocorreram problemas durante a inicialização!" << endl;
    }
}

void menu()
{
    char esc = '0';
    do
    {
        limparTela();
        cin.clear();
        cin.sync();
        cout << "\t\t\t CONTROLE ADEGA DE VINHOS \n"
             << endl;
        cout << "\t Inicio \n\n"
             << endl;
        cout << " --> Quantidade de produtos: " << final + 1 << "/" << N << endl;
        cout << " Opções: [1]Inserir [2]Remover [3]Busca [4]Ordenar [5]Listar [6]Consulta [7]Outros [0]Sair" << endl;
        cout << " > ";
        cin >> esc;
        limparBuffer();
        switch (esc)
        {
        case '1':
            menuInserir();
            break;

        case '2':
            menuRemover();
            break;

        case '3':
            menuBusca();
            break;

        case '4':
            menuOrdenar();
            break;

        case '5':
            menuImprimir();
            break;

        case '6':
            menuConsulta();
            break;

        case '7':
            menuOutros();
            break;

        case '0':
            break;

        default:
            cout << "Escolha invalida" << endl;
            pause();
            break;
        }
    } while (esc != '0');
}

void menuInserir()
{
    char esc = '0';
    do
    {
        limparTela();
        cin.clear();
        cin.sync();
        cout << "\t\t\t CONTROLE ADEGA DE VINHOS \n"
             << endl;
        cout << "\t Inserir \n\n"
             << endl;
        cout << " --> Quantidade de produtos: " << final + 1 << "/" << N << endl;
        cout << " Opções: [1]Inicio [2]Fim [3]Posicão K [0]Voltar" << endl;
        cout << " > ";
        cin >> esc;
        limparBuffer();
        switch (esc)
        {
        case '0':
            pause();
            break;

        case '1':
            val = leitura();
            if (sinal)
            {
                insCom(val);
                cout << "Operação Concluida" << endl;
                pause();
            }
            else
            {
                cout << "Operação não concluida!" << endl;
                pause();
            }
            break;

        case '2':
            val = leitura();
            if (sinal)
            {
                insFim(val);
                cout << "Operação Concluida" << endl;
                pause();
            }
            else
            {
                cout << "Operação não concluida!" << endl;
            }
            break;

        case '3':
            int pos;
            cout << " Escolha a posicão [0/" << final << "]: ";
            cin >> pos;
            limparBuffer();
            val = leitura();
            if (sinal)
            {
                insPosK(pos, val);
                cout << "Operação Concluida" << endl;
                pause();
            }
            else
            {
                cout << "Operação não concluida!" << endl;
                break;
            }
            break;

        default:
            cout << "Escolha invalida" << endl;
            pause();
            break;
        }
    } while (esc != '0');
}

void menuRemover()
{
    char esc = '0';
    do
    {
        limparTela();
        cin.clear();
        cin.sync();
        cout << "\t\t\t CONTROLE ADEGA DE VINHOS \n"
             << endl;
        cout << "\t Remover \n\n"
             << endl;
        cout << " --> Quantidade de produtos: " << final + 1 << "/" << N << endl;
        cout << " Opções: [1]Inicio [2]Fim [3]Posicão K [0]Voltar" << endl;
        cout << " > ";
        cin >> esc;
        limparBuffer();
        switch (esc)
        {
        case '1':
            remIni();
            pause();
            break;

        case '2':
            remFim();
            pause();
            break;

        case '3':
            int pos;
            cout << " Escolha a posicão [0/" << final << "]: ";
            cin >> pos;
            limparBuffer();
            remPosK(pos);
            pause();
            break;

        case '0':
            break;

        default:
            cout << "Escolha invalida" << endl;
            pause();
            break;
        }
    } while (esc != '0');
}

void menuImprimir()
{
    char esc = '0';
    do
    {
        limparTela();
        cin.clear();
        cin.sync();
        cout << "\t\t\t CONTROLE ADEGA DE VINHOS \n"
             << endl;
        cout << "\t Imprimir \n\n"
             << endl;
        cout << " --> Quantidade de produtos: " << final + 1 << "/" << N << endl;
        cout << " Opções: [1]Tudo [2]Valor [3]Quantidade [4]Ano [0]Voltar" << endl;
        cout << " > ";
        cin >> esc;
        limparBuffer();
        switch (esc)
        {
        case '1':
            imprime();
            pause();
            break;

        case '2':
            imprimeValor();
            break;

        case '3':
            imprimeQuantidade();
            break;

        case '4':
            imprimeAno();
            break;

        case '0':
            break;

        default:
            cout << "Escolha invalida" << endl;
            pause();
            break;
        }
    } while (esc != '0');
}

void menuBusca()
{
    char esc = '0';
    node bsc;
    string nome;
    float valor;
    int id;
    do
    {
        limparTela();
        cin.clear();
        cin.sync();
        cout << "\t\t\t CONTROLE ADEGA DE VINHOS \n"
             << endl;
        cout << "\t Busca \n\n"
             << endl;
        cout << " --> Quantidade de produtos: " << final + 1 << "/" << N << endl;
        cout << " Opções: [1]ID [2]Nome [3]Valor [0]Voltar" << endl;
        cout << " > ";
        cin >> esc;
        limparBuffer();
        switch (esc)
        {
        case '1':
            cout << "Insira o ID: ";
            cin >> id;
            limparBuffer();
            bsc = buscaId(id);
            if (sinal)
            {
                cout << "Posicão: " << posPorId(bsc.id) << endl;
                imprimeNode(bsc);
                pause();
            }
            else
            {
                cout << "Não encontrado!" << endl;
                pause();
            }
            break;

        case '2':
            cout << "Insira o Nome: ";
            getline(cin, nome);
            limparBuffer();
            bsc = buscaNome(nome);
            if (sinal)
            {
                cout << "Posicão: " << posPorId(bsc.id) << endl;
                imprimeNode(bsc);
                pause();
            }
            else
            {
                cout << "Não encontrado!" << endl;
                pause();
            }
            break;

        case '3':
            cout << "Insira o Valor: ";
            cin >> valor;
            limparBuffer();
            bsc = buscaValor(valor);
            if (sinal)
            {
                cout << "Posicão: " << posPorId(bsc.id) << endl;
                imprimeNode(bsc);
                pause();
            }
            else
            {
                cout << "Não encontrado!" << endl;
                pause();
            }
            break;

        case '0':
            break;

        default:
            cout << "Escolha invalida" << endl;
            pause();
            break;
        }
    } while (esc != '0');
}

void menuOrdenar()
{
    char esc = '0';
    do
    {
        limparTela();
        cin.clear();
        cin.sync();
        cout << "\t\t\t CONTROLE ADEGA DE VINHOS \n"
             << endl;
        cout << "\t Ordenar \n\n"
             << endl;
        cout << " --> Quantidade de produtos: " << final + 1 << "/" << N << endl;
        cout << " Opções: [1]ID [2]Valor [3]Ano [4]Quantidade [0]Voltar" << endl;
        cout << " > ";
        cin >> esc;
        limparBuffer();
        switch (esc)
        {
        case '1':
            ordenaId();
            pause();
            break;

        case '2':
            ordenaValor();
            pause();
            break;

        case '3':
            ordenaAno();
            pause();
            break;

        case '4':
            ordenaQtde();
            pause();
            break;

        case '0':
            break;

        default:
            cout << "Escolha invalida" << endl;
            pause();
            break;
        }
    } while (esc != '0');
}

void menuConsulta()
{
    char esc = '0';
    do
    {
        limparTela();
        cin.clear();
        cin.sync();
        cout << "\t\t\t CONTROLE ADEGA DE VINHOS \n"
             << endl;
        cout << "\t Consulta \n\n"
             << endl;
        cout << " --> Quantidade de produtos: " << final + 1 << "/" << N << endl;
        cout << " Opções: [1]ID [2]Nome [0]Voltar" << endl;
        cout << " > ";
        cin >> esc;
        limparBuffer();
        switch (esc)
        {
        case '1':
            consultaId();
            pause();
            break;

        case '2':
            consultaNome();
            pause();
            break;

        case '0':
            break;

        default:
            cout << "Escolha invalida" << endl;
            pause();
            break;
        }
    } while (esc != '0');
}

void menuOutros()
{
    char esc = '0';
    int k;
    string nome;
    float valor;
    do
    {
        limparTela();
        cin.clear();
        cin.sync();
        cout << "\t\t\t CONTROLE ADEGA DE VINHOS \n"
             << endl;
        cout << "\t Outros \n\n"
             << endl;
        cout << " --> Quantidade de produtos: " << final + 1 << "/" << N << endl;
        cout << " Opções: \n\t[1]No anterior Pos K\n\t[2]Busca Nome Insere Pos Anterior\n\t[3]Inserir Pos K + 2\n\t[4]Alterar anterior\n\t[5]Busca Valor e Remove\n\t[0]Voltar" << endl;
        cout << " > ";
        cin >> esc;
        limparBuffer();
        switch (esc)
        {
        case '1':
            cout << "Insira a Posicão: ";
            cin >> k;
            limparBuffer();
            noAntPosK(k);
            pause();
            break;

        case '2':
            cout << "Insira o Nome: ";
            getline(cin, nome);
            limparBuffer();
            buscaNomeInsAnt(nome);
            pause();
            break;

        case '3':
            cout << "Insira a Posicão: ";
            cin >> k;
            limparBuffer();
            altPosK2(k);
            pause();
            break;

        case '4':
            cout << "Insira o id: ";
            cin >> k;
            limparBuffer();
            altAnt(k);
            pause();
            break;

        case '5':
            cout << "Insira o Valor: ";
            cin >> valor;
            limparBuffer();
            buscaValorRem(valor);
            pause();
            break;

        case '0':
            break;

        default:
            cout << "Escolha invalida" << endl;
            pause();
            break;
        }
    } while (esc != '0');
}

node leitura()
{
    node novoNode;
    conf = 'N';
    sinal = false;
    cout << "Insira o ID: ";
    cin >> novoNode.id;
    limparBuffer();
    cout << "Insira o Nome: ";
    getline(cin, novoNode.nome);
    limparBuffer();
    cout << "Insira o Ano: ";
    cin >> novoNode.ano;
    limparBuffer();
    cout << "Insira o Valor: ";
    cin >> novoNode.valor;
    limparBuffer();
    cout << "Insira a Quantidade: ";
    cin >> novoNode.qtde;
    limparBuffer();
    cout << "Confirmar [N/s]: ";
    cin >> conf;
    limparBuffer();
    conf = toupper(conf);
    if (conf == 'S')
    {
        sinal = true;
    }
    limparBuffer();
    cin.clear();
    cin.sync();
    return novoNode;
}

void imprimeNode(node nodeImpr)
{
    cout << "------" << endl;
    cout << "ID: " << nodeImpr.id << endl;
    cout << "Nome: " << nodeImpr.nome << endl;
    cout << "Ano: " << nodeImpr.ano << endl;
    cout << "Quantidade: " << nodeImpr.qtde << endl;
    cout << "valor: " << nodeImpr.valor << endl;
    cout << "------" << endl;
}

void imprime()
{
    if (final >= -1)
    {
        int cont = 0;
        while (cont <= final)
        {
            imprimeNode(list[cont]);
            cont = cont + 1;
        }
    }
    else
    {
        cout << "Lista Vazia" << endl;
    }
}

node buscaId(int id)
{
    sinal = false;
    int cont = 0;
    node bsc;
    while (cont <= final)
    {
        if (list[cont].id == id)
        {
            sinal = true;
            bsc = list[cont];
            return bsc;
        }
        cont = cont + 1;
    }
    return bsc;
}

node buscaNome(string nome)
{
    sinal = false;
    int cont = 0;
    node bsc;
    while (cont <= final)
    {
        if (list[cont].nome == nome)
        {
            sinal = true;
            bsc = list[cont];
            return bsc;
        }
        cont = cont + 1;
    }
    return bsc;
}

node buscaValor(float valor)
{
    sinal = false;
    int cont = 0;
    node bsc;
    while (cont <= final)
    {
        if (list[cont].valor == valor)
        {
            sinal = true;
            bsc = list[cont];
            return bsc;
        }
        cont = cont + 1;
    }
    return bsc;
}

int posPorId(int id)
{
    sinal = false;
    int cont = -1;
    while (cont <= final)
    {
        cont = cont + 1;
        if (list[cont].id == id)
        {
            sinal = true;
            return cont;
        }
    }
    return cont;
}

void insFim(node novoNode)
{
    sinal = false;
    if (final != N - 1)
    {
        if (conf == 'S')
        {
            final = final + 1;
            list[final] = novoNode;
            sinal = true;
        }
        else
        {
            cout << "Dados não confirmados" << endl;
        }
    }
    else
    {
        cout << "Lista Cheia" << endl;
    }
}

void insCom(node novoNode)
{
    sinal = false;
    if (final != N - 1)
    {
        if (conf == 'S')
        {
            final = final + 1;
            int aux = final;
            while (aux != 0)
            {
                list[aux] = list[aux - 1];
                aux = aux - 1;
            }
            list[aux] = novoNode;
            sinal = true;
        }
        else
        {
            cout << "Dados não confirmados" << endl;
        }
    }
    else
    {
        cout << "Lista Cheia" << endl;
    }
}

void insPosK(int k, node novoNode)
{
    sinal = false;
    if (final != N - 1)
    {
        if (k >= 0 && k <= final)
        {
            if (conf == 'S')
            {
                final = final + 1;
                int aux = final;
                while (aux != k)
                {
                    list[aux] = list[aux - 1];
                    aux = aux - 1;
                }
                list[k] = novoNode;
                sinal = true;
            }
            else
            {
                cout << "Dados não confirmados" << endl;
            }
        }
        else
        {
            cout << "Posição Invalida" << endl;
        }
    }
    else
    {
        cout << "Fila cheia" << endl;
    }
}

void remFim()
{
    sinal = false;
    conf = 'N';
    if (final >= 0)
    {
        imprimeNode(list[final]);
        cout << "Confirmar [N/s]: ";
        cin >> conf;
        limparBuffer();
        conf = toupper(conf);
        if (conf == 'S')
        {
            final = final - 1;
            sinal = true;
        }
        else
        {
            cout << "Operação não confirmada" << endl;
        }
    }
    else
    {
        cout << "Lista vazia" << endl;
    }
}

void remIni()
{
    sinal = false;
    conf = 'N';
    if (final >= 0)
    {
        imprimeNode(list[0]);
        cout << "Confirmar [N/s]: ";
        cin >> conf;
        limparBuffer();
        conf = toupper(conf);
        if (conf == 'S')
        {
            int aux = 0;
            while (aux != final)
            {
                list[aux] = list[aux + 1];
                aux = aux + 1;
            }
            final = final - 1;
            sinal = true;
        }
        else
        {
            cout << "Operação não confirmada" << endl;
        }
    }
    else
    {
        cout << "Lista Vazia" << endl;
    }
}

void remPosK(int k)
{
    sinal = false;
    conf = 'N';
    if (final >= 0)
    {
        if (k >= 0 && k <= final)
        {
            imprimeNode(list[k]);
            cout << "Confirmar [N/s]: ";
            cin >> conf;
            limparBuffer();
            conf = toupper(conf);
            if (conf == 'S')
            {
                int aux = k;
                while (aux != final)
                {
                    list[aux] = list[aux + 1];
                    aux = aux + 1;
                }
                final = final - 1;
                sinal = true;
            }
            else
            {
                cout << "Operação não confirmada" << endl;
            }
        }else{
            cout << "Posição Invalida" << endl;   
        }
    }else{
        cout << "Lista vazia" << endl;
    }
}

void ordenaId()
{
    sinal = false;
    conf = 'N';
    cout << "Confirmar [N/s]: ";
    cin >> conf;
    limparBuffer();
    conf = toupper(conf);
    if (conf == 'S')
    {
        if (final >= 0)
        {
            cout << "Ordenando Dados..." << endl;
            int cont = 0;
            node atual, aux, ant;
            while (cont <= final)
            {
                int i = 0;
                atual = list[cont];
                while (i <= cont)
                {
                    ant = list[i];
                    if (atual.id < ant.id)
                    {
                        list[i] = atual;
                        list[cont] = ant;
                        atual = ant;
                    }
                    i = i + 1;
                }
                cont = cont + 1;
            }
            cout << "Dados Ordenados!" << endl;
        }
        else
        {
            cout << "Lista Vazia" << endl;
        }
    }
}

void ordenaQtde()
{
    sinal = false;
    conf = 'N';
    cout << "Confirmar [N/s]: ";
    cin >> conf;
    limparBuffer();
    conf = toupper(conf);
    if (conf == 'S')
    {
        if (final >= 0)
        {
            cout << "Ordenando Dados..." << endl;
            int cont = 0;
            node atual, aux, ant;
            while (cont <= final)
            {
                int i = 0;
                atual = list[cont];
                while (i <= cont)
                {
                    ant = list[i];
                    if (atual.qtde < ant.qtde)
                    {
                        list[i] = atual;
                        list[cont] = ant;
                        atual = ant;
                    }
                    i = i + 1;
                }
                cont = cont + 1;
            }
            cout << "Dados Ordenados!" << endl;
        }
        else
        {
            cout << "Lista Vazia" << endl;
        }
    }
}

void ordenaAno()
{
    sinal = false;
    conf = 'N';
    cout << "Confirmar [N/s]: ";
    cin >> conf;
    limparBuffer();
    conf = toupper(conf);
    if (conf == 'S')
    {
        if (final >= 0)
        {
            cout << "Ordenando Dados..." << endl;
            int cont = 0;
            node atual, aux, ant;
            while (cont <= final)
            {
                int i = 0;
                atual = list[cont];
                while (i <= cont)
                {
                    ant = list[i];
                    if (atual.ano < ant.ano)
                    {
                        list[i] = atual;
                        list[cont] = ant;
                        atual = ant;
                    }
                    i = i + 1;
                }
                cont = cont + 1;
            }
            cout << "Dados Ordenados!" << endl;
        }
        else
        {
            cout << "Lista Vazia" << endl;
        }
    }
}

void ordenaValor()
{
    sinal = false;
    conf = 'N';
    cout << "Confirmar [N/s]: ";
    cin >> conf;
    limparBuffer();
    conf = toupper(conf);
    if (conf == 'S')
    {
        if (final >= 0)
        {
            cout << "Ordenando Dados..." << endl;
            int cont = 0;
            node atual, aux, ant;
            while (cont <= final)
            {
                int i = 0;
                atual = list[cont];
                while (i <= cont)
                {
                    ant = list[i];
                    if (atual.valor < ant.valor)
                    {
                        list[i] = atual;
                        list[cont] = ant;
                        atual = ant;
                    }
                    i = i + 1;
                }
                cont = cont + 1;
            }
            cout << "Dados Ordenados!" << endl;
        }
        else
        {
            cout << "Lista Vazia" << endl;
        }
    }
}

void editar(int k)
{
    if (k >= 0 && k <= final)
    {
        node bsc = buscaId(list[k].id);
        imprimeNode(buscaId(list[k].id));
        cout << "Insira os novos valores" << endl;
        bsc = leitura();
        list[k] = bsc;
        imprimeNode(list[k]);
    }
    else
    {
        cout << "Posicão fora da lista" << endl;
    }
}

void consultaId()
{
    int id;
    char esc;
    int pos;
    limparTela();
    cin.clear();
    cin.sync();
    cout << "\t\t\t CONTROLE ADEGA DE VINHOS \n"
         << endl;
    cout << "\t Consulta ID \n\n"
         << endl;
    cout << " Insira o ID: ";
    cin >> id;
    sinal = false;
    pos = posPorId(buscaId(id).id);
    if (sinal)
    {
        cout << "Posicão: " << pos << endl;
        imprimeNode(list[pos]);
        cout << " Opções: [1]Remover [2]Editar [0]Voltar" << endl;
        cin >> esc;
        switch (esc)
        {
        case '1':
            remPosK(pos);
            break;

        case '2':
            editar(pos);
            break;

        case '0':
            break;

        default:
            break;
        }
    }
    else
    {
        cout << " Não Encontrado!" << endl;
    }
}
void consultaNome()
{
    string nome;
    char esc;
    int pos;
    limparTela();
    cin.clear();
    cin.sync();
    cout << "\t\t\t CONTROLE ADEGA DE VINHOS \n"
         << endl;
    cout << "\t Consulta Nome \n\n"
         << endl;
    cout << " Insira o Nome: ";
    getline(cin, nome);
    sinal = false;
    pos = posPorId(buscaNome(nome).id);
    if (sinal)
    {
        cout << "Posicão: " << pos << endl;
        imprimeNode(list[pos]);
        cout << " Opções: [1]Remover [2]Editar [0]Voltar" << endl;
        cin >> esc;
        switch (esc)
        {
        case '1':
            remPosK(pos);
            break;

        case '2':
            editar(pos);
            break;

        case '0':
            break;

        default:
            break;
        }
    }
    else
    {
        cout << " Não Encontrado!" << endl;
    }
}

void imprimeValor()
{
    char op;
    int qtde, i;
    float valor;
    limparBuffer();
    cout << "Selecione a operação: [1]Igual [2]Maior igual [3]Menor Igual [0]Voltar" << endl;
    cout << "> ";
    cin >> op;
    limparBuffer();
    cout << "Insira o Valor: ";
    cin >> valor;
    switch (op)
    {
    case '1':
        i = 0;
        qtde = 0;
        while (i <= final)
        {
            if (list[i].valor == valor)
            {
                qtde = qtde + 1;
                imprimeNode(list[i]);
            }
            i = i + 1;
        }
        cout << "Quantidade de Produtos com Valor igual a " << valor << ": " << qtde << endl;
        pause();
        break;

    case '2':
        i = 0;
        qtde = 0;
        while (i <= final)
        {
            if (list[i].valor >= valor)
            {
                qtde = qtde + 1;
                imprimeNode(list[i]);
            }
            i = i + 1;
        }
        cout << "Quantidade de Produtos com Valor maior igual a " << valor << ": " << qtde << endl;
        pause();
        break;

    case '3':
        i = 0;
        qtde = 0;
        while (i <= final)
        {
            if (list[i].valor <= valor)
            {
                qtde = qtde + 1;
                imprimeNode(list[i]);
            }
            i = i + 1;
        }
        cout << "Quantidade de Produtos com Valor menor igual a " << valor << ": " << qtde << endl;
        pause();
        break;

    case '0':
        break;

    default:
        break;
    }
}
void imprimeQuantidade()
{
    char op;
    int qtde, i;
    int quantidade;
    limparBuffer();
    cout << "Selecione a operação: [1]Igual [2]Maior igual [3]Menor Igual [0]Voltar" << endl;
    cout << "> ";
    cin >> op;
    limparBuffer();
    cout << "Insira a Quantidade: ";
    cin >> quantidade;
    switch (op)
    {
    case '1':
        i = 0;
        qtde = 0;
        while (i <= final)
        {
            if (list[i].qtde == quantidade)
            {
                qtde = qtde + 1;
                imprimeNode(list[i]);
            }
            i = i + 1;
        }
        cout << "Quantidade de Produtos com Quantidade igual a " << quantidade << ": " << qtde << endl;
        pause();
        break;

    case '2':
        i = 0;
        qtde = 0;
        while (i <= final)
        {
            if (list[i].qtde >= quantidade)
            {
                qtde = qtde + 1;
                imprimeNode(list[i]);
            }
            i = i + 1;
        }
        cout << "Quantidade de Produtos com Quantidade maior igual a " << quantidade << ": " << qtde << endl;
        pause();
        break;

    case '3':
        i = 0;
        qtde = 0;
        while (i <= final)
        {
            if (list[i].qtde <= quantidade)
            {
                qtde = qtde + 1;
                imprimeNode(list[i]);
            }
            i = i + 1;
        }
        cout << "Quantidade de Produtos com Quantidade menor igual a " << quantidade << ": " << qtde << endl;
        pause();
        break;

    case '0':
        break;

    default:
        break;
    }
}
void imprimeAno()
{
    char op;
    int qtde, i;
    int ano;
    limparBuffer();
    cout << "Selecione a operação: [1]Igual [2]Maior igual [3]Menor Igual [0]Voltar" << endl;
    cout << "> ";
    cin >> op;
    limparBuffer();
    cout << "Insira o Ano: ";
    cin >> ano;
    switch (op)
    {
    case '1':
        i = 0;
        qtde = 0;
        while (i <= final)
        {
            if (list[i].ano == ano)
            {
                qtde = qtde + 1;
                imprimeNode(list[i]);
            }
            i = i + 1;
        }
        cout << "Quantidade de Produtos com Ano igual a " << ano << ": " << qtde << endl;
        pause();
        break;

    case '2':
        i = 0;
        qtde = 0;
        while (i <= final)
        {
            if (list[i].ano >= ano)
            {
                qtde = qtde + 1;
                imprimeNode(list[i]);
            }
            i = i + 1;
        }
        cout << "Quantidade de Produtos com Ano maior igual a " << ano << ": " << qtde << endl;
        pause();
        break;

    case '3':
        i = 0;
        qtde = 0;
        while (i <= final)
        {
            if (list[i].ano <= ano)
            {
                qtde = qtde + 1;
                imprimeNode(list[i]);
            }
            i = i + 1;
        }
        cout << "Quantidade de Produtos com Ano menor igual a " << ano << ": " << qtde << endl;
        pause();
        break;

    case '0':
        break;

    default:
        break;
    }
}

void noAntPosK(int k)
{
    node bsc;
    if (k - 1 >= 0 && k <= final)
    {
        bsc = list[k - 1];
        imprimeNode(bsc);
    }
    else
    {
        cout << "Posição fora da lista" << endl;
    }
}

void buscaNomeInsAnt(string nome)
{
    node bsc = buscaNome(nome);
    int pos;
    if (sinal)
    {
        cout << "Produto Encontrado!" << endl;
        pos = posPorId(bsc.id);
        if (pos >= 0)
        {
            node novoNode = leitura();
            insPosK(pos - 1, novoNode);
        }
        else
        {
            node novoNode = leitura();
            insCom(novoNode);
        }
    }
    else
    {
        cout << "Produto não encontrado!" << endl;
    }
}

void altPosK2(int k)
{
    node novoNode;
    if (k >= 0 && k + 2 <= final)
    {
        novoNode = leitura();
        if (sinal)
        {
            insPosK(k + 2, novoNode);
            if (sinal)
            {
                cout << "Novo produto inserido na posicao k + 2" << endl;
            }
            else
            {
                cout << "Produto não adicionado" << endl;
            }
        }
    }
    else
    {
        cout << "Posicão fora da lista" << endl;
    }
}

void altAnt(int id)
{
    int pos = posPorId(id);
    if (pos - 1 >= 0 && pos <= final)
    {
        pos = pos - 1;
        node bsc = buscaId(list[pos].id);
        imprimeNode(buscaId(list[pos].id));
        cout << "Insira os novos valores" << endl;
        bsc = leitura();
        list[pos] = bsc;
        imprimeNode(list[pos]);
    }
    else
    {
        cout << "Posicão fora da lista" << endl;
    }
}

void buscaValorRem(float valor)
{
    int pos = posPorId(buscaValor(valor).id);
    remPosK(pos);
}