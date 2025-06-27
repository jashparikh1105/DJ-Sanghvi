#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int hashtable[100];

void insert(int key, int m);
int hashkey(int key, int m);
void display(int m);

void main() {
    int n, m, i, num;
    clrscr();

    printf("Enter the size of the table: ");
    scanf("%d", &m);

    // Initialize the hash table to 0
    for (i = 0; i < m; i++) {
        hashtable[i] = 0;
    }

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(num, m);
    }

    printf("The hash table is:\n");
    display(m);
    getch();
}

void insert(int key, int m) {
    int index = hashkey(key, m);
    
    // Linear probing to handle collisions
    while (hashtable[index] != 0) {
        index = (index + 1) % m;
    }

    hashtable[index] = key;
}

int hashkey(int key, int m) {
    return key % m;
}

void display(int m) {
    int i;
    for (i = 0; i < m; i++) {
        printf("%d : %d\n", i, hashtable[i]);
    }
}
