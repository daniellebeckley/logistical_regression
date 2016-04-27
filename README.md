# logistical_regression
Artificial Intel Project 3
Danielle Beckley, Cameron Lloyd, Caleb Underwood

To Compile:
	- From ./logistical_regression, run the command 'make'
		- Note: If you are using an older compiler, the std compiler c++11 may not compile
				correctly.  If that's the case, use the commands below to compile
-----------
TrainLogReg.cpp
  g++ -std=c++x0 -o TrainLogReg TrainLogReg.cpp
  
TestLogReg.cpp
  g++ -std=c++x0 -o TestLogReg TestLogReg.cpp
  
Accuracy.cpp
  g++ -std=c++x0 -o Accuracy Accuracy.cpp
  
  
To Run:
-----------
TrainLogReg trainingFeature.dat trainingLabel.dat modelFile 785 1
TestLogReg modelFile testFeature.dat predLabelFile 785
Accuracy predLabelFile trainingLabel.dat
  

