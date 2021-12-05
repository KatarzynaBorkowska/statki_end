#include "widok.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
char tab[4][30][30];
bool gracz = false;

void widok::menu(){
	statki();
	cout << "GRACZ A vs GRACZ B -podaj 1\nGRACZ A vs KOMPUTER -podaj 2\nKOMPUTER vs KOMPUTER -podaj 3\n";
	char znak;
	cin >> znak;
	switch(znak){
		case '1':
			AvsB();
			break;
		case '2':
			AvsC();
			break;
		case '3':
			CvsC();
			break;
		default:
			cout << "Brak takiego polecenia\n";
	}
}

void widok::CvsC(){
	
	gracz = true;
	
	plansza_tworzenie(0);// widzi swoja gracz A
    plansza_tworzenie(1);  // ta widzi komputer
    uzupelnianie(0);
    
    system("cls");
    //plansza(0);
    //cout << "Gracz A\n";
    //cout << "Oddaj plansze przeciwnikowi\n";
    
   // Sleep(5000);
    //cout << "\n";
    //system("cls");
    
    // tworzenie planszy komputera
    
    plansza_tworzenie(2); // widzi swoja komputer
    plansza_tworzenie(3); // ta widzi gracz A
    uzupelnianie(2);		
    //system("cls");
    //plansza(2);
    cout << "Gracz komputer wygenerowal swoja plansze\n";
    //cout << "Komputer zaczyna: ";
    Sleep(2000);
    
    
    bool temp;

	while(true)
	{
		gra_losowa(1);
		temp = wygrana(0);
			if(temp == true)
			{
				system("cls");
				plansza(0);
				cout << "WYGRANA Komputera B!!!\n";
				return ;
			}
		gra_losowa(3);
		temp = wygrana(2);
			if(temp == true)
			{
				system("cls");
				plansza(2);
				cout << "WYGRANA Komputera A!!!\n";
				return ;
			}
	}
}

void widok::AvsC(){
	 plansza_tworzenie(0);// widzi swoja gracz A
    plansza_tworzenie(1);  // ta widzi komputer
    uzupelnianie(0);
    
    system("cls");
    plansza(0);
    cout << "Gracz A komputer wygenerowal swoja plansze\n";
    cout << "Oddaj plansze przeciwnikowi\n";
    
    Sleep(5000);
    cout << "\n";
    system("cls");
    
    // tworzenie planszy komputera
    gracz = true;
    plansza_tworzenie(2); // widzi swoja komputer
    plansza_tworzenie(3); // ta widzi gracz A
    uzupelnianie(2);		
    system("cls");
    plansza(2);
    cout << "Gracz B komputer wygenerowal swoja plansze\n";
    cout << "Komputer zaczyna: ";
    Sleep(2000);
    
    
    bool temp;

	while(true)
	{
		gra_losowa(1);
		temp = wygrana(0);
			if(temp == true)
			{
				system("cls");
				plansza(0);
				cout << "WYGRANA Komputera!!!\n";
				return ;
			}
		gra(3);
		temp = wygrana(2);
			if(temp == true)
			{
				system("cls");
				plansza(2);
				cout << "WYGRANA Gracza A!!!\n";
				return ;
			}
	}
}

void widok::AvsB(){
 	
    // tworzenie planszy A
    plansza_tworzenie(0);// widzi swoja gracz A
    plansza_tworzenie(1);  // ta widzi gracz B
    uzupelnianie(0);
    
    system("cls");
    plansza(0);
    cout << "Gracz A\n";
    cout << "Oddaj plansze przeciwnikowi\n";
    Sleep(5000);
    cout << "\n";
    system("cls");
    
    // tworzenie planszy B
    plansza_tworzenie(2); // widzi swoja gracz B
    plansza_tworzenie(3); // ta widzi gracz A
    uzupelnianie(2);		
    system("cls");
    plansza(2);
    cout << "Gracz B\n";
    cout << "Przygotuj sie zaczynasz: ";
    Sleep(2000);
    
    bool temp;

	while(true)
	{
		gra(1);
		temp = wygrana(0);
			if(temp == true)
			{
				system("cls");
				plansza(0);
				cout << "WYGRANA Gracza B!!!\n";
				return ;
			}
		gra(3);
		temp = wygrana(2);
			if(temp == true)
			{
				system("cls");
				plansza(2);
				cout << "WYGRANA Gracza A!!!\n";
				return ;
			}
	}
}

