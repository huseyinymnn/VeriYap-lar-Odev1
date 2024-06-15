/**
* @file YukariYonluBagliListe sınıfının oldugu dosya
* @description YukariYonluBagliListe fonksiyonlarının tanımlandığı kısım 
* @course yaz okulu 1-B
* @assignment 1.ÖDEV
* @date 24.07.2023-27.07.2023 tarihleri arasında oluşturduk.
* @author Hüseyin Yaman ve Efe Göktepe huseyin.yaman2@ogr.sakarya.edu.tr | efe.goktepe@ogr.sakarya.edu.tr
*/

#ifndef YukariYonluBagliListe_hpp
#define YukariYonluBagliListe_hpp
#include<iostream>
#include<iomanip>
#include "Dugum.hpp"

using namespace std;

class YukariYonluBagliListe
{
	public:
	
		YukariYonluBagliListe();
		void ekle(int veri);
		int veriOnlarDugum(int veri);
		void satirYazdir();
		int listeElemanSayisi(); 
		Dugum* baslangic(YukariYonluBagliListe* liste); //deneme2
		void silListe(YukariYonluBagliListe* liste);
		int* diziKonumA(YukariYonluBagliListe* yukariListe,int boyut);
		//void ust(YukariYonluBagliListe** konumA, int satirSayisi,int uzunluk);
		private:
		Dugum* ilk;
		
		
		
};


#endif