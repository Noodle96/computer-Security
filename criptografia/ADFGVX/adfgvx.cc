#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

#define pb push_back

const string matrixContent = "fd60z2wg14snylhpce5moi3ut79xkvj8abrq";
//const string matrixContent = "0q9z7cmu1hf248wnrgl6vtpay3d5ekjsiobx";

bool cmp(pair<pair<char,int>, vector<char>> &a, pair<pair<char,int>, vector<char>> &b){
	int aPosition = a.first.second;
	int bPosition = b.first.second;
	return aPosition < bPosition;
}

class ADFGVX{
	private:
		char M[6][6];
		int lenMensajeOriginal;
	public:
		ADFGVX(string contenidoM){
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
		string encrypt(string msg, string clave){
			this->lenMensajeOriginal = msg.size();
			//FASE01: SUSTITUCION
			preprocesado(msg);
			string msg_sustituido = sustitucion(msg);
			cout << "msg_sustituido: "<<  msg_sustituido << endl;
			preprocesado(clave);
			int factor = (msg_sustituido.size()%clave.size()==0?msg_sustituido.size()/clave.size():(msg_sustituido.size()/clave.size())+1);


			//FASE02: TRASPOSICION
			//<KEY, [CHAR,CHAR,CHAR,....]>
			vector<pair<pair<char,int>, vector<char>>> claveColumna;
			for(int e = 0 ; e < (int)clave.size();e++){
				int salto = e;
				vector<char> temp;
				for(int i = 0 ; i < factor; i++){
					if(salto < msg_sustituido.size()) temp.pb(msg_sustituido[salto]); // claveColumna[clave[e]].pb(msg_sustituido[salto]);
					else temp.pb('A'); //claveColumna[clave[e]].pb('X'); // X is default complete
					salto += clave.size();
				}
				//string key = string(1, clave[e]);
				//key += to_string(e);
				claveColumna.pb({{clave[e],e},temp});
			}
			cout << "encrypt before" << endl;
			cout << "print clavecolumn: " << endl;
			for(auto it =claveColumna.begin() ;it != claveColumna.end() ; it++){
				cout << it->first.first << "-" <<it->first.second << "->";
				for(auto et = it->second.begin() ; et != it->second.end(); et++){
					cout << *et << " ";
				}cout << endl;
			}
			sort(all(claveColumna));
			cout << "encrypt after" << endl;
			cout << "print clavecolumn: " << endl;
			for(auto it =claveColumna.begin() ;it != claveColumna.end() ; it++){
				cout << it->first.first << "-" <<it->first.second << "->";
				for(auto et = it->second.begin() ; et != it->second.end(); et++){
					cout << *et << " ";
				}cout << endl;
			}

			//RETURN MSG ENCRYPT: EACH COLUMN	
			string msg_encrypt;
			for(auto it =claveColumna.begin() ;it != claveColumna.end() ; it++){
				for(auto et = it->second.begin() ; et != it->second.end(); et++){
					msg_encrypt += *et;
				}
			}
			return msg_encrypt;
		}
		string decrypt(string msgEncriptado, string clave){
			cout << "decrypt:" << endl;
			vector<pair< pair<char,int>, vector<char>>> claveColumna;
			//math claveColumna struct with clave indices
			for(int e = 0 ; e < clave.size(); e++){
				char key = clave[e];
				//string key = string(1, clave[e]);
				//key += to_string(e);
				//claveColumna.pb({key,vector<char>()});
				claveColumna.pb({{key,e},vector<char>()});
			}
			for(auto it = claveColumna.begin() ; it != claveColumna.end(); it++){
				//cout << it->first << "->";
				auto key = it->first;
				cout << key.first << "-" << key.second << " ";
				for(auto et = it->second.begin() ; et != it->second.end(); et++){
					cout << *et << " ";
				}cout << endl;
			}cout << endl;
			sort(all(claveColumna));
			for(auto it = claveColumna.begin() ; it != claveColumna.end(); it++){
				//cout << it->first << "->";
				auto key = it->first;
				cout << key.first << "-" << key.second << " ";
				for(auto et = it->second.begin() ; et != it->second.end(); et++){
					cout << *et << " ";
				}cout << endl;
			}cout << endl;
			
			//RECORRER EL MENSAJE ENCRIPTADO
			int factor = msgEncriptado.size() / claveColumna.size();
			cout << "alerta" <<endl;
			int position = 0;
			for(int e = 0 ; e < msgEncriptado.size();){
				cout << "alerta" <<endl;
				vector<char> temp;
				for(int j = 0 ;j < factor ; j++){
					temp.pb(msgEncriptado[e]);
					e++;
				}
				claveColumna[position].second = temp;
				position ++;
			}
			
			//CLAVE COLUMNA FILLED
			for(auto it = claveColumna.begin() ; it != claveColumna.end(); it++){
				//cout << it->first << "->";
				auto key = it->first;
				cout << key.first << "-" << key.second << " ";
				for(auto et = it->second.begin() ; et != it->second.end(); et++){
					cout << *et << " ";
				}cout << endl;
			}cout << endl;
			//ORDENAR EN BASE A LOS INDICES
			sort(all(claveColumna), cmp);
			for(auto it = claveColumna.begin() ; it != claveColumna.end(); it++){
				//cout << it->first << "->";
				auto key = it->first;
				cout << key.first << "-" << key.second << " ";
				for(auto et = it->second.begin() ; et != it->second.end(); et++){
					cout << *et << " ";
				}cout << endl;
			}cout << endl;

			//RECUPERACION DEL MENSAJE EN SU FASE01 DE SUSTITUCION
			string mensaje_encriptadoFase01;
			for(int e = 0 ; e < claveColumna[0].second.size() ; e++){
				for(int j = 0 ;j < claveColumna.size() ; j++){
					mensaje_encriptadoFase01 += claveColumna[j].second[e];
				}
			}
			cout <<"mensaje_encriptadoFase01: " <<mensaje_encriptadoFase01 << endl;

			//RECUPERAR EL MENSAJE ORIGINAL DE LA MATRIZ
			string mensaje_original;
			for(int e = 0 ;e < 2*this->lenMensajeOriginal -1 ; e+=2){
				int a = id(mensaje_encriptadoFase01[e]);
				int b = id(mensaje_encriptadoFase01[e+1]);
				if(a == -1 || b == -1){;}
				else {mensaje_original += this->M[a][b];}
			}
			return mensaje_original;
		}

		string sustitucion(string msg){
			string ans;
			for(int e = 0 ; e < (int)msg.size(); e++){
				auto XY = findInMatrix(msg[e]);
				ans += (XY.first);
				ans += (XY.second);
			}
			return ans;
		}

		pair<char,char> findInMatrix(char ch){
			for(int e = 0 ; e< 6; e++){
				for(int j = 0 ; j <6; j++){
					if(this->M[e][j] == ch){
						//return {id(e), id(j)};
						return make_pair(id(e), id(j));
					}
				}
			}
			return std::make_pair(-1, -1);
		}



		//SECONDARY FUNCTIONS
		void printMatriz(){
			for(int row = 0 ; row < 6; row++){
				for(int col = 0 ;col < 6 ; col++){
					cout << M[row][col] << " ";
				}cout << endl;
			}cout << endl;
		}
		/*
			2.- Eliminar tildes
		*/
		string deleteTildes(string line){
			string ans;
			for(int e = 0 ; e < (int)line.size(); e++){
				/* si es -157 => viene un caracter especial*/
				if( line[e]-'`' == -157){
					e++;
					/* Si es -191 => es á */
					if(line[e]-'`' == -191) ans += "a";
					/* Si es -183 => es é */
					else if(line[e]-'`' == -183) ans += "e";
					/* Si es -179 => es í */
					else if(line[e]-'`' == -179) ans += "i";
					/* Si es -173 => es ó */
					else if(line[e]-'`' == -173) ans += "o";
					/* Si es -166 => es ú */
					else if(line[e]-'`' == -166) ans += "u";
					/* Si es -223 => es Á */
					else if(line[e]-'`' == -223) ans += "A";
					/* Si es -215 => es É */
					else if(line[e]-'`' == -215) ans += "E";
					/* Si es -211 => es Í */
					else if(line[e]-'`' == -211) ans += "I";
					/* Si es -205 => es Ó */
					else if(line[e]-'`' == -205) ans += "O";
					/* Si es -198 => es Ú  */
					else if(line[e]-'`' == -198) ans += "U";
				}else{
					/* Cualquier otro caracter */
					ans += line[e];
				}
			}
			return ans;
		}
		/*
			3.- Convierta todas las letras a Mayusculas
		*/
		void convertUppercase(string &str){
			for(int e = 0 ;e < (int)str.size() ; e++){
				if(str[e] >= 97 && str[e]<=122){
					str[e] = toupper(str[e]);
				}
			}
		}
		/*
			4.- Elimine los espacios en blanco y los signos de puntuacion
		*/
		string deleteSpacesAndPunctuation(string line){
			string ans;
			for(int e =0  ;e < (int)line.size() ; e++){
				if(line[e] == ' '){;}
				else{
					if(line[e]-'`' == -158){
						e++;
						if(line[e]-'`' == -191){;}
					}
					//para detectar el caracter  '¡'
					else if(line[e] == ',' || line[e] == '.'  ||
					line[e] == '!' || line[e] == ';' || line[e] == '?' ||
					line[e] == ','){;}
					else{
						ans += line[e];
					}
				}
			}
			return ans;
		}

		void preprocesado(string &str){
			str = deleteTildes(str);
			convertUppercase(str);
			str = deleteSpacesAndPunctuation(str);
		}


		char id(int position){
			if(position == 0) return 'A';
			if(position == 1) return 'D';
			if(position == 2) return 'F';
			if(position == 3) return 'G';
			if(position == 4) return 'V';
			// if position == 5
			return 'X';
		}
		int id(char ch){
			if(ch == 'A') return 0;
			if(ch == 'D') return 1;
			if(ch == 'F') return 2;
			if(ch == 'G') return 3;
			if(ch == 'V') return 4;
			if(ch == 'X') return 5;
			return -1;
		}
};


void solve(){
	ADFGVX adfgvx = ADFGVX(matrixContent);
	//string mensaje = "envien municiones", clave = "whisky";
	//string mensaje = "NOYELLOWTEAMARBOLESmonosELIAS", clave = "sasasasasa";
	string mensaje = "nanos", clave = "losperrosdeaqp";
	string msg_encriptado = adfgvx.encrypt(mensaje,clave);
	// adfgvx.printMatriz();
	cout << "mensaje encriptado: " << msg_encriptado << endl;



	string msg_desencriptado = adfgvx.decrypt(msg_encriptado, clave);
	cout << "Mensaje desencriptado: " <<  msg_desencriptado << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	// map<char,int> mapa;
	// for(int e = 0 ;e < matrixContent.size() ; e++){
	// 	mapa[matrixContent[e]]++;
	// }
	// for(auto it = mapa.begin(); it != mapa.end() ; it++){
	// 	cout << it->first << " : " << it->second << endl;
	// }
	return 0;
}