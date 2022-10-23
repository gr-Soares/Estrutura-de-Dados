
const int N = 10;

struct node{
    int id;
    char info[50];
};

node list[N];
int final, aux;
node val;
bool sinal, conf;

bool insFim(node novoNode){
    if(final != N - 1){
        if(conf){
            final = final + 1;
            list[final] = novoNode;
            return true;
        }
    }
    return false;
}

bool insCom(node novoNode){
    if(final != N - 1){
        if(conf){
            final = final + 1;
            aux = final;
            while(aux != 0){
                list[aux] = list[aux - 1];
                aux = aux - 1;
            }
            list[0] = novoNode;
            return true;
        }
    }
    return false;
}

bool insPosK(int k, node novoNode){
    if(final != N - 1){
        if(k >= 0 && k <= final){
            if(conf){
                final = final + 1;
                aux = final;
                while(aux != k){
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

bool remFim(){
    if(final >= 0){
        val = list[final];
        if(conf){
            final = final - 1;
            return true;
        }
    }
    return false;
}

bool remIni(){
    if(final >= 0){
        val = list[0];
        if(conf){
            aux = 0;
            final = final - 1;
            while(aux != final){
                list[aux] = list[aux + 1];
                aux = aux + 1;
            }
            return true;
        }
    }
    return false;
}

bool remPosK(int k){
    if(final >= 0){
        val = list[final];
        if(conf){
            aux = k;
            while(aux != final){
                list[aux] = list[aux + 1];
                aux <- aux + 1;
            }
            final = final - 1;
            return true;
        }
    }
    return false;
}

int main(){
    final = -1;
    conf = false;
}