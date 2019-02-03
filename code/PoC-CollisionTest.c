#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Proof-of-concept of Algorithm Collision Test
// Checks random keys for pre-generated values

// BUILD WITH "gcc PoC-CollisionTest.c -lm" !!!

/*
const int myKeyA = 442142729;
const int myKeyB = 339586161;		<= With these keys, values were generated.
const int myKeyC = 839793264;
*/

const int timeA = 1550201770;
const int keyA = 119996;
const int timeB = 1550201850;
const int keyB = 337541;
const int timeC = 1550195880;
const int keyC = 189799;
const int timeD = 1550192200;
const int keyD = 485871;

unsigned int mySubKeyGenerate(){
	int numbers[9] = {0,0,0,0,0,0,0,0,0};
	unsigned int subKey = 0;
	while(subKey <= 100000000 || subKey >= 999999999){
		for(int i = 0; i<9; i++){
			numbers[i] = rand() % 10;
		}	
		for(int i = 0; i<9; i++){
			//subKey = subKey + (numbers[i]*(10**i));
			subKey = subKey + (numbers[i] * (int)pow(10,i));
		}
	}
	return subKey;
}

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

void testKey(int testedTime, int testedKey, unsigned int myKeyA, unsigned int myKeyB, unsigned int myKeyC){
	unsigned int calculatedKey = keyGenerate(testedTime, myKeyA, myKeyB, myKeyC);
	int collision = 0;
	
	if(calculatedKey == testedKey){
		collision = 1;
	}
	printf("Time: %d\tmyKey: %u-%u-%u\ttestedKey: %u\tcalculatedKey: %u\tCollision: %d\n", testedTime, myKeyA, myKeyB, myKeyC, testedKey, calculatedKey, collision);
}

int main(){
	srand(time(NULL)); // seed initialization
	
	unsigned int myKeyA, myKeyB, myKeyC;
	while(1){
		myKeyA = mySubKeyGenerate();
		myKeyB = mySubKeyGenerate();
		myKeyC = mySubKeyGenerate();
		testKey(timeA, keyA, myKeyA, myKeyB, myKeyC);
		testKey(timeB, keyB, myKeyA, myKeyB, myKeyC);
		testKey(timeC, keyC, myKeyA, myKeyB, myKeyC);
		testKey(timeD, keyD, myKeyA, myKeyB, myKeyC);
	}
	return 0;
}