bool widok::wygrana(int n)
{
	int i,j;
	for(i = 0;i < 30;i++)
	{
		for(j = 0;j < 30;j++)
		{
			if(tab[n][i][j] != '*' && tab[n][i][j] != 'O' && tab[n][i][j] != 'X'){
				return false;
			}
		}
	}
	return true;
}

void widok::gra_losowa(int n)
{
	int x,y;
	x = (rand()%30) + 1;
	y = (rand()%30) + 1;
	system("cls");
	plansza(n);
	cout << "Gra gracz ";
	if(n == 3)
		cout << "A Komputer\n";
	else 
		cout << "B Komputer\n";
	cout << "Podaj wiersz X kolumna: ";
	cout << x << " " << y << endl;
	if(tab[n-1][x-1][y-1] == 'X' || tab[n-1][x-1][y-1] == 'O')
	{
		gra_losowa(n);
		return;
	}
	if(tab[n-1][x-1][y-1] != '*' && tab[n-1][x-1][y-1] != 'X'  && tab[n-1][x-1][y-1] != 'O')
	{
		
		tab[n][x-1][y-1] = 'X';
		tab[n-1][x-1][y-1] = 'X';
		if(wygrana(n-1) == true)
			return;
		Sleep(4000);	
		traf(n,x-1,y-1);
		gra_losowa(n);
		return;
	}
	Sleep(4000);
	system("cls");
	tab[n][x-1][y-1] = 'O';
}

void widok::traf(int n, int x,int y){
	
	if(x != 0){
		if(tab[n-1][x-1][y] != '*' && tab[n-1][x-1][y] != 'X' && tab[n-1][x-1][y] != 'O')
		{
		tab[n][x-1][y] = 'X';
		tab[n-1][x-1][y] = 'X';
		system("cls");
		plansza(n);
		cout << "Gra gracz ";
		if(n == 3)
			cout << "A Komputer\n";
		else 
			cout << "B Komputer\n";
		cout << "Podaj wiersz X kolumna: ";
		cout << x << " " << y+1 << endl;
		Sleep(4000);
		traf(n,x-1,y);
		return ;
		}
		if(tab[n-1][x-1][y] != 'X' && tab[n-1][x-1][y] != 'O'){
			tab[n][x-1][y] = 'O';
		return ;
		}
		
	}
	if(x != 29){
		
		if(tab[n-1][x+1][y] != '*' && tab[n-1][x+1][y] != 'X' && tab[n-1][x+1][y] != 'O')
		{
		tab[n][x+1][y] = 'X';
		tab[n-1][x+1][y] = 'X';
		system("cls");
		plansza(n);
		
		cout << "Gra gracz ";
		if(n == 3)
			cout << "A Komputer\n";
		else 
			cout << "B Komputer\n";
		cout << "Podaj wiersz X kolumna: ";
		cout << x+2 << " " << y+1 << endl;
		Sleep(4000);
		traf(n,x+1,y);
		return ;
		}
		if(tab[n-1][x+1][y] != 'X' && tab[n-1][x+1][y] != 'O')
		{
			tab[n][x+1][y] = 'O';
		return ;
		}
		
	}
	if(y != 0){
		if(tab[n-1][x][y-1] != '*' && tab[n-1][x][y-1] != 'X'&& tab[n-1][x][y-1] != 'O')
		{
		tab[n][x][y-1] = 'X';
		tab[n-1][x][y-1] = 'X';
		system("cls");
		plansza(n);
		cout << "Gra gracz ";
		if(n == 3)
			cout << "A Komputer\n";
		else 
			cout << "B Komputer\n";
		cout << "Podaj wiersz X kolumna: ";
		cout << x+1 << " " << y << endl;
		Sleep(4000);
		traf(n,x,y-1);
		return ;
		}
		if(tab[n-1][x][y-1] != 'X'&& tab[n-1][x][y-1] != 'O')
		{
			tab[n][x][y-1] = 'O';
		return ;
		}
		
	}
	if(y != 29){
		if(tab[n-1][x][y+1] != '*' && tab[n-1][x][y+1] != 'X'&& tab[n-1][x][y+1] != 'O')
		{
		tab[n][x][y+1] = 'X';
		tab[n-1][x][y+1] = 'X';
		system("cls");
		plansza(n);
		cout << "Gra gracz ";
		if(n == 3)
			cout << "A Komputer\n";
		else 
			cout << "B Komputer\n";
		cout << "Podaj wiersz X kolumna: ";
		cout << x+1 << " " << y+2 << endl;
		Sleep(4000);
		traf(n,x,y+1);
		return ;
		}
		if(tab[n-1][x][y+1] != 'X'&& tab[n-1][x][y+1] != 'O')
		{
			tab[n][x][y+1] = 'O';
		return ;
		}
		
	}
	
	
}

