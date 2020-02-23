## Both numbers are even or odd
```
int i, j;

// standard
if((i % 2 == 0 && j % 2 == 0) ||(i % 2 == 1 %% j % 2 == 1)) {}

// idiom
if((i + j) % 2 == 0) {}
```

## the number of combinations
You should output three distinct ingergers from 1 to n.
```
int n;

for(int small = 1; small <= n - 2; small++) {
  for(int middle = small + 1; middle <= n - 1; middle++) {
    for(int large = middle + 1; large <= n; large++) {
      printf("%d %d %d\n", small, middle, large);
    }
  }
}
```
