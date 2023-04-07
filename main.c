/*
file               : main.c
author             : Daniar Miftah Ramdhani (221511047)
                     Fadel Mohammad Fadhillah (221511048)
                     Mahesya Setia Nugraha (221511054)
program description: Program tugas besar mata kuliah Struktur Data dan Algoritma (praktik).
                     Program Kamus Translate Bahasa Indonesia - Inggris.                  
*/



#include <stdio.h>
#include <stdlib.h>
#include "kamus.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int menu = 0;
	
    infotype indonesia, english;
    Node root = NULL;
    root = loadDatafromFile(root); 

    do {
        printf("\n-- MENU --\n");
        printf("1. Terjemahan Kata Indonesia - Inggris\n");
        printf("2. Tambah Data\n");
		printf("3. Tampilkan Semua Kata\n");
		printf("4. cek Lexicographic\n");
		printf("5. Exit\n");
		printf("Masukkan Pilihan Menu: ");
		scanf("%d", &menu);
		
		switch (menu) {
        case 1:
        	system("cls");
            printf("Masukkan kata dalam Bahasa Indonesia: ");
            scanf("%s", &indonesia);
            Node current = root;
            while (current != NULL) {
                if (strcmp(indonesia, current->idn) < 0) {
                    current = current->left;
                } else if (strcmp(indonesia, current->idn) > 0) {
                    current = current->right;
                } else {
                    printf("Hasil Translate dari %s adalah: ", indonesia);
                    showTranslate(current->translate);
                    break;
                }
            }

            if (current == NULL) {
                printf("Maaf,  Kata %s Belum ada di kamus\n", indonesia);
            }

            break;
        case 2:
        	system("cls");
            printf("Masukkan kata dalam Bahasa Indonesia: ");
            scanf("%s", &indonesia);
            printf("Masukkan Kata translate dalam Bahasa Inggris (pisahkan beberapa terjemahan dengan koma): ");
            scanf("%s", &english);
            entryDatatoFile(indonesia, english);
            root = entryDatatoTree(root, indonesia, english);
            printf("Berhasil Menambahkan Data ke Kamus\n");
            break;
        case 3:
        	system("cls");
            printf("\nData Kamus\n");
            inorderTraversal(root);
            break;
        case 4:
			if (isLexicographic(root)) {
			    printf("Binary tree is lexicographically sorted\n");
			} else {
			    printf("Binary tree is not lexicographically sorted\n");
			}
        case 5:
            printf("geusan\n");
            break;
        default:
            printf("Invalid input\n");
            break;
    }

	} while (menu != 5);

	return 0;
}