void widok::gra(int n) // bomba na statek
{
	int x,y;
	system("cls");
	plansza(n);
	cout << "Gra gracz ";
	if(n == 3)
		cout << "A\n";
	else 
		cout << "B\n";
	cout << "Podaj wiersz X kolumna: ";
	cin >> x >> y;
	if(tab[n-1][x-1][y-1] != '*')
	{
		tab[n][x-1][y-1] = 'X';
		tab[n-1][x-1][y-1] = 'X';
		if(wygrana(n-1) == true)
			return;
		
		gra(n);
		return;
	}
	system("cls");
	cout << "Oddaj plansze 2 graczowi\n";
	Sleep(3000);
	tab[n][x-1][y-1] = 'O';
}

void widok::statki(){// wybieranie ilosci statkow
	cout << "Ile statkow 2 masztowych? ";
	cin >> dwa;
	cout << "Ile statkow 3 masztowych? ";
	cin >> trzy;
	cout << "Ile statkow 4 masztowych? ";
	cin >> cztery;
	cout << "Ile statkow 5 masztowych? ";
	cin >> piec;
}


void widok::statki_k(int n, int l,char s) // wybieranie miesc dla statkow
{
	system("cls");
   	plansza(n);
	int x,y,i;
	char z;
	cout << "Gra gracz ";
	if(n == 0)
		cout << "A\n";
	else 
		cout << "B\n";
	cout << "Pierwsze wspolczedne statku o " << l << " masztach wiersz X kolumna: ";
		cin >> x >> y;
		
		if(x < 1 || x > 30 || y < 1 || y > 30){
			cout << "Nie ma takich wymiarow\n";
			Sleep(2000);
			statki_k(n,l,s);
			return ;
		}
		cout << "L - na lewo,\tP - na prawo,\tG - w gore,\tD - w dol\n";
		cin >> z;
	
		if(toupper(z) != 'L' && toupper(z) != 'P' && toupper(z) != 'G' && toupper(z) != 'D')
		{
			cout << "Nie ma takiego kierunku\n";
			Sleep(2000);
			statki_k(n,l,s);
			return ;
		}
	
	
	if((x - l < 0 && toupper(z) == 'G')|| (x + l > 31 && toupper(z) == 'D') || (y - l < 0 && toupper(z) == 'L') || (y + l > 31 && toupper(z) == 'P'))
	{
		cout << "Statki sie nie zmieszcza\n";
		Sleep(2000);
		statki_k(n,l,s);	
		return ;
	}
	
	x--;
	y--;
	if(tab[n][x][y] != '*')
	{
		cout << "Cos juz tam jest\n";
		Sleep(2000);
		statki_k(n,l,s);
		return ;
	}
		
	// Czy jest tam juz jakis statek
	for(i = 1;i < l;i++)
	{
		if(tab[n][x-i][y] != '*' || tab[n][x+i][y] != '*' || tab[n][x][y+i] != '*' || tab[n][x][y-i] != '*')
		{
			cout << "Cos juz tam jest\n";
			Sleep(2000);
			statki_k(n,l,s);			
			return ;
		}
	}
	
	if(tab[n][x-1][y+1] != '*' || tab[n][x+1][y-1] != '*' || tab[n][x+1][y+1] != '*' || tab[n][x-1][y-1] != '*')
	{
			cout << "Cos juz tam jest\n";
			Sleep(2000);
			statki_k(n,l,s);			
			return ;
	}
	
	// sprawdzam obwod
	
	if(toupper(z) == 'L')
	{
		if(x -1 != -1 || y - 1 != -1){
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x - 1][y-i] != '*' || tab[n][x + 1][y-i] != '*' )
			{
			statki_k(n,l,s);
			return ;
			}
		}
		if(tab[n][x][y-l] != '*' || tab[n][x][y+1] != '*')
		{
			statki_k(n,l,s);
			return ;
		}
	}
	}
	
	if(toupper(z) == 'P')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x - 1][y+i] != '*' || tab[n][x + 1][y+i] != '*')
			{
			statki_k(n,l,s);
			return ;
			}
		}
		
			if(tab[n][x][y+l] != '*' || (tab[n][x][y-1] != '*' && (y-1 != -1)))
		{
			statki_k(n,l,s);
			return ;
		}
		
		
	}
	
	if(toupper(z) == 'D')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x+i][y-1] != '*' || tab[n][x +i][y+1] != '*')
			{
			statki_k(n,l,s);
			return ;
			}
		}
		if(tab[n][x+l][y] != '*' || tab[n][x-1][y] != '*')
		{
			statki_k(n,l,s);
			return ;
		}
	}
	
	if(toupper(z) == 'G')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x-i][y-1] != '*' || tab[n][x -i][y+1] != '*')
			{
			statki_k(n,l,s);
			return ;
			}
		}
		if(tab[n][x+1][y] != '*' || tab[n][x-l][y] != '*')
		{
			statki_k(n,l,s);
			return ;
		}
	}

	
	tab[n][x][y] = s;
	for(i = 1;i < l;i++)
	{
		if(toupper(z) == 'G')
			tab[n][x-i][y] = s;
		if(toupper(z) == 'D')
			tab[n][x+i][y] = s;
		if(toupper(z) == 'P')
			tab[n][x][y+i] = s;
		if(toupper(z) == 'L')
			tab[n][x][y-i] = s;
	}
}

