#include <iostream>
#include <stdlib.h>
using namespace std;

char A[3][3] = {  {'1','2','3'},   //Oyunun temelini dizi konusunu kullanarak oluşturduk, bundan kaynaklı iki boyutlu bir dizi kullanmamız gereklidir.
        		  {'4','5','6'},
        		  {'7','8','9'} };

int X, O;               //Oyun içerisinde kullanacağımız semboller.
int round = 0;          //Oyunda maksimum hamle sayısı 9'dur, bundan dolayı hamle sınırlaması yapmalıyız.
int r, c, i, j;         //Döngü ve swich-case yapısı için kullanmamız gereken değişkenler.
char symbol = 'O';      //Oyunu 'O' sembolu ile başlattık.
bool result = false;    //Sonucumuzu bulmak icin bir result değişkeni tanımladık.
string name1 = "";      //Oyuncuların isimlerini almamız için bu tanımlar yapılmalıdır.
string name2 = "";

void Name();
void GameBoard();      
int RunGame();     
bool Control();
int Again();
int main() 
{
    Name();
    //Oyuncuların isimlerini almamız için kullandığımız fonksiyon.
    while (!Control() && round < 9)
    {
        GameBoard();          //Oyun tahtasının çağrıldığı fonksiyon.
        RunGame();           //Oyunun yürütüldüğü fonksiyon
        result=Control();    //Oyunun sonucunun hesaplandığı fonksiyon.
    }
//Bu döngü maksimum 9 kere dönmektedir ve Control() fonksiyonu tamamlandığında bitmektedir.
    if (symbol == 'X' && result == true)
    {
        cout << name1 << " kazandi !" << endl;
    }
   else if (symbol == 'O' && result == true)
    {
        cout << name2 << " kazandi !" << endl;
    }
//Control fonksiyonundan aldığımız return değerine göre kazanan kişi, bu kısımda yazdırılır
   else if(round==9 && result== false) 
    {                                           
        cout << "Sonuc berabere."<<endl;
    }
//Bir kazanan yok ise sonuç, bu kısımda yazdırılır.
Again(); 
//Oyunculara tekrar oynamak istediklerini bir soran fonksiyondur. Oyuncunun cevabına göre oyun sonlandırılır veya baştan başlatılır.
return 0;
}

void Name()
{
cout << "TicTacToe oyunu 2 kisi ile oynanmalidir. Peki nasil oynanir? Oyunculardan biri 'X' , digeri 'O' sembolunu kullanmalidir. Oyun sonunda 3 ayni sembolu arka arkaya veya carpraz siralayan oyuncu, 3 sembolun uzerine cizik atar ve oyunu kazanir. Oyun sonunda 3 ayni sembol arka arkaya veya carpraz siralanamamis ise oyun beraberedir.\n\n\n\n";
//Oyun açıklaması
    cout << "Birinci oyuncunun ismini giriniz: ";
    cin >> name1;
    cout << endl;
    cout << "Ikinci oyuncunun ismini giriniz: ";
    cin >> name2;
    cout << endl;
    cout << "Oyuna ilk baslayan: " << name1 <<".   Sembolunuz:'O'"<< endl;
    cout << "Oyuna ikinci baslayan: " << name2 <<".     Sembolunuz:'X'"<<endl;
    //Oyunculardan isim alınır ve semboller belirlenir.
}

