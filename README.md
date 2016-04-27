# logistical_regression
Artificial Intel Project 3
Danielle Beckley, Cameron Lloyd, Caleb

To Compile:
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
Accuracy predLabelFile testFeature.dat trainingLabel.dat
  

