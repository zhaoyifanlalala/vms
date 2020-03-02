//模拟售货机项目
#include <stdio.h>

// 管理员默认密码1110
#define PASSWORD 1110
// 最大库存数为10
#define MAXSTOCK 10

/*
投币口
*/
int money;
/*
出货口
*/
char sale = '=';
//int choice;
/*
商品名称
*/
char goods[5][20] = {"Juice", "Cola", "Tea", "Water", "Coffee"};
/*
商品代码
*/
char goodsnum[5] = {'A', 'B', 'C', 'D', 'E'};
/*
商品单价
*/
int price[5] = {10, 6, 5, 8, 7};
/*
商品库存
*/
int stock[5] = {5, 1, 2, 1, 9};
/*
商品状态判定,O 可买，X无库存
*/
char lights_up(int money, int price[], int stock[])
{
    char status = ' ';
    if (money >= *price)
        status = 'O';
    if (*stock == 0)
        status = 'X';
    return status;
}
int pwd = PASSWORD;
/*
收入
*/
int income;
/*
标识位 ，1显示main（），0 不显示
*/
int n = 1;

// 函数定义
// 主页面
void mainPage();
// 顾客选项页
void choicePage();
// 商品信息页
void productInfornation();
// 投入硬币页
void insertCoinPage();
// 投入硬币页逻辑
void insertCoin(int coin);
// 商品选项页
void productchiocePage();
// 商品选项页逻辑
void productchoices(int productchoice);
// 管理员页面菜单
void adminPageChoice();
// 管理员页面
void adminPage();
// 查看机器状态页
void Machinestatus();
// 查看机器状态页逻辑
void statusOfMachines();
// 取出盈利金额页面
void withdrawnPage();
// 取出盈利金额页面逻辑
void withdrawn();
// 补充库存页面
void refillPage();
// 补充库存页面逻辑
void refill(int whichgoods);
// 修改商品信息页面
void changegoodsPage();
// 修改商品信息页面逻辑
void changeGoods(int changegoods);
// 商品添加函数
void insertGoods(int changegoods, char goodsname[20], int goodsprice);