void widok::statki_l(int n,int l, char s){ //losowanie miesc dla statkow
	int i;
	
		
		char liczba[] = {'L','P','G','D'};
		
		x = (rand()%30) + 1;
		y = (rand()%30) + 1;
		i = (rand()%3) + 0;
		z = liczba[i];
	
	if((x - l < 0 && toupper(z) == 'G')|| (x + l > 31 && toupper(z) == 'D') || (y - l < 0 && toupper(z) == 'L') || (y + l > 31 && toupper(z) == 'P'))
	{
		statki_l(n,l,s);
		return ;
	}
	
	x--;
	y--;
	if(tab[n][x][y] != '*')
	{
		statki_l(n,l,s);
		return ;
	}
		
	// Czy jest tam juz jakis statek
	for(i = 1;i < l;i++)
	{
		if(tab[n][x-i][y] != '*' || tab[n][x+i][y] != '*' || tab[n][x][y+i] != '*' || tab[n][x][y-i] != '*')
		{
			statki_l(n,l,s);
			return ;
		}
	}
	
	if(tab[n][x-1][y+1] != '*' || tab[n][x+1][y-1] != '*' || tab[n][x+1][y+1] != '*' || tab[n][x-1][y-1] != '*')
	{
			statki_l(n,l,s);
			return ;
	}
	
	// sprawdzam obwod
	
	if(toupper(z) == 'L')
	{
		for(i = -1;i <= l;i++)
		{
			if(x -1 != -1 || y - 1 != -1){
			
			if(tab[n][x - 1][y-i] != '*' || tab[n][x + 1][y-i] != '*' )
			{
			statki_l(n,l,s);
			return ;
			}}
		}
		if(tab[n][x][y-l] != '*' || tab[n][x][y+1] != '*')
		{
			statki_l(n,l,s);
			return ;
		}
	}
	
	if(toupper(z) == 'P')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x - 1][y+i] != '*' || tab[n][x + 1][y+i] != '*')
			{
			statki_l(n,l,s);
			return ;
			}
		}
		
			if(tab[n][x][y+l] != '*' || (tab[n][x][y-1] != '*' && (y-1 != -1)))
		{
			statki_l(n,l,s);
			return ;
		}
		
		
	}
	
	if(toupper(z) == 'D')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x+i][y-1] != '*' || tab[n][x +i][y+1] != '*')
			{
			statki_l(n,l,s);
			return ;
			}
		}
		if(tab[n][x+l][y] != '*' || tab[n][x-1][y] != '*')
		{
			statki_l(n,l,s);
			return ;
		}
	}
	
	if(toupper(z) == 'G')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x-i][y-1] != '*' || tab[n][x -i][y+1] != '*')
			{
			statki_l(n,l,s);
			return ;
			}
		}
		if(tab[n][x+1][y] != '*' || tab[n][x-l][y] != '*')
		{
			statki_l(n,l,s);
			return ;
		}
	}

	
	tab[n][x][y] = s;
	for(i = 1;i < l;i++)
	{
		if(toupper(z) == 'G')
			tab[n][x-i][y] = s;
		if(toupper(z) == 'D')
			tab[n][x+i][y] = s;
		if(toupper(z) == 'P')
			tab[n][x][y+i] = s;
		if(toupper(z) == 'L')
			tab[n][x][y-i] = s;
	}
}


