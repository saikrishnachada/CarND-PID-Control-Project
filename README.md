# **Project8 : PID Controller Project** 

### Objectives 

To implement a PID controller in C++ to steer the car around a race track. 

---

### Overview
The proposed PID controller uses the cross track error (CTE), which is the deviation from the center-line of the lane (ground-truth), along with the manually tuned proportional (P), integral (I) and derivative (D) coefficients to compute an appropriate steering angle to maneuver back to the center of the lane while driving on the race-track. 

---

### Reflection

I have implemented a basic PID controller using the techniques discussed in the lessons. Finding the optimal coefficients for the controller has been manually done in this work. The trail & error coefficients and their corresponding effects are illustrated in the table below. 

|       | Trial 1           | Trial 2| Trial 3 | Trial 4 | Trial 5 | Trial 6 | Trial 7 | Trial 8 |
| ------------- |:-------------:| :-----:|-----:|-----:|-----:|-----:|-----:|-----:|
|**Proportional**   | 2 | 0.1 | 0.1 |0.1 |0.12 |0.2 |0.15 |0.12 |
| **Integral**     | 0      |   0|   0| 0| 0.01| 0.0001| 0.0001|  0.0001|
| **Differential** | 0      |    0 |   10 |  1|  1 |  1 |  1 | 2 |
| **Remarks** | Huge Oscillations |  Oscillations become huge over the time | Jerky corrections |Does not work at turns    |Takes sharp turns. Oscillations slowly reduces over time  |Minimal oscillations |Crosses the yellow line at one point | Looks great! |

Starting with, I have tested a proportional controller (P-controller) with a value higher than 1.0. In the trial 1, this p-value of 2.0 resulted in a steering behavior with full of oscillations from the beginning and indeed caused the vehicle to move away off the track. In the next step, the value has been reduced to 0.1 which resulted in initial good start without oscillaitons. However, slowly oscillations propagated and led the vehicle to move off-track. Later, in trial 3, keeping the P-value as 0.1, additionally a differential component with the coefficient value of 10 has been tested. Although the vehicle is moving on track, the vehicle tried to correct itself very strictly, ideally resulting in jerky behavior. Therefore, in the next trial 4, the D-value is reduced to 1.0 and the results are good. But, only concern is at turns, i.e. when the CTE increases, the vehicle is finding it difficult to steer itself to lane center. This has motivated me to investigate on the integral component. I have started in trial 5 with I-value of 0.01, which has resulted in the initial oscillations and sharp behavior during turns. Later in trial 6, the T-value has been modified to 0.0001, which inturn improved the performance of the PID controller, however still has a minimal oscillation behavior. After further trials, finally the chosen coefficients are [0.12, 0.0001, 2]. 

### Results
* The code complies without any errors with cmake and make
* The tuning of the PID controller has been done manually. 
* The vehicle runs on the track throughput which can be seen from the below video.  

![] (https://github.com/saikrishnachada/CarND-PID-Control-Project/blob/master/Run_video_finalparameters.gif)

### Areas of improvements
* Methods such as twiddle, SGD, Ziegler-Nichols can be used to perform the optimal hyperparameter search. 
* A speed controller can be implemented further using a second PID controller. 

