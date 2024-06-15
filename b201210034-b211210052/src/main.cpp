/**
* @file main.cpp
* @description main fonksiyonun calistigi kisim
* @course yaz okulu 1-B
* @assignment 1.ÖDEV
* @date 24.07.2023-27.07.2023 tarihleri arasında oluşturduk.
* @author Hüseyin Yaman ve Efe Göktepe huseyin.yaman2@ogr.sakarya.edu.tr | efe.goktepe@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "Dugum.hpp"
#include "YukariYonluBagliListe.hpp"
#include "AsagiYonluBagliListe.hpp"

using namespace std;
YukariYonluBagliListe* *konumA; 
AsagiYonluBagliListe* *konumB; 
int satirAdedi(const string& dosyaAdi) {
  std::ifstream dosya(dosyaAdi);
  int satirSayisi = 0;

  if (dosya.is_open()) {
    std::string satir;
    while (std::getline(dosya, satir)) {
      satirSayisi++;
    }
  }

  dosya.close();

  return satirSayisi;
}
int maxSatirUzunlugu(const string& dosyaAdi) {
  ifstream dosya(dosyaAdi);
  int maxSayi = 0;
  int gecici = 0;
  int sayici = 0;

  if (dosya.is_open()) {
    std::string satir;
    while (std::getline(dosya, satir)) {
      std::stringstream satirOkuyucu(satir);
      while (satirOkuyucu >> sayici) {
        gecici++;
        if (gecici > maxSayi) {
          maxSayi = gecici;
        }
      }
      gecici = 0;
    }
  }

  dosya.close();

  return maxSayi;
}
//const int satirSayisi=satirAdedi("Sayilar.txt");

YukariYonluBagliListe* listeleriDegistir(YukariYonluBagliListe** konumA, AsagiYonluBagliListe* *konumB, int indexA, int indexB){
	YukariYonluBagliListe* yliste = konumA[indexA];
  AsagiYonluBagliListe* aliste = konumB[indexB];
  Dugum* ygecici=yliste->baslangic(yliste);
  Dugum* agecici=aliste->baslangic(aliste);
  int elemanSayisiA = yliste->listeElemanSayisi();
  int elemanSayisiB = aliste->listeElemanSayisi();
  int* diziA = new int[elemanSayisiA];
  int* diziB = new int[elemanSayisiB];
  
  
  for (int i = 0; i < elemanSayisiA; i++) {
	  
    diziA[i] = ygecici->veri;
	//cout<<"veri:"<<ygecici->veri;
	ygecici=ygecici->sonraki;
  }
  
  for (int i = 0; i < elemanSayisiB; i++) {
    diziB[i] = agecici->veri;
	//cout<<"dizib veri:"<<agecici->veri<<" ";
	agecici=agecici->sonraki;
	
  }
     
	   yliste->silListe(yliste);
	  YukariYonluBagliListe* yeniYukari = new YukariYonluBagliListe;
	 
	  for (int i = 0; i < elemanSayisiB; i++) {
		  int sayi=diziB[i];
		  yeniYukari->ekle(sayi);
		}
		//yeniYukari->satirYazdir();
		
		konumA[indexA] = yeniYukari;
  return  konumA[indexA];
}
AsagiYonluBagliListe* asagiListeleriDegistir(AsagiYonluBagliListe** konumB, int indexB, int* dizi,int boyut){
	
  AsagiYonluBagliListe* aliste = konumB[indexB];
 // int boyut=aliste->listeElemanSayisi();
  Dugum* agecici=aliste->baslangic(aliste);
  int elemanSayisiB = aliste->listeElemanSayisi();
  
  
  //Dugum* diziGoster=satirKaydet;
  
  
  
	   aliste->silListe(aliste);           //elemanlarını değiştirdiğim listeyi siliyorum
	  AsagiYonluBagliListe* yeniAsagi = new AsagiYonluBagliListe; //yeni elemanları atayacağım listeyi oluşturuyorum
	 
	  for (int i = 0; i <boyut;i++) { //oluşturduğum yeni listeye elemanları atıyorum
		  int sayi=dizi[i];
		  yeniAsagi->ekle(sayi);
	  }
	  
		//yeniAsagi->satirYazdir();               //
	
		konumB[indexB] = yeniAsagi;            // konumB[indexB] artık yeni aşağı yönlü listeyi işaret ediyor
		
     return  konumB[indexB];
}
void ust(YukariYonluBagliListe** konumA, int satirSayisi) {
  double toplamOrtalama = 0.0;
  int enBuyukListeElemanSayisi = 0;
  for (int i = 0; i < satirSayisi; i++) {
    YukariYonluBagliListe* liste = konumA[i];
    if (liste->listeElemanSayisi() > 0) { 
      Dugum* baslangic = liste->baslangic(liste);
      int elemanSayisi = liste->listeElemanSayisi();
      if (enBuyukListeElemanSayisi < elemanSayisi) {
        enBuyukListeElemanSayisi = elemanSayisi;
      }
    }
  }
  for (int i = 0; i < enBuyukListeElemanSayisi; i++) {
    int toplam = 0;
    int doluIndeksSayisi = 0;
    for (int j = 0; j < satirSayisi; j++) {
      YukariYonluBagliListe* liste = konumA[j];
      if (liste->listeElemanSayisi() > 0) { 
        Dugum* baslangic = liste->baslangic(liste);
        if (i < liste->listeElemanSayisi()) {
          toplam += baslangic->veri;
          doluIndeksSayisi++;
        }
      }
    }
    if (doluIndeksSayisi > 0) {
      double ortalama = static_cast<double>(toplam) / doluIndeksSayisi;
      toplamOrtalama += ortalama;
    }
  }
  // Son indeksteki sayıların ortalamasını da dahil ediyoruz
  int sonIndeksToplam = 0;
  int sonIndeksDoluIndeksSayisi = 0;
  for (int i = 0; i < satirSayisi; i++) {
    YukariYonluBagliListe* liste = konumA[i];
    if (liste->listeElemanSayisi() > 0) { 
      Dugum* baslangic = liste->baslangic(liste);
      if (enBuyukListeElemanSayisi > 0) {
        sonIndeksToplam += baslangic->veri;
        sonIndeksDoluIndeksSayisi++;
      }
    }
  }
  if (sonIndeksDoluIndeksSayisi > 0) {
    double sonIndeksOrtalama = static_cast<double>(sonIndeksToplam) / sonIndeksDoluIndeksSayisi;
    toplamOrtalama += sonIndeksOrtalama;
  }
  cout << "Ortalama: " << toplamOrtalama << endl;
}

void alt(AsagiYonluBagliListe** konumB, int satirSayisi) {
  double toplamOrtalama = 0.0;
  int enBuyukListeElemanSayisi = 0;
  for (int i = 0; i < satirSayisi; i++) {
    AsagiYonluBagliListe* liste = konumB[i];
    if (liste->listeElemanSayisi() > 0) { 
      Dugum* baslangic = liste->baslangic(liste);
      int elemanSayisi = liste->listeElemanSayisi();
      if (enBuyukListeElemanSayisi < elemanSayisi) {
        enBuyukListeElemanSayisi = elemanSayisi;
      }
    }
  }
  for (int i = 0; i < enBuyukListeElemanSayisi; i++) {
    int toplam = 0;
    int doluIndeksSayisi = 0;
    for (int j = 0; j < satirSayisi; j++) {
      AsagiYonluBagliListe* liste = konumB[j];
      if (liste->listeElemanSayisi() > 0) { 
        Dugum* baslangic = liste->baslangic(liste);
        if (i < liste->listeElemanSayisi()) {
          toplam += baslangic->veri;
          doluIndeksSayisi++;
        }
      }
    }
    if (doluIndeksSayisi > 0) {
      double ortalama = static_cast<double>(toplam) / doluIndeksSayisi;
      toplamOrtalama += ortalama;
    }
  }
  // Son indeksteki sayıların ortalamasını da dahil ediyoruz
  int sonIndeksToplam = 0;
  int sonIndeksDoluIndeksSayisi = 0;
  for (int i = 0; i < satirSayisi; i++) {
    AsagiYonluBagliListe* liste = konumB[i];
    if (liste->listeElemanSayisi() > 0) { 
      Dugum* baslangic = liste->baslangic(liste);
      if (enBuyukListeElemanSayisi > 0) {
        sonIndeksToplam += baslangic->veri;
        sonIndeksDoluIndeksSayisi++;
      }
    }
  }
  if (sonIndeksDoluIndeksSayisi > 0) {
    double sonIndeksOrtalama = static_cast<double>(sonIndeksToplam) / sonIndeksDoluIndeksSayisi;
    toplamOrtalama += sonIndeksOrtalama;
  }
  cout << "Ortalama: " << toplamOrtalama << endl;
}


int main(){
	
	int satirSayisi = satirAdedi("Sayilar.txt");
	int maxUzunluk = maxSatirUzunlugu("Sayilar.txt");
	ifstream dosya("Sayilar.txt"); //dosya aciliyor

	if(dosya.is_open()){
		string satir;
		
		konumA=new YukariYonluBagliListe*[satirSayisi];
		konumB=new AsagiYonluBagliListe*[satirSayisi];
		int i=0;
		while(std::getline(dosya,satir)) //listeleri olusturmak icin satirlari bir daha okuyorum
		{	
			
			int siradakiSayi;
			stringstream satirOkuyucu(satir);
			 YukariYonluBagliListe* siradakiYukariListe=new YukariYonluBagliListe();	 //burada yukarı yönlü satır listesini oluşturdum			
			 AsagiYonluBagliListe* siradakiAsagiListe=new AsagiYonluBagliListe();	 //burada aşağı yönlü satır listesini oluşturdum
			while(satirOkuyucu>>siradakiSayi){
				 siradakiYukariListe->ekle(siradakiSayi); //burada gönderilen veri yapıcı fonksiyon içinde 10'a bölünüp sonucun tam sayı kısmı listeye eklenecek
				 siradakiAsagiListe->ekle(siradakiSayi); //burada gönderilen veri yapıcı fonksiyon içinde 10'a göre mod alınıp sonuç kısmı listeye eklenecek
			}
			
			konumA[i] = siradakiYukariListe;
			konumB[i] = siradakiAsagiListe; //liste başı pointerını gösteriyor
			i++;
			
			
			
		}
		
}
int indexA,indexB;
cout<<"indis girerken deger vermeye 0'dan baslayiniz."<<endl;
cout<<"A degerini giriniz: ";
cin>>indexA;
cout<<"B degerini giriniz: ";
cin>>indexB;
YukariYonluBagliListe* yukariListe=konumA[indexA];
int boyut=yukariListe->listeElemanSayisi();
int* gosterDizi=yukariListe->diziKonumA(yukariListe,boyut);


//YukariYonluBagliListe* yeniYukari =
yukariListe=listeleriDegistir(konumA, konumB, indexA, indexB);
AsagiYonluBagliListe* yeniAsagi = asagiListeleriDegistir(konumB, indexB, gosterDizi,boyut);
konumA[indexA]=yukariListe;


ust(konumA, satirSayisi);
alt(konumB,satirSayisi);
	
return 0;
}

  
	

	