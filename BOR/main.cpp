#include "RFF.h"
#include "Fridge.h"
#include <string>
#include "Searching.h"
#include "Raport.h"

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
		string CH;
		int choice;
		cin >> CH;
		choice = atoi(CH.c_str());
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
	default:
		cout << " Bledny wybor, wybierz ponownie!" << endl;
		goto start;
	}
	Searching searching;
	LoR LIST;
	LoR LFF, LFC;//list for fridge, list for comparing
	RFF program(nameoffile);
	try
	{
		LIST = program.downloadfromfile(program.filename);
	}
	catch (string wyjatek)
	{
		cout << wyjatek;
	};

	//LIST.show_LoR();// sprawdzanie czy przepisy zostaly dobrze pobrane

	cout << "\n Skoro juz wybrales, mozemy przejsc do dalszej czesci programu ;3" << endl << endl;

	cout << " Bedziesz mogl zobaczyc jakie dania mozesz wykonac za pomoca twoich produktow jakie znajdziesz w lodowce." << endl;
	cout << " Mozesz rowniez wyszukac sobie przepisu wedlug swoich potrzeb." << endl;
	cout << " Bedziesz mogl rowniez wylosowac sobie przepis na kazdy dzien tygodnia ^^" << endl;
	cout << " Na koncu, po skorzystaniu z programu, zostaniesz poproszony o wypelnienie raportu, co Ci zostalo i co z nimi zrobisz." << endl;
	cout << " Bedziesz mogl wybierac do woli !";

	LoR TMP;
	string Fname, Rname; int Famount = 0, Ramount = 0; string Funit, Runit; // do produktow znajdujacych sie w lodowce
	Fridge F, R;
	Raport raport("Raport.txt");
	F.Ihead;
	int PRtime, afp;// preparing time, amount of people
	double costF1P;//cost for food for one person
	string SP, SA, SC;//strings used to change int or float for searching
again:
	cout<<"\n 1. Lodowka\n 2. Wyszukiwanie\n 3. Opusc program";
	cout << "\n\n Twoj wybor: ";
	string CH2, ADD, RAP, XD, where;
	int choice2, rap;
	cin >> CH2;
	choice2 = atoi(CH2.c_str());
	switch (choice2)
	{
	case 1:
		cout << "\n Wybrales lodowke, zaraz poprosze Cie o podanie mi twoich produktow, ktore tam trzymasz.\n O to krotka instrukcja: ";
	Fagain:
		cout << "\n 1. dodaj produkt.\n 2. zakoncz dodawanie i pokaz przepisy";
		cout << "\n\n Twoj wybor:";
		int add;
		cin >> ADD;
		add = atoi(ADD.c_str());
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
			if (F.Ihead == nullptr)
			{
				cout << "\n Niestety nie ma takich przepisow !\n";
			}
			else
			{
				LFF = F.compare_FandInginRec(F.Ihead, LIST);
				cout << "\n O to przepisy, ktore mozesz wykonac z produktami z swojej lodowki: \n";
				LFF.show_LoR();
			}
			break;
		default:
			cout << " Bledny wybor, wybierz ponownie!" << endl;
			goto Fagain;
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
		TMP = LIST;
		LFC = searching.search(PRtime, afp, costF1P, TMP);
		LFC.show_LoR();
		goto again;
	case 3:
		cout << "\n Zamierzasz skonczyc prace na mojej aplikacji, prosze Cie jeszcze tylko o wypelnienie raportu.";
		cout << "\n Na poczatku poprosze Cie o podanie teo co Ci zostalo: ";	
		int wybor;
	Ragain:
		cout << "\n 1. dodaj produkt.\n 2. zakoncz dodawanie i przejdz dalej";
		cout << "\n\n Twoj wybor: ";
		cin >> RAP;
		rap = atoi(RAP.c_str());
		switch (rap)
		{
		case 1:
			cout << "\n Prosze o podanie 3 informacji\n 1. Nazwa: ";
			cin >> Rname;
			cout << " 2. Ilosc: ";
			cin >> Ramount;
			cout << " 3. Jednostka (gramy(g), mililitry(ml), sztuki(szt)): ";
			cin >> Runit;
			R.save(Rname, Ramount, Runit);
			R.add_to_ingredients_list(R);
			goto Ragain;
		case 2:
			onemore:
			cout << "\n W dalszej czesci zdecydujesz co chcesz zrobic z tym jedzeniem. ";
			cout << "\n 1. Do kosza. \n 2. Do kompostownika. \n 3. Piesek zje ;3 " << endl;
			cout << " Twoj wybor: ";
			cin >> XD;
			wybor = atoi(XD.c_str());
			switch (wybor)
			{
			case 1:
				where = "KOSZ";
				raport.send_to_file(R.Ihead, where, raport.Tfilename);
				break;
			case 2:
				where = "KOMPOSTOWNIK";
				raport.send_to_file(R.Ihead, where, raport.Tfilename);
				break;
			case 3:
				where = "PIES";
				raport.send_to_file(R.Ihead, where, raport.Tfilename);
				break;
			default:
				goto onemore;
			}
			break;
		}
		goto end;
	default:
		cout << " Bledny wybor, wybierz ponownie!" << endl;
		goto again;
	}
end:
	cout << "\n Dziekuje za skorzystanie z programu ;3\n\n A o to ekstrakcja jednostek w naszym pliku:\n";
	LoR UNIT;
	UNIT = LIST.extraction(LIST);
	UNIT.show_LoU();
	UNIT.delete_LoU();


	LIST.delete_LoR();
	F.delete_listofingredients();
	R.delete_listofingredients();
}