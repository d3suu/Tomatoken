# Raport about collisions of keys in algorithm
## Software used
- Modified PoC-CollisionTest.c which generates exactly 10 million entries
- grep

### PoC-CollisionTest.c patch
```
~/Tomatoken$ diff PoC-CollisionTest.c PoC-CollisionTest10mil.c 
72c72,73
< 	while(1){
---
> 	int cmon = 0;
> 	while(cmon <= 10000000){
79a81
> 		cmon += 1;
```

## Process of testing collisions
1. Generating 10 million entries to .txt file
2. Grep "Collision: 1" on these files
3. Count how much collisions occured
4. Repeat 3 times

> For testing purposes, only 4 test inputs were taken (see timeA, keyA, etc.)

## Scores
For 3 tests of 10 million keys, collisions occured exactly:
1. Test 1 - 77 times
2. Test 2 - 68 times
3. Test 3 - 80 times

This means, they occured averagely 75 times, per 10 million tests (actually 40 million becouse 4 inputs * 10 million)

## Example output of grep for one of 3 test-files
```
~/Tomatoken$ grep "Collision: 1" test6.txt
Time: 1550201850	myKey: 553887357-385401660-339169733	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201850	myKey: 313138157-127597169-499565219	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201770	myKey: 696706435-389697319-299036368	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550195880	myKey: 108105892-922104843-913460379	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 334807069-934299908-357447612	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 195170769-765928839-288074051	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201850	myKey: 320707937-651108980-767511596	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201770	myKey: 278186136-327847369-807524917	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550195880	myKey: 178645873-957689638-200322409	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201850	myKey: 625337184-498823890-586495167	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201850	myKey: 354605490-237700752-708754638	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201770	myKey: 508490888-908441707-804807589	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201770	myKey: 342927185-821751059-547042655	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201850	myKey: 368079209-378078879-717647610	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201850	myKey: 638751271-285049040-446002001	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201770	myKey: 117377856-443336592-254346683	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201770	myKey: 389671356-346504005-355411686	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201770	myKey: 465532213-475385119-884825738	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550195880	myKey: 872489903-810094680-776311995	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201850	myKey: 985464285-634964850-770457507	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201850	myKey: 668588235-443209779-538887254	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550195880	myKey: 636907468-851985144-307590036	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201770	myKey: 715067358-265747116-879893978	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201850	myKey: 303919259-945400216-744973667	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201850	myKey: 357617021-514219407-902326687	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201850	myKey: 114355298-873319477-663247942	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201770	myKey: 396273475-886270757-886402772	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550195880	myKey: 940047163-419343859-927914128	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201850	myKey: 230790712-113113342-648913739	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550195880	myKey: 869151218-376819852-165218878	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 623615798-368563570-130695798	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 121267330-164598490-539154858	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 662001224-131707075-938004904	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 811274314-728043276-414869480	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201770	myKey: 438933645-705912946-167711137	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550192200	myKey: 205547768-548992900-166109523	testedKey: 485871	calculatedKey: 485871	Collision: 1
Time: 1550201770	myKey: 385394795-112480812-699897587	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550195880	myKey: 978750167-777866112-268449977	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 408008164-382389211-162462124	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 783647658-326737040-914801008	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201770	myKey: 925882993-742360858-152991735	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201770	myKey: 169557230-158435932-930750948	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201770	myKey: 785196608-947828668-373990772	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201770	myKey: 978249164-253086011-298518784	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550195880	myKey: 735974730-677218217-338785120	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201850	myKey: 907669186-549085328-570497751	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550195880	myKey: 845077312-630397702-586578073	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 576828858-898079926-345945465	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201770	myKey: 749710048-815530404-870175158	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201770	myKey: 572104315-728901977-581448862	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550195880	myKey: 503280345-721047599-866711573	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201850	myKey: 329187675-344586499-265348052	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201770	myKey: 544850494-639946218-713565575	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201850	myKey: 271134072-317101302-288947183	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201850	myKey: 992967956-928343533-616824086	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550195880	myKey: 337687511-864999125-461674360	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 765022236-930210677-383331293	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 307846026-377070569-349197415	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 341276830-600130587-710492578	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 272837461-912281481-988549319	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 977557371-492512404-487945976	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 391951888-412793405-558892441	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201850	myKey: 885257146-317805952-507029166	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550195880	myKey: 965211705-104178160-270631492	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 292455250-869999810-412704409	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201770	myKey: 717760133-486799417-371447524	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201770	myKey: 813567389-183374062-634091960	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550195880	myKey: 524051948-654500895-971339447	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550195880	myKey: 415806663-888170878-433180172	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550192200	myKey: 148148551-771798151-845715731	testedKey: 485871	calculatedKey: 485871	Collision: 1
Time: 1550201850	myKey: 912336138-631320836-472064359	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201770	myKey: 288141422-229767801-756291885	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550195880	myKey: 710123571-538059234-387095599	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201770	myKey: 736757880-581534169-590411270	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201850	myKey: 147847335-684718716-993747152	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550201770	myKey: 215041215-791501410-343721617	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201770	myKey: 632041691-632915471-864157970	testedKey: 119996	calculatedKey: 119996	Collision: 1
Time: 1550201850	myKey: 820535217-682947220-834853350	testedKey: 337541	calculatedKey: 337541	Collision: 1
Time: 1550195880	myKey: 846980891-392176712-128654679	testedKey: 189799	calculatedKey: 189799	Collision: 1
Time: 1550201770	myKey: 532722078-853706448-888010695	testedKey: 119996	calculatedKey: 119996	Collision: 1
```
