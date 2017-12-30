/*
	Dev-C++
	1 Aralýk 2017	
	Recep KARADEMÝR
	2015141003@cumhuriyet.edu.tr

	Cumhuriyet Üniversitesi Bilgisayar Mühendisliði Bölümü
	Mühendislik Projesi Dersi
	Ödev1 : Hash Tablosunda Kelime Arama
*/


#include<iostream>
#include<cmath>		  // Matematiksel iþlemler için.
#include<fstream>    // Dosya iþlemleri için.
#include<locale.h>  // Türkçe karakter çýktýsý için.
#include<iomanip>
#include "windows.h" 

using namespace std;

const int N=100;	
const int N2A=211;// N2A N in iki katýndan büyük ve N e en yakýn asal sayý olmalý.
int yerdegistirme=1; // kelimelerin boþ yer arama saysýný yerdegistirme  belirtecek.
string dizi[N];
string HashDizi[N2A];   //  N in iki katýndan büyük ve N e en yakýn asal sayý 211. 


void dosyadan_oku_yaz()
{
   freopen("Text.txt", "r", stdin);
   string satir;
   int i=0;
   while(getline(cin,satir))
   {
   		dizi[i]=satir;
   		i++;
   }
}

int kelime_ascii_sum(string dizi)
{
  int ASCII=0,j=1,sum=0;
  for (int i=0;i<dizi.size();i++)
  {
  		char x=dizi.at(i); // at(i)  i   indisindeki karakteri döndürür.
  		ASCII=int(x);
  		sum+=pow(j,2)*ASCII;
  		j++;
  }
  return sum;
}

int hash_kelime_yerlestirme()
{
	int kare,m,yer,sumASCII; 
	for(int i=0;i<N2A;++i){ HashDizi[i]="."; }// Daha önce bir kelime yerleþtirilmesi yapýlýp yapýlmadýðýný kontrol edebilmek için.
	cout<<"\nText.txt dosyasýndaki kelimelerden yerleþirken konum çakýþmasý yaþayanlar : \n";
	for(int a=0;a<=3;++a) // artistik efekt.
	{
		cout<<"*";Sleep(500);
	}
	cout<<endl;
	
	for(int a=0,m=0;a<N;++a) // N eleman için N kere yerleþtirme yapacak.program her seferinde m=0 ile tekrar denemeler yapmalý.
	{
		sumASCII=kelime_ascii_sum(dizi[a]);	//a. indisteki kelimenin konumuna göre ascii toplamýný bulan satýr
		sumASCII%=N2A;	// a indisindeki kelimenin ascii toplamýnýn N2A ile modu alýndý.
		yer=sumASCII;	// boþ olmasý beklenen yere  yer deðiþkeni atandý.
		if(HashDizi[yer]==".")	// Potansiyel boþ beklenen yer boþ mu?
		{
			//cout<<"\n\n"<<yer<<". indisteki kelime\n"<<dizi[a]<<"\n"<<sum<<endl;
			HashDizi[yer]=dizi[a]; // o halde kelimeyi yerleþtir.
		}
		else // Potansiyel yer boþ deðilse...
		{
			m=1;   // m=0 ile tekrar denememek için 
			while(m<N2A-1)// Potansiyel yer doluysa 210 defa baþka bir yere yerleþtirmeye çalýþýlacak.
			{
				if(m==1)
				{
					cout<<"____________________________________________________________\n\n"<<endl;
					cout<<"Boþ yer bulamayan kelime      = "<<dizi[a]<<endl;
					cout<<dizi[a]<<" kelimesinin yerleþmesi gereken yer(ler)e yerleþen kelime(ler) : \n";
				}
				cout<<setw(3)<<yer<<" yerine yerleþen kelime    = "<<HashDizi[yer]<<endl;
				kare=pow(m,2); // kare 1^2 , 2^2 , 3^2  , 4^2  ... þeklinde artacak.
				yer=(kare+sumASCII)%N2A;
				if(HashDizi[yer]==".") // denemeyle boþ yer bulundu mu?
				{
					HashDizi[yer]=dizi[a]; // evet denemeyle boþ yer bulundu ve kelimeyi boþ yere yerleþtirdik.
					break;  // boþ yer arama döngüsü while ýn dýþýna çýk.
				}
				++m; // boþ yer bulunamadý m 1 artýrýlmalý.
			}
		}	
	}

	cout<<"\n\nQuadratic sondalama ile kelimelerin yerleþtiði yerler : \n\n";
	
	for(int a=0;a<=3;++a)// artistik efekt
	{
		cout<<"*";Sleep(500);
	}
	
	cout<<endl;
	
	for(int i=0;i<N2A;++i)
	{
		if(HashDizi[i]!=".")
		{
			cout<<setw(3)<<left<<i<<"."<<" indisteki kelime : "<<setw(11)<<left<<HashDizi[i]<<"----------> ASCII SUM = "<<kelime_ascii_sum(HashDizi[i])<<endl;
		}
		else
		{
			cout<<setw(3)<<left<<i<<"."<<" indisteki kelime : "<<"                 [KELÝME YOK]"<<endl;
		}
	}
}

