#include<cstdio>
#define MAX_PROCESS_NAME_SIZE 10
#define PROCESS_QUEUE_SIZE 100001

struct Process{
  char name[MAX_PROCESS_NAME_SIZE];
  int left_time;
};

Process queue[PROCESS_QUEUE_SIZE];
int head, tail = 0;

void enqueue(Process process) {
  queue[tail] = process;
  tail = (++tail % PROCESS_QUEUE_SIZE);
}

Process dequeue() {
  Process process = queue[head];
  head = (++head % PROCESS_QUEUE_SIZE);

  return process;
}

bool is_empty() {
  return head == tail;
}

int main() {
  int number_of_queue , quantum;
  Process current_process;

  scanf("%d %d", &number_of_queue, &quantum);

  for(int i = 0; i < number_of_queue; i++) {
    scanf("%s %d", current_process.name, &current_process.left_time);

    enqueue(current_process);
  }

  int elapsed_time = 0;
  while(true) {
    if(is_empty()) {
      break;
    }

    Process process = dequeue();

    if(process.left_time > quantum) {
      process.left_time -= quantum;
      enqueue(process);

      elapsed_time += quantum;
    } else {
      elapsed_time += process.left_time;

      printf("%s %d\n", process.name, elapsed_time);
    }
  }
}
