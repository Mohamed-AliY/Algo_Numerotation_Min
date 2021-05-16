/* 
Mohamed-Ali Yazid le 16/05/2021
Programme de test
*/

#include "Graph.hh"

int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
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
	g.getNumerotations();

	g.afficheNumerotations();

	cout<<"---------------------------------"<<endl;
	Graph g2(5,7);
	g2.afficheInfos();
	g2.BFS(0);
	g2.getNumerotations();

	g2.afficheNumerotations();


}