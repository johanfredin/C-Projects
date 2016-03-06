/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "bill.h"


Bill* createBill(char *name, short* index) {
    Bill *bill = malloc(sizeof(Bill));
    
    size_t length = strlen(name);
    char* newName = malloc(sizeof(name) * length);
    newName = strncpy(newName, name, length);
    bill->record =  newName;
    bill->index = *index;
    bill->isChecked = 0;
    bill->next = NULL;
    return bill;
}

void removeBills(Bill *first) {
    Bill *current = first;
    Bill *next = NULL;
    
    for(; current != NULL; current = next) {
        next = current->next;
        free(current->record);
        free(current);
    }
}

Bill* getLinkedBillsFromFile(FILE *billsFile) {
    
    char currentLine[100];
    short counter = 0;
    
        
        Bill *first = NULL;
        Bill *current = NULL;
        Bill *next = NULL;
        
    for(; fscanf(billsFile, "%100[^\n]\n", currentLine) == 1; current = next) {    
        next = createBill(currentLine, &counter);
        if(first == NULL) {
            first = next;
        } if(current != NULL) {
            current->next = next;
        }
        
        counter++;
    }
    return first;
   
}

void displayBills(Bill *bill) {
    
    puts("Bills in system:");
    puts("----------------");
    while(bill->next != NULL) {
        printf("name=%s, index=%hi, isChecked=%i \n", bill->record, bill->index, bill->isChecked);
        bill = bill->next;
        
    }
    
}

/**
 * Compares the passed in record with the bill and sets the bills checked flag to true if they match
 * @param bill
 * @param currentLine
 */
short checkBill(Bill *bill, char *currentLine) {
    while(bill->next != NULL) {
        if(strstr(currentLine, bill->record)) {
            bill->isChecked = 1;
            return 1;
        }
        bill = bill->next;
    }
    return 0;
}

void displayMissingBills(Bill *bill) {
    while(bill->next != NULL) {
        if(!bill->isChecked) {
            puts(bill->record);
        }
        bill = bill->next;
    } 
}