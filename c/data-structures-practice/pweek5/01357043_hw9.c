#include <stdio.h>

#define MAX_SIZE 1000
#define MAX_OUTPUT 2000

int main()
{
    int N;
    scanf("%d", &N);
    int queue[MAX_SIZE];
    int front = 0, rear = 0, count = 0;
    char output[MAX_OUTPUT][20];
    int out_count = 0;

    while (1)
    {
        int cmd;
        if (scanf("%d", &cmd) != 1)
            return 0;
        if (cmd == -1)
            break;

        if (cmd == 1)
        {
            int x;
            scanf("%d", &x);
            if (count == N)
            {
                sprintf(output[out_count++], "FULL");
                // 重要
            }
            else
            {
                queue[rear] = x;
                rear = (rear + 1) % N;
                count++;
            }
        }
        else if (cmd == 0)
        {
            if (count == 0)
            {
                sprintf(output[out_count++], "EMPTY");
            }
            else
            {
                sprintf(output[out_count++], "%d", queue[front]);
                front = (front + 1) % N;
                count--;
            }
        }
    }
    for (int i = 0; i < out_count; i++)
    {
        printf("%s\n", output[i]);
    }
    return 0;
}
