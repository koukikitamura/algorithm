#include <cstdio>
#define NO_SCORE -1

char calc_grading(int midterm_score, int final_score, int makeup_core) {
  if(midterm_score == NO_SCORE || final_score == NO_SCORE) {
    return 'F';
  }

  int total_score = midterm_score + final_score;
  if(total_score >= 80) {
    return 'A';
  }
  if(total_score >= 65) {
    return 'B';
  }
  if(total_score >= 50) {
    return 'C';
  }
  if(total_score >= 30) {
    if(makeup_core >= 50) {
      return 'C';
    }

    return 'D';
  }

  return 'F';
}

int main() {
  while(true) {
    int midterm_score, final_core, makeup_core;
    scanf("%d %d %d%*c", &midterm_score, &final_core, &makeup_core);

    if(midterm_score == NO_SCORE && final_core == NO_SCORE && makeup_core == NO_SCORE) {
      break;
    }

    char grading = calc_grading(midterm_score, final_core, makeup_core);

    printf("%c\n", grading);
  }
}
