#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numeric>		// include inner_product

using namespace std;

void read_training_label(string filename, vector<int> &training_label, int N_samples);
void read_training_feature(string filename,  vector< vector<int> > &training_feature, int D_features, int N_samples);
void initialize_w(vector<float> &w, int D_features);

int main(int argc, char* argv[]){
	//getting parameters
    string feature_name = argv[1];
    string label_name = argv[2];
    string model_file_param = argv[3];
	int D_features = atoi(argv[4]);      
	int N_iterations = atoi(argv[5]); 

//short cut for command line:  ./a.out trainingFeature.dat trainingLabel.dat ModelFile.txt 1 1000
  
    //variables
    vector<int> training_label;
    vector< vector<int> > training_feature;
    float c = 1*pow(10, -6), denomenator, dot_w_xi, exponential;
    int t = 0, yi, currLabel;
    vector<float> w, temp;

    //reading in files to vectors
    read_training_label(label_name, training_label, N_iterations);
    read_training_feature(feature_name, training_feature, D_features, N_iterations);
	initialize_w(w, D_features);
	
    //applying logistical regression to test features	
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
			yi = 1;
		}

		// Read next D features from 'training_feature' vector and assign values to xi
		vector<int> xi(training_feature[i]);

		/* compute ∇w L = -yi xi exp(-yi w·xi) / (1+ exp(-yi w·xi)) */
		// Compute the dot product of w and xi
		//dot_w_xi = inner_product(&xi.at(0), &xi.at(D_features-1), &w.at(0), 0);
		dot_w_xi = 0;
		for (int j=0; j<D_features; j++){
			dot_w_xi += w[j] * xi[j];
		}

		// yi = -yi
		yi = yi * -1;

		// compute exp(-yi w·xi)
		exponential = exp(yi * dot_w_xi);

		// compute numerator (-yi xi exp(-yi w·xi))
		vector<float> numerator;
		for (int j=0; j < D_features; j++){
			numerator.push_back((float) yi * (float) xi[j] * exponential);
		}

		// compute denomenator (1+ exp(-yi w·xi))
		denomenator = (1 + exponential);

		//loss = numerator / denomenator;
		vector<float> loss;
		for (int j=0; j < D_features; j++){
			loss.push_back(numerator[j] / denomenator);
		}

    	//compute w←w–(c/t)∇w L
		float c_t = c/t;
		for (int j=0; j < D_features; j++){
			temp.push_back(w[j] - (c_t * loss[j]));
		}
		w.swap(temp);
		temp.clear();
    }

    //writing to the file: 
    ofstream modelFile(model_file_param);
    while(w.size() > 0){
      modelFile << w.back() << " ";
      w.pop_back();
    }

    modelFile.close();

    cout << "done" << endl;
    cout << "Training_label size: " << training_label.size() << endl;
    cout << "Training_feature size: " << training_feature.size() << endl;
    return 0;
}

void read_training_label(string filename, vector<int>& training_label, int N_samples){
    ifstream in(filename.c_str());
    string line; 	
    int track = 0;

    /* If training label file is open, read 'N_samples' amount of lines and 
       add int (0 or 1) to training label vector */
    if(in.is_open()){
        while(getline(in,line) && track < N_samples){		
            training_label.push_back(stoi(line));
            track++;	 
        }
        in.close();
    }
    else{ cout << "unable to open training label file!" << endl;}
}

void read_training_feature(string filename, vector< vector<int> > &training_feature, int D_features, int N_samples){
    ifstream in(filename.c_str());
    string line;
    int samples = 0;
    
    // If training feature file is open, read N_sample amount of lines and
    //    copy each int to traing freature vector 
    if(in.is_open()){
        /*while(getline(in, line) && track < N_samples){
            int start = 0;
            for(int i = 0; i < line.length() && track < N_samples; i++){
                if(line.at(i) == ' '){
                    string current = line.substr(start, i);
                    training_feature.push_back(stoi(current));
                    track++;
                    start = i;
                }
            }
        }*/

		/* If training feature file is open:
				- Read in each line, until you've read in 'N_samples' samples
				- Parse line, and add each feature to 'training_feature' vector until
					'D_features' amount of features are added 
		*/
		training_feature.resize(N_samples, vector<int>(D_features, 0));
		while (getline(in, line) && samples < N_samples){
			int start = 0;
			int features = 0;
			for (int i=0; i < line.length() && features < D_features; i++){	
				if (line.at(i) == ' '){
					string current = line.substr(start, i);
					training_feature[samples][features] = (stoi(current));
					start = i;
					features++;
				}	
			}
			samples++;
		}
    }
    else{ cout << "unable to open training feature file!" << endl;}
}

/*
	Intialized weight vector to zero
*/
void initialize_w(vector<float> &w, int D_features){
	for (int i=0; i<D_features; i++){
		w.push_back(0);
	}
}
 
