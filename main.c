/*
 * ENGR 476 - Project 2 - HDLC ( Layer 2 Protocol )
 *
 */

/* 
 * File:   main.c
 * Author: Cody Estes
 *
 * Created on September 26, 2017, 1:17 PM
 * Submitted September 30, 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * 
 */

 
 
int main(int argc, char** argv) {
    
    char temp[8];
    char flagg[] = "01111110";
    bool flag = false;
    char c, tep;
    int i, k, p;
    
    for(k=0; k<8;k++) {
    	temp[k] = '0';
	}
    
    printf("Enter values if you wish...:\n");
    printf("Flag:\t");
    
    for(i = 0; i < 8; i++) {
    	printf("%c ", flagg[i]);
	}
	
	printf("\n");
    
    i = 0; p = 0;
    
    while(flag == false) {
    	c = getche();
    	
    	for(k = 7; k > 0; k--){
    		temp[k] = temp[k-1];
		}
		
		temp[0] = c;
		
    	for(k = 0; k < 8; k++) {
    		if(temp[k] == flagg[k]){
    			p++;
			}
		}
		
		if(p == 8) {
			printf("flagged");
			flag = true;
		}
		else p = 0;
		
	}
	
	i = 0; p = 0;
	
	printf("\n\ninformation recieved shown below to the right of input:\n");
	
	while(flag == true) {
		c = getche();
		
		printf("\t%c\n", c);
    	
    	for(k = 7; k > 0; k--){
    		temp[k] = temp[k-1];
		}
		
		temp[0] = c;
		
    	for(k = 0; k < 8; k++) {
    		if(temp[k] == flagg[k]){
    			p++;
			}
		}
		
		if(p == 8) {
			printf("flagged: End Transmission");
			flag = false;
		}
		else p = 0;
	}
    
    
    return (EXIT_SUCCESS);
}