string aranan_kelime_kucuk_harf()
{
	TEKRAR:
	string str;int yaz=1;
	cout<<"Girdiðiniz büyük I ve Ý harfi küçük i harfine dönüþecektir !!! \nÝngiliz alfabesini kullanýn ! \n"<<endl;
	cout<<"Text.txt dosyasýnda aramak istediðiniz kelimeyi girin : "<<endl;
	getline(cin,str);
	// a=97   A=65   olduðundan +32
	for (int i=0; i<str.length();i++)// String'ler aslinda bir dizi gibidir indisi 0 dýr ve her harfin kendine ait bir indisi vardýr bu indis sayisini .length() fonksiyonu ile buluruz....
	{
		if(str[i]==-104)
		{
			str[i]=str[i]+209;
		}
		else if(str[i]<65)
		{
			system("cls");
			cout<< "\nÝngiliz alfabesi dýþýnda bir deðer girdiniz.";
			yaz=0;
			break;
		}
    	if(str[i]>=65 && str[i]<=90)// Burada cümlemizin her bir elemanimizin ASCII tablosuna gore buyuk harf olup olmadigini kontrol ediyoruz. Eger buyuk ise kosul dogrulanýr ve kucuk harf'e donusturur.
    	{
        	str[i]=str[i]+32;
    	}
	}
	if(yaz==1)
	{
		cout<<"\nGirdiðiniz kelime : "<<str<<" þeklinde aranacaktýr.\n";
		return str;
	}
	else
	{
		cout<<"\nBÝR HATA OLUÞTU ! \n\n";
		goto TEKRAR;
	}
	
}

int arama_fonksiyon(string aranan)
{
		
		int bitir=2,kare,m,yer,sumASCII;
		sumASCII=kelime_ascii_sum(aranan);	//aranan kelimenin konumuna göre ascii toplamýný bulan satýr
		sumASCII%=N2A;	// a indisindeki kelimenin ascii toplamýnýn N2A ile modu alýndý.
		yer=sumASCII;	// boþ olmasý beklenen yere  yer deðiþkeni atandý.
		
		if(HashDizi[yer]==aranan)	// aranan stringi ilk yerinde bulunduysa.
		{
			cout<<"Aranan kelime "<< yer<<". indiste bulunmaktadýr."<<endl;
			cout<<"Kelime "<<yerdegistirme<<" kez boþ yer aramýþ.  "<<yerdegistirme<<". denemedeki yere yerleþmiþ."<<endl;
			bitir=1; // program sonlanmalý.
		}
		else if(HashDizi[yer]==".") // kelime dizinin içerisinde kesin olarak yoksa. Yerleþtirme hatasý vs için.
		{	
			cout<<"\nKelime Text.txt içerisinde yok ! \n"; 
			bitir=2; // program benzerlerini aramalý.
		}
		else if(HashDizi[yer]!=aranan)// kelime aranmaya baþlandý ve bulunduysa.
		{
			m=1;
			while(m<N2A-1)// Potansiyel yer doluysa 210 defa baþka bir yerde aramaya çalýþýlacak.
			{
				kare=pow(m,2); // kare 1^2 , 2^2 , 3^2  , 4^2  ... þeklinde artacak.
				yer=(kare+sumASCII)%N2A;
				if(HashDizi[yer]==aranan)
				{
					cout<<"Aranan kelime "<< yer<<". indiste bulunmaktadýr."<<endl;
					cout<<"Kelime "<<yerdegistirme<<" kez boþ yer aramýþ.  "<<yerdegistirme<<". denemedeki yere yerleþmiþ."<<endl;
					bitir=1; // program sonlanmalý.
					break;
				}
				m++;// kelime bulunamadý m 1 artýrýlmalý.
				yerdegistirme=m+1;
			}
		}
		return bitir; // bitir==2 ise a ve b fonksiyonlarýna gidip yer deðiþtirerek ve eksilterek arama yap demek.// a ve b fonksiyonlarýný hazýrla öyle ara.
}

