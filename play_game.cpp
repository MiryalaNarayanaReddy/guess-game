#include "play_game.h"

void play_game()
{
    int user_choice;
    std::cout << "The range is \"one to upperlimit\"\n"
              << "Choose the upper limit: ";
    std::cin >> user_choice;
    std::cout<<"you have 20 choices to guess\n";
    const int secret_number = rand() % (user_choice + 1);
    std::cout << "guess the number: " << std::endl;
    std::vector<int> guess;
    int curr_guess;
    int flag = 0;
    while (true)
    {
        std::cin >> curr_guess;
        guess.push_back(curr_guess);
        if (curr_guess == secret_number)
        {
            break;
        }
        else if (curr_guess < secret_number)
        {
            std::cout << "too low" << std::endl;
        }
        else
        {
            std::cout << "too high" << std::endl;
        }
        if (guess.size() == 20)
        {
            std::cout << "*******LIMIT EXCEEDED*****\n"
                      << "correct answer: " << secret_number << "\n"
                      << "GAME OVER\n";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        std::cout << "you won! in " << guess.size();
        if (guess.size() > 1)
            std::cout << "guesses" << std::endl;
        else
            std::cout << "guess" << std::endl;
        print_guess(guess);
        update_highscore(guess.size());
    }
}

void print_guess(std::vector<int> guess)
{
    std::cout << "your guesses:\n";
    for (int n : guess)
    {
        std::cout << n << "\t";
    }
    std::cout << std::endl;
}

void update_highscore(int curr_score)
{
    int highscore;
    std::ifstream file;
    file.open("high_score.txt");
    file >> highscore;
    file.close();
    if (highscore > curr_score)
    {
        std::cout << "NEW HIGH SCORE: " << curr_score << std::endl;
        std::ofstream file;
        file.open("high_score.txt");
        file << curr_score;
        file.close();
    }
}