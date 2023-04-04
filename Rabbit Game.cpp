///ITL089_Furtuna-Cola Andrei-Alexandru_11
#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

double scor=0;
int Limita=0;

void Start_Story()
{
    system("cls");
    cout<<"Iepurele Bocanila si-a cumparat un teren nou!\n";
    cout<<"Acesta are zone mai luminate, usor de modificat, dar si intunecate, opusul celorlalte.\n";
    cout<<"Cu cat mai luminate, cu atat costa mai putin sa plantezi morcovei!\n";
    cout<<"Scopul este sa incerci sa plantezi morcovei, pentru a cheltui cat mai putin!\n";
    cout<<"De asemenea, poti construi 3 tunele pentru a te deplasa mai usor!/n";
    cout<<"Odata construite, iepurele se deplaseaza pe diagonala 3 spatii, iar terenul devine foarte ieftin de plantat!\n";
    cout<<"Jocul este terminat de indata ce a plantat 16 morcovi, deoarece are nevoie de mancare ca sa poata invata pentru BAC!\n\n";
    cout<<"Atentie, Bocanila nu are decat "<<Limita/100<<"."<<Limita%100<<" lei!";
    system("pause");
}

int main()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    /// you can loop k higher to see more color choices
    /*for(int k = 1; k < 255; k++)
    {
        // pick the colorattribute k you want
        SetConsoleTextAttribute(hConsole, k);
        cout << k << " I want to be nice today!" << endl;
    }
    system("pause");*/

    ///Bordare si setare char
    //  char(201)   char(205)   char(187)    |    -1 -2 -3
    //  char(186)               char(186)    |    -4    -7
    //  char(200)   char(205)   char(188)    |    -5 -2 -6

    ///hconsole - 247 -> 120 -> 128 -> 15
    ///char(176), char(177), char(178);

    //cout<<" "<<char(176)<<char(177)<<char(178);

    srand(time(0));
    int Play_Field[30][30];

    for(int i=0; i<=15; i++)
    {
        for(int j=0; j<=13; j++)
        {
            Play_Field[i][j]=0;
        }
    }
    for(int i=1; i<=14; i++)
    {
        for(int j=1; j<=12; j++)
        {
            Play_Field[i][j]=200+(rand()%300);
            Limita+=Play_Field[i][j];
        }
    }
    Limita=Limita/168*16;

    for(int i=0; i<=13; i++)
    {
        Play_Field[0][i]=-2;
        Play_Field[15][i]=-2;
    }
    for(int i=0; i<=15; i++)
    {
        Play_Field[i][0]=-4;
        Play_Field[i][13]=-7;
    }
    Play_Field[0][0]=-1;
    Play_Field[0][13]=-3;
    Play_Field[15][0]=-5;
    Play_Field[15][13]=-6;


    ///formare matrice!!
    int ending=0;
    Play_Field[1][1]=100;
    int RabbitI=1;
    int RabbitJ=1;
    int Numar_Morcovi=0;
    int Numar_Tunele=0;

    Start_Story();

    ///Start Game

    system("cls");
    SetConsoleTextAttribute(hConsole, 15);
    for(int i=0; i<=15; i++)
    {
        for(int j=0; j<=13; j++)
        {
            if(i==RabbitI && j==RabbitJ)
            {
                SetConsoleTextAttribute(hConsole, 15);
                cout<<char(213)<<char(181);
            }
            else if(Play_Field[i][j]>=200 && Play_Field[i][j]<=500)
            {
                if(Play_Field[i][j]>=200 && Play_Field[i][j]<=200)
                {
                    SetConsoleTextAttribute(hConsole, 240);
                    cout<<"  ";
                }
                if(Play_Field[i][j]>=201 && Play_Field[i][j]<=230)
                {
                    SetConsoleTextAttribute(hConsole, 247);
                    cout<<char(176)<<char(176);
                }
                if(Play_Field[i][j]>=231 && Play_Field[i][j]<=260)
                {
                    SetConsoleTextAttribute(hConsole, 247);
                    cout<<char(177)<<char(177);
                }
                if(Play_Field[i][j]>=261 && Play_Field[i][j]<=290)
                {
                    SetConsoleTextAttribute(hConsole, 247);
                    cout<<char(178)<<char(178);
                }

                if(Play_Field[i][j]>=291 && Play_Field[i][j]<=320)
                {
                    SetConsoleTextAttribute(hConsole, 128);
                    cout<<"  ";
                }
                if(Play_Field[i][j]>=321 && Play_Field[i][j]<=350)
                {
                    SetConsoleTextAttribute(hConsole, 128);
                    cout<<char(176)<<char(176);
                }
                if(Play_Field[i][j]>=351 && Play_Field[i][j]<=380)
                {
                    SetConsoleTextAttribute(hConsole, 128);
                    cout<<char(177)<<char(177);
                }
                if(Play_Field[i][j]>=381 && Play_Field[i][j]<=410)
                {
                    SetConsoleTextAttribute(hConsole, 128);
                    cout<<char(178)<<char(178);
                }

                if(Play_Field[i][j]>=411 && Play_Field[i][j]<=440)
                {
                    SetConsoleTextAttribute(hConsole, 120);
                    cout<<"  ";
                }
                if(Play_Field[i][j]>=441 && Play_Field[i][j]<=470)
                {
                    SetConsoleTextAttribute(hConsole, 120);
                    cout<<char(176)<<char(176);
                }
                if(Play_Field[i][j]>=471 && Play_Field[i][j]<500)
                {
                    SetConsoleTextAttribute(hConsole, 120);
                    cout<<char(177)<<char(177);
                }
                if(Play_Field[i][j]>=500 && Play_Field[i][j]<=500)
                {
                    SetConsoleTextAttribute(hConsole, 120);
                    cout<<char(178)<<char(178);
                }
            }
            else if(Play_Field[i][j]==-1)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(201)<<char(205);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-2)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(205)<<char(205);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-3)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(205)<<char(187);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-4)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(186)<<" ";
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-5)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(200)<<char(205);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-6)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(205)<<char(188);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-7)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<" "<<char(186);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<"  ";
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        cout<<'\n';
    }
    while(!ending)
    {
        char direction[100];
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n\nIn ce directie ati dori sa se deplaseze Bocanila?\n";
        cout<<"\n(W pentru nord, A pentru vest, S pentru sud, si D pentru est! Sau apasa P pentru a planta un morcov)\n";
        cout<<"\n(Pentru a construi un tunel, scrie \"Tunel1\", si un tunel va fi construit in dreapta sus, \"Tunel2\", si un tunel va fi construit in dreapta jos!\n";
        cout<<"   \"Tunel3\", si un tunel va fi construit in stanga sus, sau \"Tunel4\", si un tunel va fi construit in stanga jos!)\n";
        int valid=0;
        ///MOVEMENT
        do
        {
            valid=0;
            cin>>direction;
            if(!strcmp(direction,"p") ||!strcmp(direction,"P"))
            {
                if(Play_Field[RabbitI][RabbitJ]>7 && Play_Field[RabbitI][RabbitJ]<=500)
                {
                    scor+=Play_Field[RabbitI][RabbitJ];
                    valid=1;
                    Play_Field[RabbitI][RabbitJ]=7;
                    ++Numar_Morcovi;
                    if(Numar_Morcovi==16)
                        ending=1;
                }
            }
            ///TUNNEL
            if(Numar_Tunele<3)
            {
                if(!strcmp(direction,"Tunel1"))
                {
                    Play_Field[RabbitI][RabbitJ]=11;
                    Play_Field[RabbitI-1][RabbitJ+1]=10;
                    Play_Field[RabbitI-2][RabbitJ+2]=10;
                    Play_Field[RabbitI-3][RabbitJ+3]=11;
                    RabbitI-=3;
                    RabbitJ+=3;
                    valid=1;
                    Numar_Tunele++;
                }
                else if(!strcmp(direction,"Tunel2"))
                {
                    Play_Field[RabbitI][RabbitJ]=11;
                    Play_Field[RabbitI+1][RabbitJ+1]=10;
                    Play_Field[RabbitI+2][RabbitJ+2]=10;
                    Play_Field[RabbitI+3][RabbitJ+3]=11;
                    RabbitI+=3;
                    RabbitJ+=3;
                    valid=1;
                    Numar_Tunele++;
                }
                else if(!strcmp(direction,"Tunel3"))
                {
                    Play_Field[RabbitI][RabbitJ]=11;
                    Play_Field[RabbitI-1][RabbitJ-1]=10;
                    Play_Field[RabbitI-2][RabbitJ-2]=10;
                    Play_Field[RabbitI-3][RabbitJ-3]=11;
                    RabbitI-=3;
                    RabbitJ-=3;
                    valid=1;
                    Numar_Tunele++;
                }
                else if(!strcmp(direction,"Tunel4"))
                {
                    Play_Field[RabbitI][RabbitJ]=11;
                    Play_Field[RabbitI+1][RabbitJ-1]=10;
                    Play_Field[RabbitI+2][RabbitJ-2]=10;
                    Play_Field[RabbitI+3][RabbitJ-3]=11;
                    RabbitI+=3;
                    RabbitJ-=3;
                    valid=1;
                    Numar_Tunele++;
                }
            }
            ///Rook movement
            if(!strcmp(direction,"w") || !strcmp(direction,"W"))
            {
                RabbitI--;
                valid=1;
            }
            if(!strcmp(direction,"d") || !strcmp(direction,"D"))
            {
                RabbitJ++;
                valid=1;
            }
            if(!strcmp(direction,"s") || !strcmp(direction,"S"))
            {
                RabbitI++;
                valid=1;
            }
            if(!strcmp(direction,"a") || !strcmp(direction,"A"))
            {
                RabbitJ--;
                valid=1;
            }
            ///Bishop movement
            if(!strcmp(direction,"wa") || !strcmp(direction,"WA") || !strcmp(direction,"aw") || !strcmp(direction,"AW"))
            {
                RabbitI--;
                RabbitJ--;
                valid=1;
            }
            if(!strcmp(direction,"wd") || !strcmp(direction,"WD") || !strcmp(direction,"dw") || !strcmp(direction,"DW"))
            {
                RabbitI--;
                RabbitJ++;
                valid=1;
            }
            if(!strcmp(direction,"sa") || !strcmp(direction,"SA") || !strcmp(direction,"as") || !strcmp(direction,"AS"))
            {
                RabbitI++;
                RabbitJ--;
                valid=1;
            }
            if(!strcmp(direction,"sd") || !strcmp(direction,"SD") || !strcmp(direction,"ds") || !strcmp(direction,"DS"))
            {
                RabbitI++;
                RabbitJ++;
                valid=1;
            }
            if(!valid)
            {
                cout<<"Miscarea nu este corecta... Incearca din nou!\n";
            }
        }
        while(!valid);

        int Start_BAD_ENDING=1;
        system("cls");
        for(int i=0; i<=15; i++)
        {
            for(int j=0; j<=13; j++)
            {
                if(i==RabbitI && j==RabbitJ)
                {
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<char(213)<<char(181);
                    Start_BAD_ENDING=0;
                }
                else if(Play_Field[i][j]==7)
                {
                    SetConsoleTextAttribute(hConsole, 228);
                    cout<<char(233)<<" ";
                }
                else if(Play_Field[i][j]>=200 && Play_Field[i][j]<=500)
                {
                    if(Play_Field[i][j]>=200 && Play_Field[i][j]<=200)
                    {
                        SetConsoleTextAttribute(hConsole, 240);
                        cout<<"  ";
                    }
                    else if(Play_Field[i][j]>=201 && Play_Field[i][j]<=230)
                    {
                        SetConsoleTextAttribute(hConsole, 247);
                        cout<<char(176)<<char(176);
                    }
                    else if(Play_Field[i][j]>=231 && Play_Field[i][j]<=260)
                    {
                        SetConsoleTextAttribute(hConsole, 247);
                        cout<<char(177)<<char(177);
                    }
                    else if(Play_Field[i][j]>=261 && Play_Field[i][j]<=290)
                    {
                        SetConsoleTextAttribute(hConsole, 247);
                        cout<<char(178)<<char(178);
                    }

                    else if(Play_Field[i][j]>=291 && Play_Field[i][j]<=320)
                    {
                        SetConsoleTextAttribute(hConsole, 128);
                        cout<<"  ";
                    }
                    else if(Play_Field[i][j]>=321 && Play_Field[i][j]<=350)
                    {
                        SetConsoleTextAttribute(hConsole, 128);
                        cout<<char(176)<<char(176);
                    }
                    else if(Play_Field[i][j]>=351 && Play_Field[i][j]<=380)
                    {
                        SetConsoleTextAttribute(hConsole, 128);
                        cout<<char(177)<<char(177);
                    }
                    else if(Play_Field[i][j]>=381 && Play_Field[i][j]<=410)
                    {
                        SetConsoleTextAttribute(hConsole, 128);
                        cout<<char(178)<<char(178);
                    }

                    else if(Play_Field[i][j]>=411 && Play_Field[i][j]<=440)
                    {
                        SetConsoleTextAttribute(hConsole, 120);
                        cout<<"  ";
                    }
                    else if(Play_Field[i][j]>=441 && Play_Field[i][j]<=470)
                    {
                        SetConsoleTextAttribute(hConsole, 120);
                        cout<<char(176)<<char(176);
                    }
                    else if(Play_Field[i][j]>=471 && Play_Field[i][j]<500)
                    {
                        SetConsoleTextAttribute(hConsole, 120);
                        cout<<char(177)<<char(177);
                    }
                    else if(Play_Field[i][j]>=500 && Play_Field[i][j]<=500)
                    {
                        SetConsoleTextAttribute(hConsole, 120);
                        cout<<char(178)<<char(178);
                    }
                }
                else if(Play_Field[i][j]==-1)
                {
                    SetConsoleTextAttribute(hConsole, 240);
                    cout<<char(201)<<char(205);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if(Play_Field[i][j]==-2)
                {
                    SetConsoleTextAttribute(hConsole, 240);
                    cout<<char(205)<<char(205);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if(Play_Field[i][j]==-3)
                {
                    SetConsoleTextAttribute(hConsole, 240);
                    cout<<char(205)<<char(187);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if(Play_Field[i][j]==-4)
                {
                    SetConsoleTextAttribute(hConsole, 240);
                    cout<<char(186)<<" ";
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if(Play_Field[i][j]==-5)
                {
                    SetConsoleTextAttribute(hConsole, 240);
                    cout<<char(200)<<char(205);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if(Play_Field[i][j]==-6)
                {
                    SetConsoleTextAttribute(hConsole, 240);
                    cout<<char(205)<<char(188);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if(Play_Field[i][j]==-7)
                {
                    SetConsoleTextAttribute(hConsole, 240);
                    cout<<" "<<char(186);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, 240);
                    cout<<"  ";
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
            cout<<'\n';
        }

        ///Bad ending
        if(Start_BAD_ENDING)
        {
            ending=2;
            system("cls");
            cout<<"Oh nu! Bocanila a sarit din greseala in afara parcelei sale! Din pacate, acesta s-a pierdut...\n";
            cout<<"Nu iti face griji! Poti incerca din nou! Cu un nou spatiu de data asta!\n\n";
            system("pause");
            return 0;
        }
    }

    system("cls");
    for(int i=0; i<=15; i++)
    {
        for(int j=0; j<=13; j++)
        {
            if(i==RabbitI && j==RabbitJ)
            {
                SetConsoleTextAttribute(hConsole, 15);
                cout<<char(213)<<char(181);
            }
            else if(Play_Field[i][j]==7)
            {
                SetConsoleTextAttribute(hConsole, 228);
                cout<<char(233)<<" ";
            }
            else if(Play_Field[i][j]>=200 && Play_Field[i][j]<=500)
            {
                if(Play_Field[i][j]>=200 && Play_Field[i][j]<=200)
                {
                    SetConsoleTextAttribute(hConsole, 240);
                    cout<<"  ";
                }
                else if(Play_Field[i][j]>=201 && Play_Field[i][j]<=230)
                {
                    SetConsoleTextAttribute(hConsole, 247);
                    cout<<char(176)<<char(176);
                }
                else if(Play_Field[i][j]>=231 && Play_Field[i][j]<=260)
                {
                    SetConsoleTextAttribute(hConsole, 247);
                    cout<<char(177)<<char(177);
                }
                else if(Play_Field[i][j]>=261 && Play_Field[i][j]<=290)
                {
                    SetConsoleTextAttribute(hConsole, 247);
                    cout<<char(178)<<char(178);
                }

                else if(Play_Field[i][j]>=291 && Play_Field[i][j]<=320)
                {
                    SetConsoleTextAttribute(hConsole, 128);
                    cout<<"  ";
                }
                else if(Play_Field[i][j]>=321 && Play_Field[i][j]<=350)
                {
                    SetConsoleTextAttribute(hConsole, 128);
                    cout<<char(176)<<char(176);
                }
                else if(Play_Field[i][j]>=351 && Play_Field[i][j]<=380)
                {
                    SetConsoleTextAttribute(hConsole, 128);
                    cout<<char(177)<<char(177);
                }
                else if(Play_Field[i][j]>=381 && Play_Field[i][j]<=410)
                {
                    SetConsoleTextAttribute(hConsole, 128);
                    cout<<char(178)<<char(178);
                }

                else if(Play_Field[i][j]>=411 && Play_Field[i][j]<=440)
                {
                    SetConsoleTextAttribute(hConsole, 120);
                    cout<<"  ";
                }
                else if(Play_Field[i][j]>=441 && Play_Field[i][j]<=470)
                {
                    SetConsoleTextAttribute(hConsole, 120);
                    cout<<char(176)<<char(176);
                }
                else if(Play_Field[i][j]>=471 && Play_Field[i][j]<500)
                {
                    SetConsoleTextAttribute(hConsole, 120);
                    cout<<char(177)<<char(177);
                }
                else if(Play_Field[i][j]>=500 && Play_Field[i][j]<=500)
                {
                    SetConsoleTextAttribute(hConsole, 120);
                    cout<<char(178)<<char(178);
                }
            }
            else if(Play_Field[i][j]==-1)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(201)<<char(205);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-2)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(205)<<char(205);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-3)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(205)<<char(187);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-4)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(186)<<" ";
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-5)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(200)<<char(205);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-6)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<char(205)<<char(188);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(Play_Field[i][j]==-7)
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<" "<<char(186);
                SetConsoleTextAttribute(hConsole, 15);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 240);
                cout<<"  ";
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        cout<<'\n';
    }

    if(ending)
    {
        if(scor>Limita)
        {
            system("cls");
            cout<<"Oh nu... Bocanila nu a avut destui bani... a picat BAC-ul... insa nu te descuraja!\n";
            cout<<"La anul incearca din nou! Si iti cere ajutorul inca odata!\n";
            system("pause");
            return 0;
        }
        cout<<"\n\n\n";

        ///line 1
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 2
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 3
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 4
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 5
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 6
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 7
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 8
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 9
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 10
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 11
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 12
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 13
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  "<<"  "<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 14
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 15
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 128);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 16
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        ///line 17
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        SetConsoleTextAttribute(hConsole, 32);
        cout<<"  "<<"  ";
        cout<<'\n';

        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n\n";
        cout<<"In total, pentru a pune morcovii, a costat "<<scor/100<<" din cei "<<Limita/100<<"."<<Limita%100<<" lei!\n";
        cout<<"Felicitari!! Bocanila a luat nota 10 la BAC si se pregateste pentru universitate!\n";
        cout<<"Va multumeste pentru ajutorul oferit! Fara voi, nu ar fi putut sa faca acest lucru!\n";
    }

    return 0;
}
