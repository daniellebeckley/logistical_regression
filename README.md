# logistical_regression<br>
###Artificial Intel Project 3<br>
**Danielle Beckley, Cameron Lloyd, Caleb Underwood**<br>

To Compile:
-----------

- From ./logistical_regression, run the command `make`
  - Note: On older compilers, the std compiler c++11 may not compile successfully. If that's the case, use the commands below to compile 

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
> ./TrainLogReg trainingFeature.dat trainingLabel.dat ModelFile.txt 785 12665
> ./TestLogReg ModelFile.txt testFeature.dat predLabel.dat 785
> ./Accuracy predLabel.dat trueLabel.dat
```  

