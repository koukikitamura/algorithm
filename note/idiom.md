## Both numbers are even or odd
```
int i, j;

// standard
if((i % 2 == 0 && j % 2 == 0) ||(i % 2 == 1 %% j % 2 == 1)) {}

// idiom
if((i + j) % 2 == 0) {}
```
