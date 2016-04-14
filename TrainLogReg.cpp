#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void read_training_label(string filename, vector<string> &training_label);
void read_training_feature(string filename, vector<string> &training_feature);
int main(int argc, char* argv[]){
	//string training_feature = arg[1];
	//string training_label = arg[2];
	//string model_file = arg[3];
	//int training_one = arg[4];
	//int training_two = arg[5]; 

  vector<string> training_label;
  vector<string> training_feature;

  read_training_label("trainingLabel.dat", training_label);
  read_training_feature("trainingFeature.dat", training_feature);

 cout << "done" << endl;
 cout << training_label.size() << endl;
 cout << training_feature.size() << endl;
 
return 0;
}
void read_training_label(string filename, vector<string>& training_label){
  ifstream in(filename.c_str());
  string line; 	
  if(in.is_open()){
    
    while(getline(in,line)){
      
      training_label.push_back(line);	 
    }
    in.close();
  }
  else{ cout << "unable to open file!" << endl;}
}

void read_training_feature(string filename, vector<string> &training_feature){
  ifstream in(filename.c_str());
  string line;
  if(in.is_open()){
    while(getline(in, line)){
      int start = 0;
      for(int i = 0; i < line.length(); i++){
	if(line.at(i) == ' '){
	  string current = line.substr(start, i);
	  training_feature.push_back(current);
	  start = i;
	}
      }
    }
 }



}
