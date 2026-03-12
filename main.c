#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List düğüm yapısı
typedef struct Node {
    char log[256];
    struct Node* next;
} Node;

Node* head = NULL;

// Listeye yeni log ekleme
void addLog(char* line) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->log, line);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Logları yazdırma
void printLogs() {

    Node* temp = head;

    printf("Linked List içindeki Syslog kayıtları:\n\n");

    while (temp != NULL) {
        printf("%s\n", temp->log);
        temp = temp->next;
    }
}

int main() {

    // Örnek syslog kayıtları
    char logs[][256] = {
        "Mar 10 10:00:01 system started",
        "Mar 10 10:05:12 user login",
        "Mar 10 10:10:45 network connected",
        "Mar 10 10:15:33 cron job executed"
    };

    int size = 4;

    // Linked list'e ekleme
    for(int i = 0; i < size; i++) {
        addLog(logs[i]);
    }

    // Listeyi yazdır
    printLogs();

    return 0;
}
