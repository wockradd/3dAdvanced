#include "./hfiles/fileStuff.h"
#include "./hfiles/main.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <glm/glm.hpp>
using namespace std;

struct Mesh generateMeshFromFile(string fileName){
    Mesh m = Mesh();//final mesh we're gonna return
    vector<glm::vec3> tempVec;
    vector<glm::vec3> tempNormals;

    //reading file stuff
    string line;
    ifstream myfile; 
    myfile.open(fileName);

    if (myfile.is_open()){
        while (getline(myfile,line)){//read line by line
            stringstream ss;
            string junk;
            float x, y ,z;
            string f1,f2,f3;

            if(line[0] == 'v'){//vectors
                ss << line;               
                ss >> junk >> x >> y >> z;
                glm::vec3 v(x,y,z);       
                
                if(line[1]=='n'){ //normal
                    cout << line << " normal\n";
                    tempNormals.push_back(v); 
                }else if(line[1]=='t'){//texture, do nothing
                    
                }else{//vector
                    tempVec.push_back(v); 
                    cout << line << " vector\n";
                }
                
                
            }

            if(line[0] =='f'){//faces
                Tri t = Tri(); 
                int splitPos, vectorIndex;          

                ss << line;     
                ss >> junk >> f1 >> f2 >> f3;


                //deal with f1
                splitPos = f1.find("/");
                vectorIndex = stoi(f1.substr(0,splitPos));
                t.v1 = tempVec[vectorIndex-1];
                f1 = f1.substr(splitPos+1,f1.size());
                splitPos = f1.find("/");
                vectorIndex = stoi(f1.substr(splitPos+1,f1.size()));
                t.normal = tempNormals[vectorIndex-1];

                //deal with f2
                splitPos = f2.find("/");
                vectorIndex = stoi(f2.substr(0,splitPos));
                t.v2 = tempVec[vectorIndex-1];

                //deal with f3
                splitPos = f3.find("/");
                vectorIndex = stoi(f3.substr(0,splitPos));
                t.v3 = tempVec[vectorIndex-1];

                //add tri to list
                m.tris.push_back(t);
            } 
        }
    myfile.close();
  }else{
      cout << "something went wrong\n";
  }
  return m;
}
