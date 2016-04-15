#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <numeric>

using namespace std;

vector<float> Read_File(char * model_File);
float DotProduct(vector<float> w, vector<float> x);

int main(int argc, char *argv[]){

  char* modelFile = argv[1];
  char* testFeatureFile = argv[2];
  char* predLabelFile = argv[3];
  char* charD = argv[4];

  //Convert D to an int
  std::string stringD(charD);
  int D = atoi(stringD.c_str());

  // Creates and opens output file
  ofstream outputFile;
  outputFile.open(predLabelFile);

  // ModelFile Vector
  vector<float> w = Read_File(modelFile);  // use model file created in part 1

  /*
    Computes the DotProduct of ModelFile vector, w, and all 'D' testFeatureFile
    vectors, x, and writes them to the newly created file
  */
  for (int i = 0; i < D; i++){
    vector<float> x = Read_File(testFeatureFile);

    if (DotProduct(w,x) > 0){
      outputFile << "1" << endl;
    }
    if (DotProduct(w,x) < 0){
      outputFile << "0" << endl;
    }
  }

  return 0;
}

/*
  Reads the float values in ModelFile and stores them in a vector
*/
vector<float> Read_File(char * model_file){

  vector<float> weight;

  // Convert File Name to String
  std::string file(model_file);

  // Read File
  ifstream in(file.c_str());
  string line;

  if (in.is_open()){

    // The file is a single line
    getline(in, line);
    string word;

    // Reads String char by char
    for (int i = 0; i < line.length() + 1; i++){
      char x = line[i];

      // Retreives each substring in the string
      if(x != ' '){
        word = word + x;
        x = line[i];
      }
      if ( x == ' ' || i == line.length()) {
        // Converts string to (float)double and adds it to weight vector
        char *c = &word[0u];
        double num = atof(c);
        weight.push_back((float)num);
        word = "";
      }
    }

  }

  return weight;
}

/*
  Returns the dot product of 2 vectors
*/
float DotProduct(vector<float> w, vector<float> x){
  return inner_product(w.begin(), w.end(), x.begin(), 0.0);
}

