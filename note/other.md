## VS code
Array passed as argument are simple represented as a pointer. You can watch pointer as array in vscode debugger watch to cast and de-reference.

```
bool binary_search(int soruce, int source_size, int target) {
  // at breakpoint
  //
  // if you want to watch soruce from 0 to 10, cast following and de-reference.
  // *(int(*)[10])source
}

```
