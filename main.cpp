#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"

using namespace std;

struct Container{
        unsigned codigo;
        unsigned tamanho;
        float peso;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    unsigned tamPatio, quadra;

    cout << "\t ___                                        ___" << endl;
    cout << "\t|                                              |" << endl;
    cout << "\t|                                              |" << endl;
    cout << "\t|   P Á T I O     DE     C O N T A I N E R S   |" << endl;
    cout << "\t|                                              |" << endl;
    cout << "\t|___                                        ___|" << endl;

    cout << "\n\t       Digite o Nº de Quadras do Pátio: ";
    cin >> tamPatio;

    //Criando um Vetor de tamanho tamPatio de Ponteiros p para Pilha<Container> // Um Vetor de Pilhas // Cada quadra vai ser um Ponteiro // Se deixasse só *p, seria apenas um Ponteiro para uma Pilha
    Pilha<Container> *p[tamPatio];

    //Inicializando 10 Pilhas de CC de tamanho = 5, ou seja, cada Quadra permitirá empilhar até 5 Containers
    for(unsigned i=0;i<tamPatio;i++){
        p[i] = new Pilha<Container>(5);
        //Apontando cada elemento do Vetor para uma Pilha
        //Área de Heap: área que só o Sistema Operacional acessa quando se utiliza o "new" // não é a área do Programa em si
    }

    system("cls");
    Container cc; //cc é uma Variavel do tipo Container
    int opc;

