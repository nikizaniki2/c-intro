#include <stdio.h>
#include <stdlib.h>

//Used for strcmp()
#include <string.h>


#define book_amount 5

struct book
{
    char name[20];
    char author[20];
    int release_date;
    double price;
};

void fill_info(struct book books[book_amount]){
    for (int i=0;i<book_amount;i++){
        printf("Name of book %d : ", i+1);
        scanf("%s", books[i].name);
        printf("\nAuthor of the book: ");
        scanf("%s", books[i].author);
        printf("\nRelease date: ");
        scanf("%d", &books[i].release_date);
        printf("\nBook price: ");
        scanf("%lf", &books[i].price);
        printf("\n");
    }
}

//Can be hard coded to be 2005 easily.
void display_book_by_year(struct book books[book_amount], int year){
    for(int i=0; i<book_amount; i++){
        if(books[i].release_date >= year){
            printf("\n %s, %s, %d, %lf", books[i].name, books[i].author, books[i].release_date, books[i].price);
        }
    }
}

void search_book_by_author(struct book books[book_amount]){
    char search_by[20];
    printf("\nName of author: ");
    scanf("%s", search_by);

    for(int i=0; i<book_amount; i++){
        if(!strcmp(books[i].author, search_by)){
            printf("\n %s, %s, %d, %lf", books[i].name, books[i].author, books[i].release_date, books[i].price);
        }
    }
}

int main()
{
    struct book my_books[book_amount];
    fill_info(my_books);

    int year = 2005;
    display_book_by_year(my_books, year);

    search_book_by_author(my_books);

    return 0;
}
