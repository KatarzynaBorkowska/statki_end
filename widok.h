#ifndef WIDOK_H
#define WIDOK_H

class widok
{
	public:
	int dwa,trzy ,cztery ,piec ; // statki
	int x,y;
	char z;
	
	virtual ~widok() { };
	
	void gra(int);
	bool wygrana(int);
	void plansza(int);
	void plansza_tworzenie(int);
	void uzupelnianie(int);
	void statki();
	void statki_k(int,int,char);
	void statki_l(int,int,char);
	void gra_losowa(int);
	
	void menu();
	
	void AvsB();
	void AvsC();
	void CvsC();
	
	void traf(int, int, int);
	
};

#endif


