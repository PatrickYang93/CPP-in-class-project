/****************************************
Name:			Qiguang Yang
Date:			11/18/2015
Course:			CSCI240

Properties:		This project can analyze wild fire data in USA 
				in the past 20 years. The total damage in square
				miles can be calculated. The total damage in acers 
				in each states and years can be displayed as well.

Inputs:			data from input file "fire_data".

Outputs:		collated wild fire data, total damage in square miles,
				otal damage in acers in each states and years. Top 10
				worst wild fire.
*****************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(){
	ifstream inFile("A-small-practice.in");
	ofstream outFile("A-small-practice.out");
	int T = 0;
	int n = 0;
	int x[8];
	int y[8];
	int valX;
	int valY;
	int counter = 1;
	inFile >> T;
	while(inFile){
		inFile >> n;
		int min = 0;
		for(int i = 0; i < n; i++){
			inFile >> x[i];
		}
		for(int i = 0; i < n; i++){
			inFile >> y[i];
		}
		for(int k = 0; k < n; k++){
			min += x[k]*y[k];
		}
		for(int j = 0; j < n; j++){
			int temp = 0;
			for(int q = 0; q < n; q++){
				for(int p = 0; p < n; p++){
					for(int l = 0; l < n; l++){
						if(l+q >= n){
							valX = x[l+q-n];
						}
						else{
							valX = x[l+q];
						}
						if(l+p >= n){
							valY = y[l+p-n];
						}
						else{
							valY = y[l+p];
						}
						temp += valX*valY;
					}
				}
			}
			if(temp < min){
				min = temp;
			}
		}
		outFile << "Case #" << counter << ": " << min << endl;
		counter ++;
	}
	return 0;
}
