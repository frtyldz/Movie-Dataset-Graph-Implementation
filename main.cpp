/**
 * CS 202 - HW 4
 * A main file
 * Please make sure that your code compiles and runs with this main file
 */
#include "graph.h"
#include <cstring>
#include <iostream>
#include <fstream>
/*You can add additional libraries here to read and process the dataset*/

using namespace std;

int main(int argc, char* argv[]) {
    /*YOUR IMPLEMENTATION*/
    Graph* g = new Graph();
    ifstream infile("movieDataset.txt");
    string line;
    
    int choice;
    char* performer;
    bool gameOn = true;
    //if(infile.is_open()){
    while (getline(infile, line))
    {
        int pos = line.find(";");
        string left = line.substr(pos + 1);
        string movie = line. substr(0, pos);
        pos = left.find(";");
        string performer1 = left. substr(0, pos);
        left = left.substr(pos + 1);
        pos = left.find(";");
        string performer2 = left. substr(0, pos);
        left = left.substr(pos + 1);
        pos = left.find(";");
        string director = left.substr(pos + 1);
        g->addPerformer(performer1);
        g->addPerformer(performer2);
        g->addEdge(movie, performer1, performer2, director);
    }
    cout<<"ok"<<endl;
        while (gameOn != false){
        cout<<"Welcome to Movie Dataset\n";
        cout<<"\n";
        cout<<"Select an option:\n";
        cout<<"\n";
        cout << "1- See movies of a performer\n";
        cout << "2- Delete performers who directed the movie in which s/he played\n";
        cout << "3- Find performer(s) who played in highest number of movies\n";
        cout << "4- Find performer number of performers based on a given performer\n";
        cout << "5- Find performer(s) who played in highest number of movies with a given performer\n";
        cout << "6- Find director(s) who directed highest number of movies of a given performer\n";
        cout << "7- Exit\n";
        
        cin >> choice;
        
        switch (choice)
        {
            case 1:{
                cout << "Enter a performer: \n";
                scanf ("%[^\n]%*c", performer);
                list<string> :: iterator it1;
                list<string> l = g->getMovies(performer);
                cout<< "perf:" << performer;
                cout << choice;
                for(it1 = l.begin(); it1 != l.end(); it1 ++){
                    cout<< *it1<<endl;
                }
                cout<<endl;
                break;
            }
            case 2:{
                list<string> :: iterator it1;
                list<string> l = g->deletePerformers();
                for(it1 = l.begin(); it1 != l.end(); it1 ++){
                    cout<< *it1<<endl;
                }
                cout<<endl;
                break;
            }
            case 3:{
                map<string, int> m = g->getMostActivePerformers();
                map<string, int>::iterator iter;
                iter = m.begin();
                while ( iter != m.end()){
                    cout<<"The most active performer is "<< iter->first<< " and number of films are "<< iter->second<<endl;
                    iter++;
                }
                cout<<endl;
                break;
            }
            case 4:{
                map<string, int> m = g->getPerformerNumber("Connors, Chuck");
                map<string, int>::iterator iter;
                iter = m.begin();
                while ( iter != m.end()){
                    cout<<"The performer is "<< iter->first<< " and it's perform number is "<< iter->second<<endl;
                    iter++;
                }
                cout<<endl;
                break;
            }
            case 5:{
                cout << "Enter a performer: \n";
                //cin>> performer;
                map<string, int> m = g->getFrequentPartner("Wayne, John");
                map<string, int>::iterator iter;
                iter = m.begin();
                while ( iter != m.end()){
                    cout<<"The most played performer is "<< iter->first<< " and number of films are "<< iter->second<<endl;
                    iter++;
                }
                cout<<endl;
                break;
            }
            case 6:{
                cout << "Enter a director: \n";
                //cin>> performer;
                map<string, int> m = g->getFrequentDirector("Wayne, John");
                map<string, int>::iterator iter;
                iter = m.begin();
                while ( iter != m.end()){
                    cout<<"The most played director is "<< iter->first<< " and number of films are "<< iter->second<<endl;
                    iter++;
                }
                cout<<endl;
                break;
            }
            case 7:{
                cout << "End of Program.\n";
                gameOn = false;
                break;
            }
            default:{
                cout << "InValid Choice. \n";
                cout << "Choose again.\n";
                //cin >> choice;
                break;
            }
        }
    }
	return 0;
}
// End of main file
