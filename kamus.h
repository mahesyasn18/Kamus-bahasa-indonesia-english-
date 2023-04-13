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



void entry_data_to_file(infotype idn, infotype eng);

Node entry_data_to_tree(Node root, infotype idn, infotype eng);

void entry_translate_to_linkedlist(address *head, infotype eng);

void show_translate(address head);

Node load_data_from_file(Node root);

void print_tree(Node root);

int is_lexicographic(Node root); 

void inorder_traversal(Node root);
