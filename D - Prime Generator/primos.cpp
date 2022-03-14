#include <iostream>

using namespace std;

int primos_prep[32001];
int n_primos;

int e_primo(int x){
    if(x < 2) 
        return false;
    for (int divisor = 2; divisor*divisor <= x; ++divisor){
        if(x % divisor == 0)
            return false;
    }
    return true;
}

void preprocessa_primo(int l){
    n_primos = 0;
    for (int i = 2; i <= l; ++i){
        if(e_primo(i)){
            primos_prep[n_primos] = i;
            n_primos++;
        }
    }   
}

/* Essa função vai pegar um valor X, vai olhar no vetor de primos pre processados do começo até 
 * atingir a metade desse valor. Ou seja, se X é 5, vou olhar meu vetor de primos começando pelo
 * 2. 2*2 é 4, logo, é menor que 5. Resto da divisão de 5 % 2 é 1, então incremento e olho o próximo 
 * primo. Nesse caso é o 3, logo, 3 * 3 = 9, opa, 9 é maior que 5, e 3 ultrapassa a metade de 5, sendo
 * assim, saímos do loop e retornamos verdadeiro. 
 */
int e_primo_prep(int x){
    if(x < 2) 
        return false;
    for (int i_pri = 0; i_pri < n_primos && primos_prep[i_pri]*primos_prep[i_pri] <= x; ++i_pri){
        int divisor = primos_prep[i_pri];
        if(x % divisor == 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    preprocessa_primo(32000);
    int t; // int guarda até uns 2 bilhões, então deve ser suficiente --> -2,147,483,648 to 2,147,483,647      

    cin >> t;
    for (int i = 0; i < t; ++i){
        int n, m;
        cin >> n >> m;

        for (int x = n; x <= m; ++x){
            if (e_primo_prep(x))
                cout << x << endl;
        }
        if (i < t - 1)
            cout << endl;
        
    }
    return 0;
}
