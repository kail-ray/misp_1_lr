#include "k.h"
bool isValid(const string& s)
{
    std::locale loc("ru_RU.UTF-8");
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    std::wstring ws = codec.from_bytes(s);
    std::string numAlpha = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::wstring wA = codec.from_bytes(numAlpha);
    for(unsigned int i = 0; i < ws.size(); i++) {
        if (wA.find(ws[i]) == string::npos) {
            return false;
        }
    }
    return true;
}
int main(int argc, char **argv)
{
    string key;
    string text;
    unsigned op;
    cout<<"Введите ключ для шифрования: ";
    cin>>key;
    if (!isValid(key)) {
        cerr<<"ключ не подходит\n";
        return 1;
    }
    cout<<"ключ действителен\n";
    modAlphaCipher cipher(key);
    do {
        cout<<"Шифр готов. Возможные операции (0-выход, 1-шифрование, 2-дешифрование): ";
        cin>>op;
        if (op > 2) {
            cout<<"неправильная операция\n";
        } else if (op >0) {
            cout<<"Введите текст: ";
            cin>>text;
            if (isValid(text)) {
                if (op==1) {
                    cout<<"зашифрованный текст: "<<cipher.encrypt(text)<<endl;
                } else {
                    cout<<"расшифрованный текст: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                cout<<"операция прервана. неправильный текст\n";

            }
        }
    } while (op!=0);
    
    return 0;
}