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
//temps d'exécution ( comparer a algo instinctif)
// eventuellement chercher outil visualisation graphe

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

//on s'aide d'une matrice d'incidence pour créer les arêtes


class Graph {


  	public:
  		Graph(int vertices);
  		void addEdge(int src, int dest);
  		void BFS(int startVertex);
  		void enumNumerot(int j);
  		int* getOrdre(){return ordre;};
  		list<int> fromTableToList();
  		void afficheNumerotations();
  		void afficheNumCourante();
  		void afficheOrdre();
  		void afficheVisites();
  		void afficheVariables(int j,int k);
  	private:
  		int numVertices;
  		list<int>* adjLists;
  		bool* Marque;
  		int* ordre;

  		//eventuellement déplacer	
  		list<list<int>> numMin;
  		int* numCourante;
  		vector<int> Visites;
  		int bestRang,rangNum,sortie;
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  ordre=new int[vertices];

  numCourante=new int[vertices];
  for(int i=0;i<vertices;i++){
  	Visites.push_back(0);
  	numCourante[i]=vertices+1;
  }
  bestRang=vertices;
  rangNum=0;
  sortie=0;

}

// Add edges to the graph
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
  //cout<<"ajouté ("<<src<<","<<dest<<")"<<endl;
}

// BFS algorithm
void Graph::BFS(int startVertex) {
  Marque = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    Marque[i] = false;

  list<int> queue;

  Marque[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  int j=0;  //affecter un ordre aux sommets parcours

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "Visited " << currVertex << " ";
    queue.pop_front();
    ordre[j]=currVertex; //on remplit le tableau ordre
    j++;

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!Marque[adjVertex]) {
        Marque[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
  cout<<endl;
  //afficher ordre
  //debug
  cout<<"tableau ordre: [";
  for(int k=0;k<numVertices;k++)
  	cout<<ordre[k]<<" ";
  cout<<"]"<<endl;
}

list<int> Graph::fromTableToList(){
	list<int> numerotationList;
	for(int i=0;i<numVertices;i++){
		numerotationList.push_back(numCourante[i]);
	}
	return numerotationList;
}

void Graph::afficheNumerotations(){
	
	cout<<"Numerotations minimales: [";

	list<list<int>> :: iterator it;
	list<int> :: iterator it2;
	for (it=numMin.begin();it!=numMin.end();it++){
		cout<<"(";
		for(it2=(*it).begin();it2!=(*it).end();it2++){
			cout<<*it2<<",";
		}
		cout<<"),";
	}
	cout<<"]"<<endl;
	cout<<"rang minimal: "<<bestRang<<endl;
	cout<<"rang numerotation courante: "<<rangNum<<endl;
}

void Graph::afficheNumCourante(){
	cout<<"numCourante: ";
	for(int i=0;i<numVertices;i++){
		cout<<numCourante[i]<<",";
	}
	cout<<endl;
}
void Graph::afficheVisites(){
	cout<<"Visites:";
	for(int i=0;i<numVertices;i++){
		cout<<Visites[i]<<",";
	}
	cout<<endl;
}
void Graph::afficheOrdre(){
	cout<<"ordre: ";
	for(int i=0;i<numVertices;i++){
		cout<<ordre[i]<<",";
	}
	cout<<endl;
}

void Graph::afficheVariables(int j,int k){

	cout<<"------------------------"<<endl;
	cout<<"afficheVariables("<<j<<","<<k<<")"<<endl;
	afficheVisites();
	afficheNumCourante();
	afficheNumerotations();
	cout<<"------------------------"<<endl;
}

void Graph::enumNumerot(int j){
	int rang2=rangNum;
	vector<int> Vis2(Visites);
	for (int k=0;k<numVertices;k++){
		afficheVariables(j,k);
		if (!(Visites[k])){
			
			//on désaffecte les numéros pour les sommets non visités
			for (int l=j+1;l<numVertices;l++)
				numCourante[ordre[l]]=numVertices+1;
			Visites[k]=1;
			numCourante[ordre[j]]=k;

			list<int>::iterator i;
  			for (i = adjLists[ordre[j]].begin(); i != adjLists[ordre[j]].end(); ++i) {
  				if (abs(numCourante[ordre[j]]-numCourante[*i])>bestRang){
  					sortie=1;//on prépare l'élimination d’office de la numérotation, on passe à la suivante
  				}
  				else if (abs(numCourante[ordre[j]]-numCourante[*i])>rangNum){
  					cout<<"mise a j rangNum"<<endl;//debug
  					rangNum=abs(numCourante[ordre[j]]-numCourante[*i]);
  				}

  			}
  			//passage à numérotation suivante
  			if(sortie){
  				sortie=0;
  				continue;
  			}
  			
  			//mise à jour de numMin
  			
  			//méthode find présente dans algorithm
  			if (find(Visites.begin(),Visites.end(),0)==Visites.end()){

  				//debug
  				cout<<"_______"<<endl;
  				cout<<"| AJOUT |"<<endl;
  				cout<<"_______"<<endl;

  				list<int> numerotationList=fromTableToList();
  				if(rangNum==bestRang){
  					//debug
  					cout<<"_______"<<endl;
  					cout<<"| push_back |"<<endl;
  					cout<<"_______"<<endl;
  					numMin.push_back(numerotationList);
  				}
  				else{
  					//debug
  					cout<<"_______"<<endl;
  					cout<<"| clear |"<<endl;
  					cout<<"_______"<<endl;	
  					numMin.clear();
  					bestRang=rangNum;
  					numMin.push_back(numerotationList);
  				}

  			}
  			enumNumerot(j+1);
  			rangNum=rang2;
  			Visites=Vis2;
		}
	}

}

int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
	// g.addEdge(1,4);
	// g.addEdge(1,5);
	cout<<"---------------------"<<endl;
	cout<<"Premier BFS:"<<endl;
	g.BFS(0);
	// cout<<"---------------------"<<endl;
	// cout<<"2e BFS:"<<endl;
	// g.BFS(1);
	// cout<<"---------------------"<<endl;
	// cout<<"3eme BFS:"<<endl;
	// g.BFS(2);
	// cout<<"---------------------"<<endl;
	// cout<<"4e BFS:"<<endl;
	// g.BFS(3);
	cout<<"---------------------"<<endl;
	g.afficheOrdre();
	cout<<"---------------------"<<endl;
	g.enumNumerot(0);

	g.afficheNumerotations();
}