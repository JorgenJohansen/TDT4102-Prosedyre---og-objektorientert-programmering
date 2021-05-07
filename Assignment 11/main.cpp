
#include <iostream>
#include <vector>
#include <set>

#include "person.h"
//#include "generic.h"
#include "LinkedList.h"

using namespace std;

//Done
void replace(vector<string>& liste, string old, string replacement){
	int counter = 0;
	vector<string>::iterator it = find(liste.begin(),liste.end(),old);
	if(it == liste.end()){
		cout << "Element " << old << " does not exist" << endl;
	}
	while(it != liste.end()){
		it = liste.erase(it);
		liste.insert(it,replacement);
		it = find(liste.begin(),liste.end(),old);
		counter++;
	}
	if(counter > 0){
		for(vector<string>::iterator it2 = liste.begin();
		it2 != liste.end(); it2++){
			cout << *it2 << " ";
		}
	}
	
	
}

//WIP
void replace2(set<string>& set1, string old, string replacement){
	int counter = 0;
	set<string>::iterator it = find(set1.begin(), set1.end(), old);
	if(it == set1.end()){
		cout << "Element " << old << " does not exist" << endl;
	}
	while(it != set1.end()){
		it = set1.erase(it);
		set1.insert(it, replacement);
		it = find(set1.begin(), set1.end(), old);
		counter++;
	}
	
	if(counter > 0){
		for(set<string>::iterator it2 = set1.begin();
		it2 != set1.end(); it2++){
			cout << *it2 << " ";
		}
	}
	
}

/**
 * Vi trenger namespaces for å forhindre
 * navnekonflikter.
 * Bruker da :: for å aksessere funksjoner
 * i navnerommet
 * Eller "using namespace scope"
 * Alias: namespace s = scope
 * Ikke støttet i C

*/

//Oppgave 4a)
template<typename T> 
T maximum(T lhs, T rhs){
    if(lhs == rhs){
        cout << "Elementene er like!" << endl;
    }else if(lhs > rhs){
        return lhs;
    }else if(rhs > lhs){
        return rhs;
    }
}

/**
 * Teori:
*/

//Oppgave 4b)
//Done
template<typename R>
vector<R> shuffle(vector<R> v){
	for(unsigned int i = 0; i < v.size(); i++){
		unsigned int m = rand() % v.size();
		if(i == m){
			m = rand() % v.size();
		}
		R temp = v[i];
		v[i] = v[m];
		v[m] = temp;
	}
	return v;
}

template<typename R>
void genericPrint(vector<R> v){
	for(unsigned int i = 0; i < v.size(); i++){
		cout << v.at(i) << " ";
	}
	cout << endl;
}




int main()
{
	
	// vector<string> stringList = {"Lorem","Ipsum","Dolor","Sit","Amet","Consectetur"};

	// //Oppgave 1a)
	// for(vector<string>::iterator it = stringList.begin();
	// it != stringList.end(); it++){
	// 	cout << *it << " ";
	// }

	// cout << endl;

	// //Oppgave 1b)
	// for(vector<string>::reverse_iterator rit = stringList.rbegin();
	// rit != stringList.rend(); rit++){
	// 	cout << *rit << " ";
	// }


	//Oppgave 1c)
	// std::vector<std::string> liste2 = {"Ost", "Egg", "Melk", "Ost"};
	// replace(liste2,"Ost","Taco");

	//Oppgave 1d)
	// set<string> setList = {"Lorem","Ipsum","Dolor","Sit","Amet","Consectetur"};

	// for(set<string>::iterator it = setList.begin();
	// it != setList.end(); it++){
	// 	cout << *it << " ";
	// }

	// cout << endl;

	// for(set<string>::reverse_iterator rit = setList.rbegin();
	// rit != setList.rend(); rit++){
	// 	cout << *rit << " ";
	// }


	// std::set<std::string> liste2 = {"Ost", "Egg", "Melk", "Mel"};
	// replace2(liste2,"Ost","Taco");

	
	// Person p1{"Jørgen","Johansen"};
	// Person p2{"Hans","Fredriksen"};

	// std::list<Person> personliste;

	// p1.insertOrdered(personliste, p1);
	// p1.insertOrdered(personliste, p2);

	// for(std::list<Person>::iterator it = personliste.begin();
	// it != personliste.end(); it++){
	// 	cout << *it;
	// }

	//Oppgave 4a)
	// cout << maximum(1,2) << endl;
	// cout << maximum(1.0,2.0) << endl;
	// cout << maximum('A', 'B') << endl;
	
	//Oppgave 4b)
	// srand(static_cast<unsigned int>(time(nullptr)));
	// vector<int> v1{1,2,3,4,5,6};
	// //shuffle(v1);
	// genericPrint(shuffle(v1));

	// vector<double> v2{1.0,2.0,3.0,4.0,5.0,6.0};
	// genericPrint(shuffle(v2));
	// vector<char> v3{'a','b','c','d','e','f'};
	// genericPrint(shuffle(v3));
	cout << "Halla\n";
	LinkedList::LinkedList list{};
	list.find("hei");
	LinkedList::Node* node{};
	//list.insert(node, "hallo");
	//list.remove("hallo");
	// LinkedList
	// list.insert()

	//Oppgave 3b)
	//Teori:
	/**
	 * Det er bedre å bruke vektor når vi skal lese fra lista
	 * siden det tar konstant tid(random access)
	 * Når vi da skal skrive til en liste ved enten å legge
	 * til en verdi eller slette vil det være bedre å 
	 * bruke lenket liste siden det tar konstant tid
	 * 
	 * Hvis vi legger til et element først i lista og deretter
	 * henter ut det første elementet vil det være samme oppførsel
	 * som en stack(LIFO)
	 * Hvis vi legger elementet bakerst i lista og deretter
	 * henter ut det første elementet vil det ha samme oppførsel
	 * som en kø(FIFO)
	*/


	cin.get();
}