    //Menu
    do{
        cout << "\t ___                                        ___" << endl;
        cout << "\t|                                              |" << endl;
        cout << "\t|                                              |" << endl;
        cout << "\t|   P Á T I O     DE     C O N T A I N E R S   |" << endl;
        cout << "\t|                                              |" << endl;
        cout << "\t|___                                        ___|\n" << endl;
        cout << "\t\t     1    -    Armazenar" << endl;
        cout << "\t\t     2    -    Remover" << endl;
        cout << "\t\t     3    -    Consultar" << endl;
        cout << "\t\t     4    -    Exibir Pátio" << endl;
        cout << "\t\t     5    -    Sair\n\t________________________________________________" << endl;

        cout << "\n\n\t\t\tSelecione: ";
        cin >> opc;

        system("cls");

        switch(opc){
            //Armazenar Container:
            case 1:
                cout << "\t ___                                        ___" << endl;
                cout << "\t|                                              |" << endl;
                cout << "\t|    A R M A Z E N A R    C O N T A I N E R    |" << endl;
                cout << "\t|___                                        ___|" << endl;
                cout << "\n\t\t   Digite a Quadra (0 a " << tamPatio-1 << "): ";
                cin >> quadra;

                cout << "\n\t________________________________________________" << endl;

                //Se quadra estiver Cheia
                if(p[quadra]->pilhaCheia()) // Ou if(    (*p[quadra]).pilhaCheia()   )
                {
                    cout << "\n\t\t       Quadra Lotada....\n\n\t   ";
                    system("pause");
                }
                else{
                    cout << "\n\t\t      DADOS  DO  CONTAINER\n\n";
                    cout << "\t\t      Código : ";
                    cin >> cc.codigo;

                    cout << "\t\t      Tamanho: ";
                    cin >> cc.tamanho;

                    cout << "\t\t      Peso   : ";
                    cin >> cc.peso;

                    //Empilhando
                    p[quadra]->empilha(cc); // ->: Operador de Referência quando também se utiliza o "new"
                    cout << "\t________________________________________________" << endl;
                    cout << "\n\n\t\t    Empilhamento com Sucesso!\n\n\t   ";
                    system("pause");
                }
                break;
            /****************************************************************************************************/

            //Remover Container:
            case 2:
                cout << "\t ___                                        ___" << endl;
                cout << "\t|                                              |" << endl;
                cout << "\t|     R E M O V E R      C O N T A I N E R     |" << endl;
                cout << "\t|___                                        ___|" << endl;
                cout << "\n\t\t   Digite a Quadra (0 a " << tamPatio-1 << "): ";
                cin >> quadra;

                cout << "\n\t________________________________________________" << endl;

                //Se quadra estiver Vazia
                if(p[quadra]->pilhaVazia()) // Ou if(    (*p[quadra]).pilhaVazia()   )
                {
                    cout << "\n\t\t\t Quadra Vazia....\n\n\t  ";
                    system("pause");
                }
                else{
                    //Desempilhando
                    cc = p[quadra]->desempilha();

                    cout << "\n\t\t      DADOS  DO  CONTAINER\n\n";
                    cout << "\t\t      Código : " << cc.codigo << endl;
                    cout << "\t\t      Tamanho: " << cc.tamanho << endl;
                    cout << "\t\t      Peso   : " << cc.peso << endl;

                    cout << "\t________________________________________________" << endl;
                    cout << "\n\n\t\t  Desempilhamento com Sucesso!\n\n\t   ";
                    system("pause");
                }
                break;
            /****************************************************************************************************/

            //Consultar Container:
            case 3:
                cout << "\t ___                                        ___" << endl;
                cout << "\t|                                              |" << endl;
                cout << "\t|    C O N S U L T A R    C O N T A I N E R    |" << endl;
                cout << "\t|___                                        ___|" << endl;
                cout << "\n\t\t   Digite a Quadra (0 a " << tamPatio-1 << "): ";
                cin >> quadra;

                cout << "\n\t________________________________________________" << endl;

                //Se quadra estiver Vazia
                if(p[quadra]->pilhaVazia()) // Ou if(    (*p[quadra]).pilhaVazia()   )
                {
                    cout << "\n\t\t\t Quadra Vazia....\n\n\t  ";
                    system("pause");
                }
                else{
                    //Localizando o Topo da Quadra
                    cc = p[quadra]->elementoTopo();

                    cout << "\n\t\t      DADOS  DO  CONTAINER\n\n";
                    cout << "\t\t      Código : " << cc.codigo << endl;
                    cout << "\t\t      Tamanho: " << cc.tamanho << endl;
                    cout << "\t\t      Peso   : " << cc.peso << endl;

                    cout << "\t________________________________________________\n\n\t   ";
                    system("pause");

                }
                break;
            /****************************************************************************************************/

            //Exibir todo o Pátio:
            case 4:
                cout << "\t ___                                        ___" << endl;
                cout << "\t|                                              |" << endl;
                cout << "\t|     E X I B I R     T O D O     P Á T I O    |" << endl;
                cout << "\t|___                                        ___|" << endl;
                cout << "\n\t________________________________________________" << endl;

                //Percorrer todo o Pátio
                for(int q=0; q<tamPatio; q++) {

                    //Se quadra estiver Vazia      q = quadra
                    if(p[q]->pilhaVazia()){
                        cout << "\n\t\t\tQUADRA " << q << ": Vazia...";
                        cout << "\n\t________________________________________________" << endl;
                    }
                    else{
                        //Posição da Quadra
                        cout << "\n\t\t\t    QUADRA " << q << ":" << endl;

                        for(int i=0; i<=p[q]->getTopo(); i++){
                            //Localizando cada Container da determinada Quadra
                            cc = p[q]->getValor(i);

                            //Nº do Container
                            cout << "\n\n\t      " << i+1 << "º Container\n\n";
                            cout << "\t           Código : " << cc.codigo << endl;
                            cout << "\t           Tamanho: " << cc.tamanho << endl;
                            cout << "\t           Peso   : " << cc.peso << endl;
                        }
                        cout << "\n\t________________________________________________" << endl;
                    }
                }
                cout << "\n\t  ";
                system("pause");
                break;
            /****************************************************************************************************/

            //Sair:
            case 5:
                cout << "\t ___                                        ___" << endl;
                cout << "\t|                                              |" << endl;
                cout << "\t|                                              |" << endl;
                cout << "\t|   P Á T I O     DE     C O N T A I N E R S   |" << endl;
                cout << "\t|                                              |" << endl;
                cout << "\t|___                                        ___|" << endl;
                cout << "\n\t\t\t     Fim...." << endl;
                cout << "\t________________________________________________\n\n";
                return 0;
                break;
            /****************************************************************************************************/

            //Se for digitado outro Valor:
            default:
                continue;
                break;
        }

        system("cls");
    }
    while(opc != 5);

/*
    //Atribuindo Valores
    c.codigo=12;
    c.peso = 33.2;
    c.tamanho=20;

    //Empilhando na Posição 7 do Pátio
    int np=7;
    p[np]->empilha(c);

    //Empilhando 2º Container na Posição 7 do Pátio
    c.codigo=15;
    c.peso = 35.2;
    c.tamanho=40;
    p[np]-> empilha(c);


    //Exibido a Pilha da Posição 7
    for (int i=0;i<=p[np]->getTopo();i++){

        //Das 10 partes do Pátio, cada um pode inserir até 5 Containers... Na parte 7 do Pátio, já possui 2 Containers, então getValor(i) está acessando a Posição deles na parte 7 do Pátio
        c=p[np]->getValor(i);

        cout<<"\n\ncodigo..:"<<c.codigo<<endl;
        cout<<"peso:...:"<<c.peso<<endl;
        cout<<"Tamanho.:"<<c.tamanho<<endl;
    }
*/
}
