#include <stdio.h>
#define MAX 100 // Adjust MAX as needed

int queue[MAX], front = -1, rear = -1;
int queue1[MAX], front1 = -1, rear1 = -1;

int isFull() {
  return rear == MAX - 1;
}

int isEmpty() {
  return front == -1 || front > rear;
}

int enqueue(int data) {
  if (isFull()) {
    printf("Queue Overflow.\n");
    return 0;
  } else {
    if (front == -1)
      front = 0;
    rear++;
    queue[rear] = data;
    return 1;
  }
}

int dequeue() {
  int data;
  if (isEmpty()) {
    printf("Queue Underflow.\n");
    return 0;
  } else {
    data = queue[front];
    front++;
    return data;
  }
}

void transferAndPrintSorted() {
  front1 = -1; // Initialize front1
  rear1 = -1; // Initialize rear1

  while (!isEmpty()) {
    int temp = dequeue();
    int found = 0; // Flag to indicate if temp is placed in queue1

    // Find the correct position for temp in queue1 (increasing order)
    for (int i = front1; i <= rear1; i++) {
      if (temp < queue1[i]) {
        // Shift elements in queue1 one position ahead
        for (int j = rear1; j >= i; j--) {
          queue1[j + 1] = queue1[j];
        }
        queue1[i] = temp;
        found = 1;
        rear1++; // Increase rear1 after inserting
        break; // Exit loop after placing temp
      }
    }

    // If temp wasn't placed in queue1 due to being larger than all elements,
    // enqueue it at the end if there's space
    if (!found && rear1 != MAX - 1) {
      rear1++;
      queue1[rear1] = temp;
    } else if (!found && rear1 == MAX - 1) {
      printf("Queue1 Overflow.\n");
      return;
    }
  }

  printf("Elements in sorted order in queue1: ");
  for (int i = 0; i <= rear1; i++) {
    printf("%d ", queue1[i]);
  }
  printf("\n");
}

int main() {
  enqueue(30);
  enqueue(10);
  enqueue(90);
  enqueue(616);
  enqueue(77);

  transferAndPrintSorted();

  return 0;
}
