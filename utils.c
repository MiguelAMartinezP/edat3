#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

bool createTable(const char * tableName);
bool createIndex(const char * indexName);
bool findKey(const char * book_id, const char * indexName, int * nodeIDOrDataOffset);
bool addTableEntry(Book * book, const char * tableName, const char * indexName);
bool addIndexEntry(char * book_id, int bookOffset, const char * indexName);
void printTree(size_t level, const char * indexName);
void replaceExtensionByIdx(const char * fileName, char * indexName);

bool createTable(const char * tableName){

    FILE * f=NULL;
    
    if(!tableName){
        f=fopen(tableName, "w");
        if(fprintf(f, "-1")<0)
            printf("Error al abrir/crear el fichero");
    }


    f=fopen(tableName, "r");
    if(!f){
        f=fopen(tableName, "w");
        if(fprintf(f, "-1")<0)
            printf("Error al abrir/crear el fichero");
    }

    createIndex(tableName);

    fclose(f);


}

bool createIndex(const char * indexName){

    FILE * f=NULL;
    const char *tableName = "myDataBase.dat";
    
    if(indexName==tableName)
        strcpy(indexName, "myDataBase.idx");

    if(!indexName){
        f=fopen(indexName, "w");
        if(fprintf(f, "-1 -1")<0)
            printf("Error al abrir/crear el fichero");
    }


    f=fopen(indexName, "r");
    if(!f){
        f=fopen(indexName, "w");
        if(fprintf(f, "-1")<0)
            printf("Error al abrir/crear el fichero");
    }

    fclose(f);
}

void printTree(size_t level, const char * indexName){

    int i=0;
    FILE * f=NULL;

    if(!indexName || level<0){
        printf("Error al impimir el arbol");
        return;
    }

    f=fopen(indexName, "r");
    if(!f)
        return;

   /* for(i=0; i<=level; i++){
        fprintf();
    }*/
    
}