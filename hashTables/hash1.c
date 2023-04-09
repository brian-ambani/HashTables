#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5000 // Size of the hashfunction

unsigned long hash_function(char* str)
{
	unsigned long i = 0;

	for ( int j = 0; str[j]; j++)
		i += str[j];

	return i % CAPACITY;
}

// Define the HashTable item.

typedef struct Ht_item
{
	char* key;
	char* value;
} Ht_item;


// Define the HashTable

typedef struct HashTable
{
	// Contains an array of pointer to items.
	
	Ht_item** items;
	int size;
	int count;
}HashTable;


// Create items by allocating memory for a key and value

Ht_item* create_item(char* key, char* value)
{
	// Create a pointer to a new HashTable item.
	Ht_item* item = (Ht_item) malloc(sizeof(Ht_item));
	item->key = (char*) malloc(strlen(key) + 1);
	item->value = (char*) malloc(strlen(value) + 1);
	strcpy(item->key, key);
	strcpy(item->value, value);
	return item;
}

// Create table by allocating memory and setting size, count and item

HashTable* create_table(int size)
{
	// Create a new HashTable
	Hashtable* table = (HashTable*) malloc(sizeof(HashTable));
	table-> size = size;
	table->count = 0;
	table->items = (Ht_item**) calloc(table->size, sizeof(Ht_item*));

	for (int i = 0; i < table->size; i++)
		table->items[i] = NULL;

	return table;
}























