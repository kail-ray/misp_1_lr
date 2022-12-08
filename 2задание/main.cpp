#include "modAlphaCipher.h"


bool isValid(const string& s)
{
    for(const auto &c:s) // цикл проходит по всему массиву и выдает сам объект этого массива
        if (!isalpha(c) )
            return false;
    return true;

}


int main(int argc, char **argv)
{
    int key;
    string st;
    unsigned operation;
    cout<<"ВВЕДИТЕ КЛЮЧ (ЧИСЛО) : ";
    cin>>key;
    if (!cin.good()) {
        clog<<"КЛЮЧ НЕ ПОДХОДИТ\n";
        return 1;
    }
    cout<<"КЛЮЧ ПРИНЯТ\n";
    modAlphaCipher cipher(key);
    do {
        cout<<"ВЫБЕРИТЕ ОПЕРАЦИЮ (0-ВЫХОД, 1-ЗАШИФРОВАТЬ, 2-РАСШИФРОВАТЬ): ";
        cin>>operation;
        if (operation > 2) {
            cout<<"ОШИБКА В ВЫБОРЕ ОПЕРАЦИИ\n";
        } else if (operation >0) {
            cout<<"ВВЕДИТЕ СТРОКУ, СОСТОЯЩУЮ ИЗ ЛАТИНИЦЫ : ";
            cin>>st;
            if (isValid(st)) {
                if (operation==1) {
                    cout<<"ЗАШИФРОВАННАЯ СТРОКА: "<<cipher.coder(st)<<endl;
                } else {
                    cout<<"РАСШИФРОВАННАЯ СТРОКА: "<<cipher.decoder(st)<<endl;
                }
            } else {
                cout<<"НЕКОРРЕКТНАЯ СТРОКА.\n";
            }
        }
    } while (operation!=0);

    return 0;
}