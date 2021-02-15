/**
* @file SayiListesi.cpp
* @description SayiListesi sınıfımızın metot gövdesi... Yapıcı metodumuzu oluşturuyor.
Listenin her elemanına dosyadaki her satırdan
okuduğumuz verileri atamak için bir döngü oluşturup atama işlemini bu döngü içerisinde
yapıyor.
* @course 2.ÖĞRETİM C GRUBU
* @assignment 1
* @date 22.11.2020
* @author İsmail Üçel-ismail.ucel@ogr.sakarya.edu.tr
*/

#include "SayiListesi.hpp"
using namespace std;

SayiListesi::SayiListesi()
{
    listeOrta = NULL;
    elemanSayisi = 0 ;
    sonrakiListe = NULL;
}

void SayiListesi::ekle(int *sayilar, int uzunluk)
{
    Dugum *yeni;
    elemanSayisi = uzunluk;
    for (int i = 0; i < uzunluk; i++)
    {
        //Liste Bossa
        if (listeOrta == NULL)
        {
            listeOrta = new Dugum(sayilar[i]);
        }
        else
        {
            if (i <= (uzunluk - 1) / 2)
            {
                //sola ekle
                yeni = new Dugum(sayilar[i]);
                Dugum *pOrta = listeOrta;
                //en sola git
                while (pOrta->solGetir() != NULL)
                {
                    pOrta = pOrta->solGetir();
                }

                pOrta->solAta(yeni);
                yeni->sagAta(pOrta);
            }
            else
            {
                //saga ekle
                yeni = new Dugum(sayilar[i]);
                Dugum *pOrta = listeOrta;
                //en saga git
                while (pOrta->sagGetir() != NULL)
                {
                    pOrta = pOrta->sagGetir();
                }
                pOrta->sagAta(yeni);
                yeni->solAta(pOrta);
            }
        }
    }

    //en saga git
    Dugum *pEnSag = listeOrta;
    while (pEnSag->sagGetir() != NULL)
    {
        pEnSag = pEnSag->sagGetir();
    }
    //en sola git
    Dugum *pEnSol = listeOrta;
    while (pEnSol->solGetir() != NULL)
    {
        pEnSol = pEnSol->solGetir();
    }
    //Birbirlerine bagla
    pEnSag->sagAta(pEnSol);
    pEnSol->solAta(pEnSag);

    //diziyi sil
    delete sayilar;
}

void SayiListesi::yazdir()
{
    Dugum *pOrta = listeOrta;
    for (int i = 0; i < (elemanSayisi-1)/2; i++)
    {
        pOrta = pOrta->solGetir();
    }
    for (int i = 0; i < elemanSayisi ; i++)
    {
       cout <<  pOrta->icerikGetir() << " ";
        pOrta = pOrta->sagGetir();
    }
    cout << endl;
}

SayiListesi::~SayiListesi(){
    Dugum *orta = listeOrta->sagGetir();
    while (orta != listeOrta)
    {
        Dugum* tutucu = orta;
        orta = orta->sagGetir();
        delete tutucu;
    }
}