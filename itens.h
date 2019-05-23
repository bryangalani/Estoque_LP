#ifndef ITENS_H
#define ITENS_H

#include <string.h>
#include <string>
#include<iostream>

using namespace std;

class itens{
    string nome;
    int quantidade;
public:
    void set_nome(string name){nome = name;}
    void set_quantidade(int quant){quantidade = quant;}

    int get_quantidade(){return quantidade;}
    string get_nome(){return nome;}
    itens();

};

class Refrigerados: public itens{
    float temperatura_armazenamento;
public:
    void set_temp(float temp) { temperatura_armazenamento = temp;}
    float get_temp() { return temperatura_armazenamento; }

};

class Quentes: public itens{
    int validade;
public:
    void set_validade (int val){validade=val;}
    int get_validade(){return validade; }
};

class Snacks: public itens{
    string sabor;
public:
    void set_sabor(string flavour) {sabor = flavour;}
    string get_sabor(){return sabor;}

};


#endif // ITENS_H
