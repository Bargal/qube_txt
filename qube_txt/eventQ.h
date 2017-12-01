#pragma once
//wydarzenie podczas gry.
class eventQ
{
	int hpE; //wytrzyma�o�� obiektu
	int siE; //si�a obiektu (przeciwnik)
	int chestHpE; //dodatek �ycia (skrzynka)
	bool keyE; //czy obiekt ma klucz?
	bool friendE; //czy obiekt jest przyjazny/skrzynka otwarta (true) czy wrogi/zamkni�ta

	void createChest(); //tworzenie skrzynki
	void createMob(); //tworzenie potwora

public:
	//getter zmiennej keyE
	bool getKey();
	//tworzy nowy event losowy
	void create();
	//wy�wietla info tekstowe o evencie oraz przyjmuje i wy�wietla klawisz interakcji z eventem
	void info(char);
	//wykonuje akcje zwi�zan� z aktualnym eventem - do ogarni�cia czy int czy void i przyjmowane argumenty (mo�e nie konieczne)
	int action(int);

	eventQ();
	~eventQ();
};
