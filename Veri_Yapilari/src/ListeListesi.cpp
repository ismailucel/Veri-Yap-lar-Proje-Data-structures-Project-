/**
* @file ListeListesi.cpp
* @description ListeListesi sınıfımızın metot gövdesi... Bu kod bloğunda yapıcı metodumuzdan sonra swap işlemlerimizi yapıyoruz.
* @course 2.ÖĞRETİM C GRUBU
* @assignment 1
* @date 22.11.2020
* @author İsmail Üçel-ismail.ucel@ogr.sakarya.edu.tr
*/
#include "ListeListesi.hpp"

ListeListesi::ListeListesi()
{
    bas = NULL;
}

void ListeListesi::listeEkle(SayiListesi *_liste)
{
    //Eger liste bossa
    if (bas == NULL)
    {
        bas = _liste;
    }
    else
    {
        SayiListesi *pBas = bas;
        //Sona git
        while (pBas->sonrakiListe != NULL)
        {
            pBas = pBas->sonrakiListe;
        }
        pBas->sonrakiListe = _liste;
    }
}

SayiListesi *ListeListesi::enBuyukListe()
{
    SayiListesi *pBas = bas;
    SayiListesi *enBuyuk = bas;
    while (pBas != NULL)
    {
        if (enBuyuk->listeOrta->icerikGetir() < pBas->listeOrta->icerikGetir())
        {
            enBuyuk = pBas;
        }
        pBas = pBas->sonrakiListe;
    }
    return enBuyuk;
}

SayiListesi *ListeListesi::enKucukListe()
{
    SayiListesi *pBas = bas;
    SayiListesi *enKucuk = bas;
    while (pBas != NULL)
    {
        if (enKucuk->listeOrta->icerikGetir() > pBas->listeOrta->icerikGetir())
        {
            enKucuk = pBas;
        }
        pBas = pBas->sonrakiListe;
    }
    return enKucuk;
}

void ListeListesi::caprazla()
{
    SayiListesi *enBuyuk = enBuyukListe();
    SayiListesi *enKucuk = enKucukListe();

    Dugum *bSolBas = enBuyuk->listeOrta->solGetir();
    Dugum *kSagBas = enKucuk->listeOrta->sagGetir();
    Dugum *bSagBas = enBuyuk->listeOrta->sagGetir();
    Dugum *kSolBas = enKucuk->listeOrta->solGetir();
    //ayir
    bSolBas->sagAta(NULL);
    enBuyuk->listeOrta->solAta(NULL);
    //ayir
    bSagBas->solAta(NULL);
    enBuyuk->listeOrta->sagAta(NULL);
    //ayir
    kSagBas->solAta(NULL);
    enKucuk->listeOrta->sagAta(NULL);
    //ayir
    kSolBas->sagAta(NULL);
    enKucuk->listeOrta->solAta(NULL);

    tersCevir(bSagBas);
    tersCevir(kSagBas);

    //bagla
    bSolBas->solAta(enKucuk->listeOrta);
    enKucuk->listeOrta->sagAta(bSolBas);
    //bagla
    bSagBas->sagAta(enKucuk->listeOrta);
    enKucuk->listeOrta->solAta(bSagBas);
    //bagla
    kSagBas->sagAta(enBuyuk->listeOrta);
    enBuyuk->listeOrta->solAta(kSagBas);
    //bagla
    kSolBas->solAta(enBuyuk->listeOrta);
    enBuyuk->listeOrta->sagAta(kSolBas);

    int kucukElemanSay = enKucuk->elemanSayisi;
    enKucuk->elemanSayisi = enBuyuk->elemanSayisi;
    enBuyuk->elemanSayisi = kucukElemanSay;

    cout << "EN BUYUK LISTE ORTA DUGUM ADRES: " << enBuyuk->listeOrta << endl;
    cout << "EN BUYUK LISTE DEGERLER:" << endl;
    enBuyuk->yazdir();
    cout << "EN KUCUK LISTE ORTA DUGUM ADRES: " << enKucuk->listeOrta << endl;
	cout << "EN KUCUK LISTE DEGERLER:" << endl;
    enKucuk->yazdir();
}

void ListeListesi::tersCevir(Dugum* _bas){
    //Solu sag yap
    while(_bas != NULL){
        Dugum* solTut = _bas->solGetir();
        _bas->solAta(_bas->sagGetir());
        _bas->sagAta(solTut);
        _bas = _bas->solGetir();
    }
}

ListeListesi::~ListeListesi(){
    SayiListesi *pBas = bas;
    while (pBas != NULL)
    {
        SayiListesi* silinecek  = pBas;
        pBas = pBas->sonrakiListe;
        delete silinecek;
    }
}