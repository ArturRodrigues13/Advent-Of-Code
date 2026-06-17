#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <cstdint>
using namespace std;

struct instrucao {

	string op;
	string entrada1;
	string entrada2;
};

bool ehNumero(string s) {
	if (s.empty()) return false;
    return isdigit(s[0]);
}

uint16_t calculaFio(unordered_map<string, instrucao>& circuito, unordered_map<string, uint16_t>& wires, string fio) {

	if (wires.count(fio)) return wires[fio];

    if (ehNumero(fio)) {
        return (uint16_t)stoi(fio);
    }

	if (!circuito.count(fio)) return 0;

    instrucao ins = circuito[fio];
    uint16_t resultado = 0;

    if (ins.op == "ATB") resultado = calculaFio(circuito, wires, ins.entrada1);
    else if (ins.op == "NOT") resultado = ~calculaFio(circuito, wires, ins.entrada1);
    else if (ins.op == "AND") {
        uint16_t val1 = calculaFio(circuito, wires, ins.entrada1);
        uint16_t val2 = calculaFio(circuito, wires, ins.entrada2);
        resultado = val1 & val2;
    }
    else if (ins.op == "OR") {
        uint16_t val1 = calculaFio(circuito, wires, ins.entrada1);
        uint16_t val2 = calculaFio(circuito, wires, ins.entrada2);
        resultado = val1 | val2;
    }
	else if(ins.op == "RSHIFT") resultado = calculaFio(circuito, wires, ins.entrada1) >> stoi(ins.entrada2);
	else resultado = calculaFio(circuito, wires, ins.entrada1) << stoi(ins.entrada2);

    wires[fio] = resultado;
    return resultado;
}

int main () {

	vector<string> componentes;
	string termo, linha;
	unordered_map<string, instrucao> circuito;
	unordered_map<string, uint16_t> wires;
	uint16_t valor;

	while (getline(cin, linha)) {
        if (linha.empty()) continue;

        vector<string> componentes;
        string termo;
        stringstream leitura(linha);

        while (leitura >> termo) {
            componentes.push_back(termo);
        }

        instrucao ins_atual;

        if (componentes.size() == 3) {
            ins_atual.op = "ATB";
            ins_atual.entrada1 = componentes[0];
            circuito[componentes[2]] = ins_atual;
        }
        else if (componentes.size() == 4) {
            ins_atual.op = "NOT";
            ins_atual.entrada1 = componentes[1];
            circuito[componentes[3]] = ins_atual;
        }
        else if (componentes.size() == 5) {
            ins_atual.op = componentes[1]; // AND, OR, LSHIFT, RSHIFT
            ins_atual.entrada1 = componentes[0];
            ins_atual.entrada2 = componentes[2];
            circuito[componentes[4]] = ins_atual;
        }
    }

    valor = calculaFio(circuito, wires, "a");
    cout << valor << endl;

	return 0;
}
