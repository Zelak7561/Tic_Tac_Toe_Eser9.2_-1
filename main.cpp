/*
tttPlayGround()
il costruttore di default. Azzera il contenuto di playground e
imposta prossimoG=1;
La classe tttPlayGround presenta la seguente interfaccia:
void show()
visualizza il contenuto di playground in modo che, le celle
contenenti 0 appaiano vuote, quelle a 1 riportino il carattere O e
quelle con 2 il carattere X


char prossimo()
restituisce il il carattere O se prossimoG vale 1, oppure X se
prossimoG vale 2;
bool muovi(int riga, int col)
assegna il valore corrente di prossimoG alla cella indicata da
riga e col . Quindi aggiorna il valore di prossimoG per dare
il turno all’altro giocatore (se è 1 passa a 2, se è 2 passa a 1).
restituisce false se non è possibile fare la mossa (true se è ok).
void reset()
*/

#include <iostream>


using namespace std;


class tttPlayGround{

    int playground[3][3];
    int prossimoG;


    public:
    tttPlayGround() {
        reset();
    }


    //Getter
    int getProssimoG(){
        return prossimoG;
    }


    void show(){
        cout << "Playground: "<< endl;
        cout << endl;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                    if(playground[i][j] == 0){
                        cout << " " << "\t";
                    }
                    if(playground[i][j] == 1){
                        cout << "O" << "\t";
                    }
                    if(playground[i][j] == 2){
                        cout << "X" << "\t";
                    }
            }
            cout << endl;
        }
    }

     char prossimo(){
     for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                    if(playground[i][j] == 1){
                       return 'O';
                    }
                    if(playground[i][j] == 2){
                        return 'X';
                    }
            }

        }
    }



    bool muovi(int riga, int col){

        if (riga < 0 || riga > 2 || col < 0 || col > 2) {
            return false;
        }

        if(playground[riga][col] == 0){
          if(prossimoG == 1){
            playground[riga][col] = 1;
            prossimoG = 2;
            return true;
          }
          if(prossimoG == 2){
            playground[riga][col] = 2;
            prossimoG = 1;
             return true;
          }

        }
             return false;
    }


    void reset(){
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                playground[i][j] = 0;
            }
        }
        prossimoG = 1;
    }

};


int main()
{
    tttPlayGround Ply1;

    int moves = 5;

    cout << "Benvenuto nel tris" << endl;

    cout << endl;

    for (int i = 0; i < 5; i++){
            int pos_r = 0;
            int pos_c = 0;
            cout << "Giocatore: " << Ply1.getProssimoG() << endl;
            cout << "Inserire la posizione della riga" << endl;
            cin >> pos_r;
            cout << "Inserire la posizione della riga" << endl;
            cin >> pos_c;

            if (!Ply1.muovi(pos_r, pos_c)) {
            cout << "Mossa non valida, riprova!" << endl;
            i--;
            continue;
        }

        Ply1.show();
    }

    cout << "Playground: " << endl;
    Ply1.show();



    return 0;
}
