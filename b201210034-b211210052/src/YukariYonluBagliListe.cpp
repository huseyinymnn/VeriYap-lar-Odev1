/**
* @file YukariYonluBagliListe.cpp  oldugu dosya
* @description YukarıYonluBağlıListe sınıfının fonksiyonlarının olduğu kisim
* @course yaz okulu 1-B
* @assignment 1.ÖDEV
* @date 24.07.2023-27.07.2023 tarihleri arasında oluşturduk.
* @author Hüseyin Yaman ve Efe Göktepe huseyin.yaman2@ogr.sakarya.edu.tr | efe.goktepe@ogr.sakarya.edu.tr
*/

#include "YukariYonluBagliListe.hpp"


  
YukariYonluBagliListe::YukariYonluBagliListe(){
      ilk=0;
}
   
void YukariYonluBagliListe::ekle(int veri){ //ekleme islemini yapan fonksiyon
		veri=veriOnlarDugum(veri);
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
    
int YukariYonluBagliListe::veriOnlarDugum(int veri){ //ekleme islemini yaparken sadece onlar basamagini veri olarak alan fonksiyon
			if(veri<10) return veri;
            int onlarbasamagi=veri/10;
            return onlarbasamagi;
}

Dugum* YukariYonluBagliListe::baslangic(YukariYonluBagliListe* liste) { //deneme2
  Dugum* ilk = liste->ilk;
  return ilk;
}

/*int YukariYonluBagliListe::listeElemanSayisi(YukariYonluBagliListe* liste) { //deneme1
  int uzunluk = 0;
  Dugum* gecici = liste->ilk;
  while (gecici != nullptr) {
    uzunluk++;
    gecici = gecici->sonraki;
  }
  return uzunluk;
}*/


void YukariYonluBagliListe::silListe(YukariYonluBagliListe* liste) {
			Dugum* gecici = liste->baslangic(liste);
			while (gecici != nullptr) {
				Dugum* silinecek = gecici;
				gecici = gecici->sonraki;
				delete silinecek;
			}
			liste->ilk = nullptr;
		delete liste;
} 
        
void YukariYonluBagliListe::satirYazdir(){			 //yaptigim islemleri kontrol etmek icin yazdigim yazdir fonksiyonu
		Dugum* gec = ilk;
		//cout<<"ilk elemanin adresi: "<<gec;
   
		while(gec!=0)
		{
			cout<<setw(4)<<gec->veri;
			gec=gec->sonraki;
		}
		cout<<endl;
}      
int* YukariYonluBagliListe::diziKonumA(YukariYonluBagliListe* yukariListe,int boyut){ //elemanları değişen yukarı yonlu bagli listenin elemanlarını diziye atayan fonksiyon

			int* dizi=new int[boyut];
			Dugum* gecici=yukariListe->baslangic(yukariListe);
			for(int i=0;i<boyut;i++){
			  dizi[i]=gecici->veri;
			  gecici=gecici->sonraki;	
			}
		return dizi;
		}
		
int YukariYonluBagliListe::listeElemanSayisi(){
			int elemanSayisi=0;
			Dugum* gecici=ilk;
			while(gecici!=NULL){
				gecici=gecici->sonraki;
				elemanSayisi++;
			}
			return elemanSayisi;
		}		