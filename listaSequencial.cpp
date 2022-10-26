#include <iostream>
#include <iomanip>

using namespace std;

const int N = 5;

struct node {
    int id, qtd;
    string descricao;
    float valor;
};

node list[N] = {1 , 3 , "Chateau Dufort Vivens" , 300.00 , 2 , 5 , "Ballantine's Finest Escoces" , 90.0 ,
                3 , 20 , "Antartica Original" , 5.0, 4 , 10 , "Jack Daniels Honey" , 143.91};
int final, aux, idBsc;
node val;
bool sinal, conf;

bool insFim(node novoNode) {
    if (final != N - 1) {
        cin >> conf;
        if (conf == true) {
            final = final + 1;
            list[final] = novoNode;
            return true;
        }
    }
    return false;
}

bool insCom(node novoNode) {
    if (final != N - 1) {
        cin >> conf;
        if (conf == true) {
            final = final + 1;
            aux = final;
           while (aux != 0) {
                list[aux] = list[aux - 1];
                aux = aux - 1;
            }
            list[aux] = novoNode;
            return true;
        }
    }
    return false;
}

bool insPosK(int k, node novoNode) {
    if (final != N - 1) {
        if (k >= 0 && k <= final) {
            cin >> conf;
            if (conf == true) {
                final = final + 1;
                aux = final;
                while (aux != k) {
                    list[aux] = list[aux - 1];
                    aux = aux - 1;
                }
                list[k] = novoNode;
                return true;
            }
        }
    }
    return false;
}

bool remFim() {
    if (final >= 0) {
        aux = final -1;
        cout << list[aux].id << endl << list[aux].qtd << endl << list[aux].descricao << endl << list[aux].valor << endl;
        cin >> conf;
        if (conf == true) {
            final = final - 1;
            return true;
        }
    }
    return false;
}

bool remIni() {
    if (final >= 0) {
        aux = 0;
        cout << list[aux].id << endl << list[aux].qtd << endl << list[aux].descricao << endl << list[aux].valor << endl;
        cin >> conf;
        if (conf == true) {
            while (aux != final) {
                list[aux] = list[aux + 1];
                aux = aux + 1;
            }
            final = final - 1;
            return true;
        }
    }
    return false;
}

bool remPosK(int k) {
    if (final >= 0) {
        aux = k;
        cout << list[aux].id << endl << list[aux].qtd << endl << list[aux].descricao << endl << list[aux].valor << endl;
        cin >> conf;
        if (conf == true) {
            while (aux != final) {
                list[aux] = list[aux + 1];
                aux = aux + 1;
            }
            final = final - 1;
            return true;
        }
    }
    return false;
}

bool consAntK(int k) {
    if (final >= 0) {
        cin >> conf;
        if (conf == true) {
            aux = k;
            cout << list[aux - 1].id << list[aux - 1].qtd << list[aux - 1].descricao << list[aux - 1].valor;
            return true;
        }

    }
    return false;
}


int main() {
    final = 4;
    conf = false;
    sinal = remIni();
}