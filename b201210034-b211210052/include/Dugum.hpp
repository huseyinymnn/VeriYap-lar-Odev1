/**
* @file Dugum sınıfının  oldugu dosya
* @description dugum  sınıfıın oldugu kısım 
* @course yaz okulu 1-B
* @assignment 1.ÖDEV
* @date 24.07.2023-27.07.2023 tarihleri arasında oluşturduk.
* @author Hüseyin Yaman ve Efe Göktepe huseyin.yaman2@ogr.sakarya.edu.tr | efe.goktepe@ogr.sakarya.edu.tr
*/
#ifndef Dugum_hpp
#define Dugum_hpp
#include<iostream>

using namespace std;

class Dugum
{
	public:
		Dugum(int veri);
		int veri;
		Dugum* sonraki;
		
		
};

#endif