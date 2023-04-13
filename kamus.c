/*
file               : kamus.c
author             : Daniar Miftah Ramdhani (221511047)
                     Fadel Mohammad Fadhillah (221511048)
                     Mahesya Setia Nugraha (221511054)
program description: Program tugas besar mata kuliah Struktur Data dan Algoritma (praktik).
                     Program Kamus Translate Bahasa Indonesia - Inggris.                  
*/


#include "kamus.h"

void entry_data_to_file(infotype idn, infotype eng) {
    FILE *fp;
    fp = fopen("file.dat", "a+");

    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    fprintf(fp, "%s %s\n", idn, eng);
    fclose(fp);
}

Node entry_data_to_tree(Node root, infotype idn, infotype eng) {
    Node parent = NULL;
    Node current = root;
    
    while (current != NULL) {
        parent = current;
        if (strcmp(idn, current->idn) < 0) {
            current = current->left;
        } else if (strcmp(idn, current->idn) > 0) {
            current = current->right;
        } else {
            entry_translate_to_linkedlist(&(current->translate), strtok(eng, ","));
            char *token = strtok(NULL, ",");
            while (token != NULL) {
                entry_translate_to_linkedlist(&(current->translate), token);
                token = strtok(NULL, ",");
            }
            return root;
        }
    }
    
    Node newNode = (Node) malloc(sizeof(BTnode));
    strcpy(newNode->idn, idn);
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->translate = NULL;
    entry_translate_to_linkedlist(&(newNode->translate), strtok(eng, ","));
    char *token = strtok(NULL, ",");
    while (token != NULL) {
        entry_translate_to_linkedlist(&(newNode->translate), token);
        token = strtok(NULL, ",");
    }
    
    if (parent == NULL) {
        root = newNode;
    } else if (strcmp(idn, parent->idn) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    
    return root;
}


void entry_translate_to_linkedlist(address *head, infotype eng) {
    address temp = *head;

    if (temp == NULL) {
        temp = (address) malloc(sizeof(ElmtList));
        strcpy(temp->eng, eng);
        temp->next = NULL;
        *head = temp;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = (address) malloc(sizeof(ElmtList));
    strcpy(temp->next->eng, eng);
    temp->next->next = NULL;
}

void show_translate(address head) {
    address temp = head;

    while (temp != NULL) {
        printf("%s ", temp->eng);
        temp = temp->next;
    }

    printf("\n");
}


void print_tree(Node root) {
    if (root != NULL) {
        printf("%s: ", root->idn);
        show_translate(root->translate);
        print_tree(root->left);
        print_tree(root->right);
    }
}

Node load_data_from_file(Node root) {
    FILE *fp;
    fp = fopen("file.dat", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    infotype idn, eng;
    while (fscanf(fp, "%s %s", idn, eng) == 2) {
        root = entry_data_to_tree(root, idn, eng);
    }

    fclose(fp);
    return root;
}

int is_lexicographic(Node root) {
    if (root == NULL) {
        return 1;
    }

    if (root->left != NULL && strcmp(root->idn, root->left->idn) < 0) {
        return 0;
    }

    if (root->right != NULL && strcmp(root->idn, root->right->idn) > 0) {
        return 0;
    }

    return is_lexicographic(root->left) && is_lexicographic(root->right);
}

void inorder_traversal(Node root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%s: ", root->idn);
        show_translate(root->translate);
        inorder_traversal(root->right);
    }
}


