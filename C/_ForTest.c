#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX_SIZE 101
#define MAX 1000
void SWAP(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void Select_Sort(int list[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (list[j] < list[min])
                min = j;
        }
        if (i != min)
        {
            SWAP(&list[i], &list[min]);
        }
    }
}
/* i 現在要放正確數字的位置（前面已排好）
        min 在從 i 到 n -
    1 找到的最小值的位置
        list[i] 現在這格還沒確定是否最小
            list[min] 搜尋後確定的真正最小數 void
            bubble_Sort(int list[], int n)
*/
void Insertion_Sort(int list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0 && list[j] > list[j + 1]; j--)
        {
            SWAP(&list[j], &list[j + 1]);
        }
    }
}
/*
外層：每次右邊加入一個新元素（index = i）
內層：往左比較，把它放到前面已排序區的正確位置
最小值會往左堆直到右邊到底
*/
void bubble_Sort(int list[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                SWAP(&list[j], &list[j + 1]);
            }
        }
    }
}
/*
最大值往右堆,縮減右邊範圍,重覆到縮減至0
*/
void Binary_Search(int list[], int n, int target)
{
    int middle;
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (list[middle] < target)
        {
            left = middle + 1;
        }
        else if (list[middle] == target)
        {
            printf("%d", middle);
            return;
        }
        else
            right = middle - 1;
    }
    printf("not found\n");
    return;
}
void Binary_Search_recursive(int list[], int left, int right, int target)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (list[mid] == target)
        return mid;
    if (list[mid] > target)
        return bsearch_recursive(list, left, mid - 1, target);
    return bsearch_recursive(list, mid + 1, right, target);
}
typedef struct
{
    char last_name;
    int student_id;
    float grade;
    union
    {
        int kid;
        int beard;
    } u;
    // UNION 只能存一種型態,像是多選一的資料庫,一次只能有一種資料生效
    // ex:bread or kid 二選一
    // 看裡面最大的型態來分配空間
} student;
// typedef <原型別> <別名>;
// struct 名字{}是個結構行別,名字因為用typedef已不重要

struct Node
{
    bool is_leaf;
    union
    {
        struct
        {
            struct Node *left;
            struct Node *right;
        } internal;
        double data;
    } info;
};
// 可以儲存下列任一的聯合資訊
// 實現binary tree (only leaf nodes have data)
void strInsert(char *s, char *t, int i)
{
    /* insert string t into string s at position i */
    char string[MAX_SIZE], *temp = string;
    if (i < 0 && i > strlen(s))
    {
        fprintf(stderr, "Position is out of bounds \n");
        exit(1);
    }
    if (!strlen(s))
        strcpy(s, t);
    else if (strlen(t))
    {
        strncpy(temp, s, i); // 複製 s 的前 i 個字元到 temp
        temp[i] = '\0';
        strcat(temp, t);       // 在後面加上 t
        strcat(temp, (s + i)); // 加上 s 從第 i 個位置開始的剩餘字元
        strcpy(s, temp);       // 把結果寫回 s
    }
}
int naiveFind(char *string, char *pat)
{
    /* match the last character of pattern first,
    and then match from the beginning */
    int i, j, start = 0;
    int lasts = strlen(string) - 1;
    int lastp = strlen(pat) - 1;
    int endmatch = lastp;
    for (i = 0; endmatch <= lasts; endmatch++, start++)
    {
        if (string[endmatch] == pat[lastp])
            for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++)
                ; // empty statement: advance while matching
        if (j == lastp)
            return start; /* successful */
    }
    return -1;
}
// O(n · m).
// 測試stack
// fprintf(stderr, "Stack is FULL!!");
typedef struct
{
    int key;
} element;

element stack[MAX];
int top = -1;

void push(element item)
{
    if (top >= MAX - 1)
        return;
    stack[++top] = item;
}

element pop()
{
    return stack[top--];
}

int isEmpty()
{
    return top == -1;
}

int Fibo_stack(int n)
{
    int result = 0;
    element tmp;

    tmp.key = n;
    push(tmp); // bootstrapping

    while (!isEmpty())
    {
        tmp = pop();

        if (tmp.key == 0)
        {
            result += 0;
        }
        else if (tmp.key == 1)
        {
            result += 1;
        }
        else
        {
            element a, b;
            a.key = tmp.key - 1;
            b.key = tmp.key - 2;
            push(a);
            push(b);
        }
    }

    return result;
}
// 火車的問題在4個數字中3先出來變得不可能
element queue[MAX_SIZE];
int front = 0; // 指向第一個有效元素的位置
int rear = 0;  // 指向最後一個有效元素的下一個位置

// 判斷是否為空佇列
int isEmpty()
{
    return front == rear;
}

// 判斷是否為滿佇列
int isFull()
{
    return rear == MAX_SIZE;
}

// 將元素加入佇列尾端
void Enqueue(element item)
{
    if (isFull())
    {
        fprintf(stderr, "Queue is FULL!!\n");
        return;
    }
    queue[rear++] = item; // 先放資料，再將 rear 往後移動
}

// 從佇列前端取出元素
element Dequeue()
{
    element errKey;
    if (isEmpty())
    {
        errKey.key = -99; // 錯誤碼
        fprintf(stderr, "Queue is EMPTY!!\n");
        return errKey;
    }
    return queue[front++]; // 取出資料，再將 front 往後移動
}
// 一般的佇列實作就只有這樣
element queue[MAX_SIZE];
int front = 0; // 指向佇列第一個有效元素的前一格
int rear = 0;  // 指向佇列最後一個有效元素

// 判斷是否為空佇列
int isEmpty()
{
    return front == rear;
}

// 判斷是否為滿佇列（預留一格不用）
int isFull()
{
    return (rear + 1) % MAX_SIZE == front;
}

// Enqueue：從尾端加入資料
void Enqueue(element item)
{
    if (isFull())
    {
        fprintf(stderr, "Queue is FULL!!\n");
        return;
    }
    rear = (rear + 1) % MAX_SIZE; // 先移動 rear
    queue[rear] = item;           // 再放資料
}

// Dequeue：從前端取出資料
element Dequeue()
{
    element errKey;
    if (isEmpty())
    {
        errKey.key = -99; // 錯誤值
        fprintf(stderr, "Queue is EMPTY!!\n");
        return errKey;
    }
    front = (front + 1) % MAX_SIZE; // 先移到資料位置
    return queue[front];            // 取出資料
}
// Circular Queue的資料結構更好,但是貨車問題的解法3以上就不能先出了
int main()
{
    student a;
    clock_t start = clock();
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    // cup time_used
    printf("Time used: %f\n", cpu_time_used);
    time_t start_time = time(NULL);
    time_t end_time = time(NULL);
    printf("Elapsed time: %ld seconds\n", end_time - start_time);
    // realtime used

    int i, n, key;
    int list[MAX_SIZE];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        list[i] = rand() % 1000;
        printf("%d ", list[i]);
    }
    printf("\n");
    Select_Sort(list, n);
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
    scanf("%d", &key);
    Binary_Search(list, n, key);
    return 0;
}
