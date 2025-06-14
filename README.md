#  Student Grades Manager in C

This is a simple C program that manages student data, including:
- Storing student info and grades
- Calculating weighted averages
- Sorting students by name
- Displaying class average
- Showing student rank based on average

##  Features

- Prevents duplicate student codes
- Calculates each student's average based on subject coefficients
- Calculates class average
- Sorts students alphabetically
- Displays student rank

---

##  How to Compile

```bash
gcc main.c -o student-manager
````

##  How to Run

```bash
./student-manager
```

## Example Input

```bash
n-etudiants: 2
n-notes: 3

--- Student 1 ---
Code: 101
Nom: Messi 
Prenom: Lionel
Date (jj mm aaaa): 10 3 2002
Note 1: 15
Note 2: 12
Note 3: 17

--- Student 2 ---
Code: 102
Nom: Ronaldo
Prenom: Cristiano
Date (jj mm aaaa): 25 4 2001
Note 1: 14
Note 2: 16
Note 3: 13

Coef 1: 2
Coef 2: 3
Coef 3: 1
```

## Example Output

```bash
Moy de classe: 14.17

Etudiants trie par nom:
Messi Lionel(10/3/2002) : Moyenne = 14.17 / Rang : 1
Ronaldo Cristiano(25/4/2001) : Moyenne = 14.17 / Rang : 2

```
