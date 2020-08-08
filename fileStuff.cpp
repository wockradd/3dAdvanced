#include "./hfiles/fileStuff.h"
#include "./hfiles/main.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <glm/glm.hpp>
using namespace std;

struct Mesh generateMeshFromFile(){
    Mesh m = Mesh();//final mesh we're gonna return
    vector<glm::vec3> tempVec;

    //reading file stuff
    string line;
    ifstream myfile; 
    myfile.open("./resources/cart.obj");

    if (myfile.is_open()){
        while (getline(myfile,line)){//read line by line
            stringstream ss;
            char junk;
            float x, y ,z;

            if(line[0] == 'v'){
                
                ss << line;               //send the string to the stream
                ss >> junk >> x >> y >> z;//use the stream to initialize the variables

                glm::vec3 v(x,y,z);

                tempVec.push_back(v); //add to list
            }

            if(line[0] =='f'){
                Tri t = Tri();            //create a new tri
                ss << line;               //turn the string into a stream
                ss >> junk >> x >> y >> z;//use the stream to initialize the variables

                t.v1 = tempVec[x-1];
                t.v2 = tempVec[y-1]; //create new tri
                t.v3 = tempVec[z-1];

                m.tris.push_back(t);//add to list
            } 
        }
    myfile.close();
  }else{
      cout << "something went wrong\n";
  }
  return m;
}