void GameBoard() 
{
    cout << "     |     |" << endl;
    cout << "  " << A[0][0] << "  |  " << A[0][1] << "  |  " << A[0][2] <<  endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |" << endl;
    cout << "  " << A[1][0] << "  |  " << A[1][1] << "  |  " << A[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |" << endl;
    cout << "  " << A[2][0] << "  |  " << A[2][1] << "  |  " << A[2][2] << endl;
    cout << "     |     |" << endl;
    //Dizi kullanılarak oluşturulan oyun tahtası.
}
int RunGame() 
{
    int space;

    if (symbol == 'O') 
    {
        cout << name1 << " sira sizde. Sembol:'O'"<<endl;
        cout<<"Secim: ";
    }
    //Oyuncuların sırasını ve sembolünü söyleyen komuttur.
    else 
    {
        cout << name2 << " sira sizde. Sembol'X'"<<endl;
        cout<<"Secim: ";
    }
    cin >> space;
    if (space < 1 || space > 9) 
    {
        cout << "Lutfen tabloda gordugunuz rakamlardan baska sayilar tuslamayiniz!\a";
        RunGame();      
    }
     //Eğer oyuncu 1'den 9'a kadar olan rakamlardan başka bir sayı tuşlarsa fonksiyon uyarı verir ve tekrar tuşlama hakkı tanır.
    int r,c;
    switch (space) {        
    case 1:
        r = 0;
        c = 0;
        break;
    case 2:
        r = 0;
        c = 1;
        break;
    case 3:
        r = 0;
        c = 2;
        break;
    case 4:
        r = 1;
        c = 0;
        break;
    case 5:
        r = 1;
        c = 1;
        break;
    case 6:
        r = 1;
        c = 2;
        break;
    case 7:
        r = 2;
        c = 0;
        break;
    case 8:
        r = 2;
        c = 1;
        break;
    case 9:
        r = 2;
        c = 2;
        break;
    }
    //Bu kısımda oyuncunun tuşladığı rakama göre dizideki satır ve sütun değerlerini belirlenir.

    if (symbol == 'X' && A[r][c] != 'X' && A[r][c] != 'O') {
        A[r][c] = 'X';
        symbol = 'O';   
        round++;
        system("cls");
    } 
    //Oyuncunun tuşladığı rakama göre satır ve sütun değerleri alındıktan sonra o boşlukta bir sembol olup olmadığı kontrol edilir.
    //Eğer boşlukta bir sembol yok ise yeni sembol konulur ve sonraki tura geçilir.
    else if (symbol == 'O' && A[r][c] != 'X' && A[r][c] != 'O') {

        A[r][c] = 'O';
        symbol = 'X';
        round++;
        system("cls");
    }
    else if (A[r][c] == 'X' || A[r][c] == 'O') {
        cout << "Bu bosluk dolu. Lutfen baska bir bosluga yerlestirin.\n";
        RunGame();   
    }
//Eğer oyuncunun tuşladığı boşlukta bir sembol var ise oyun uyarı verir ve tekrar tuşlama hakkı tanır.
}
bool Control() 
{
    if (A[0][0] == A[1][1] && A[0][0] == A[2][2] && A[0][0]!=' ')
        return true;
   
    if (A[2][0] == A[1][1] && A[2][0] == A[0][2] && A[2][0] != ' ')
        return true;

    if (A[0][0] == A[1][0] && A[0][0] == A[2][0] && A[0][0] != ' ')
        return true;

    if (A[0][1] == A[1][1] && A[0][1] == A[2][1] && A[0][1] != ' ')
        return true;

    if (A[0][2] == A[1][2] && A[0][2] == A[2][2] && A[0][2] != ' ')
        return true;

    if (A[0][0] == A[0][1] && A[0][0] == A[0][2] && A[0][0] != ' ')
        return true;

    if (A[1][0] == A[1][1] && A[1][0] == A[1][2] && A[1][0] != ' ')
        return true;

    if (A[2][0] == A[2][1] && A[2][0] == A[2][2] && A[2][0] != ' ')
        return true;
/*Yukarıda yazılan olasılıklar sağlandığı takdirde oynayan kişi kazanmış demektir. "True" koşulların sağlandığı anlamına gelmektedir.
result=true olarak tanımlanır ve kazanan kişinin ismi main fonksiyonunda yazdırılır.*/
return false;
/*Yukarıda yazılan olasılıklar sağlanmadığı zaman ise result=false olarak tanımlanır. Bu da bir kazanan olmadığı anlamına gelir. 
Yani oyun beraberedir.*/
}

int Again()
{
    int answer;
    cout<<"Oyun sona erdi, tekrar oynamak ister misiniz? Cevabiniz evet ise 1'i, hayir ise 0'i tuslayiniz."<<endl;
    cin>>answer;
//Oyunculara tekrar oynamak istediklerini bir soran komuttur.

if(answer==1)
{
    main(); 
}
//Tuşladığınız rakam 1 ise main fonksiyonu çağırılır ve oyun tekrar başlar.

else if(answer==0)
{
cout<<"Oyun sona ermistir. Oynadiginiz icin tesekkur ederiz."<<endl;
}
//Tuşladığınız rakam 0 ise oyun sonlandırılır ve bu oyunu hazırlayan kişilerin isimleri ekrana yazdırılır.
else
{
cout<<"Lutfen 1 ve 0'dan baska rakam tuslamayiniz!"<<endl<<endl;
Again();    
}
// 1 ve 0'dan başka bir rakam tuşladığınız takdirde uyarı verir ve Again() fonksiyonu tekrar çağrılır.
}
