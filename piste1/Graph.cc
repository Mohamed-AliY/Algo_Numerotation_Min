/* 
Mohamed-Ali Yazid le 16/05/2021
*/

#include "Graph.hh"

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  ordre=new int[vertices];

  numCourante=new int[vertices];
  for(int i=0;i<vertices;i++){
  	Visites.push_back(0);
  	numCourante[i]=2*numVertices;
  }
  bestRang=vertices;
  rangNum=0;
  sortie=0;

}

//créer des instances aléatoires
Graph::Graph(int vertices, int edges){

  numVertices = vertices;
  adjLists = new list<int>[vertices];
  ordre=new int[vertices];

  numCourante=new int[vertices];
  std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> distrib{0,vertices-1};

  // dans le cas où il y a plus de sommets que d'arêtes
  if(edges<numVertices-1){
    cout<<"Erreur: nombre d'arêtes trop petit"<<endl;
    cout<<"Nombre de sommets mis à (edge number+1)"<<endl;
  }
  //alignement des sommets
  else if (edges==numVertices-1){
    for(int j=0;j<edges;j++){
      addEdge(j,j+1);
    }
  }
  else{
  	vector<int> Connect;

  	vector<int> Disconnect;
  	int sommet1,sommet2;
  	int valeur=distrib(re);
  	Connect.push_back(valeur);
  	for (int i=0;i<vertices;i++){
  		if (i!=valeur)
  			Disconnect.push_back(i);
  	}
  	//tant que pas tous les sommets sont connectés
  	while(!Disconnect.empty()){

  		std::uniform_int_distribution<int> distrib2{0,(int)Connect.size()-1};

  		std::uniform_int_distribution<int> distrib3{0,(int)Disconnect.size()-1};
  		sommet1=distrib2(re);
  		sommet2=distrib3(re);

       //  while (!((find(adjLists[Connect[sommet1]].begin(),adjLists[Connect[sommet1]].end(),Disconnect[sommet2])==adjLists[Connect[sommet1]].end()) && (Connect[sommet1] != sommet2))){
       //    sommet2=distrib3(re);
      	//   sommet1=distrib2(re);
      	// }
      	addEdge(Connect[sommet1],Disconnect[sommet2]);

		//retirer sommet2 de Disconnect et l'ajouter a Connect

      	// vector<int>::iterator iter ;
      	// for (iter=Disconnect.begin();iter!=Disconnect.end();iter++){
      	// 	if (*iter=Disconnect[sommet2]){
      	Connect.push_back(Disconnect[sommet2]);
      	Disconnect.erase(Disconnect.begin()+sommet2);
      	// 	}

      }
    // on crée les arêtes restantes au hasard
    if(edges>=vertices){
   		for(int j=vertices-1;j<edges;j++){
        	int vertex1=distrib(re);
        	int vertex2=distrib(re);
        	while (!((find(adjLists[vertex1].begin(),adjLists[vertex1].end(),vertex2)==adjLists[vertex1].end()) && (vertex1 != vertex2))){
        	  vertex1=distrib(re);
        	  vertex2=distrib(re);
        	 }
        	addEdge(vertex1,vertex2);
        }
   	 }
   }


 

  // //nombre de sommets inférieur ou egal au nombre d'arêtes
  // else{
  //   //on relie les sommets numero 0 à vertices-1
  // 	for (int i=0;i<vertices;i++){
  // 		//int vertex1=distrib(re);
  // 		int vertex2=distrib(re);
  //     while(!((find(adjLists[i].begin(),adjLists[i].end(),vertex2)==adjLists[i].end()) && (i != vertex2)))
  //       vertex2=distrib(re);
  //     addEdge(i,vertex2);
   		

  // 	}
  //   // on crée les arêtes restantes au hasard
  //   if (edges>vertices){
  //     for(int j=vertices;j<edges;j++){
  //       int vertex1=distrib(re);
  //       int vertex2=distrib(re);
  //       while (!((find(adjLists[vertex1].begin(),adjLists[vertex1].end(),vertex2)==adjLists[vertex1].end()) && (vertex1 != vertex2)))
  //         vertex2=distrib(re);
  //       addEdge(vertex1,vertex2);
  //     }
  //   }
  // }

  for(int i=0;i<vertices;i++){
    Visites.push_back(0);
    numCourante[i]=2*numVertices;
  }
  bestRang=vertices;
  rangNum=0;
  sortie=0;
}

// Add edges to the graph
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
  //debug
  cout<<"ajouté ("<<src<<","<<dest<<")"<<endl;
}

void Graph::afficheInfos(){

	cout<<"Arêtes du graphe : ";
	list<int>::iterator it;
	cout<<"[";
	for(int i=0;i<numVertices;i++){
		for (it = adjLists[i].begin(); it != adjLists[i].end(); ++it) {
			cout<<"("<<i<<","<<*it<<")";
			cout<<",";
		}
	}
	cout<<"]"<<endl;

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


}

list<int> Graph::numerotTableToList(){
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
	cout<<"Rang minimal: "<<bestRang<<endl;
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


//méthode de l'algorithme élaboré
void Graph::enumNumerot(int j){
	int rang2=rangNum;
	vector<int> Vis2(Visites);
	for (int k=0;k<numVertices;k++){
		Visites=Vis2;
		if (!(Visites[k])){
			//on désaffecte les numéros pour les sommets non visités
			for (int l=j+1;l<numVertices;l++)
				numCourante[ordre[l]]=2*numVertices;

			Visites[k]=1;
			numCourante[ordre[j]]=k;

      		//détection de dépassement de rang
			list<int>::iterator i;
  			for (i = adjLists[ordre[j]].begin(); i != adjLists[ordre[j]].end(); ++i) {
  				int valLiaison=abs(numCourante[ordre[j]]-numCourante[*i]);
  				if ((valLiaison>bestRang) && (valLiaison<numVertices+1)){
  					sortie=1;//on prépare l'élimination d’office de la numérotation, on passe à la suivante
  				}
  				else if ((valLiaison>rangNum) && (valLiaison<numVertices+1)){
  					rangNum=valLiaison;
  				}

  			}
  			//passage à la numérotation suivante
  			if(sortie){
  				sortie=0;
  				continue;
  			}
  			
  			//mise à jour de numMin
  			
  			//méthode find présente dans algorithm
  			if (find(Visites.begin(),Visites.end(),0)==Visites.end()){


  				list<int> numerotationList=numerotTableToList();
  				if(rangNum==bestRang){
  					numMin.push_back(numerotationList);
  				}
  				else{

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
void Graph::CorrigeNumerotation(){
	//pour le bon affichage des numérotations
	list<list<int>> :: iterator it;
	list<int> :: iterator it2;

	for (it =numMin.begin(); it != numMin.end();it++){
		for(it2=(*it).begin();it2!=(*it).end();it2++){
			*it2+=1;
		}
	}
}

//appelle BFS et algorithme d'énumération avec une seule fonction
void Graph::getNumerotations(){
	cout<<"---------------------------------"<<endl;
	BFS(0);
	enumNumerot(0);
	CorrigeNumerotation();
	afficheNumerotations();
}

