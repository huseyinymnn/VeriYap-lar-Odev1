/**
* @file YukariYonluBagliListe.cpp  oldugu dosya
* @description AsagiYonluBağlıListe sınıfının fonksiyonlarının olduğu kisim
* @course yaz okulu 1-B
* @assignment 1.ÖDEV
* @date 24.07.2023-27.07.2023 tarihleri arasında oluşturduk.
* @author Hüseyin Yaman ve Efe Göktepe huseyin.yaman2@ogr.sakarya.edu.tr | efe.goktepe@ogr.sakarya.edu.tr
*/
#include "AsagiYonluBagliListe.hpp"


  
AsagiYonluBagliListe::AsagiYonluBagliListe(){
      ilk=0;
}
      
void AsagiYonluBagliListe::ekle(int veri){ //ekleme islemini yapan fonksiyon
		veri=veriBirlerDugum(veri);
		Dugum* yeni = new Dugum(veri);
    if(ilk==0)
    {
        ilk = yeni;
        return;
        
    }
		Dugum* gecici = ilk;
	while(gecici->sonraki!=0){
			gecici= gecici->sonraki;
	}
		gecici->sonraki = yeni;
		
}
    
int AsagiYonluBagliListe::veriBirlerDugum(int veri){ //ekleme islemini yaparken sadece birler basamagini veri olarak alan fonksiyon
            int birlerbasamagi=veri%10;
            return birlerbasamagi;
}

Dugum* AsagiYonluBagliListe::baslangic(AsagiYonluBagliListe* liste) { //deneme2
  Dugum* ilk = liste->ilk;
  return ilk;
}

/*int AsagiYonluBagliListe::listeElemanSayisi(AsagiYonluBagliListe* liste) { //deneme1
  int uzunluk = 0;
  Dugum* gecici = liste->ilk;
  while (gecici != nullptr) {
    uzunluk++;
    gecici = gecici->sonraki;
  }
  return uzunluk;
} */
        
void AsagiYonluBagliListe::satirYazdir(){			 //yaptigim islemleri kontrol etmek icin yazdigim yazdir fonksiyonu
		Dugum* gec = ilk;
		cout<<"ilk elemanin adresi: "<<gec;
   
		while(gec!=0)
		{
			cout<<setw(4)<<gec->veri;
			gec=gec->sonraki;
		}
		cout<<endl;
}      
void AsagiYonluBagliListe::silListe(AsagiYonluBagliListe* liste) {
			Dugum* gecici = liste->baslangic(liste);
			while (gecici != nullptr) {
				Dugum* silinecek = gecici;
				gecici = gecici->sonraki;
				delete silinecek;
			}
			liste->ilk = nullptr;
		delete liste;
} 
int AsagiYonluBagliListe::listeElemanSayisi(){
			int elemanSayisi=0;
			Dugum* gecici=ilk;
			while(gecici!=NULL){
				gecici=gecici->sonraki;
				elemanSayisi++;
			}
			return elemanSayisi;
		}