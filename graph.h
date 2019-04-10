/** @file Graph.h */

#include <list>
#include <map>
#include <queue>
#include <cstring>
#include <string>
/*Do not add new libraries or files*/

using namespace std;

struct node {
    string name;
    string movie;
    string director; 
};

/** An adjacency list representation of an undirected graph. */
class Graph
{
public:

   /** Adjacency list representation of the graph;
    * the map pair consists of the performer (key)
    * and the node list (value). */
   map<string, list<node> > adjList;

   /** Constructor.*/
   Graph();

   /** Adds a new performer to the map with performerName 
    * as key, and an empty node list as value */
   void addPerformer(string performerName);

   /** Adds a new node to the list of performer1 
    * using performer2, movieTitle and director data, and
    * adds a new node to the list of performer2
    * using performer1, movieTitle and director data. */
   void addEdge(string movieTitle, string performer1, string performer2, string director);

   /** Given a performer name, returns all movies 
    * in which the performer performed as a list of string. */
   list<string> getMovies(string performerName);

   /** Deletes all performers who played in a movie   
    * directed by himself/herself from the graph and returns 
    * those performers as a list of string. */
   list<string> deletePerformers();

   /** Returns performer(s) who played highest number of movies
    * as a map where performer name is key and 
    * the number of movies is value. */
   map<string, int> getMostActivePerformers();

   /** Given a performer name, returns all performers with
    * a performer number up to 3 as a map where the performer name
    * is key and the corresponding performer number is value */
   map<string, int> getPerformerNumber(string performerName);

   /** Given a performer name, returns his/her most frequent
    * partners as a map where the performer name is key
    * and the number of movies they played together is value */
   map<string, int> getFrequentPartner(string performerName);

   /** Given a performer name, returns his/her most frequent
    * director as a map where the director name is key
    * and the number of movies they were together is value */
   map<string, int> getFrequentDirector(string performerName);

}; // end Graph
// End of header file
