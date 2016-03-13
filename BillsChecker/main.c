/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: johan
 *
 * Created on February 25, 2016, 9:44 PM
 */
#include "bill.h"

short verboseOptionEnabled = 0;

FILE* openFile(char*);
void checkBills(Bill*, FILE* file);

/*
 * 
 */
int main(int argc, char** argv) {
    
    // Retrieve the file containing required bills
    char *neededBillsFileDir = argv[1];
    
    // Retrieve the file containing the current bills
    char *billsFileDir = argv[2];
    
    FILE *requiredBillsFile = openFile(neededBillsFileDir);
    FILE *transactionsFile = openFile(billsFileDir);
    
    // If the files are null we shut down the program
    if(requiredBillsFile == NULL || transactionsFile == NULL) {
        return EXIT_FAILURE;
    }
    
    // Retrieve the first bill and make a linked list
    Bill *bill = getLinkedBillsFromFile(fopen(neededBillsFileDir, "r"));
    
    // Check if we missed any bills
    checkBills(bill, transactionsFile);
   
    // Finally remove the bills
    removeBills(bill);
     
    return (EXIT_SUCCESS);
    
}

FILE* openFile(char* directory) {
    FILE* file = fopen(directory, "r");
    if(file == NULL) {
        fprintf(stderr, "Can't open the file %s.\n", directory); 
    }
    return file;
}

void checkBills(Bill* bill, FILE* transactionsFile) {
    short checkSum = 0;
    char currentLine[250];
    while(fscanf(transactionsFile, "%250[^\n]\n", currentLine) == 1) {
        if(verboseOptionEnabled) {
            puts(currentLine);
        }
        checkSum += checkBill(bill, currentLine);
    }
        
    // time to check if we paid the bills!
    if(checkSum <= 0) {
        puts("All bills paid, good job pal!");
    } else {
        puts("Missing bills");
        puts("-------------");
        displayMissingBills(bill);
    }
}


