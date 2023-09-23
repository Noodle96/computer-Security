#include <bits/stdc++.h>
using namespace std;
fstream fileIn, fileOut;

string function01(string line){
	string ans;
	for(int e = 0 ; e < (int)line.size(); e++){
		/* si es -157 => viene un caracter especial*/
		if( line[e]-'`' == -157){
			e++;
			/* Si es -175 => es ñ */
			if(line[e]-'`' == -175) ans += "n";
			/* Si es -191 => es á */
			else if(line[e]-'`' == -191) ans += "á";
			/* Si es -183 => es é */
			else if(line[e]-'`' == -183) ans += "é";
			/* Si es -179 => es í */
			else if(line[e]-'`' == -179) ans += "í";
			/* Si es -173 => es ó */
			else if(line[e]-'`' == -173) ans += "ó";
			/* Si es -166 => es ú */
			else if(line[e]-'`' == -166) ans += "ú";
			/* Si es -223 => es Á */
			else if(line[e]-'`' == -223) ans += "Á";
			/* Si es -215 => es É */
			else if(line[e]-'`' == -215) ans += "É";
			/* Si es -211 => es Í */
			else if(line[e]-'`' == -211) ans += "Í";
			/* Si es -205 => es Ó */
			else if(line[e]-'`' == -205) ans += "Ó";
			/* Si es -198 => es Ú  */
			else if(line[e]-'`' == -198) ans += "Ú";
		}else{
			/* Cualquier otro caracter que no sea especial*/
			if(line[e] == 'j') ans += "i";
			else if(line[e] == 'h') ans+= "i";
			else if(line[e] == 'k') ans+= "l";
			else if(line[e] == 'u') ans+= "v";
			else if(line[e] == 'w') ans+= "v";
			else if(line[e] == 'y') ans+= "z";
			else{
				ans += line[e];
			}
		}
	}
	return ans;
}


void preProcesamiento01(){
	fileIn.open("message.txt", ios::in);
	fileOut.open("salida01.txt", ios::out);
	string line; 
	while(getline(fileIn,line)){
		fileOut << function01(line) << endl;
	}
	fileIn.close();
	fileOut.close();
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	/*
		1. Realizar las siguientes sustituciones: jxi, hxi,ñxn, kxl, uxv, wxv, yxz
	*/
	preProcesamiento01(); 

	
	return 0;
}