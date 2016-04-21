#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void read_training_label(string filename, vector<int> &training_label, int N_samples);
void read_training_feature(string filename, vector<int> &training_feature, int N_samples);

int main(int argc, char* argv[]){
	//getting parameters
    string feature_name = argv[1];
    string label_name = argv[2];
    string model_file_param = argv[3];
	int D_features = atoi(argv[4]);      //we don't need to worry about this because of how we
										 // split up lines in the training_feature_function
	int N_iterations = atoi(argv[5]); 

//short cut for command line:  ./a.out trainingFeature.dat trainingLabel.dat ModelFile.txt 1 1000
  
    //variables
    vector<int> training_label;
    vector<int> training_feature;
    float c = 1*pow(10, -6);
    int t = 0;
    vector<float> w;

    //reading in files to vectors
    read_training_label(label_name, training_label, N_iterations);
    read_training_feature(feature_name, training_feature, N_iterations);

    //applying logistical regression to test features

	int yi, xi, currLabel, cross_w_xi = 0, numerator, denomenator, loss;
    for(int i = 0; i < N_iterations; i++){
		t++;

		// Read current ine from training label file and assign value to yi
		// 		0 --> -1
		// 		1 --> 0
		currLabel = training_label.at(i);
		if (currLabel == 0){
			yi = -1;
		}
		else{
			yi = 0;
		}

		// Read current ine from training featuer and assign value to xi
		// 		0 --> -1
		// 		1 --> 0
		xi = training_feature.at(i);

		// Compute the cross product of w and xi
		for (int j=0; j < w.size(); j++){
			cross_w_xi += (w.at(j) * xi);
		}

		// compute numerator (-yi xi exp(-yi w·xi))
		numerator = ((-1 * yi) * xi * exp((-1 * yi) * cross_w_xi));

		// compute denomenator (1+ exp(-yi w·xi))
		denomenator = (1 + exp((-1 * yi) * cross_w_xi));
	
		// compute ∇w L = -yi xi exp(-yi w·xi) / (1+ exp(-yi w·xi)) 
		loss = numerator / denomenator;

    	//compute w←w–(c/t)∇w L
		float curr = (0.000001/ t) * loss;
		w.push_back(curr);

    }

    //writing to the file: 
    ofstream modelFile(model_file_param);
    while(w.size() > 0){
      modelFile << w.back() << endl;
      w.pop_back();
    }

    modelFile.close();

    cout << "done" << endl;
    cout << training_label.size() << endl;
    cout << training_feature.size() << endl;
    return 0;
}

void read_training_label(string filename, vector<int>& training_label, int N_samples){
    ifstream in(filename.c_str());
    string line; 	
    int track = 0;

    // If training label file is open, read N_sample amount of lines and 
    //   add int (0 or 1) to training label vector
    if(in.is_open()){
        while(getline(in,line) && track < N_samples){
            training_label.push_back(stoi(line));
            track++;	 
        }
        in.close();
    }
    else{ cout << "unable to open training label file!" << endl;}
}

void read_training_feature(string filename, vector<int> &training_feature, int N_samples){
    ifstream in(filename.c_str());
    string line;
    int track = 0;
    
    // If training feature file is open, read N_sample amount of lines and
    //    copy each int to traing freature vector 
    if(in.is_open()){
        while(getline(in, line) && track < N_samples){
            int start = 0;
            for(int i = 0; i < line.length() && track < N_samples; i++){
                if(line.at(i) == ' '){
                    string current = line.substr(start, i);
                    training_feature.push_back(stoi(current));
                    track++;
                    start = i;
                }
            }
        }
    }
    else{ cout << "unable to open training feature file!" << endl;}
}
