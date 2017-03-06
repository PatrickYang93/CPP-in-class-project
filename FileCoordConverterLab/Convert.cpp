/******************************************************************************
Title:			Coordinate Conversion
Name:			Jordan Ringenberg
Course:			CSCI240
Instructor:		Jordan Ringenberg
Due Date:		Tuesday, November 5th, 2015

Description: This program will convert an object coordinate input file so that 
			 indices start at 0 rather than 1

Input:		 Input file containing 2D or 3D object coordinates

Output:		 Corresponding file with each coordinate "shifted" by -1
******************************************************************************/
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

int		countLines		(ifstream &);
void	convertCoords	(string, int &, int &);
void	convertCoords	(string, int &, int &, int &);
void	writeOutput		(ofstream &, int, int);
void	writeOutput		(ofstream &, int, int, int);
void	updateStatus	(int, int, int defaultIncr = 10);

int main(){
	ifstream inFile ("inCoords_100000_3D.txt");
	ofstream outFile("outCoords.txt");
	string xy;

	int x;
	int y;
	int z;
	int lineNum;
	int totalLines;

	lineNum		= 0;
	totalLines  = countLines(inFile);

	cout << "Preparing to convert " << totalLines << " lines...\n" << endl;
	while(inFile >> xy){
		convertCoords(xy, x, y, z);

		writeOutput(outFile, x, y, z);

		updateStatus(++lineNum, totalLines, 5);
	}
	cout << "\nConversion complete" << endl;

	inFile.close();
	outFile.close();
	return 0;
}

//*****************************************************************************
//Count and return the number of lines in file.
//*****************************************************************************
int countLines(ifstream &inFile){
	string line;
	int count	= 0;

	while(getline(inFile,line)){
		count ++;
	}

	//reset the stream to the beginning of the file
	inFile.clear();
	inFile.seekg(0,inFile.beg);
	
	return count;
}

//*****************************************************************************
//Convert comma-separated xy string coordinates to integer values. 
//*****************************************************************************
void convertCoords(string coords, int &x, int &y){
	int commaLoc;
	string xStr;
	string yStr;

	//find the index of the comma within the string
	commaLoc = coords.find(",");

	//separate string, at comma location, into two strings (for x and y part)
	xStr = coords.substr(0,commaLoc);
	yStr = coords.substr(commaLoc+1,coords.length() - commaLoc -1);

	//convert the x and y string values to integers
	x = atoi(xStr.c_str()) - 1;
	y = atoi(yStr.c_str()) - 1;
}

//*****************************************************************************
//Convert comma-separated xyz string coordinates to integer values. 
//*****************************************************************************
void convertCoords(string coords, int &x, int &y, int &z){
	int commaLoc1;
	int commaLoc2;

	string xStr;
	string yStr;
	string zStr;

	string yzStr;

	//find the index of the 1st comma within the string
	commaLoc1 = coords.find(",");

	//separate string, at comma location, into two strings (for x and yz part) 
	xStr = coords.substr(0,commaLoc1) ;
	yzStr = coords.substr(commaLoc1+1,coords.length() - commaLoc1 -1);

	//find the index of the 2st comma within the string (from yz string)
	commaLoc2 = yzStr.find(",");

	//separate string, at comma location, into two strings (for y and z part)
	yStr = yzStr.substr(0,commaLoc2);
	zStr = yzStr.substr(commaLoc2+1,yzStr.length() - commaLoc2 -1);

	//convert the x, y, and z string values to integers
	x = atoi(xStr.c_str()) - 1;
	y = atoi(yStr.c_str()) - 1;
	z = atoi(zStr.c_str()) - 1;
}

//****************************************************** ***********************
//Write one line of the output file as comma-separated x,y coordinates. 
//*****************************************************************************
void writeOutput(ofstream &outFile, int x, int y){
	outFile << "(" << x << "," << y << ")" << endl;
}

//*****************************************************************************
//Write one line of the output file as comma-separated x,y,z coordinates. 
//*****************************************************************************
void writeOutput(ofstream &outFile, int x, int y, int z){
	outFile << "(" << x << "," << y << "," << z << ")" << endl;
}

//****************************************************************************
//Print file-writing status updates to the console at specified percentage
//increments based on the current completion percentage. 
//
//Default pctIncrement: 10
//*****************************************************************************
void updateStatus (int lineNum, int totalLines, int pctIncrement){
	if(totalLines == 0){
		cerr << "Error - number of lines is equal to 0. Returning..." << endl;
		return;
	}
	int pct = (lineNum * 100) / totalLines;
	int rem = (lineNum * 100) % totalLines;
	string tot = to_string(totalLines);

	if(pct % pctIncrement == 0 && rem == 0){
		cout << setw(3) << pct << "%";
		cout << " (" << setw(tot.length()) << lineNum << " lines) Converted\n";
	}
}
