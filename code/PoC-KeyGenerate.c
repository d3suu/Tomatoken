#include <stdio.h>
#include <stdlib.h>

// Proof-of-concept of keyGeneration Algorithm
// Emulate generation of key's every ten seconds

const int myKeyA = 442142729;
const int myKeyB = 339586161;
const int myKeyC = 839793264;

unsigned int keyGenerate(int unixTime, int myKeyA, int myKeyB, int myKeyC){
	int a = unixTime;
	a = 860197 * (a&65535) + (a>>16);
	int b = a * 7563;
	b = 475058 * (b&65535) + (b>>16);
	int c = b * myKeyA;
	c = 893211 * (c&65535) + (c>>16);
	int d = c * myKeyB;
	d = 823636 * (d&65535) + (d>>16);
	int e = d * myKeyC;
	e = 516986 * (e&65535) + (e>>16);
	char strBuffer[20];
	sprintf(strBuffer, "%u", (a<<16) + b + c + d + e);
	strBuffer[6] = '\0';
	return atoi(strBuffer);
}

int main(){
	int time = 1549202100;
	for(int i = 0; i<=1000000; i+=10){
		printf("%d: %u\n", time+i, keyGenerate(time+i, myKeyA, myKeyB, myKeyC));
	};
	return 0;
}
