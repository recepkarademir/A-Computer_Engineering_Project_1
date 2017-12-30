/*
	Dev-C++
	1 Aral�k 2017	
	Recep KARADEM�R
	2015141003@cumhuriyet.edu.tr

	Cumhuriyet �niversitesi Bilgisayar M�hendisli�i B�l�m�
	M�hendislik Projesi Dersi
	�dev1 : Hash Tablosunda Kelime Arama
*/


#include<iostream>
#include<cmath>		  // Matematiksel i�lemler i�in.
#include<fstream>    // Dosya i�lemleri i�in.
#include<locale.h>  // T�rk�e karakter ��kt�s� i�in.
#include<iomanip>
#include "windows.h" 

using namespace std;

const int N=100;	
const int N2A=211;// N2A N in iki kat�ndan b�y�k ve N e en yak�n asal say� olmal�.
int yerdegistirme=1; // kelimelerin bo� yer arama says�n� yerdegistirme  belirtecek.
string dizi[N];
string HashDizi[N2A];   //  N in iki kat�ndan b�y�k ve N e en yak�n asal say� 211. 


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
  		char x=dizi.at(i); // at(i)  i   indisindeki karakteri d�nd�r�r.
  		ASCII=int(x);
  		sum+=pow(j,2)*ASCII;
  		j++;
  }
  return sum;
}

int hash_kelime_yerlestirme()
{
	int kare,m,yer,sumASCII; 
	for(int i=0;i<N2A;++i){ HashDizi[i]="."; }// Daha �nce bir kelime yerle�tirilmesi yap�l�p yap�lmad���n� kontrol edebilmek i�in.
	cout<<"\nText.txt dosyas�ndaki kelimelerden yerle�irken konum �ak��mas� ya�ayanlar : \n";
	for(int a=0;a<=3;++a) // artistik efekt.
	{
		cout<<"*";Sleep(500);
	}
	cout<<endl;
	
	for(int a=0,m=0;a<N;++a) // N eleman i�in N kere yerle�tirme yapacak.program her seferinde m=0 ile tekrar denemeler yapmal�.
	{
		sumASCII=kelime_ascii_sum(dizi[a]);	//a. indisteki kelimenin konumuna g�re ascii toplam�n� bulan sat�r
		sumASCII%=N2A;	// a indisindeki kelimenin ascii toplam�n�n N2A ile modu al�nd�.
		yer=sumASCII;	// bo� olmas� beklenen yere  yer de�i�keni atand�.
		if(HashDizi[yer]==".")	// Potansiyel bo� beklenen yer bo� mu?
		{
			//cout<<"\n\n"<<yer<<". indisteki kelime\n"<<dizi[a]<<"\n"<<sum<<endl;
			HashDizi[yer]=dizi[a]; // o halde kelimeyi yerle�tir.
		}
		else // Potansiyel yer bo� de�ilse...
		{
			m=1;   // m=0 ile tekrar denememek i�in 
			while(m<N2A-1)// Potansiyel yer doluysa 210 defa ba�ka bir yere yerle�tirmeye �al���lacak.
			{
				if(m==1)
				{
					cout<<"____________________________________________________________\n\n"<<endl;
					cout<<"Bo� yer bulamayan kelime      = "<<dizi[a]<<endl;
					cout<<dizi[a]<<" kelimesinin yerle�mesi gereken yer(ler)e yerle�en kelime(ler) : \n";
				}
				cout<<setw(3)<<yer<<" yerine yerle�en kelime    = "<<HashDizi[yer]<<endl;
				kare=pow(m,2); // kare 1^2 , 2^2 , 3^2  , 4^2  ... �eklinde artacak.
				yer=(kare+sumASCII)%N2A;
				if(HashDizi[yer]==".") // denemeyle bo� yer bulundu mu?
				{
					HashDizi[yer]=dizi[a]; // evet denemeyle bo� yer bulundu ve kelimeyi bo� yere yerle�tirdik.
					break;  // bo� yer arama d�ng�s� while �n d���na ��k.
				}
				++m; // bo� yer bulunamad� m 1 art�r�lmal�.
			}
		}	
	}

	cout<<"\n\nQuadratic sondalama ile kelimelerin yerle�ti�i yerler : \n\n";
	
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
			cout<<setw(3)<<left<<i<<"."<<" indisteki kelime : "<<"                 [KEL�ME YOK]"<<endl;
		}
	}
}

string aranan_kelime_kucuk_harf()
{
	TEKRAR:
	string str;int yaz=1;
	cout<<"Girdi�iniz b�y�k I ve � harfi k���k i harfine d�n��ecektir !!! \n�ngiliz alfabesini kullan�n ! \n"<<endl;
	cout<<"Text.txt dosyas�nda aramak istedi�iniz kelimeyi girin : "<<endl;
	getline(cin,str);
	// a=97   A=65   oldu�undan +32
	for (int i=0; i<str.length();i++)// String'ler aslinda bir dizi gibidir indisi 0 d�r ve her harfin kendine ait bir indisi vard�r bu indis sayisini .length() fonksiyonu ile buluruz....
	{
		if(str[i]==-104)
		{
			str[i]=str[i]+209;
		}
		else if(str[i]<65)
		{
			system("cls");
			cout<< "\n�ngiliz alfabesi d���nda bir de�er girdiniz.";
			yaz=0;
			break;
		}
    	if(str[i]>=65 && str[i]<=90)// Burada c�mlemizin her bir elemanimizin ASCII tablosuna gore buyuk harf olup olmadigini kontrol ediyoruz. Eger buyuk ise kosul dogrulan�r ve kucuk harf'e donusturur.
    	{
        	str[i]=str[i]+32;
    	}
	}
	if(yaz==1)
	{
		cout<<"\nGirdi�iniz kelime : "<<str<<" �eklinde aranacakt�r.\n";
		return str;
	}
	else
	{
		cout<<"\nB�R HATA OLU�TU ! \n\n";
		goto TEKRAR;
	}
	
}

