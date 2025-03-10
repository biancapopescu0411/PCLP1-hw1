# C Programming - Four Algorithmic Problems  

## Overview  
This repository contains four distinct C programs that solve different algorithmic challenges. Each program is structured with efficient logic and optimized operations. The problems include **grading optimization, movement simulation on a checkboard, vector calculations, and nonogram puzzle validation**.  

## Problems Implemented  

### **Code in Vim (`codeinvim.c`)**
This program determines the **minimum number of subjects** a student must improve to achieve a target cumulative score. The algorithm follows these steps:  
- Reads **N** subjects, each with a **grade** and a **credit value**.  
- Computes the **initial weighted score**.  
- Calculates the **impact of improving each grade** (difference to the highest possible grade, weighted by credit).  
- Sorts the subjects **by impact** (descending).  
- Iteratively improves grades until reaching the required minimum score.  
- Outputs the **minimum number of subjects** that need improvement.  
- If reaching the target score is **impossible**, it prints `-1`.  

#### Example Input/Output  
Input: 
5 8 9 7 6 10 2 3 1 2 1 180 

Output: 
2

(*Interpretation:* The student must improve grades in **at least 2 subjects** to reach the target score.)  

---

### **Gigel and the Checkboard (`gigel_and_the_checkboard.c`)**
Gigel navigates a **N×N chessboard**, moving according to values in the cells:  
- If on a **white** square, he moves **left or right**.  
- If on a **black** square, he moves **up or down**.  
- The value in the cell determines the movement distance.  
- Positive values move **right/down**, negative values move **left/up**.  
- Moves **wrap around** the board edges using modular arithmetic.  
- The traversal **stops at a zero value**.  
- Outputs the **total distance traveled** and the **final position**.  

#### Example Input/Output  
Input: 5 1 -2 3 0 4 2 1 -3 2 -1 

Output: 7 3 C

(*Interpretation:* Gigel moves across the board, travels **7 units**, and stops at position **row 3, column C**.)  

---

### **Infinite Product (`infinite_product.c`)**
This program performs **various mathematical computations** on two vectors of **N** pairs:  
- Reads **N** pairs of numbers, in **octal base**.  
- Computes the **scalar product** of the vectors.  
- Identifies the **second largest elements** in each vector.  
- Computes the **Euclidean norm** of each vector.  

#### Example Input/Output  
Input: 3 7 5 3 4 2 6 

Output: 65 5 6 8.062258 8.717798

(*Interpretation:* The scalar product is **65**, second-largest values are **5 and 6**, and the Euclidean norms are **8.062258 and 8.717798**.)  

---

### **Nonogram (`nomogram.c`)**
This program verifies whether a **nonogram puzzle** is correctly solved.  
- Reads **T** test cases (puzzles).  
- For each puzzle:  
  - Reads **grid size** (**N × M**).  
  - Reads **row constraints** (group counts).  
  - Reads **column constraints**.  
  - Reads the **grid** itself.  
- Validates if the **grid matches the constraints** for both rows and columns.  
- Outputs `"Corect"` if valid, `"Eroare"` otherwise.  

#### Example Input/Output  
Input: 1 5 5 2 2 1 2 1 2 3 1 1 1 1 3 2 2 1 2 1 2 3 1 1 1 1 3 2 2 1 1 1 1 1 

Output: Corect

(*Interpretation:* The grid satisfies all constraints, so the solution is **correct**.)  

---

## Project Structure  
 ```
MyProject/
├── codeinvim.c
├── gigel_and_the_checkboard.c
├── infinite_product.c
├── nomogram.c
└── Makefile
 ```
