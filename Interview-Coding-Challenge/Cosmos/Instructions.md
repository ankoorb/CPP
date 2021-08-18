### Instructions


I used **`C++ 17`** to develop the application. As I do not have access to the company's **`test.txt`** I wrote a Python script to generate synthetic data **`synthetic.txt`** to test the **CLI** application.  **NOTE:** For some reason Divide & Conquer algorithm for Closest Pair of Points does not give correct result (it returns 0 distance) so I need to debug the algorithm.

1. **`cd coding_challenge`**
2. Run **`python synthetic.py`** to generate **`synthetic.txt`**
3. Run **`make build`** to build the **CLI** application (`make clean` if you want to remove build files and executable)
4. Run **`cd build`**
5. **`./Cosmos ../synthetic.txt [Key_1] [Key_2]`** to run the application. 

   > Example: `./Cosmos ../sample.txt Alpha_Dra E465D`
