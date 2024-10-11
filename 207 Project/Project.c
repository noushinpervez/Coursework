#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// a structure that contains different attributes of node
struct node
{
    char foodName[50];
    int quantity;
    float price;
    int data;
    struct node *next;
    struct node *prev;
};

// global struct pointers
struct node *heada = NULL, *taila = NULL; // for admin
struct node *headc = NULL, *tailc = NULL; // for customer
struct node *head_s; // for total sales
struct node *newNode;

// prints main menu
void mainMenu()
{
    printf("\n\t\t\t\t\t\t\t===========================================================================\n");
    printf("\t\t\t\t\t\t\t\t\tWelcome to Fast-food Shop Management System\n");
    printf("\t\t\t\t\t\t\t===========================================================================\n\n\n");
    printf("\t\t\t\t\t\t\tAdmin Section- 1\n");
    printf("\t\t\t\t\t\t\tCustomer Section- 2\n");
    printf("\t\t\t\t\t\t\tExit- 3\n\n");
    printf("\t\t\t\t\t\t\tEnter Your Choice: ");
}

// deletes a node from the linked list
struct node *del(int data, struct node *head, struct node *tail)
{
    if(head == NULL)
        printf("\n\t\t\t\t\t\t\tList is empty!\n");
    else
    {
        struct node *temp;

        if(data == head->data)
        {
            temp = head;
            head = head->next;

            if(head != NULL)
                head->prev = NULL;

            free(temp);
        }
        else if(data == tail->data)
        {
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
        else
        {
            temp = head;
            while(data != temp->data)
                temp = temp->next;

            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            free(temp);
        }
    }

    return head;
}

// displays the linked list
void displayList(struct node *head)
{
    struct node *temp1 = head;

    if(temp1 == NULL)
        printf("\n\t\t\t\t\t\t\tList is empty!\n\n");
    else
    {
        printf("\n");
        while(temp1 != NULL)
        {
            if(temp1->quantity == 0)
                printf("\t\t\t\t\t\t\t%d\t%s\t%0.2f\n", temp1->data, temp1->foodName, temp1->price);
            else
                printf("\t\t\t\t\t\t\t%d\t%s\t%d\t%0.2f\n", temp1->data, temp1->foodName, temp1->quantity,temp1->price);

            temp1 = temp1->next;
        }
        printf("\n");
    }
}

// logs in to admin menu
int login()
{
    printf("\n\t\t\t\t\t\t\t--------------------Login--------------------\n");
    char username[15];
    char password[15];
    int i;

    printf("\n\t\t\t\t\t\t\tEnter the username: ");
    scanf("%s", &username);

    printf("\t\t\t\t\t\t\tEnter the password: ");
    for(i = 0; i < 3; i++)
    {
        password[i] = getch();
        printf("*");
    }
    password[i] = '\0';

    if(strcmp(username, "food") == 0 && strcmp(password, "123") == 0)
        return 1;
    else
        return 0;
}

// prints admin menu
void adminMenu()
{
    printf("\n\t\t\t\t\t\t\t1. Display order menu\n");
    printf("\t\t\t\t\t\t\t2. Add a new item in the order menu\n");
    printf("\t\t\t\t\t\t\t3. Delete an item from the order menu\n");
    printf("\t\t\t\t\t\t\t4. Update an item in the order menu\n");
    printf("\t\t\t\t\t\t\t5. View total sales\n");
    printf("\t\t\t\t\t\t\t6. Back To Main Menu\n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice: ");
}

// creates a node for admin's linked list
struct node *createAdmin(struct node *head, int data, char foodName[50], float price)
{
    newNode = (struct node *)malloc(sizeof(struct node)); // allocates memory

    newNode->data = data;
    newNode->price = price;
    newNode->quantity = 0;
    strcpy(newNode->foodName, foodName);
    newNode->next = NULL;
    newNode->prev = NULL;

    struct node *temp = head;

    if(temp == NULL) // to check whether the node is the first node of linked list or not
        heada = taila = newNode;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = taila;
        taila = newNode;
    }

    return heada;
}

