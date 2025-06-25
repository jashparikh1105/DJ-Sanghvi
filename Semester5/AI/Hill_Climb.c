#include <stdio.h>
#include <stdlib.h>

#define LIMIT 4

int topIndex = -1, goalIndex = -1;
int activeState[LIMIT], targetState[LIMIT];
int heuristicValues[LIMIT];
int currentHeuristicScore = 0;
int finalHeuristicScore = 0;

// Linked list for explored states
struct ListElement {
    int content;
    struct ListElement* next;
};

struct ListElement* start = NULL;

// Linked List Functions
void printList() {
    struct ListElement* ptr = start;
    printf("[");
    while (ptr != NULL) {
        printf(" %d ", ptr->content);
        ptr = ptr->next;
    }
    printf("]");
}

void appendNode(int content) {
    struct ListElement* newNode = malloc(sizeof(struct ListElement));
    newNode->content = content;
    newNode->next = NULL;
    if (start == NULL) {
        start = newNode;
    } else {
        struct ListElement* temp = start;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void removeNode(int content) {
    struct ListElement* temp = start, *prev = NULL;
    if (temp != NULL && temp->content == content) {
        start = temp->next;
        return;
    }
    while (temp != NULL && temp->content != content) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
}

int searchList(int content) {
    struct ListElement* temp = start;
    while (temp != NULL) {
        if (temp->content == content) return 1;
        temp = temp->next;
    }
    return 0;
}

// Stack Operations
int addToStack(int arr[], int index) {
    int element;
    if (index == LIMIT - 1) {
        printf("\nStack Overflow!");
    } else {
        for (int i = 0; i < LIMIT; i++) {
            scanf("%d", &element);
            index = index + 1;
            arr[index] = element;
        }
    }
    return index;
}

int removeFromStack(int arr[], int index) {
    if (index == -1) {
        printf("\nStack Underflow!");
    } else {
        printf("\nRemoved element: %d", arr[index]);
        index = index - 1;
    }
    return index;
}

void displayStack(int arr[], int index) {
    if (index == -1) {
        printf("\nStack is Empty!\n");
    } else {
        printf("\nCurrent elements in the stack: \n");
        for (int i = index; i >= 0; --i)
            printf("%d\n", arr[i]);
    }
}

// Heuristic Calculation
int computeCurrentHeuristic(int activeState[], int targetState[], int index) {
    currentHeuristicScore = 0;
    heuristicValues[0] = 0;
    for (int i = 1; i <= index; i++) {
        if (activeState[i] == targetState[i] && activeState[i - 1] == targetState[i - 1]) {
            heuristicValues[i] = i;
        } else {
            heuristicValues[i] = -i;
        }
        currentHeuristicScore += heuristicValues[i];
    }
    return currentHeuristicScore;
}

void computeHeuristic(int activeState[], int targetState[], int heuristicValues[]) {
    currentHeuristicScore = computeCurrentHeuristic(activeState, targetState, topIndex);
    displayStack(activeState, topIndex);
    printList();
    printf("\nCurrent heuristic value: %d", currentHeuristicScore);

    if (currentHeuristicScore >= finalHeuristicScore) {
        printf("\nGoal state achieved!\n");
        return;
    }

    if (topIndex >= 0 && activeState[topIndex] != targetState[topIndex]) {
        appendNode(activeState[topIndex]);
        printf("\n");
        topIndex = removeFromStack(activeState, topIndex);
        currentHeuristicScore = computeCurrentHeuristic(activeState, targetState, topIndex);
        computeHeuristic(activeState, targetState, heuristicValues);
    } else {
        return;
    }

    printf("\n\n");

    if (topIndex == -1) {
        for (int i = 0; i < LIMIT; i++) {
            if (searchList(targetState[i])) {
                removeNode(targetState[i]);
                topIndex = topIndex + 1;
                activeState[topIndex] = targetState[i];
                displayStack(activeState, topIndex);
                printList();
                currentHeuristicScore = computeCurrentHeuristic(activeState, targetState, topIndex);
                printf("\nUpdated heuristic score: %d\n", currentHeuristicScore);
                goalIndex = goalIndex - 1;
            }
        }
    }
}

// Main Function
int main() {
    printf("Enter the current state values: \n");
    topIndex = addToStack(activeState, topIndex);

    printf("Enter the goal state values: \n");
    goalIndex = addToStack(targetState, goalIndex);

    printf("\nGoal states\tHeuristic Value\n");
    for (int i = goalIndex; i >= 0; i--) {
        printf("%d\t\t%d\n", targetState[i], i);
        finalHeuristicScore += i;
    }

    printf("\nFinal heuristic value: %d\n", finalHeuristicScore);

    computeCurrentHeuristic(activeState, targetState, topIndex);

    printf("\nCurrent states\tHeuristic Value \n");
    for (int i = LIMIT - 1; i >= 0; i--) {
        printf("%d\t\t%d\n", activeState[i], heuristicValues[i]);
    }

    printf("\nTotal heuristic score: %d", currentHeuristicScore);
    printf("\n\n--------------------------------------------------------\n");

    computeHeuristic(activeState, targetState, heuristicValues);

    return 0;
}
