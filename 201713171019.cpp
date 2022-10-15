// 201713171019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Hanife Cennet Alkan 201713171019-1.Öğretim
#include <iostream>
using namespace std;

class Yigin
{
public:
	Yigin()
	{
		pSonraki = NULL;   //pSonrakiye ilk degeri atıyoruz
	}
	int veri;             //elemanlarin degerlerini tutuyoruz
	Yigin* pSonraki;      //sonraki elemanin adresini bulmak icin
};

//push fonksiyonu oluşturma
void push(Yigin* pTop, Yigin* pYeni)
{
	while (pTop->pSonraki != NULL)   //Son elemana kadar ilerleryi saglar
	{
		pTop = pTop->pSonraki;      //Eleman ile birlikte adresi de ilerletir
	}
	pTop->pSonraki = pYeni;         //Yeni eleman olusturma
}

//pop fonksiyonunu oluşturma
Yigin* pop(Yigin* pTop)
{
	while (pTop->pSonraki->pSonraki != NULL)    //son elemandan bir onceki elemana ilerlemek için
		pTop = pTop->pSonraki;               //elemanin adresi de tasinir
	Yigin* pTemp = pTop->pSonraki;           //geldigimiz elemanin adresini tempe atiyoruz
	pTop->pSonraki = NULL;                   //son elemandan onceki elemandaydik sonraki adresi null yapiyoruz
	return pTemp;                           // son elemani silmis oluyoruz
}

//menuleri cagirabilmek icin method seklinde yazdik
void yiginMenu()
{
	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n" << endl;
	cout << "Yigin icin islem seciniz:" << endl;
	cout << "1.Yigina Eleman Ekle" << endl;
	cout << "2.Yigindan Eleman Cikar:" << endl;
	cout << "3.Yigini Temizle" << endl;
	cout << "4.Yigindaki Elemanlari Goster" << endl;
	cout << "5.Yigindaki Eleman Sayisini Goster" << endl;
	cout << "6.Ana Menuye Geri Don" << endl;	
	cout << "\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl;
}
Yigin* DeleteAll(Yigin* pBas)
{
	while (pBas->pSonraki != NULL)  //elemanlar arasında ilerleme
	{
		Yigin* pTemp = pBas->pSonraki;
		pBas->pSonraki = NULL;    //adresler silinir
		return pTemp;
	}
}

class Kuyruk
{
public:
	Kuyruk()
	{
		pSonraki = NULL;
	}
	int veri;           //elemanlarin degerleri tutulur
	Kuyruk* pSonraki;  //sonraki elemanin adresini bulmak icin oluşturduk
};
//menuleri geri cagirabilmek icin method seklinde yazdik
void kuyrukMenu()
{
	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl;
	cout << "Kuyruk icin islem seciniz:" << endl;
	cout << "1.Kuyruga eleman ekle" << endl;
	cout << "2.Kuyruktan eleman cikar:" << endl;
	cout << "3.Kuyrugu temizle" << endl;
	cout << "4.Kuyruktaki elemanlari goster" << endl;
	cout << "5.Kuyruktaki eleman sayisini goster" << endl;
	cout << "6.Ana menuye geri don" << endl;
	cout << "\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl;
}
void SonaEkleK(Kuyruk* pBas, Kuyruk* pYeni)
{
	while (pBas->pSonraki != NULL)  //Son elemana kadar ilerlemeiy saglar
		pBas = pBas->pSonraki;      //Elemanla birlikte adresinde ilerlemesini saglar
	pBas->pSonraki = pYeni;         //Yeni eleman olusturuyoruz
}
Kuyruk* BastanCikar(Kuyruk* pBas, int index)
{
	for (int i = 0; i < index - 2; i++)   //pop fonksiyonu ile ayni islemler
		pBas = pBas->pSonraki;
	Kuyruk* pTemp = pBas->pSonraki;                  
	pBas->pSonraki = pBas->pSonraki->pSonraki;             
	return pTemp;
}
Kuyruk* DeleteAll(Kuyruk* pBas)
{
	while (pBas->pSonraki != NULL)
	{
		Kuyruk* pTemp = pBas->pSonraki;
		pBas->pSonraki = NULL;        //adresleri siliyoruz
		return pTemp;
	}
}
class Bagli
{
public:
Bagli()
{                           
	pSonraki = NULL;       //pSonrakiye ilk degeri atıyoruz
}
	int veri;              //elemanlarin degerlerini tutuyoruz
	Bagli* pSonraki;       //sonraki elemanin adresini bulmak icin
};		

