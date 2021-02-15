/**
* @file SayiListesi.hpp
* @description SayiListesi sınıfının tanımını yapıyoruz.ekle ve yazdir gibi metotlarımızı belirtiyoruz.
* @course 2.ÖĞRETİM C GRUBU
* @assignment 1
* @date 22.11.2020
* @author İsmail Üçel-ismail.ucel@ogr.sakarya.edu.tr
*/

#ifndef SAYILISTESI_HPP
#define SAYILISTESI_HPP

#include <iostream>
#include "Dugum.hpp"

using namespace std;

class SayiListesi
{
    public:
        Dugum* listeOrta;
        int elemanSayisi;
        SayiListesi* sonrakiListe;
        SayiListesi();
        void ekle(int *sayilar,int uzunluk);
        void yazdir();
        ~SayiListesi();
};

#endif