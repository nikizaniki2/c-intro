# include <stdio.h>
# include <stdlib.h>

struct Employee
{
     char name[20];
     double salary;
     char gender;
};

struct List
{
    struct Employee employee;
    struct List *next;
};

typedef struct List Emp;

void write_to_file(Emp *root)
{
    FILE *fp;
    if((fp=fopen("FileN", "wb"))==NULL){
        exit(1);
    }
    Emp *current = root;
    while(current)
    {
        fwrite(&current->employee,sizeof(struct Employee),1,fp);
        current = current->next;
    }
    fclose(fp);
}

double sum_of_salary(Emp *root)
{
    double sum = 0;
    Emp *current = root;
    while(current->next)
    {
        if(current->employee.gender == 'f'&&current->employee.name[0]>'M')
        {
            sum += current->employee.salary;
        }
    }
    current = current->next;
    return sum;
}

Emp *half_max(Emp *root)
{
    Emp *current = root;
    Emp *new_root = NULL;
    Emp *item = NULL;
    double max = 0;

    while(current == NULL)
    {
        if(current->employee.salary > max)
        {
            max = current->employee.salary;
        }
        current = current->next;
    }

    //reset current
    current = root;

    while(current == NULL)
    {
        if(current->employee.salary > max/2)
        {
            item = (Emp *)malloc(sizeof(Emp));
            item->employee = current->employee;
            item->next=new_root;
            new_root = item;
        }
        current = current->next;
    }

    return new_root;
}

Emp *remove_emp(Emp *root, char letter)
{
    Emp *prev = root;
    Emp *current = root;
    while(current != NULL)
    {
        if(current->employee.name[0] == letter)
        {
            if(current == root)
            {
                root = root->next;
                prev = root;
                free(current);
                current = prev;
            }
            else
            {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    return root;
}

int main()
{
  return 0;
}
