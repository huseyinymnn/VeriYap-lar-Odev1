/**
* @file AsagiYonluBagliListe sınıfının oldugu dosya
* @description AsagiYonluBagliListe fonksiyonlarının tanımlandığı kısım
* @course yaz okulu 1-B
* @assignment 1.ÖDEV
* @date 24.07.2023-27.07.2023 tarihleri arasında oluşturduk.
* @author Hüseyin Yaman ve Efe Göktepe huseyin.yaman2@ogr.sakarya.edu.tr | efe.goktepe@ogr.sakarya.edu.tr
*/
#ifndef AsagiYonluBagliListe_hpp
#define AsagiYonluBagliListe_hpp
#include<iostream>
#include<iomanip>
#include "Dugum.hpp"

using namespace std;

class AsagiYonluBagliListe
{
	public:
		AsagiYonluBagliListe();
		void ekle(int veri);
		int veriBirlerDugum(int veri);
		void satirYazdir();
		int listeElemanSayisi(); //deneme1
		Dugum* baslangic(AsagiYonluBagliListe* liste); //deneme2
		void silListe(AsagiYonluBagliListe* liste);
		private:
		Dugum* ilk;
		
		
};


#endif