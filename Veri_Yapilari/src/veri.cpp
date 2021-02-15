/**
* @file veri.cpp
* @description veri sınıfımızın metot gövdesi... Sayilar.txt dosyamızdaki elemanları tek tek okuyor, işlemler tamamlandıktan sonra dosyayı kapıyor ve
sayiListeleri listemizi siliyor.
* @course 2.ÖĞRETİM C GRUBU
* @assignment 1
* @date 22.11.2020
* @author İsmail Üçel-ismail.ucel@ogr.sakarya.edu.tr
*/
#include <ListeListesi.hpp>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
    ifstream oku("Sayilar.txt", ios::in);
    string boslugaKadar = "";
    string satir = "";
    ListeListesi *sayiListeleri = new ListeListesi();
    if (oku.is_open())
    {
        while (getline(oku, satir))
        {
            SayiListesi *liste = new SayiListesi();
            boslugaKadar = "";
            int *dizi = new int[satir.length()];
            int gercekUzunluk = 0;
            for (int i = 0; i < satir.length(); i++)
            {
                if (satir[i] == ' ')
                {
                    dizi[gercekUzunluk] = stoi(boslugaKadar);
                    gercekUzunluk++;
                    boslugaKadar = "";
                }
                else
                {
                    boslugaKadar = boslugaKadar + satir[i];
                }
            }
            dizi[gercekUzunluk] = stoi(boslugaKadar);
            gercekUzunluk++;
            liste->ekle(dizi, gercekUzunluk);
            sayiListeleri->listeEkle(liste);
        }
    }
    oku.close();
    sayiListeleri->caprazla();

    delete sayiListeleri;
    system("pause");
}
