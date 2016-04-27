#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numeric>		// include inner_product
#include <sstream>		// include istringstream

using namespace std;

vector<float> Read_Model_File(string model_File, int D_features);
float DotProduct(vector<float> w, vector<float> x);
void Read_Test_Feature_File(string test_file, vector<float> w, string predLabelFile, int D_features);

int main(int argc, char *argv[]){

	string modelFile = argv[1];
	string testFeatureFile = argv[2];
	string predLabelFile = argv[3];
	int D_features = atoi(argv[4]);

	// ModelFile Vector
	vector<float> w = Read_Model_File(modelFile, D_features);

	// Reads TestFeatureFile, Computes Dot Product of vectors and writes results to predLabelFile
	Read_Test_Feature_File(testFeatureFile, w, predLabelFile, D_features);

	return 0;
}

/*
  Reads the float values in ModelFile and stores them in a vector
*/
vector<float> Read_Model_File(string model_file, int D_features){
	vector<float> weight;
	string line;
	ifstream in(model_file);

	if (in.is_open()){

		getline(in, line);
		istringstream iss(line);
		string word;
		for (int i=0; i < D_features; i++){
			iss >> word;
			weight.push_back(stof(word));	
		}

		in.close();
	}
    else{ cout << "unable to open model file!" << endl;}

	return weight;
}

/*
  Reads input TestFeatureFile line by line
  Then computes dot product of each line vector and the modelFile, w, vector
  Writes result to the predLabelFile
*/
void Read_Test_Feature_File(string test_file, vector<float> w, string predLabelFile, int D_features){
	ofstream outputFile(predLabelFile);
	ifstream in(test_file);
	vector<float> testVector;
	string line, word;


	if (in.is_open()){
	
		while (getline(in, line)){
			istringstream iss(line);
			for (int i=0; i < D_features; i++){
				iss >> word;
				testVector.push_back(stof(word));
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

		in.close();
		outputFile.close();
	}
    else{ cout << "unable to open test feature file!" << endl;}

}

/*
  Returns the dot product of 2 vectors
*/
float DotProduct(vector<float> w, vector<float> x){
	float product = 0;
	for (int i = 0; i < w.size(); i++){
		product += (w[i] * x[i]);
	}
	return product;
}

