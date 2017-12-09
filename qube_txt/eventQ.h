#pragma once
//wydarzenie podczas gry.
class eventQ
{
	int hpE; //wytrzyma³oœæ obiektu
	int siE; //si³a obiektu (przeciwnik)
	int chestHpE; //dodatek ¿ycia (skrzynka)
	bool keyE; //czy obiekt ma klucz?
	bool friendE; //czy obiekt jest przyjazny/skrzynka otwarta (true) czy wrogi/zamkniêta

	void createChest(); //tworzenie skrzynki
	void createMob(); //tworzenie potwora

public:
	//getter zmiennej keyE
	bool getKey();
	//tworzy nowy event losowy
	void create();
	//wyœwietla info tekstowe o evencie oraz przyjmuje i wyœwietla klawisz interakcji z eventem
	void info(char);
	//wykonuje akcje zwi¹zan¹ z aktualnym eventem - do ogarniêcia czy int czy void i przyjmowane argumenty (mo¿e nie konieczne)
	int action(int);

	eventQ();
	~eventQ();
};
