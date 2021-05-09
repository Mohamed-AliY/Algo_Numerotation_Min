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

#include <iostream>
#include <list>

using namespace std;

//on s'aide d'une matrice d'incidence pour créer les arêtes


class Graph {


  	public:
  		Graph(int vertices);
  		void addEdge(int src, int dest);
  		void BFS(int startVertex);
  		void enumNumerot(int j);
  		int* getOrdre(){return ordre;};
  	private:
  		int numVertices;
  		list<int>* adjLists;
  		bool* Marque;
  		int* ordre;

  		//eventuellement déplacer	
  		list<int[]> numMin;
  		int* numCourante;
  		int* Visites;
  		int bestRang,rangNum,sortie;
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  ordre=new int[vertices];

  numCourante=new int[vertices];
  Visites=new int[vertices];
  for(int i=0;i<vertices;i++){
  	Visites[k]=0;
  	numCourante[k]=vertices+1;
  }
  bestRang=vertices;
  rangNum=0;
  sortie=0;

  //cout<<"construit"<<endl;
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
  cout<<"tableau ordre: [";
  for(int k=0;k<numVertices;k++)
  	cout<<ordre[k]<<" ";
  cout<<"]"<<endl;
}


void enumNumerot(int j){
	int rang2=rangNum;
	int Vis2[numVertices];
	memcpy(Vis2,Visites,numVertices*sizeof(int));
	for (int k=0;k<numVertices;k++){
		if !(Visites[k]){
			//on désaffecte les numéros pour les sommets non visités
			for (int l=j+1;j<numVertices;j++)
				numCourante[ordre[l]]=numVertices+1;
			Visites[k]=1;
			numCourante(ordre[j])=k;

			list<int>::iterator i;
  			for (i = adjLists[j].begin(); i != adjLists[j].end(); ++i) {
  				if (abs(numCourante[ordre[j]]-numCourante[*i])>bestRang)
  					sortie=1;//on prépare l'élimination d’office de la numérotation, on passe à la suivante
  				else if (abs(numCourante[ordre[j]]-numCourante[*i])>rangNum)
  					rangNum=abs(numCourante[ordre[j]]-numCourante[*i]);

  			}
  			//passage à numérotation suivante
  			if(sortie){
  				sortie=0;
  				continue;
  			}
  			
  			//mise à jour de numMin
  			if
		}
	}

}

int main(){
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,4);
	g.addEdge(1,5);
	cout<<"---------------------"<<endl;
	cout<<"Premier BFS:"<<endl;
	g.BFS(0);
	cout<<"---------------------"<<endl;
	cout<<"2e BFS:"<<endl;
	g.BFS(1);
	cout<<"---------------------"<<endl;
	cout<<"3eme BFS:"<<endl;
	g.BFS(2);
	cout<<"---------------------"<<endl;
	cout<<"4e BFS:"<<endl;
	g.BFS(3);
}