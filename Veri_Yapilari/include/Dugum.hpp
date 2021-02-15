/**
* @file Dugum.hpp
* @description Dugum sınıfının tanımını yapıyoruz.sagAta,solAta,icerikGetir,icerikAta gibi metotlarımızı belirtiyoruz.
* @course 2.ÖĞRETİM C GRUBU
* @assignment 1
* @date 22.11.2020
* @author İsmail Üçel-ismail.ucel@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
using namespace std;

class Dugum
{
private:
	Dugum* sag;
	Dugum* sol;
	int icerik;
public:
	Dugum(int _icerik);
	Dugum* sagGetir();
	Dugum* solGetir();
	void sagAta(Dugum* _sag);
	void solAta(Dugum* _sol);
	int icerikGetir();
	void icerikAta(int _icerik);	
};
#endif
