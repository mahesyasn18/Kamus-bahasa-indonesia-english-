/*
file               : kamus.h
author             : Daniar Miftah Ramdhani (221511047)
                     Fadel Mohammad Fadhillah (221511048)
                     Mahesya Setia Nugraha (221511054)
program description: Program tugas besar mata kuliah Struktur Data dan Algoritma (praktik).
                     Program Kamus Translate Bahasa Indonesia - Inggris.                  
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0
#define boolean unsigned char

typedef char infotype[40];
typedef struct BTNode *Node;

typedef struct tElmtList *address;
typedef struct tElmtList {
	 infotype eng;
	 address  next;
} ElmtList;
typedef struct BTNode{
	infotype idn;
	Node left,right;
	address translate;
} BTnode;



void entryDatatoFile(infotype idn, infotype eng);

Node entryDatatoTree(Node root, infotype idn, infotype eng);

void entryTranslatetoLinkedList(address *head, infotype eng);

void showTranslate(address head);

Node loadDatafromFile(Node root);

void printTree(Node root);

int isLexicographic(Node root); 

void inorderTraversal(Node root);
