#pragma once
#include "biblioteka.h"

class Zapiszgre
{
public:
	Clock clockZapis;
	Time timeZapis;

	void drawZapisz(RenderWindow& window);
	void MoveUpZapisz();
	void MoveDownZapisz();
	void uploadZapisz(Event& event, RenderWindow& window);
	Zapiszgre();
	~Zapiszgre();
	int ZapisPressed()
	{
		return WybranyZapis;
	}
	void ClockRestart();
	int ClockTime();
	void DownloadDataToSave(int EHp[10],int SSHp,int SSscore,string filename);
	
private:


	int WybranyZapis ;
	Font font;
	Text Zapis[4];
	
};

