#include "start.h"

int main()
{
    char option;
    option = display_menu();
    perform_action(option);
    return 0;
}