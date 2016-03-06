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
/*
 * 
 */
int main(int argc, char** argv) {
    
    // Retrieve the file containing the list of bills needed
    Bill *bill = getLinkedBillsFromFile(fopen("resources/Bills Needed.csv", "r"));
    
    char *fileDir = "resources/transactionlist.xls";
    FILE *transactionsFile = fopen(fileDir, "r");
    
    if(!(transactionsFile = fopen(fileDir, "r"))) {
        fprintf(stderr, "Can't open the file.\n");
        removeBills(bill);
        return EXIT_FAILURE;
    } else {
        
        short checkSum = 0;
        char currentLine[250];
        while(fscanf(transactionsFile, "%100[^\n]\n", currentLine) == 1) {
            checkSum += checkBill(bill, currentLine);
        }
        
        // time to check if we paid da bills!
        if(checkSum <= 0) {
            puts("All bills paid, good job pal!");
        } else {
            puts("Missing bills");
            puts("-------------");
            displayMissingBills(bill);
        }
        
    }
    
    removeBills(bill);
    
    
    return (EXIT_SUCCESS);
    
    
}


