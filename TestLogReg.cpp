#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <numeric>

using namespace std;

vector<float> Read_Model_File(char * model_File);
float DotProduct(vector<float> w, vector<float> x);
void Read_Test_Feature_File(char * test_file, vector<float> w, char* predLabelFile, int D);

int main(int argc, char *argv[]){

  char* modelFile = argv[1];
  char* testFeatureFile = argv[2];
  char* predLabelFile = argv[3];
  char* charD = argv[4];

  //Converts D to an int
  std::string stringD(charD);
  int D = atoi(stringD.c_str());

  // ModelFile Vector
  vector<float> w = Read_Model_File(modelFile);

  // Reads TestFeatureFile, Computes Dot Product of vectors and writes results to predLabelFile
  Read_Test_Feature_File(testFeatureFile, w, predLabelFile, D);

  return 0;
}

/*
  Reads the float values in ModelFile and stores them in a vector
*/
vector<float> Read_Model_File(char * model_file){

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

    // Reads string char by char
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
  Reads input TestFeatureFile line by line
  Then computes dot product of each line vector and the modelFile, w, vector
  Writes result to the predLabelFile
*/
void Read_Test_Feature_File(char * test_file, vector<float> w, char* predLabelFile, int D){

  // Creates and opens output file
  ofstream outputFile;
  outputFile.open(predLabelFile);

  vector<float> testVector;

  // Convert File Name to String
  std::string file(test_file);

  // Read Input File
  ifstream in(file.c_str());

  if (in.is_open()){

    for (int i = 0; i < D; i++){
      string line, word;
      getline(in, line);

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
          testVector.push_back((float)num);
          word = "";
        }
      }

      /*
        Computes the DotProduct of ModelFile vector, w, and all 'D' testFeatureFile
        vectors, x, and writes them to the newly created file
      */
      if (DotProduct(w,testVector) > 0){
        outputFile << "1" << endl;
      }
      if (DotProduct(w,testVector) < 0){
        outputFile << "0" << endl;
      }
      
      // Clears out testVector to be used again
      testVector.clear();

    }
  }
}

/*
  Returns the dot product of 2 vectors
*/
float DotProduct(vector<float> w, vector<float> x){

  float product = 0;
  for (int i = 0; i <= w.size()-1; i++){
    product += (w[i] * x[i]);
  }
  return product;
}