int arama_fonksiyon(string aranan)
{
		
		int bitir=2,kare,m,yer,sumASCII;
		sumASCII=kelime_ascii_sum(aranan);	//aranan kelimenin konumuna g�re ascii toplam�n� bulan sat�r
		sumASCII%=N2A;	// a indisindeki kelimenin ascii toplam�n�n N2A ile modu al�nd�.
		yer=sumASCII;	// bo� olmas� beklenen yere  yer de�i�keni atand�.
		
		if(HashDizi[yer]==aranan)	// aranan stringi ilk yerinde bulunduysa.
		{
			cout<<"Aranan kelime "<< yer<<". indiste bulunmaktad�r."<<endl;
			cout<<"Kelime "<<yerdegistirme<<" kez bo� yer aram��.  "<<yerdegistirme<<". denemedeki yere yerle�mi�."<<endl;
			bitir=1; // program sonlanmal�.
		}
		else if(HashDizi[yer]==".") // kelime dizinin i�erisinde kesin olarak yoksa. Yerle�tirme hatas� vs i�in.
		{	
			cout<<"\nKelime Text.txt i�erisinde yok ! \n"; 
			bitir=2; // program benzerlerini aramal�.
		}
		else if(HashDizi[yer]!=aranan)// kelime aranmaya ba�land� ve bulunduysa.
		{
			m=1;
			while(m<N2A-1)// Potansiyel yer doluysa 210 defa ba�ka bir yerde aramaya �al���lacak.
			{
				kare=pow(m,2); // kare 1^2 , 2^2 , 3^2  , 4^2  ... �eklinde artacak.
				yer=(kare+sumASCII)%N2A;
				if(HashDizi[yer]==aranan)
				{
					cout<<"Aranan kelime "<< yer<<". indiste bulunmaktad�r."<<endl;
					cout<<"Kelime "<<yerdegistirme<<" kez bo� yer aram��.  "<<yerdegistirme<<". denemedeki yere yerle�mi�."<<endl;
					bitir=1; // program sonlanmal�.
					break;
				}
				m++;// kelime bulunamad� m 1 art�r�lmal�.
				yerdegistirme=m+1;
			}
		}
		return bitir; // bitir==2 ise a ve b fonksiyonlar�na gidip yer de�i�tirerek ve eksilterek arama yap demek.// a ve b fonksiyonlar�n� haz�rla �yle ara.
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
		//arama ba�l�yor...
		int kare,m,yer,sumASCII;
		sumASCII=kelime_ascii_sum(tempdizi);	//aranan kelimenin konumuna g�re ascii toplam�n� bulan sat�r
		sumASCII%=N2A;	// a indisindeki kelimenin ascii toplam�n�n N2A ile modu al�nd�.
		yer=sumASCII;	// bo� olmas� beklenen yere  yer de�i�keni atand�.
		
		if(HashDizi[yer]==tempdizi)	// aranan stringi ilk yerinde bulunduysa.
		{
			cout<<"Aranan kelime "<<tempdizi<<" olarak "<< yer<<". indiste bulunmaktad�r."<<endl;
		}
		else if(HashDizi[yer]==".") // kelime dizinin i�erisinde kesin olarak yoksa. Yerle�tirme hatas� vs i�in.
		{	
			// yer de�i�tirmeye devam edilecek.
		}
		else if(HashDizi[yer]!=tempdizi)// kelime aranmaya ba�land� ve bulunduysa.
		{
			m=1;
			while(m<N2A-1)// Potansiyel yer doluysa 210 defa ba�ka bir yerde aramaya �al���lacak.
			{
				kare=pow(m,2); // kare 1^2 , 2^2 , 3^2  , 4^2  ... �eklinde artacak.
				yer=(kare+sumASCII)%N2A;
				if(HashDizi[yer]==tempdizi)
				{
					cout<<"Aranan kelime "<<tempdizi<<" olarak "<< yer<<". indiste bulunmaktad�r."<<endl;
					break;
				}
				m++;// kelime bulunamad� m 1 art�r�lmal�.
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
		cout<< "Kelime �u �ekillerde aranmal�d�r : "<<endl;
		cout<<tempdizi<<endl;
	}
}

int main()
{
	string aranan;
	setlocale(LC_ALL, "Turkish");
	aranan=aranan_kelime_kucuk_harf();//aracak kelime belirlendi.
	dosyadan_oku_yaz(); // Text.txt i�erisindeki kelimeler bellekteki bir string dizisine y�klendi.
	hash_kelime_yerlestirme();// Kelimeler quadratic y�nteme g�re HashDizi dizisinin i�erisine y�klendiler.
	if(arama_fonksiyon(aranan)==2)
	{
		yer_degistir_ara(aranan);
		eksiltip_ara(aranan);
	}
	cout<<"\nArad���n�z kelime Text.txt i�erisinde arand�.\nProgram sonland�r�l�yor.\n";
	system("exit");
	return 0;

}

