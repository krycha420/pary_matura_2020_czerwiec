#include <iostream>
#include <fstream>
using namespace std;
int liczby[100];
string slowa [100];
int ntab [100];
string nslowa[100];
char literka;
int najmneijszaliczba;
string najmniejszalitera;
int dzielnik =2, ile =0, maxile=0;

bool CzyPierwsza(int n)
{
    for(int dzielnik =2; dzielnik*dzielnik <= n; dzielnik++)
    {
        if(n%dzielnik==0)
            return false;
    }
    return true;
}


int main()
{
    ifstream in("pary.txt");
    ofstream out("wyniki.txt");
    for(int i =0; i<100; i++)
    {
        in>>liczby[i]>>slowa[i];
    }
    in.close();
    out << "4.1" <<endl;
    for(int i =0; i<100; i++)
    {
        if(liczby[i]%2==0)
        {
            if (liczby[i] ==4)
            {
                out << "4 2 2 "<< endl;
                continue;
            }
            for(int kandydat =3; kandydat <liczby[i]; kandydat+=2)
            {
                if(CzyPierwsza(kandydat)&& CzyPierwsza(liczby[i]-kandydat))
                {
                    out << liczby[i]<< " "<< kandydat << " " << liczby[i]- kandydat<< endl;
                    break;
                }
            }
        }
    }

    out << "4.2" << endl;
    for ( int i = 0; i<100; i++)
    {
        maxile =1;
        ile =1;
        for (int n =0; n<slowa[i].length(); n++)
        {
            if(slowa[i][n]== slowa[i][n+1])
            {
                ile++;
                if(ile>maxile)
                {
                    maxile = ile;
                    literka = slowa[i][n];

                }
            }
            else
            {
                ile = 1;
            }


        }
        if(maxile==1)
        {
            literka = slowa[i][0];
        }

        for (int u =0; u<maxile; u++)
        {
            out << literka;
        }
        out <<" ";
        out << maxile << endl;
    }
 for (int i =0; i<100; i++)
 {
     if(liczby[i]== slowa[i].length())
     {
       if((liczby[i]< liczby[0]) || (liczby[i]==liczby[0]&& slowa[i]<slowa[0]))
     {
         swap(liczby[0], liczby[i]);
         swap(slowa[0], slowa[i]);
     }
     }

 }
out<< "4.3" << endl;
out << liczby[0]<< " " << slowa [0]<< endl;
out.close();
if (slowa[20]<slowa[26])
    cout << "Tak" << endl;
else
    cout << "nie" << endl;
}
