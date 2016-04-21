OUTPUTS = Accuracy TestLogReg TrainLogReg

all: $(OUTPUTS)

Accuracy: Accuracy.cpp
	g++ -std=c++11 Accuracy.cpp -o Accuracy

TestLogReg: TestLogReg.cpp
	g++ TestLogReg.cpp -o TestLogReg

TrainLogReg: TrainLogReg.cpp
	g++ -std=c++11 TrainLogReg.cpp -o TrainLogReg

clean:
	rm -rf $(OUTPUTS)