void widok::uzupelnianie(int n) // statkami
{
	int i,w;
	if(gracz == false)
	{
		cout << "Jezeli chcesz wprowadzic dane z klawiatury podaj 1,\njezeli chcesz je wylosowac podaj 2\n";
	cin >> w;
	}
	else{
		w = 0;
	}
	

	for(i = 0;i < dwa;i++)
	{
		if(w == 1)
			statki_k(n,2,'2');
		else
			statki_l(n,2,'2');	
	}
	for(i = 0;i < trzy;i++)
	{
		if(w == 1)
			statki_k(n,3,'3');
		else
			statki_l(n,3,'3');		
	}
	for(i = 0;i < cztery;i++)
	{
		if(w == 1)
			statki_k(n,4,'4');
		else
			statki_l(n,4,'4');			
	}
	for(i = 0;i < piec;i++)
	{
		if(w == 1)
			statki_k(n,5,'5');
		else
			statki_l(n,5,'5');		
	}
	
}


void widok::plansza(int n)// wysruk planszy
{
	int i, j;
            
    if(n == 0 || n == 3)
    	cout << "A";
    else
    	cout << "B";
    cout << "  ";
    for (i = 1;i < 31;i++) {
        cout << i << " ";
        if (i < 10)
            cout << " ";
    }
    cout << "\n";

    for (i = 0;i < 30;i++)
    {
        cout << i + 1 << " ";
        if (i < 9)
            cout << " ";
        for (j = 0;j < 30;j++)
            cout << tab[n][i][j] << "  ";
        cout << endl;
    }
    
}

void widok::plansza_tworzenie(int n)
{
    int i, j;
    for (i = 0;i < 30;i++)
        for (j = 0;j < 30;j++)
            tab[n][i][j] =  '*';
   
}


