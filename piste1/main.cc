/* 
Mohamed-Ali Yazid le 16/05/2021
Programme de test
*/

#include "Graph.hh"
#include <fstream>

int main(){
	// //Pour créer un graphe à la main
	// Graph g(4);
	// g.addEdge(0,1);
	// g.addEdge(0,2);
	// g.addEdge(1,2);
	// g.addEdge(2,3);

	// g.getNumerotations();

	// //un graphe au hasard de 5 sommets et 7 arêtes
	// Graph g2(5,7);
	// g2.getNumerotations();


	// //pour calculer le temps d'exécution et le stocker dans un fichier
	// cout<<"---------------------------------"<<endl;
	// ofstream flux("resultatsPiste1.txt");
	// if(flux){
	// 	flux<<"Temps relevés en us pour différentes graphes"<<endl;
	// 	for(int j=4;j<=10;j++){
	// 		flux<<"---------------------------------"<<endl;
	// 		flux<<"V="<<j<<", E="<<j+2<<endl;
	// 		//exemple sur plusieurs graphes
	// 		for(int i=0;i<8;i++){
	// 			std::chrono::high_resolution_clock::time_point a= std::chrono::high_resolution_clock::now();
	// 			Graph(j,j+2).getNumerotations();
	// 			std::chrono::high_resolution_clock::time_point b= std::chrono::high_resolution_clock::now();
	// 			unsigned int time= std::chrono::duration_cast<std::chrono::microseconds>(b - a).count();
	// 			cout<<"temps de calcul: "<<time<<"us"<<endl;
	// 			cout<<"---------------------------------"<<endl;
	// 			flux<<time<<endl;
	// 		}
	// 	}
	// }
	// else
 //    {
 //        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
 //    }



}