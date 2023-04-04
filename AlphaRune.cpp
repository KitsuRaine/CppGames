#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

char s[100],yorn,c;
int io,jo,i,j,mat[10][10],ei,ej,hp=3,posibil;

int main()
{
    ///Name: AlphaRune

    ///In acest joc, trebuie sa parcurgi un teren sub forma de tabla de sah
    ///si sa colectezi cat mai multe artefacte de la monstri. Acestia pot
    ///fi invinsi prin a castiga 2 din 3 runde de piatra-foarfeca-hartie.
    ///Pentru fiecare runda pierduta, eroul pierde o viata. Cand numarul
    ///de vieti ajunge la 0, eroul pierde, insa, daca acesta colecteaza
    ///cat mai multe din cele 8 artefacte, iar ajunge in coltul din dreapta
    ///sus, acesta castiga.
    cout<<"Introduceti numele eroului: ";cin>>s;
    cout<<"\n"<<s<<" este numele dorit? (y or n)\n\n";cin>>yorn;
    while(yorn!='y')
    {
        ///De multe ori, in jocuri, exista varianta de a-ti schimba numele
        cout<<"Reintroduceti numele: ";cin>>s;
        cout<<"\n"<<s<<" este numele corect?(y or n)\n\n";cin>>yorn;
    }
    ///In orice joc, exista secrete, in acesta, prin folosirea numelui: lexA,
    ///caracterul primeste 5 viati in loc de 3.
    if(s[0]=='l' && s[1]=='e' && s[2]=='x' && s[3]=='A' && strlen(s)==4)
        hp=10;
    cout<<'\n';
    cout<<'\n';
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=6;j++)
        {
            mat[i][j]=0;
        }
    }
    ///randomizarea a 8 obstacole
    for(i=1;i<=8;i++)
    {
        io=rand()%5+1;
        jo=rand()%5+1;
        if(mat[io][jo]==0)
        {
            posibil=1;
            mat[io][jo]=1;
        }
        else
            posibil=0;
        while(posibil==0)
        {
            io=rand()%6+1;
            jo=rand()%6+1;
            if(mat[io][jo]==0)
            {
                posibil=1;
                mat[io][jo]=1;
                break;
            }
            else
                posibil=0;
        }
    }
    mat[6][1]=3;
    mat[1][6]=2;
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=6;j++)
        {
            if(mat[i][j]==0)
            {
                cout<<". ";
            }
            else if(mat[i][j]==1)
            {
                cout<<"X ";
            }
            else if(mat[i][j]==3)
            {
                cout<<"E ";
            }
            else if(mat[i][j]==2)
            {
                cout<<"G ";
            }
        }
            if(i==3)
                cout<<"          Hp = "<<hp;
        cout<<'\n';
    }
    ei=6;
    ej=1;
    int eia=6;
    int eja=1;
    int scor=0;
    while(hp>0)
    {
        cout<<"\n\nIntroduceti directia (N/n, E/e, S/s, W/w) in care se va misca eroul: ";cin>>c;
        if(c=='N' || c=='n')
            ei--;
        if(c=='E' || c=='e')
            ej++;
        if(c=='S' || c=='s')
            ei++;
        if(c=='W' || c=='w')
            ej--;
        if(mat[ei][ej]==1)
        {
            cout<<'\n';
            cout<<'\n';
            cout<<"!!! Eroul a intrat in lupta!!!\n";
            cout<<'\n';
            cout<<'\n';
            cout<<" 1 - Piatra \n 2 - Foarfeca \n 3 - Hartie ";
            int win=0;
            int lose=0;
            int pfh=0;
            while(win+lose<3)
            {
                cout<<'\n';
                cout<<'\n';
                int enemy=rand()%3+1;
                cout<<"Monstrul este pregatit!\n\n";
                cin>>pfh;cout<<'\n';

                if((pfh==3&&enemy==1)||(pfh==2&&enemy==3)||(pfh==1&&enemy==2))
                    win++,cout<<"Eroul a castigat runda!\n Scorul este "<<win<<" - "<<lose;
                else if(pfh==enemy)
                    cout<<"Egalitate!\n Scorul este "<<win<<" - "<<lose;
                else if((pfh==1&&enemy==3)||(pfh==3&&enemy==2)||(pfh==2&&enemy==1))
                    lose++,cout<<"Off, mostrul a castigat runda!\n Scorul este "<<win<<" - "<<lose;
                cout<<'\n';
                cout<<'\n';
            }
            cout<<"Lupta s-a terminat!\n";
            ///Lupta
            if(lose>win)
            {
                cout<<"Din pacate, eroul a pierdut lupta!";
                hp--;
            }
            else
            {
                cout<<"Eroul a castigat lupta!";
                scor++;
            }
            cout<<"\n";
        }
        cout<<'\n';
        cout<<'\n';
        cout<<'\n';
        cout<<'\n';
        cout<<'\n';
        cout<<'\n';
        if(mat[ei][ej]==2)
        {
            cout<<s<<" a ajuns la finalul calatoriei!\n";
            break;
        }
        mat[ei][ej]=3;
        mat[eia][eja]=0;
        eja=ej;
        eia=ei;
        for(i=1;i<=6;i++)
        {
            for(j=1;j<=6;j++)
            {
                if(mat[i][j]==0)
                {
                    cout<<". ";
                }
                else if(mat[i][j]==1)
                {
                    cout<<"X ";
                }
                else if(mat[i][j]==3)
                {
                    cout<<"E ";
                }
                else if(mat[i][j]==2)
                {
                    cout<<"G ";
                }
            }
            if(i==3)
                cout<<"          Hp = "<<hp<<"   Scor: "<<scor;
            cout<<'\n';
        }
    }
    if(hp==0)
    {
        cout<<'\n';
        cout<<'\n';
        cout<<'\n';
        cout<<'\n';
        cout<<'\n';
        cout<<'\n';
        cout<<"Eroul a murit, incearca din nou!\n";
    }
    cout<<"Scorul final obtinut este "<<scor<<" din 8.\n\n\n";
    cout<<'\n';
    cout<<'\n';
    cout<<'\n';
    cout<<'\n';
    cout<<'\n';
    return 0;
}
