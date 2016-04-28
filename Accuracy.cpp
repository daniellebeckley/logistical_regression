//	Accuracy.cpp
//	Compares Prediction and Truth label files
//	Prints out final accuracy

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void read_in_file(string filename, vector<int> &vector);
double compare(vector<int> predicted, vector<int> truth);

int main(int argc, char* argv[]){
	string predLabelFile = argv[1];
	string trueLabelFile= argv[2];

	vector<int> predicted;
	vector<int> truth;
	read_in_file(predLabelFile, predicted);
	read_in_file(trueLabelFile, truth);

	double accuracy = compare(predicted, truth);
	cout << "Accuracy: " << accuracy << endl;

	return 0;
}

//reads in values from  file
void read_in_file(string filename, vector<int> &vector){
 	ifstream in(filename.c_str());
  	string line; 	
  	if(in.is_open()){
    	while(getline(in,line)){
			vector.push_back(stoi(line));	 
    	}
    	in.close();
  	}
	else{ cout << "ERROR:: unable to open file: " << filename << "!" << endl;}
}
//returns the accuracy
double compare(vector<int> predicted, vector<int> truth){
	int correct = 0;
	int total = 0;
	while(predicted.size() > 0 && truth.size() > 0){
		if(predicted.back() == truth.back()){
			correct++;
		}
		total++;
		predicted.pop_back();
		truth.pop_back();
	}
	double accuracy = (double)correct/total;
	return accuracy;
}
