/* 
Mohamed-Ali Yazid le 09/05/2021
premier programme du projet d'algorithmique
But: Pour un graphe précis, tester l'algorithme élaboré et voir
les numérotations minimales obtenues.

------------------------------------------------------------------------------
*/

//renommer variables
//destructeur
//séparer en fichiers
//temps d'exécution ( comparer a algo intuitif)
//epurer code=>affichages, noms var, modularité
//augmenter visibilité tests=catch.hpp
// eventuellement chercher outil visualisation graphe


#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

//on s'aide d'une matrice d'incidence pour créer les arêtes


class Graph {


  	public:
  		Graph(int vertices);
  		Graph(int vertices, int edges);
  		void addEdge(int src, int dest);
  		void afficheInfos();
  		int* getOrdre(){return ordre;};
  		list<int> numerotTableToList();

  		//méthodes d'affichage
  		void afficheNumerotations();
  		void afficheNumCourante();
  		void afficheOrdre();
  		void afficheVisites();
  		void afficheVariables(int j,int k);


  		void CorrigeNumerotation();
  		void getNumerotations();

  		//méthodes apparaîssant dans l'algorithme
  		void BFS(int startVertex);
  		void enumNumerot(int j);

  	private:
  		int numVertices;
  		list<int>* adjLists;
  		bool* Marque;


  		//variables de l'algorithme
  		int* ordre;	
  		list<list<int>> numMin;
  		int* numCourante;
  		vector<int> Visites;
  		int bestRang,rangNum,sortie;
};

