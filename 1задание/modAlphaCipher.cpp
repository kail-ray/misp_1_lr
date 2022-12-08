#include "k.h"
modAlphaCipher::modAlphaCipher(const string& skey)
{
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(numAlpha); // перекодируем
    for (unsigned i=0; i<ws.size(); i++) {//на каждом шаге добавляет в ассоциативный массив символ и его номер
        alphaNum[ws[i]]=i;
    }
    key = convert(skey);
}

string modAlphaCipher::encrypt(const string& open_text)       //Здесь сначала формируется вектор work из строки открытого текста с помощью метода
{                                                              //convert(). Затем в цикле к каждому элементу вектора прибавляется элемент ключа по модулю размера алфавита
   vector<int> work = convert(open_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

string modAlphaCipher::decrypt(const string& cipher_text)//тоже самое только расшифровываем 
{
    vector<int> work = convert(cipher_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

inline vector<int> modAlphaCipher::convert(const string& s)//преобразует строку в целочисленный вектор
{
   vector<int> result;
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(s); // перекодируем
    for (unsigned i=0; i<ws.size(); i++) {
        result.push_back(alphaNum[ws[i]]);
    }
    return result;
}

inline string modAlphaCipher::convert(const vector<int>& v)//преобразует вектор в строку
{
    string result;
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(numAlpha);
    wstring result_s = codec.from_bytes("");
    for (unsigned i=0; i<v.size(); i++) {
        result_s.push_back(ws[v[i]]);
    }
    result = codec.to_bytes(result_s);
    return result;
}