void mainPage()
{
    printf("*---------------------------*\n");
    printf("|     Vending   Machine     |\n");
    printf("*---------------------------*\n");
    printf("|   %c    %c    %c    %c    %c   |\n", goodsnum[0], goodsnum[1], goodsnum[2], goodsnum[3], goodsnum[4]);
    printf("|  ¥%d  ¥ %d  ¥ %d  ¥ %d  ¥ %d  |\n", price[0], price[1], price[2], price[3], price[4]);
    printf("|  [%c]  [%c]  [%c]  [%c]  [%c]  |\n", lights_up(money, &price[0], &stock[0]), lights_up(money, &price[1], &stock[1]), lights_up(money, &price[2], &stock[2]), lights_up(money, &price[3], &stock[3]), lights_up(money, &price[4], &stock[4]));
    printf("*---------------------------*\n");
    printf("|                    [¥%2d]  |\n", money);
    printf("|                           |\n");
    printf("|           [=%c=]           |\n", sale);
    printf("*---------------------------*\n");
}
// 顾客选项页
void choicePage()
{
    puts("\n");
    printf("What would you like to do?\n");
    printf(" 1. Read product information\n");
    printf(" 2. Insert coin\n");
    printf(" 3. Press product button\n");
    printf(" 4. Press return button\n");
    printf(" 9. Open service menu (code required)\n");
    printf(" 0. Quit\n\n");
}
// 商品信息页
void productInfornation()
{
    printf("(1) The displayed products are:\n");
    printf("A. %s (¥%2d)\n", goods[0], price[0]);
    printf("B. %s (¥%2d)\n", goods[1], price[1]);
    printf("C. %s (¥%2d)\n", goods[2], price[2]);
    printf("D. %s (¥%2d)\n", goods[3], price[3]);
    printf("E. %s (¥%2d)\n", goods[4], price[4]);
    n = 0;
}
// 投入硬币页
void insertCoinPage()
{
    printf("(2) Which coin would you like to insert?\n");
    printf("1. ¥1\n");
    printf("2. ¥2\n");
    printf("3. ¥5\n");
    printf("4. ¥10\n");
    printf("0. Go back\n\n");
}
// 投入硬币页逻辑
void insertCoin(int coin)
{
    switch (coin)
    {
    case 1:
        money = money + 1;
        printf("You have inserted ¥1.\n");
        break;
    case 2:
        money = money + 2;
        printf("You have inserted ¥2.\n");
        break;
    case 3:
        money = money + 5;
        printf("You have inserted ¥5.\n");
        break;
    case 4:
        money = money + 10;
        printf("You have inserted ¥10.\n");
        break;
    case 0:
        printf("Going back!\n");
    default:
        printf("Invalid choice!\n");
        break;
    }
}
// 商品选项页
void productchiocePage()
{
    printf("(3) Which product button would you like to press?\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("3. C\n");
    printf("4. D\n");
    printf("5. E\n");
    printf("0. Go back\n\n");
}
// 商品选项页逻辑
void productchoices(int productchoice)
{
    switch (productchoice)
    {
    case 1:
        money -= price[0];
        sale = goodsnum[0];
        income += price[0];
        printf("You have pressed button A.\n");
        break;
    case 2:
        money -= price[1];
        sale = goodsnum[1];
        income += price[1];
        printf("You have pressed button B.\n");
        break;
    case 3:
        money -= price[2];
        sale = goodsnum[2];
        income += price[2];
        printf("You have pressed button C.\n");
        break;
    case 4:
        money -= price[3];
        sale = goodsnum[3];
        income += price[3];
        printf("You have pressed button D.\n");
        break;
    case 5:
        money -= price[4];
        sale = goodsnum[4];
        income += price[4];
        printf("You have pressed button E.\n");
        break;
    case 0:
        printf("Going back!\n");
    default:
        printf("Invalid choice!\n");
        break;
    }
}
// 管理员页面菜单
void adminPageChoice()
{
    printf("Correct code!\n");
    printf("(9) What would you like to do?\n");
    printf("1. Inspect machine status\n");
    printf("2. Withdraw all money\n");
    printf("3. Refill product\n");
    printf("4. Change product\n");
    printf("0. Go back\n\n");
    printf("Your choice:");
}
// 管理员页面
void adminPage()
{
    n = 0;
    int password;
    printf("(9) Opening service menu. Access code is required.\n");
    printf("Enter access code:");
    scanf("%d", &password);
    if (password != pwd)
    {
        printf("Incorrect code!\n");
    }
    else
    {
        int adminchoice;
        adminPageChoice();
        scanf("%d", &adminchoice);
        if (adminchoice == 0)
        {
            printf("Going back!\n");
        }
        switch (adminchoice)
        {
        case 1:
            Machinestatus();
            break;
        case 2:
            withdrawnPage();
            break;
        case 3:
            refillPage();
            int whichgoods;
            printf("Your choice:\n");
            scanf("%d", &whichgoods);
            refill(whichgoods);
            break;
        case 4:
            changegoodsPage();
            int changegoods;
            char goodsname[20];
            int goodsprice;
            printf("Your choice:\n");
            scanf("%d", &changegoods);
            changeGoods(changegoods);
            printf("Enter new product name:");
            scanf("%s",goodsname);
            printf("Enter new product price:");
            scanf("%d",&goodsprice);

        default:
            printf("Invalid choice!\n");
            break;
        }
        mainPage();
    }
}
// 查看机器状态页
void Machinestatus()
{
    printf("(9-1)Machine status\n");
    statusOfMachines();
}
// 查看机器状态页逻辑
void statusOfMachines()
{
    printf("Amount of revenue: ¥%d\n", income);
    printf("Amount of inserted coins: ¥%d\n", money);
    printf("A. %s ($%2d) (%d left)\n", goods[0], price[0], stock[0]);
    printf("B. %s ($%2d) (%d left)\n", goods[1], price[1], stock[1]);
    printf("C. %s ($%2d) (%d left)\n", goods[2], price[2], stock[2]);
    printf("D. %s ($%2d) (%d left)\n", goods[3], price[3], stock[3]);
    printf("E. %s ($%2d) (%d left)\n", goods[4], price[4], stock[4]);
}
// 取出盈利金额页面
void withdrawnPage()
{
    printf("(9-2)All money is being withdrawn\n");
    withdrawn();
}
// 取出盈利金额页面逻辑
void withdrawn()
{
    printf("¥%d is withdrawn\n", income + money);
}
// 补充库存页面
void refillPage()
{
    printf("(9-3) Which product would you like to refill?\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("3. C\n");
    printf("4. D\n");
    printf("5. E\n");
    printf("0. Go back\n");
}
// 补充库存页面逻辑
void refill(int whichgoods)
{
    switch (whichgoods)
    {
    case 1:
        stock[0] = MAXSTOCK;
        printf("You have refilled product A to full.\n");
        break;
    case 2:
        stock[1] = MAXSTOCK;
        printf("You have refilled product B to full.\n");
        break;
    case 3:
        stock[2] = MAXSTOCK;
        printf("You have refilled product C to full.\n");
        break;
    case 4:
        stock[3] = MAXSTOCK;
        printf("You have refilled product D to full.\n");
        break;
    case 5:
        stock[4] = MAXSTOCK;
        printf("You have refilled product E to full.\n");
        break;
    }
}
// 修改商品信息页面
void changegoodsPage()
{
    printf("(9-4) Which product would you like to change?\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("3. C\n");
    printf("4. D\n");
    printf("5. E\n");
    printf("0. Go back\n");
}
// 修改商品信息页面逻辑
void changeGoods(int changegoods)
{
    switch (changegoods)
    {
    case 1:
        printf("You are changing product A.\n");
        break;
    case 2:
        printf("You are changing product B.\n");
        break;
    case 3:
        printf("You are changing product C.\n");
        break;
    case 4:
        printf("You are changing product D.\n");
        break;
    case 5:
        printf("You are changing product E.\n");
        break;
    }
}
// 商品添加函数
void insertGoods(int changegoods, char goodsname[20], int goodsprice){
    changegoods -= 1;
    goods[changegoods][20] = goodsname[20];
    price[changegoods] = goodsprice;
    stock[changegoods] = MAXSTOCK;
    printf("The new product E has been filled to full.\n");
}

int main()
{
    int choice;
    int coin;
    int productchoice;
    int choice4;
    int choice9;
    int choice9_3;
    int choice9_4;

    while (1)
    {
        if (n == 1)
            mainPage();
        choicePage();
        printf("Your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            productInfornation();
            break;
        case 2:
            insertCoinPage();
            printf("Your choice:");
            scanf("%d", &coin);
            insertCoin(coin);
            break;

        case 3:
            productchiocePage();
            printf("Your choice:");
            scanf("%d", &productchoice);
            productchoices(productchoice);
            break;
        case 4:
            printf("(4) Return button is pressed.\n");
            printf("¥%2d has been returned.\n", money);
            money = 0;
            break;
        case 9:
            adminPage();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}