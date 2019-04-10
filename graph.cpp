/** @file Graph.cpp
 * An adjacency list representation of an undirected graph. 
*/

#include "graph.h"
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <cstring>
#include <iterator>
/*Do not add new libraries or files*/

using namespace std;

Graph::Graph()
{
}  // end constructor

void Graph::addPerformer(string performerName)
{   /*YOUR IMPLEMENTATION*/
    list<node> l;
    adjList.insert(pair<string, list<node> >(performerName, l));
}  // end addPerformer

void Graph::addEdge(string movieTitle, string performer1, string performer2, string director)
{   /*YOUR IMPLEMENTATION*/
    node n;
    node n1;
    n.name = performer1;
    n.movie = movieTitle;
    n.director = director;
    n1.director = director;
    n1.name = performer2;
    n1.movie = movieTitle;
    adjList[performer1].push_front(n1);
    adjList[performer2].push_front(n);
    //adjList.insert(pair<>)
}  // end addEdge

list<string> Graph::getMovies(string performerName)
{   /*YOUR IMPLEMENTATION*/
    list<string> newL;
    list<node> :: iterator it1;
    for( it1 = adjList[performerName].begin(); it1 != adjList[performerName].end(); it1 ++){
        newL.push_front(it1->movie);
    }
    return newL;
}  // end getMovies

list<string> Graph::deletePerformers()
{   /*YOUR IMPLEMENTATION*/
    list<string> newS;
    map<string, list<node> >:: iterator iter;
    list<node> :: iterator it1;
    for ( iter = adjList.begin(); iter != adjList.end(); iter++ )
    {
        for(it1 = iter->second.begin(); it1 != iter->second.end(); it1 ++){
            if(it1->name == it1->director){
                newS.push_front(it1->name);
                adjList[it1->name].clear();
            }
        }
    }
    return newS;
}  // end deletePerformers

map<string, int> Graph::getMostActivePerformers()
{   /*YOUR IMPLEMENTATION*/
    map<string, list<node> >::iterator iter;
    map<string, int> newA;
    iter = adjList.begin();
    list<node> max = iter->second;
    string maxP = "firat";
    while ( iter != adjList.end()){
        iter ++;
        if(iter != adjList.end()){
            if( max.size() < iter->second.size()){
                max = iter->second;
                maxP = iter->first;
            }
        }
    }
    newA.insert(pair<string,int>(maxP, max.size()));
    iter = adjList.begin();
    while(iter != adjList.end()){
        if(( max.size() == iter->second.size()) && ( iter->first != maxP)){
            newA.insert(pair<string,int>(iter->first, iter->second.size()));
        }
        iter++;
    }
    return newA;
}  // end getMostActivePerformers

map<string, int> Graph::getPerformerNumber(string performerName)
{   /*YOUR IMPLEMENTATION*/
    list<node> :: iterator it1;
    list<node> :: iterator it2;
    list<node> :: iterator it3;
    map<string, list<node> > :: iterator itA;
    map<string, int> newA;
    newA.insert(pair<string,int>(performerName, 0));
    it1 = adjList[performerName].begin();
    while(  it1 != adjList[performerName].end()){
        newA.insert(pair<string,int>(it1->name, 1));
        for(it2 = adjList[it1->name].begin(); it2 != adjList[it1->name].end(); it2 ++){
            newA.insert(pair<string,int>(it2->name, 2));
            for(it3 = adjList[it2->name].begin(); it3 != adjList[it2->name].end(); it3 ++){
                newA.insert(pair<string,int>(it3->name, 3));
            }
        }
        it1 ++;
    }
    return newA;
}

map<string, int> Graph::getFrequentPartner(string performerName)
{   /*YOUR IMPLEMENTATION*/
    int max_count = 0;
    list<node> :: iterator it1 = adjList[performerName].begin();
    list<node> :: iterator it2 = adjList[performerName].begin();
    string most;
    map<string, int> newA;
    for(it1 = adjList[performerName].begin(); it1 != adjList[performerName].end(); it1 ++){
        string temp = it1->name;
        int tempcount = 0;
        for(it2 = adjList[performerName].begin(); it2 != adjList[performerName].end(); it2 ++){
            if(it2->name == temp)
                tempcount++;
            if(tempcount > max_count){
                most = temp;
                max_count = tempcount;
                newA.insert(pair<string,int>(most, max_count));
            }
        }
    }
    newA.find(most)->second = max_count;
    map<string, int> :: iterator it3 = newA.begin();
    map<string, int> :: iterator max = newA.begin();
    bool check = true;
    
    while(it3 != newA.end()){
        if(check == true){
           it3++;
        }
        if(it3 != newA.end()){
          if( max->second < it3->second ){
              newA.erase(max);
              max = it3;
              check = true;
          }
          else if(max->second > it3->second){
              map<string, int> :: iterator temp = it3;
              it3++;
              newA.erase(temp);
              check = false;
          }
          else{
              check = true;
          }
        }
    }
    return newA;
}  // end getFrequentPartner

map<string, int> Graph::getFrequentDirector(string performerName)
{   /*YOUR IMPLEMENTATION*/
    int max_count = 0;
    list<node> :: iterator it1 = adjList[performerName].begin();
    list<node> :: iterator it2 = adjList[performerName].begin();
    string most;
    map<string, int> newA;
    for(it1 = adjList[performerName].begin(); it1 != adjList[performerName].end(); it1 ++){
        string temp = it1->director;
        int tempcount = 0;
        for(it2 = adjList[performerName].begin(); it2 != adjList[performerName].end(); it2 ++){
            if(it2->director == temp){
                tempcount++;
            }
            if(tempcount > max_count){
                most = temp;
                max_count = tempcount;
                newA.insert(pair<string,int>(most, max_count));
            }
        }
    }
    newA.find(most)->second = max_count;
    map<string, int> :: iterator it3 = newA.begin();
    map<string, int> :: iterator max = newA.begin();
    bool check = true;
    while( it3 != newA.end()) {
        if(check == true){
            it3++;
        }
        if(it3 != newA.end()){
            if( max->second < it3->second ){
                map<string, int> :: iterator temp = max;
                max = it3;
                it3++;
                newA.erase(temp);
                check = false;
            }
            else if(max->second > it3->second){
                map<string, int> :: iterator temp = it3;
                it3++;
                newA.erase(temp);
                check = false;
            }
            else{
                check = true;
            }
        }
    }
    return newA;
}  // end getFrequentDirector


