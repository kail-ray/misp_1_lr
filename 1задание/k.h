#pragma once
#include <iostream>
#pragma once
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <locale>
#include <codecvt>
#include <vector>
#include <map>
using namespace std;
class modAlphaCipher
{
private:
    string numAlpha ="АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
    map <char,int> alphaNum; //ассоциативный массив "номер по символу"
    vector <int> key; //ключ
    vector<int> convert(const string& s); //преобразование строка-вектор
    string convert(const vector<int>& v); //преобразование вектор-строка
public:
    modAlphaCipher()=delete; //запретим конструктор без параметров
    modAlphaCipher(const string& skey); //конструктор для установки ключа
    string encrypt(const string& open_text); //зашифрование
    string decrypt(const string& cipher_text);//расшифрование
};