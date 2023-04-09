#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <stdbool.h>

#define SIZE 20

struct DataItem {
	int data;
	int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;


int hashCode(int key){
	return key % SIZE;
}



void insert(int key,int data)
{
	struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
	item->data = data;
	item->key = key;

	// get the hash
	int hashIndex = hashCode(key);

	// move in array until an empty or deleted cell
	
	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
	{
		// got to next cell
		++hashIndex;

		// wrap around the table
		hashIndex %= SIZE;
	}

	hashArray[hashIndex] = item;
}


void display(){
	int i = 0;

	for (i  = 0; i < SIZE; i++){

		if (hashArray[i] != NULL)
			printf(" (%d, %d)", hashArray[i]->key,hashArray[i]->data);
		else
			printf("~~ ");
	}

	printf("\n");
}

int main()
{
	dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
	dummyItem->data = -1;
	dummyItem->key = -1;
	
	insert(1, 30);
	insert(2,70);

	display();

}
