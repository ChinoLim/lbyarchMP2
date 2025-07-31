## LBYARCH S12B Group 8
Mascardo, Hans Christian <br/>
Navarro, Rafael Luis

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/2ccfdf82-6ed7-4a3d-97c6-b25354421ec1" />

<img width="1448" height="743" alt="image" src="https://github.com/user-attachments/assets/c432d17b-3d5f-4f92-b425-8599faa2744a" />

### Link for Short Demo (Make sure to use DLSU acct):
https://drive.google.com/file/d/1nBECFr_LcqupDppMbUjWLqp_sB6gGgsa/view?usp=sharing

### Consolidated Acceleration Formula:
### $A=\frac{(V_f-V_i\ )\ast\frac{5}{18}}{T}$ ###
Where: <br/>
A = acceleration in m/s2 <br/>
Vi = initial velocity in km/h <br/>
Vf = final velocity in km/h to reach 1 km <br/>
T = total time in seconds to reach 1 km <br/>

### Execution Time for Y=10,000 (in ms): For 30 Runs:
|  |  |  |  |  |  |  |
|---|---|---|---|---|---|---|
| 884 |	822 |	752 |	848 |	849 |	747 |	768 |
| 753 |	990 |	803 |	734 |	691 |	750 |	741 |
| 765 |	858 |	727 |	692 |	703 |	762 |	796 |
| 733 |	680 |	767 |	1137 |	870 |	789 |	764 |
| 688 |	746 |

Average Execution Time: **786.97 ms** <br/>
Average Execution Time per row input: **78.7 µs**


### Analysis
The performance of the x86-64 assembly program, which calculates the acceleration of cars with output displayed in C, shows an average execution time of 786.97 milliseconds for 10,000 identical inputs. The execution time in 30 runs ranges from 680 ms to 1,137 ms, indicating variability presumably due to background processes and memory access contention. While there is a linear consistency in the execution time and number of inputs, it shows that there is a positive linear scaling wherein the execution time and the number of inputs increase proportionally. An average execution time per row input is shown to be at 78.7 microseconds for a 10,000-input program. In contrast, the checker program written purely in C, responsible for computing and displaying the outputs of 10,000 inputs was observed to be worse, ranging from 25 to 30 seconds. Therefore, x86-64 is shown to be faster and highly efficient than C in terms of fetching and calculating data. These implementations show the efficiency in terms of runtime and level of programming, wherein high and low-level codes produce significant differences in managing and executing codes internally.


