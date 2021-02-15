/**
* @file ListeListesi.hpp
* @description ListeListesi sınıfının tanımını yapıyoruz.listeEkle,caprazla ve tersCevir gibi metotlarımızı belirtiyoruz.
* @course 2.ÖĞRETİM C GRUBU
* @assignment 1
* @date 22.11.2020
* @author İsmail Üçel-ismail.ucel@ogr.sakarya.edu.tr
*/

#ifndef LISTELISTESI_HPP
#define LISTELISTES_HPP

#include <iostream>
#include "SayiListesi.hpp"
using namespace std;

class ListeListesi
{
public:
	SayiListesi* bas;
	ListeListesi();
	void listeEkle(SayiListesi* _liste); //Sona eleman ekle
	SayiListesi* enBuyukListe();
	SayiListesi* enKucukListe();
	void caprazla(); //Caprazlama islemi
	void tersCevir(Dugum* _bas); //Baglantilari ters cevirir
	~ListeListesi();
};

#endif