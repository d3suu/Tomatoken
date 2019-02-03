# Differences between key generation in C on AVR and x86_64
## 1. Type size's
Problem with porting x86_64 to AVR is that sizes of types are different. In this example on x86_64 ```int``` takes 4 bytes, while on AVR it takes only 2.

To simply get rid of problems, change any integrer in x86 C, to ```long``` type.

## 2. Libc sprintf flags
While on x86_64, ```%u``` will work just fine (in ```keyGeneration()``` function case), in AVR we have to change it to ```%lu```.

## 3. atoi() vs atol()
Again, those damn types.

## Real life comparison
### x86_64
```C
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
```
### AVR
```C
unsigned long keyGenerate(long unixTime, long myKeyA, long myKeyB, long myKeyC){
	long a = unixTime;
	a = 860197 * (a&65535) + (a>>16);
	long b = a * 7563;
	b = 475058 * (b&65535) + (b>>16);
	long c = b * myKeyA;
	c = 893211 * (c&65535) + (c>>16);
	long d = c * myKeyB;
	d = 823636 * (d&65535) + (d>>16);
	long e = d * myKeyC;
	e = 516986 * (e&65535) + (e>>16);
	char strBuffer[20];
	sprintf(strBuffer, "%lu", (a<<16) + b + c + d + e);
	strBuffer[6] = '\0';
	return atol(strBuffer);
}
```
