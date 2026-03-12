#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char log[256];
    struct Node* next;
}Node;

Node* head = NULL;

void addLog(char* line){

    Node* newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->log,line);

    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void printLogs(){

    Node* temp = head;

    while(temp != NULL){
        printf("%s",temp->log);
        temp = temp->next;
    }
}

int main(){

    FILE *file = fopen("/var/log/syslog","r");

    if(file == NULL){
        printf("Dosya acilamadi\n");
        return 1;
    }

    char line[256];

    while(fgets(line,sizeof(line),file)){
        addLog(line);
    }

    fclose(file);

    printLogs();

    return 0;
}
