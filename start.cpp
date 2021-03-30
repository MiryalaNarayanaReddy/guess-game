#include "start.h"
#include "play_game.h"

char display_menu()
{
    char selection;
    std::cout << "~~~~~MENU~~~~~\n"
              << std::endl;
    std::cout << "PLAY        P" << std::endl
              << "HIGH_SCORE  H" << std::endl
              << "QUIT        Q"<< std::endl
              << std::endl;

    std::cout << "selection: ";
    std::cin >> selection;
    return selection;
}
void perform_action(char selection)
{
    switch (selection)
    {
    case 'P':
        play_game();
        display_menu();
        break;
    case 'H':
        display_highscore();
        break;
    case 'Q':
        std::cout << "Ok!!...that's alright..\nThank you." << std::endl;
        break;
    default:
        std::cout << "INVALID INPUT\n";
        break;
    }
}
void display_highscore()
{
    int highscore;
    std::ifstream file;
    file.open("high_score.txt");
    file >> highscore;
    std::cout << "HIGH SCORE: " << highscore << std::endl;
    file.close();
}
