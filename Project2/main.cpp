//References used:
//https://www.cplusplus.com/reference/map/map/
//Prof Aman's Lecture 7 (sets, maps, and hashtables) and Lecture 8a (graph termanology and impementation)

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

class AdjacencyList {
private:
    //reference for using this data structure to implement the graph:
    //Prof Aman's Lecture 8a (graph termanology and impementation) pg. 56
    map<string, vector<pair<string, double>>> graph;

    map<string, double> pageR;
    map<string, double> pageR2;
public:
    void insertEdge(string to, string from);
    void ranks();
    void PageRank();
    void countEachVal();
    void multiply(int n);
};

//insert key and value into the graph
//code reference for inserting element into this map:
//Prof Aman's Lecture 8a (graph termanology and impementation) pg. 56
void AdjacencyList::insertEdge(string to, string from) {
    graph[to].push_back(make_pair(from, 0.00));
    if(graph.find(from)==graph.end()){
        graph[from] = {};
    }
}

//assigning the 1/dj in the vector pair value of a map, if there is an edge (dj is the outdegree of node j)
void AdjacencyList::countEachVal(){
    map<string, vector<pair<string,double>>>::iterator iter;
    map<string, vector<pair<string,double>>>::iterator iter2;
    map<string, vector<pair<string,double>>>::iterator iter3;

    //iterate till the end of the map
    for(iter = graph.begin(); iter != graph.end(); ++iter){
        string name = iter->first;  //get current page name
        double d = 0.00;

        //iterate till the end of the map
        for(iter2 = graph.begin(); iter2 != graph.end(); ++iter2){
            //iterate though vector
            for(int i = 0; i < iter2->second.size(); i++) {
                 string name2 = iter2->second[i].first;
                 if(name == name2){ //if the page name in the vector match the current page name
                     d++; //increment outdegree counter
                 }
            }
        }

        //iterate till the end of the map
        for(iter3 = graph.begin(); iter3 != graph.end(); ++iter3){
            //iterate though vector
            for(int j = 0; j < iter3->second.size(); j++) {
                string name3 = iter3->second[j].first;
                if(name == name3){ //if the page name in the vector match the current page name
                    double p = (double) (1.00)/d;
                    iter3->second[j].second = p; //assign 1/dj
                }
            }
        }
    }
}

//assigning initial page rank values (when power_iteration = 0)
void AdjacencyList::ranks() {
    map<string, vector<pair<string,double>>>::iterator it;
    double graphNum = (double)graph.size();  //size of the graph
    //iterate till the end of the graph, and assign page rank of the pages
    for(it = graph.begin(); it != graph.end(); ++it){
        pageR[it->first] = (double)1/graphNum;
        pageR2[it->first] = (double)1/graphNum;
    }
}

// prints the PageRank of all pages after p powerIterations in ascending alphabetical order of webpages and rounding rank to two decimal places
//reference for printing all the elements:
//Prof Aman's Lecture 8a (graph termanology and impementation) pg. 56
void AdjacencyList::PageRank(){
    map<string, double>::iterator it2;

    //iterate till the end of the map and print the corresponding page ranks
    for(it2 = pageR.begin(); it2 != pageR.end(); ++it2){
        cout << fixed;
        cout << setprecision(2);
        cout << it2->first << " " << it2->second << endl;
    }
}

//multiplies the 1/dj in the adjacency list with the corresponding page ranks
void AdjacencyList::multiply(int n) {
    //iterate through number of power iterations -1 because initialization is already done
    for(int i = 0; i < n-1; i++){
        map<string, vector<pair<string,double>>>::iterator it;
        map<string, double>::iterator it2;
        map<string, double>::iterator it3;
        map<string, double>::iterator it4;
        map<string, double>::iterator it5;

        //iterate till the end of the map
        for(it = graph.begin(); it != graph.end(); ++it){
            double add = 0.00;
            //iterate through the vector
            for(int j = 0; j < it->second.size(); j++) {
                string name = it->second[j].first;
                it2 = pageR.find(name);  //find the page rank
                add += (it->second[j].second * it2->second);  //multiply
            }

            //save the new page rank into the second page rank
            string name2 = it->first;
            it3 = pageR2.find(name2);
            it3->second = add;
        }

        //iterate through the second updated page rank and copy all the values to the first page rank map
        for(it4 = pageR2.begin(); it4 != pageR2.end(); ++it4){
            string name4 = it4->first;
            it5 = pageR.find(name4);
            it5->second = it4->second;
        }
    }

}


int main() {
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines >> power_iterations;

    AdjacencyList g; //Create a graph object

    for(int i=0; i< no_of_lines; i++){
        cin >> from >> to;

        g.insertEdge(to, from); //insert key and value
    }


    g.countEachVal();  //assign 1/dj, if there is an edge (dj is the outdegree of node j)
    g.ranks(); //assign initial values to the page ranks (power iterator = 0)
    g.multiply(power_iterations);  //multiply the 1/dj with the corresponding page ranks
    g.PageRank(); //print all the power iterators

    return 0;
}