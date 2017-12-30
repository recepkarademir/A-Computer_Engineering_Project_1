![Search logo](https://www.epo.org/searching-for-patents/technical/espacenet/espacenet.jpg)

# Mühendislik Projesi Dersi Ödev 1
HASH TABLOSUNDA KELİME ARAMA
------------------------------
1 Aralık 2017	

Recep KARADEMİR

2015141003@cumhuriyet.edu.tr
____________________________________________________________________________________________________________________________________

Özet:
------------------------------
Text.txt adında içerisinde 100 adet kelime bulunan metin dosyasında istediğimiz kelimeyi en hızlı bir şekilde arayan program hazırlanacaktır. Hızlı aramanın yapılabilmesi için metin dosyasındaki kelimeler belleğe quadratic sondalama yöntemiyle yerleştirilecektir. Arama quadratic sondalama ile yapılacak.



GİRİŞ
------------------------------
Metin dosyasında bulunan kelimelerin Hash Tablosu mantığı kullanılarak bir diziye kopyalanması ve bu dizide arama işleminin en hızlı şekilde yapılması.
Arama yapılırken birebir eşleşen kelime dışında benzer kelimelerin de bulunabilmesi için yapılan işlemler içermektedir.
Metin belgesi içerisindeki kelimeler konumlarına göre quadratic sondalama kullanılarak belleğe yüklenmeli ve bellekten hızlı arama yapılmalıdır.
Metin dosyasında aranan kelimenin dosyada kaç kez tekrar ettiğini veya yerleşebileceği yerlere daha önceden nelerin yerleştiğini yazdıran bir program hazırlanmıştır.



UYGULAMA
------------------------------
C++ ile yazdığım program, Text.txt dosyasındaki kelimeleri fonksiyonlar kullanarak aramaktadır.
Program çalışma detayları şu şekildedir :
Text.txt dosya içerisinde boş satır olmamalı ! 
Boş satır olursa beklenmedik hatalar alınabilir veya boş satır diziye eklenir.
Text.txt dosya içerisinde satırlarda yazan elemanlardan sonra boşluk olmamalı ! Elemanlardan sonra boşluk olursa beklenmedik hatalar alınabilir.
Elemanlardan sonra boşluk olursa eleman+boşluk diziye eklenir ve dizide eleman+boşluk şeklinde aranmalıdır.
Aranacak kelime Text.txt içerisinde varsa derste anlatıldığı gibi program onu bulup bitecektir. Eksilterek veya yer değiştirerek aramayacaktır.
Text.txt  içerisindeki kelimelerin on harften kısa olması görsel çıktı için daha uygun olacaktır.
Program birebir arama ve yer değiştirerek arama yapabilmektedir.
Program eksilterek arama yapamamaktadır. Eksilterek hangi kelimelerin aranacağını yazdırabilmektedir.
İngiliz alfabesi ile yazılan büyük veya küçük harfli kelimeleri arayabilmektedir.



SONUÇLAR
------------------------------
Program global değişkenler yardımıyla fonksiyonlar içerisinde işlem yapmaktadır.
Aranan kelime fonksiyonlar yardımıyla global string dizinde aranacaktır.
Çakışan kelimeler çıktı olarak verilecektir.
Örneğin 52 değeri arandığında çıktı:

![Hash_Table logo](https://www.sysadmins.lv/content/images/articles/hashtable-behind-the-scenes/linear-probing-search.png)

      Aranan değer 6. indiste bulunmaktadır.
      Kelime 5 kez boş yer aramış.  5. denemedeki yere yerleşmiş. 


şeklinde olacaktır.
___________________________________________________________________________________________________________________________________

İletişim
------------------------------

http://www.recepkarademir.com
https://recepkarademir.blogspot.com.tr
https://recepkarademir.wordpress.com
