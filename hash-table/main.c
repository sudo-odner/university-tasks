#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* findAnagram(char* word) {
    int len = strlen(word);
    char* anagram = (char*)malloc((len + 1) * sizeof(char));
    strcpy(anagram, word);

    for (int i = 0; i < len - 1; i++) {
        int j = i + rand() % (len - i);
        char temp = anagram[i];
        anagram[i] = anagram[j];
        anagram[j] = temp;
    }

    return anagram;
}

int hashFunction(char* word) {
    word = findAnagram(word);
    int i = 0;
    for (int j=0; word[j]; j++)
        i += word[j];
    return i % 50000;
}


struct KeyNode {
    int key;
    int size;
    int cap;
    char **word;
};

struct HashTable {
    int cap;
    int size;
    struct KeyNode** items;

};

struct KeyNode* createItem(struct KeyNode* key, char* word){
    struct KeyNode* item = key;
    if ((item->cap) > (item->size)) {
        item->word[item->size] = (char *) malloc(strlen(word) * sizeof(int));
        item->word[item->size] = word;
        item->size += 1;

        return item;
    }
    printf("Err: Hash table is full");
    return item;
}

struct KeyNode* createKey(int cap, int key){
    struct KeyNode* item = (struct KeyNode*) malloc(sizeof(struct KeyNode));
    item->key = key;
    item->cap = cap;
    item->size = 0;
    item->word = (char**) malloc (cap * sizeof(char*));

    return item;
}

struct HashTable* createHashTable(int cap) {
    struct HashTable* table = (struct HashTable*) malloc (sizeof(struct HashTable));
    table->cap = cap;
    table->size = 0;
    table->items = (struct KeyNode**) calloc (table->cap, sizeof(struct KeyNode*));

    return table;
}

void HashTableInsert(struct HashTable* table, char* word) {
    int hashKey = hashFunction(word);
    struct KeyNode* existHash = table->items[hashKey];

    if (existHash == NULL) {
        if (table->cap == table->size) {
            printf("Err: Table is full");
        } else {
            struct KeyNode* newHashKey = createKey(20, hashKey);
            createItem(newHashKey, word);

            table->items[hashKey] = newHashKey;
            table->size += 1;
        }
    } else {
        createItem(existHash, word);
    }
}

struct KeyNode* HashTableSearchByWord(struct HashTable* table, char* word) {
    int keyHash = hashFunction(word);
    struct KeyNode* hashKey = table->items[keyHash];

    if (hashKey != NULL) {
        printf("%s: [\n", findAnagram(word));
        for (int i = 0; i < hashKey->size; i++) {
            printf("\t%s,\n", hashKey->word[i]);
        }
        printf("]");
    } else {
        printf("Not found word or anagram in hash table");
    }

    return hashKey;
}

int main() {
    struct HashTable* table = createHashTable(10000);
    HashTableInsert(table, "first");
    HashTableInsert(table, "second");
    HashTableInsert(table, "frsti");

    HashTableSearchByWord(table, "frasdfsti");

    return 0;
}