// deletes food item from admin's linked list
int deleteAdmin()
{
    printf("\n\t\t\t\t\t\t\tEnter the food ID of the food item to be deleted: ");

    int num;
    scanf("%d", &num);

    struct node *temp = heada;

    while(temp != NULL)
    {
        if(temp->data == num)
        {
            heada = del(num, heada, taila);
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

// updates an food item in the linked list
int update()
{
    printf("\n\t\t\t\t\t\t\tEnter the food ID of the food item to be updated: ");

    int num;
    char tmp;
    scanf("%d", &num);

    struct node *temp = heada;

    while(temp != NULL)
    {
        if(temp ->data == num)
        {
            printf("\t\t\t\t\t\t\tEnter new food item name: ");
            scanf("%c", &tmp);
            scanf("%[^\n]", temp->foodName);
            printf("\t\t\t\t\t\t\tEnter new price: ");
            scanf("%f", &temp->price);
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

// keeps track of total sales
struct node *totalSales(int data, int quantity)
{
    newNode = (struct node *)malloc(sizeof(struct node));

    int flag = 0;
    struct node *temp1 = heada;

    while(temp1->data != data)
        temp1 = temp1->next;

    newNode->data = data;
    newNode->price = quantity * (temp1->price);
    newNode-> quantity = quantity;
    strcpy(newNode->foodName, temp1->foodName);
    newNode->next = NULL;

    struct node *temp = head_s;

    if(temp == NULL)
        head_s = newNode;
    else
    {
        while(temp->next != NULL)
        {
            if(temp->data == data)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }

        if(flag == 1) // if data already exists then increment data
        {
            temp->quantity += newNode->quantity;
            temp->price += newNode->price;
        }
        else
            temp->next = newNode;
    }

    return head_s;
}

// calculates total sales in a day
void calculate()
{
    struct node *temp = headc;
    while(temp != NULL)
    {
        head_s = totalSales(temp->data, temp->quantity); // creates new node
        temp = temp->next;
    }
}

// displays total sales
void total()
{
    struct node *temp = head_s;
    float total_sales = 0;

    displayList(head_s);

    while(temp != NULL)
    {
        total_sales += temp->price;
        temp = temp->next;
    }
    printf("\t\t\t\t\t\t\tTotal sales: %0.02f\n", total_sales);
}

// prints customer menu
void customerMenu()
{
    printf("\n\t\t\t\t\t\t\t1. Place your order\n");
    printf("\t\t\t\t\t\t\t2. View your ordered items\n");
    printf("\t\t\t\t\t\t\t3. Delete an item from ordered items\n");
    printf("\t\t\t\t\t\t\t4. Display final bill\n");
    printf("\t\t\t\t\t\t\t5. Back To Main Menu \n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice: ");
}

// creates a node for customer's linked list
struct node *createCustomer(struct node *head, int data, int quantity)
{
    newNode = (struct node *)malloc(sizeof(struct node));

    struct node *temp1 = heada;
    int flag = 0;

    while(temp1 != NULL) // to check whether the data exists or not
    {
        if(temp1->data == data)
        {
            flag = 1;
            break;
        }
        temp1 = temp1->next;
    }

    if(flag == 1) // if the data exists in order menu then new node will be created
    {
        newNode->data = data;
        newNode->price = quantity * (temp1->price);
        newNode-> quantity = quantity;
        strcpy(newNode->foodName, temp1->foodName);
        newNode->next = NULL;
        newNode->prev = NULL;

        struct node *temp = head;

        if(temp == NULL)
            headc = tailc = newNode;
        else
        {
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = tailc;
            tailc = newNode;
        }
    }
    else
        printf("\n\t\t\t\t\t\t\tThis item is not present in the menu!\n");

    return headc;
}

// deletes food item from customer's linked list
int deleteCustomer()
{
    struct node *temp = headc;

    printf("\n\t\t\t\t\t\t\tEnter the food id of the food item to be deleted: ");

    int num;
    scanf("%d", &num);

    while(temp != NULL)
    {
        if(temp->data == num)
        {
            headc = del(num, headc, tailc);
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

// deletes entire linked list
struct node *deleteList(struct node *head)
{
    if(head == NULL)
        return NULL;
    else
    {
        struct node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
            free(temp->prev);
        }
        free(temp);
        head = NULL;
    }

    return head;
}

// displays the total bill by a customer
void displayBill()
{
    displayList(headc);

    struct node *temp = headc;
    float total_price = 0;

    while(temp != NULL)
    {
        total_price += temp->price;
        temp = temp->next;
    }
    printf("\t\t\t\t\t\t\tTotal price: %0.02f\n", total_price);
}

// displays admin section options and interface
void admin()
{
    while(1)
    {
        if(login())
        {
            printf("\n\t\t\t\t\t\t\tLogin Success!\n\n");
            break;
        }
        else
            printf("\n\t\t\t\t\t\t\tPlease try again!\n\n");
    }

    printf("\n\t\t\t\t\t\t\t----------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\tAdmin Section\n");
    printf("\t\t\t\t\t\t\t----------------------------------------------\n");

    while(1) // continues executing until admin chooses to exit
    {
        adminMenu();

        int opt;
        scanf("%d", &opt);

        if(opt == 6)
            break;

        switch(opt)
        {
            case 1:
                printf("\n\t\t\t\t\t\t\t   ### Order menu ###\n");
                displayList(heada);
                break;
            case 2:
                printf("\n\t\t\t\t\t\t\tEnter the food ID of the food item: ");

                int num, flag = 0;
                char name[50];
                char tmp;
                float price;
                scanf("%d", &num);

                struct node *temp = heada;

                while(temp != NULL)
                {
                    if(temp->data == num)
                    {
                        printf("\n\t\t\t\t\t\t\tFood item with given food ID already exists!!\n\n");
                        flag = 1;
                        break;
                    }
                    temp = temp->next;
                }

                if(flag == 1)
                    break;

                printf("\t\t\t\t\t\t\tEnter food item name: ");
                scanf("%c", &tmp);
                scanf("%[^\n]", name);
                printf("\t\t\t\t\t\t\tEnter price: ");
                scanf("%f", &price);

                heada = createAdmin(heada, num, name, price);
                printf("\n\t\t\t\t\t\t\tNew food item added to the list!\n");
                printf("\n\t\t\t\t\t\t\t### Updated list of food items menu ###\n");
                displayList(heada);
                break;
            case 3:
                if(heada == NULL)
                    printf("\n\t\t\t\t\t\t\tList is empty!\n\n");
                else
                {
                    if(deleteAdmin())
                    {
                        printf("\n\t\t\t\t\t\t\t### Updated list of food items menu ###\n");
                        displayList(heada);
                    }
                    else
                        printf("\n\t\t\t\t\t\t\tFood item with given ID doesn't exist!\n\n");
                }

                break;
            case 4:
                if(heada == NULL)
                    printf("\n\t\t\t\t\t\t\tList is empty!\n\n");
                else
                {
                    if(update())
                    {
                        printf("\n\t\t\t\t\t\t\t### Updated list of food items menu ###\n");
                        displayList(heada);
                    }
                    else
                        printf("\n\t\t\t\t\t\t\tFood item with given ID doesn't exist!\n\n");
                }

                break;
            case 5:
                printf("\n\t\t\t\t\t\t\t   ### Total Sales ###\n");
                total();
                break;

            default:
                printf("\n\t\t\t\t\t\t\tWrong Input! PLease choose valid option\n");
                break;
        }
    }
}

// displays customer section options and interface
void customer()
{
    int flag = 0, j = 1;
    char ch;

    printf("\n\t\t\t\t\t\t\t----------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\tCustomer Section\n");
    printf("\t\t\t\t\t\t\t----------------------------------------------\n");

    while(1)
    {
        customerMenu();

        int opt;
        scanf("%d", &opt);

        if(opt == 5)
            break;

        switch(opt)
        {
            case 1:
                displayList(heada);

                printf("\n\t\t\t\t\t\t\tEnter the food ID of the item you want to order: ");
                int n;
                scanf("%d", &n);
                printf("\t\t\t\t\t\t\tEnter quantity: ");
                int quantity;
                scanf("%d", &quantity);

                headc = createCustomer(headc, n, quantity);
                break;
            case 2:
                printf("\n\t\t\t\t\t\t\t### List of ordered items ###\n");
                displayList(headc);
                break;
            case 3:
                if(headc == NULL)
                    printf("\n\t\t\t\t\t\t\tList is empty!\n\n");
                else
                {
                    if(deleteCustomer())
                    {
                        printf("\n\t\t\t\t\t\t\t### Updated list of your ordered food items ###\n");
                        displayList(headc);
                    }
                    else
                        printf("\n\t\t\t\t\t\t\tFood item with given ID doesn't exist!\n");
                }

                break;
            case 4:
                calculate();
                printf("\n\t\t\t\t\t\t\t   ### Final Bill ###\n");
                displayBill();
                printf("\n\n\t\t\t\t\t\t\t----------Thank you----------\n");

                headc = deleteList(headc);
                printf("\t\t\t\t\t\t\tPress any key to return to main menu:\n\t\t\t\t\t\t\t");
                fflush(stdin);
                ch = fgetc(stdin);
                flag = 1;
                break;

            default:
                printf("\n\t\t\t\t\t\t\tWrong Input! PLease choose valid option\n");
                break;
        }
        if(flag == 1)
            break;
    }
}

int main()
{
    // creates a linked list of food items
    heada = createAdmin(heada, 1, "Chicken Sub Sandwich", 159);
    heada = createAdmin(heada, 2, "Smokey Chicken Cheese Sandwich", 169);
    heada = createAdmin(heada, 3, "Chicken Cheese Burger", 185);
    heada = createAdmin(heada, 4, "Beef Cheese Burger", 195);
    heada = createAdmin(heada, 5, "Naga Wings", 180);
    heada = createAdmin(heada, 6, "Chicken Tenders", 175);
    heada = createAdmin(heada, 7, "Masala Potatoes", 89);
    heada = createAdmin(heada, 8, "Hot Chips", 89);
    heada = createAdmin(heada, 9, "Choco Cold Coffee", 75);
    heada = createAdmin(heada, 10, "Peached Tea", 110);

    while(1)
    {
        mainMenu();
        int choice;
        scanf("%d", &choice);

        if(choice == 3)
        {
            printf("\n\n\t\t\t\t\t\t\t----------Thank you----------\n");
            break;
        }

        switch(choice)
        {
            case 1:
                admin();
                break;
            case 2:
                customer();
                break;
            case 3:
                break;

            default:
                printf("\n\t\t\t\t\t\t\tWrong Input! PLease choose valid option\n");
                break;
        }
    }
}
