#ifndef ADFGVX_H
#define ADFGVX_H

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
#define pb push_back
const string matrixContent = "fd60z2wg14snylhpce5moi3ut79xkvj8abrq";

class ADFGVX{
private:
    char M[6][6];
public:
    ADFGVX(string contenidoM=""){
        preprocesado(contenidoM);
        //cout << "contenidoM: " << contenidoM <<endl;
        int i = 0;
        //FILL MATRIX
        for(int row = 0 ; row < 6; row++){
            for(int col = 0 ;col < 6 ; col++){
                this->M[row][col] = contenidoM[i];
                i++;
            }
        }
    }
    ~ADFGVX(){;}

    //MAIN FUNCTIONS
    string encrypt(string msg, string clave);
    string decrypt(string msgEncriptado, string clave);

    string sustitucion(string msg);
    pair<char,char> findInMatrix(char ch);

    //SECONDARY FUNCTIONS
    void printMatriz();
    string deleteTildes(string line);
    void convertUppercase(string &str);
    string deleteSpacesAndPunctuation(string line);
    void preprocesado(string &str);
    char id(int position);
    int id(char ch);
};

#endif // ADFGVX_H