void ArayaEkle(Bagli * pBas, Bagli * pYeni, int index)
{
for (int c = 0; c < index - 2; c++)                  //istedigimiz siraya gidiyoruz
	pBas = pBas->pSonraki;                           //pBasi sonraki adrese ilerletiyoruz
		pYeni->pSonraki = pBas->pSonraki;            //pYeni pBasin gosterdigi adresi gosteriyor
		pBas->pSonraki = pYeni;				         //eklemek istedigimiz asil yerin adresini pyeniye attik
}	
	void SonaEkle(Bagli * pBas, Bagli * pYeni)
	{
		while (pBas->pSonraki != NULL)				//Son elemana kadar ilerlemesini saglar
			pBas = pBas->pSonraki;					//Elemanla birlikte adresi de ilerletir
		pBas->pSonraki = pYeni;						//Yeni eleman olusturma
	}
	Bagli* AradanCikar(Bagli * pBas, int index)
	{
		for (int j = 0; j < index - 2 ; j++)         //Eklemede de aynısını yapmıştık
			pBas = pBas->pSonraki;
		Bagli* pTemp = pBas->pSonraki;
		pBas->pSonraki = pBas->pSonraki->pSonraki;   //farki cikarttigi sayinin adresine bagli
		return pTemp;                                //elemani ondan sonraki elemana bagliyor
	}

	Bagli* SondanCikar(Bagli * pBas)
	{
		while (pBas->pSonraki->pSonraki != NULL)	//pop islemiyle ayni
			pBas = pBas->pSonraki;
		Bagli* pTemp = pBas->pSonraki;
		pBas->pSonraki = NULL;
		return pTemp;
	}

	Bagli* DeleteAll(Bagli * pBas)
	{
		while (pBas->pSonraki->pSonraki != NULL)
		{
			Bagli* pTemp = pBas->pSonraki;			//adresler silinir
			pBas->pSonraki = NULL;
			return pTemp;
		}
	}
	/*menuleri geri cagirabilmek icin method  yazdik*/
	void anaMenu()
	{
		cout << "^^__^^__^^__^^__^^__^^__^^__^^__^^__^^__^^\n" << endl;
		cout << "Yapmak istediginiz uygulamayi seciniz:" << endl;
		cout << "1. Yigin Uygulamasi" << endl;
		cout << "2. Kuyruk Uygulamasi" << endl;
		cout << "3. Tek Yonlu Bagli Liste Uygulamasi" << endl;
		cout << "4. Programdan Cikis" << endl;
		cout << "\n^^__^^__^^__^^__^^__^^__^^__^^__^^__^^__^^" << endl;
	}

	void bagliMenu()
	{
		cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n" << endl;
		cout << "Bagli liste icin islem seciniz:" << endl;
		cout << "1. Listeye elaman ekle" << endl;
		cout << "2. Listeden eleman cikar" << endl;
		cout << "3  Listeyi temizle" << endl;
		cout << "4. Listedeki elemanlari goster" << endl;
		cout << "5. Listedeki eleman sayisini goster" << endl;
		cout << "6. Ana menuye geri don" << endl;
		cout << "\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl;
	}

	void bagliMenu1()
	{
		cout << "#_#_#_#_#_#_#_#_#_#_#_#\n"<< endl; 
		cout << "Ekleme turunu seciniz:" << endl;
		cout << "1. Araya elaman ekle" << endl;
		cout << "2. Sona eleman ekle" << endl;
		cout << "3. Liste islemlerine geri don" << endl;	
		cout << "\n#_#_#_#_#_#_#_#_#_#_#_#" << endl;
	}

	void bagliMenu2()
	{
		cout << "#_#_#_#_#_#_#_#_#_#_#_#\n" << endl;
		cout << "Cikarma turunu seciniz:" << endl;
		cout << "1. Aradan elaman cikar" << endl;
		cout << "2. Sondan eleman cikar" << endl;
		cout << "3. Liste islemlerine geri don" << endl;
		cout << "\n#_#_#_#_#_#_#_#_#_#_#_#" << endl;
	}

	void secimiCalistir(int secim)
	{
		int c;
		switch (secim)
		{
		case 1:
		{
			//elemanlari oluşturalım:
			Yigin* y1 = new Yigin(); // oluşan elemanlarin pSonraki = NULL
			Yigin* y2 = new Yigin();
			Yigin* y3 = new Yigin();
			Yigin* y4 = new Yigin();
			//elemanlara değer verelim:
			y1->veri = 1;
			y2->veri = 2;
			y3->veri = 3;
			y4->veri = 4;
			//elemanlari birbirine bağlayalım:
			y1->pSonraki = y2; 
			y2->pSonraki = y3;
			y3->pSonraki = y4;

			do
			{					//menulere geri donebilmek ve cikis yapabilmek icin
				yiginMenu();	//do-while dongusu kullaniyoruz
				cin >> c;		//menuyu ekrana getirdik
								//sayiyi aldik
				int sayi;
				if (c == 1)
				{
					Yigin* y5 = new Yigin();								 //yeni eleman icin degisken olusturduk
					cout << "Eklemek istedigininiz sayiyi giriniz" << endl;
					cin >> sayi;											//kullaniciden sayi alindi
					y5->veri = sayi;                                        //sayiyi y5'e atadık
					push(y1, y5);											//fonk.u cagirip sayiyi ekledik
					cout << "Sayi eklendi" << endl;

				}
				else if (c == 2)
				{
					pop(y1);												//fonk.u cagirip sayiyi cikardik 
					cout << "Sayi cikarildi" << endl;
				}
				else if (c == 3)
				{
					DeleteAll(y1);
				}
				else if (c == 4)
				{
					//verileri yazdıralım:
					Yigin* pTemp = y1;									    //y1 in adresini tempe atariz//elemanlarin sonuna kadar ilerliyoruz
					cout << "\tson" << endl;                          
					while (pTemp != NULL)									//elemanlarin sonuna kadar ilerliyoruz						
					{
						cout << "\t|" << pTemp->veri << "|" << endl;	    //ilerken verileri yazdiriyoruz
						pTemp = pTemp->pSonraki;							//sonraki adrese geciyoruz  
					}
					cout << "\tbas" << endl;

				}
				else if (c == 5)
				{
					Yigin* pbas = y1;										//y1 in adresini pbasa atadik
					int b = 1;											    //kac sayi oldugunu anlamak icin 
					while (pbas->pSonraki != NULL)							//son elemana ilerliyoruz
					{
						pbas = pbas->pSonraki;								//adres ilerliyor
						b++;												//while dondukce deger artiyor
					}
					cout << b << "Eleman var" << endl;
				}
			} while (c != 6);					//6 a basinca ana menüye doner							

			break;
	}
	case 2:
	{
			Kuyruk* k1 = new Kuyruk();            //elemanlari olusturuyoruz
			Kuyruk* k2 = new Kuyruk();
			Kuyruk* k4 = new Kuyruk();
			Kuyruk* k3 = new Kuyruk();           

			k1->veri = 2;						//elemanlara deger atiyoruz
			k2->veri = 0;
			k3->veri = 2;
			k4->veri = 0;

			k1->pSonraki = k2;					//adresleri birbirine bagliyoruz
			k2->pSonraki = k3;
			k3->pSonraki = k4;

			do                                  //menulere geri donebilmek ve cikis yapabilmek icin
			{									//do-while dongusu kullaniyoruz
				kuyrukMenu();
				cin >> c;						//kullanicidan sayiyi aldik

				int sayi;
				if (c == 1)
				{
					Kuyruk* k5 = new Kuyruk();								//yeni eleman icin degisken olusturduk
					cout << "Eklemek istediginiz sayiyi giriniz:" << endl;
					cin >> sayi;											//kullanicidan sayiyi aldik
					k5->veri = sayi;										//sayiyi k5 e attik
					SonaEkleK(k1, k5);										//fonk.u cagirdik ve sayiyi ekledik
					cout << "Sayi eklendi" << endl;
				}
				else if (c == 2)
				{
					BastanCikar(k1, 1);
					cout << "eleman cikarildi " << endl;
				}
				else if (c == 3)
				{
					DeleteAll(k1);
				}
				else if (c == 4)
				{
					Kuyruk* pTemp = k1;										//k1 in adresini tempe attik
					cout << "<---Kuyruk Basi--->\n";
					while (pTemp != NULL)									//elemanlarin sonuna dogru ilerliyoruz
					{
						cout << pTemp->veri << endl;						 //ilerlerken verileri yazdiriyoruz
						pTemp = pTemp->pSonraki;							//sonraki adreslere geciyoruz
					}
					cout << "<---Kuyruk Sonu--->" << endl;
				}
				else if (c == 5)
				{
					Kuyruk* pbas = k1;										//k1 in adresini pbasa atiyoruz
					int b = 1;												//kac sayi oldugunu anlamak icin 
					while (pbas->pSonraki != NULL)							//son elemana dogru ilerliyoruz
					{
						pbas = pbas->pSonraki;								//adres ilerliyor
						b++;												//while a dondukce artiyor
					}
					cout << b << "Eleman vardır" << endl;
				}
			} while (c != 6);							//6 a basinca ana menuye doner

			break;
		}
		case 3:
		{
			Bagli* b1 = new Bagli();				//elemanlari olusturuyoruz
			Bagli* b2 = new Bagli();
			Bagli* b3 = new Bagli();
			Bagli* b4 = new Bagli();

			b1->veri = 1;							//elemanlara deger atiyoruz
			b2->veri = 5;
			b3->veri = 6;
			b4->veri = 3;

			b1->pSonraki = b2;
			b2->pSonraki = b3;
			b3->pSonraki = b4;

			do                                     //menulere geri donebilmek ve cikis yapabilmek icin
			{									   //do-while dongusu kullaniyoruz
				bagliMenu();
				cin >> c;						//kullanicidan sayiyi aldik

				int sayi;
				switch (c)
				{
					int sira;
				case 1:
				{
					do
					{							//iki farkli menu olustuyoruz
						int secim;				//bu nedenle 2 tane do while dongusu kullandık
						bagliMenu1();
						cin >> secim; 

						int yeniDugum;

						if (secim == 1)
						{
							Bagli* b5 = new Bagli();                           //yeni eleman icin degisken olusturduk
							cout << "Ekleyeceginiz sayi hangisi:" << endl;     //kullanicidan sayiyi aldik
							cin >> yeniDugum;
							cout << "Kacinci siraya ekleyeceksiniz:" << endl;
							cin >> sira;
							b5->veri = yeniDugum;									//nundan sonrasi yigin bolumuyle genel olarak ayni
							ArayaEkle(b1, b5, sira);

						}
						else if (secim == 2)
						{
							cout << "Eklemek istediginiz sayi:" << endl;
							cin >> yeniDugum;
							Bagli* pYeni = new Bagli();
							pYeni->veri = yeniDugum;
							SonaEkle(b1, pYeni);
						}
					} while (secim != 3);					
				}
				break;

				case 2:
				{
					do
					{
						int secim;
						bagliMenu2();
						cin >> secim;

						if (secim == 1)
						{
							cout << "Kacinci siradaki dugumu cikaracaksiniz:" << endl;
							cin >> sira;
							AradanCikar(b1, sira);
						}
						else if (secim == 2)
						{
							SondanCikar(b1);
						}
					} while (secim != 3);
				}
				break;

				case 3:
				{
					DeleteAll(b1);
				}
				case 4:
				{
					Bagli* pTemp = b1;
					cout << "<---Liste Basi--->";
					while (pTemp != NULL)
					{
						cout << "-" << pTemp->veri << "-";
						pTemp = pTemp->pSonraki;
					}
					cout << "<---Liste Sonu--->" << endl;
				}
				break;

				case 5:
				{
					Bagli* pbas = b1;
					int b = 1;
					while (pbas->pSonraki != NULL)
					{
						pbas = pbas->pSonraki;
						b++;
					}
					cout << b << " eleman var" << endl;
				}
				break;
				}
			} while (c != 6);
		}
		
	}
    }

	int main()
	{
		int secim;
		do
		{
			anaMenu();
			cin >> secim;
			secimiCalistir(secim);

		} while (secim != 4);

	}

		

		
	