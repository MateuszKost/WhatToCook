#include "RFF.h"
#include "Fridge.h"
#include <string>
#include "Searching.h"

using namespace std;

int main()
{
	string nameoffile = "plik.txt";

	
	cout << " Witaj w aplikacji kulinarnej, ktorej zadaniem jest pomoc w gotowaniu !" << endl;
	cout << " Jako, ze w dzisiejszych czasach ciezko jest wszystkim dogodzic, staralem sie jak najbardziej zuniwersalizowac program." << endl;
	cout << " Jako uzytkownik otrzymujesz odgornie mozliwosc wyboru, ktory dotyczy tego co masz zamiar zjesc." << endl;
	cout << " Specjalnie dla Ciebie sprawilem, ze ten program jest roznorodny !" << endl;
	cout << " Do sedna, bo za duzo sie juz rozpisuje, a jeszcze nic nie wiesz." << endl;
	cout << " Za chwile odpowiesz na jedno pytanie na podstawie ktorego otrzymasz dostep do przepisow jakich sobie zazyczyles." << endl<<endl;
	
	cout << " Czy preferujesz zjesc danie z miesem, bezmiesne (czyli vege), czy tez nie robi Ci to roznicy ?" << endl;
	cout << " 1. Z miesem\n 2. Bez miesa/vege\n 3. Jest mi obojetne" << endl;
	
	start:
		cout << "\n Twoj wybor: ";
		int choice;
		cin >> choice;
	switch (choice)
	{
	case 1:
		nameoffile = "miesne.txt";
		cout << "\n Wybrales miesne przepisy!\n";
		break;
	case 2:
		nameoffile = "vege.txt";
		cout << "\n Wybrales vege przepisy!\n";
		break;
	case 3:
		nameoffile = "wszystkie.txt";
		cout << "\n Wybrales wszystkie przepisy!\n";
		break;
	case 4:
		cout << "\n test\n";
		break;
	default:
		cout << " Bledny wybor, wybierz ponownie!" << endl;
		goto start;
	}
	Searching searching;
	Recipe recipe;
	LoR LFF, LFC;//list for fridge, list for comparing
	RFF program(nameoffile);
	recipe = program.downloadfromfile(program.filename);
	//recipe.Ihead->show_Ing();
	//recipe.show_Recipe();

	cout << "\n Skoro juz wybrales, mozemy przejsc do dalszej czesci programu ;3" << endl << endl;

	cout << " Bedziesz mogl zobaczyc jakie dania mozesz wykonac za pomoca twoich produktow jakie znajdziesz w lodowce." << endl;
	cout << " Mozesz rowniez wyszukac sobie przepisu wedlug swoich potrzeb." << endl;
	cout << " Bedziesz mogl rowniez wylosowac sobie przepis na kazdy dzien tygodnia ^^" << endl;
	cout << " Na koncu, po skorzystaniu z programu, zostaniesz poproszony o wypelnienie raportu, co Ci zostalo i co z nimi zrobisz." << endl;
	cout << " Bedziesz mogl wybierac do woli !";

	string Fname; int Famount = 0; string Funit; // do produktow znajdujacych sie w lodowce
	Fridge F;
	int PRtime, afp;// preparing time, amount of people
	double costF1P;//cost for food for one person
	string SP, SA, SC;//strings used to change int or float for searching
again:
	cout<<"\n 1. Lodowka\n 2. Wyszukiwanie\n 3. Opusc program";
	//cout << "\n 1. Lodowka\n 2. Wyszukiwanie\n 3. Losuj przepisy\n 4. Opusc program";

	cout << "\n\n Twoj wybor: ";
	int choice2;
	cin >> choice2;
	switch (choice2)
	{
	case 1:
		cout << "\n Wybrales lodowke, zaraz poprosze Cie o podanie mi twoich produktow, ktore tam trzymasz.\n O to krotka instrukcja: ";
		Fagain:
		cout << "\n 1. dodaj produkt.\n 2. zakoncz dodawanie i pokaz przepisy";
		cout << "\n\n Twoj wybor:";
		int add;
		cin >> add;
		switch (add)
		{
		case 1:
			cout << "\n Prosze o podanie 3 informacji\n 1. Nazwa: ";
			cin >> Fname;
			cout << " 2. Ilosc: ";
			cin >> Famount;
			cout << " 3. Jednostka (gramy(g), mililitry(ml), sztuki(szt)): ";
			cin >> Funit;
			F.save(Fname, Famount, Funit);
			F.add_to_ingredients_list(F);
			goto Fagain;

		case 2:
			cout << "\n O to przepisy, ktore mozesz wykonac z produktami z swojej lodowki: \n";
			LFF = F.compare_FandInginRec(F, recipe);
			LFF.show_LoR();
			break;
		}
		goto again;
	case 2:
		cout << "\n Wybrales wyszukiwanie przepisu! Przepisy mozesz wyszukac po:\n - czasie jaki chcesz przeznaczyc na przygotowanie dania\n - ilosci osob, dla ktorej chcesz przygotowac danie\n - cenie maksymalnej jaka chcesz przeznaczyc na danie\n" << std::endl;
		cout << " Prosze wpisac wartosc, badz kliknac enter jezeli nie chcesz uzyc tej ocpji wyszukiwania!" << endl;
		cout << " Po wpisaniu zmiennych do wyszukiwarki, wyswietla Ci Ci sie przepisy spelniajace twoje wymogi!\n" << endl;
		getchar();
		cout << " 1. Jaki maksymalny czas chcesz przeznaczyc na przygotowanie ? :";
		getline(cin, SP);
		PRtime = atoi(SP.c_str());
		cout << " 2. Na ile maksymalnie osob chcesz przygotowac danie ? :";
		getline(cin, SA);
		afp = atoi(SA.c_str());
		cout << " 3. Jaka maksymalna ilosc pieniedzy na osobe chcesz przenaczyc na danie ? :";
		getline(cin, SC);
		costF1P = atof(SC.c_str());

		LFC = searching.search(PRtime, afp, costF1P, recipe);
		LFC.show_LoR();
		//cout << PRtime << afp << costF1P;
		goto again;
	/*case 3:
		cout << "\n Wybrales wszystkie przepisy!\n";
		goto again;*/
	case 3:
		cout << "\n Zamierzasz skonczyc prace na mojej aplikacji, prosze Cie jeszcze tylko o wypelnienie raportu jezeli chcesz";
		// tutaj bedzie instrukcja do pisania raportu etc
		goto end;
	default:
		cout << " Bledny wybor, wybierz ponownie!" << endl;
		goto again;
	}
end:
	cout << "\n Dziekuje za skorzystanie z programu ;3\n\n";
	//Fridge F;//("mama", 20, "ml");
	/*F.save("mama", 20, "XD");
	F.add_to_ingredients_list(F);
	F.add_to_ingredients_list(F);
	F.add_to_ingredients_list(F);
	
	F.show_LOF();// dodawanie do listy w lodowce dzia³a xd
	*/
}