void yer_degistir_ara(string degis)
{
	string tempdizi;
	tempdizi=degis;
	int boyut,j=0;
	char temp;
	boyut=degis.length();
	for(int i=1;i<boyut;i++)
	{
		temp=tempdizi[j];
		tempdizi[j]=tempdizi[j+1];
		tempdizi[j+1]=temp;
		//arama baþlýyor...
		int kare,m,yer,sumASCII;
		sumASCII=kelime_ascii_sum(tempdizi);	//aranan kelimenin konumuna göre ascii toplamýný bulan satýr
		sumASCII%=N2A;	// a indisindeki kelimenin ascii toplamýnýn N2A ile modu alýndý.
		yer=sumASCII;	// boþ olmasý beklenen yere  yer deðiþkeni atandý.
		
		if(HashDizi[yer]==tempdizi)	// aranan stringi ilk yerinde bulunduysa.
		{
			cout<<"Aranan kelime "<<tempdizi<<" olarak "<< yer<<". indiste bulunmaktadýr."<<endl;
		}
		else if(HashDizi[yer]==".") // kelime dizinin içerisinde kesin olarak yoksa. Yerleþtirme hatasý vs için.
		{	
			// yer deðiþtirmeye devam edilecek.
		}
		else if(HashDizi[yer]!=tempdizi)// kelime aranmaya baþlandý ve bulunduysa.
		{
			m=1;
			while(m<N2A-1)// Potansiyel yer doluysa 210 defa baþka bir yerde aramaya çalýþýlacak.
			{
				kare=pow(m,2); // kare 1^2 , 2^2 , 3^2  , 4^2  ... þeklinde artacak.
				yer=(kare+sumASCII)%N2A;
				if(HashDizi[yer]==tempdizi)
				{
					cout<<"Aranan kelime "<<tempdizi<<" olarak "<< yer<<". indiste bulunmaktadýr."<<endl;
					break;
				}
				m++;// kelime bulunamadý m 1 artýrýlmalý.
			}
		}
		// arama bitti.
		j++;
		tempdizi=degis;
	}
}

void eksiltip_ara(string eksilt)
{
	int boyut,j=0,m=0;
	boyut=eksilt.length();
	string tempdizi=eksilt;
	for(int i=0;i<boyut;++i)
	{
		j=0,m=0;
		for(int a=1;a<boyut+1;a++)
		{
			if(j==i)
			{
				tempdizi[j]=eksilt[m+1];
				++m;
			}
			else
			{
				tempdizi[j]=eksilt[m];
			}
		
			m++,j++;
		}
		cout<< "Kelime þu þekillerde aranmalýdýr : "<<endl;
		cout<<tempdizi<<endl;
	}
}

int main()
{
	string aranan;
	setlocale(LC_ALL, "Turkish");
	aranan=aranan_kelime_kucuk_harf();//aracak kelime belirlendi.
	dosyadan_oku_yaz(); // Text.txt içerisindeki kelimeler bellekteki bir string dizisine yüklendi.
	hash_kelime_yerlestirme();// Kelimeler quadratic yönteme göre HashDizi dizisinin içerisine yüklendiler.
	if(arama_fonksiyon(aranan)==2)
	{
		yer_degistir_ara(aranan);
		eksiltip_ara(aranan);
	}
	cout<<"\nAradýðýnýz kelime Text.txt içerisinde arandý.\nProgram sonlandýrýlýyor.\n";
	system("exit");
	return 0;

}

