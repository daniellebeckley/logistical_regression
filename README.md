# logistical_regression<br>
###Artificial Intel Project 3<br>
**Danielle Beckley, Cameron Lloyd, Caleb Underwood**<br>

To Compile:
-----------

- From ./logistical_regression, run the command `make`
  - Note: If you are using an older compiler, the std compiler c++11 may not compile successfully. If that's the case, use the commands below to compile 

```
TrainLogReg.cpp
  g++ -std=c++x0 -o TrainLogReg TrainLogReg.cpp
  
TestLogReg.cpp
  g++ -std=c++x0 -o TestLogReg TestLogReg.cpp
  
Accuracy.cpp
  g++ -std=c++x0 -o Accuracy Accuracy.cpp
 ```
  
To Run:
-----------
```
> ./TrainLogReg trainingFeature.dat trainingLabel.dat modelFile 785 12665<
> ./TestLogReg modelFile testFeature.dat predLabelFile 785
> ./Accuracy predLabelFile trainingLabel.dat
```  

