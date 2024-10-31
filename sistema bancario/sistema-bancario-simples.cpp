#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    string nome;
    string cpf;

public:
    Cliente(string nome, string cpf) : nome(nome), cpf(cpf) {}

    string getNome() const { return nome; }
    string getCpf() const { return cpf; }
};

class ContaBancaria {
private:
    int numero;
    double saldo;
    Cliente titular;

public:
    ContaBancaria(int numero, Cliente titular, double saldo = 0.0)
        : numero(numero), saldo(saldo), titular(titular) {}

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depositado: R$ " << valor << " na conta " << numero << endl;
        } else {
            cout << "Valor inválido para depósito." << endl;
        }
    }

    void sacar(double valor) {
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            cout << "Sacado: R$ " << valor << " da conta " << numero << endl;
        } else {
            cout << "Saldo insuficiente para saque ou valor inválido." << endl;
        }
    }

    void transferir(double valor, ContaBancaria &destino) {
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            destino.depositar(valor);
            cout << "Transferido: R$ " << valor << " da conta " << numero
                 << " para a conta " << destino.numero << endl;
        } else {
            cout << "Saldo insuficiente ou valor inválido para transferência." << endl;
        }
    }

    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
        if (valor > 0 && saldo >= valor) {
            double valorPorConta = valor / 2;
            saldo -= valor;
            destino1.depositar(valorPorConta);
            destino2.depositar(valorPorConta);
            cout << "Transferido: R$ " << valorPorConta << " para cada conta ("
                 << destino1.numero << " e " << destino2.numero << ") da conta " << numero << endl;
        } else {
            cout << "Saldo insuficiente ou valor inválido para transferência." << endl;
        }
    }

    void exibirSaldo() const {
        cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
    }

    void exibirInformacoes() const {
        cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << endl;
        cout << "Número da Conta: " << numero << ", Saldo: R$ " << saldo << endl;
    }
};

int main() {
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    conta1.exibirSaldo();

    conta1.transferir(200.0, conta2);

    conta1.transferir(300.0, conta2, conta3);

    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
