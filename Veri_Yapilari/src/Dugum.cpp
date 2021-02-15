/**
* @file Dugum.cpp
* @description Dugum sınıfımızın metot gövdesi... Düğümleri oluşturuyor.
* @course 2.ÖĞRETİM C GRUBU
* @assignment 1
* @date 22.11.2020
* @author İsmail Üçel-ismail.ucel@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

using namespace std;

Dugum::Dugum(int _icerik)
{
    sag = NULL;
    sol = NULL;
    icerik = _icerik;
}
Dugum *Dugum::sagGetir()
{
    return sag;
}
void Dugum::sagAta(Dugum *_sag)
{
    sag = _sag;
}
Dugum *Dugum::solGetir()
{
    return sol;
}
void Dugum::solAta(Dugum * _sol)
{
    sol = _sol;
}
int Dugum::icerikGetir()
{
    return icerik;
}
void Dugum::icerikAta(int _icerik)
{
    icerik = _icerik;
}