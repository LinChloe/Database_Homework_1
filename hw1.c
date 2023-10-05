#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STUDENT 20
#define Database 50

//define
typedef struct{
	int id;
	char name[STUDENT];
	int score;
}Test;

//initial
Test*database[Database];
int databaseSize = 0;

//create
Test*createTest(int id, const char* name, int score){
	Test* test = (Test*)malloc(sizeof(Test));
	test->id = id;
	strncpy(test->name, name, sizeof(test->name));
	test->score = score;
	return test;
}

//add
void addToDatabase(Test* test){
	if(databaseSize < Database){
		database[databaseSize++] = test;
	}else{
		printf("Oh,no!The dtabase is full and new records cannot be added.\n");
	}
}

//get
Test* getTestById(int id){
	for(int i = 0;i < databaseSize; i++){
		if (database[i]->id == id){
			return database[i];
		}
	}
	return NULL;
}

//update
void updateTest(Test* test, const char* name, int score){
	strncpy(test->name, name, sizeof(test->name));
	test->score = score;
}

//delete
void deleteTest(Test* test){
	for(int i = 0; i < databaseSize; i++){
		if(database[i] == test){
			free(database[i]);
			for(int j = i; j < databaseSize -1; j++){
				database[j] = database[j + 1];
			}
			databaseSize--;
			break;
		}
	}
}

//example
int main(){
	//create
	Test* test1 = createTest(1, "Frank", 98);
	Test* test2 = createTest(2, "Cindy", 65);
	Test* test3 = createTest(3, "Ambier", 77);
	
	//add
	addToDatabase(test1);
	addToDatabase(test2);
	addToDatabase(test3);

	//get
	Test* retrievedTest = getTestById(1);
	if(retrievedTest !=NULL){
		printf("Id : %d\tName : %s\tget %d points !!\n", retrievedTest->id, retrievedTest->name, retrievedTest->score);
	}else{
		printf("I cannot find the score !\n");
	}

	//update
	updateTest(test2, "Mr.White", 100);

	//delete
	deleteTest(test3);

	//release memory
	free(test1);
	free(test2);

	return 0;
}
	


