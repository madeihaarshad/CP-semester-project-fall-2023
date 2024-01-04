#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<windows.h>
using namespace std;
//Quest 1

struct Player {
    string name;
    int Hp;
    int exp;
    int heal;
};

struct Yoshimitsu {
    int yoshimitsuHp;
    int yoshimitsuExp;
    string yoshimitsuName;
};

void combat(Player& player, Yoshimitsu& yoshimitsu);
void createCharacter(Player& player);
void displayCharacter(const Player& player);
Yoshimitsu createYoshimitsuCharacter();
void displayYoshimitsu(const Yoshimitsu& yoshimitsu);
int inventory();
string yoshimitsuAttackName(int attack);



void createCharacter(Player& player) {
    cout << "Enter your name: ";
    cin >> player.name;

    player.Hp = 100;
    player.exp = 0;

    for (int i = 0; i < 3; i++) {
        cout << "Creating Character" << string(i + 1, '.') << endl;
        Sleep(2000);
        system("cls");
    }
}

void displayCharacter(const Player& player) {
    cout << "\nName: " << player.name << "\nHealth: " << player.Hp << "\nExperience: " << player.exp << endl;
    Sleep(2000);
    system("cls");
}

Yoshimitsu createYoshimitsuCharacter() {
    Yoshimitsu yoshimitsu;
    yoshimitsu.yoshimitsuName = (rand() % 2 == 0) ? "Sorcerer" : "Enchanter";
    yoshimitsu.yoshimitsuHp = 100;
    yoshimitsu.yoshimitsuExp = 0;

    for (int i = 0; i < 3; i++) {
        cout << "Creating Yoshimitsu Character" << string(i + 1, '.') << endl;
        Sleep(2000);
        system("cls");
    }
    return yoshimitsu;
}

void displayYoshimitsu(const Yoshimitsu& yoshimitsu) {
    cout << "\nName: " << yoshimitsu.yoshimitsuName << "\nHealth: " << yoshimitsu.yoshimitsuHp << "\nExperience: " << yoshimitsu.yoshimitsuExp << endl;
    Sleep(1500);
    system("cls");
}

int inventory() {
    int choice;
    cout << "Choose your inventory to attack on Yoshimitsu (1-7)\n 1. Left punch\n 2. Right punch\n 3. Right kick\n 4. Left kick\n 5. Flash kick\n 6. Flying jump kick\n 7. Counter hit\n ";
    cin >> choice;
    if (choice < 1 || choice > 7) {
        cout << "Invalid number. Please try again!\n";
        return inventory();
    }

    return choice;
}

string yoshimitsuAttackName(int attack) {
    switch (attack) {
    case 1:
        return "Left punch";
    case 2:
        return "Right punch";
    case 3:
        return "Right kick";
    case 4:
        return "Left kick";
    case 5:
        return "Flash kick";
    default:
        return "Invalid Attack";
    }
}

void combat(Player& player, Yoshimitsu& yoshimitsu) {
    int playerDamage = 0;
    int yoshimitsuDamage = 0;

    for (int round = 0; round < 4; ++round) {
        int playerChoice = inventory();
        int damage = rand() % 60 + 1;

        cout << "Round " << round + 1 << ": Player's Choice - " << playerChoice << ", Damage: " << damage << "\n";

        playerDamage += damage;
    }

    for (int round = 0; round < 4; ++round) {
        int attack = rand() % 5 + 1;
        int damage = rand() % 50 + 1;

        cout << "Round " << round + 1 << ": Yoshimitsu's Attack - " << yoshimitsuAttackName(attack) << ", Damage: " << damage << "\n";

        yoshimitsuDamage += damage;
    }

    cout << "Total damage given by Yoshimitsu: " << yoshimitsuDamage << "\n";
    cout << "Total damage given to Yoshimitsu: " << playerDamage << "\n";

    if (yoshimitsuDamage > playerDamage) {
        cout << "Sorry! You lost the game. Yoshimitsu is the winner...!\n";
    }
    else if (yoshimitsuDamage < playerDamage) {
        cout << "Congratulations! You Won....!\n";
    }
    else {
        cout << "Tie....!\n";
    }
}
//Quest 2

struct CharacterCreation {
    string name;
    string role;
    int health = 100;
    int experiencepoints = 0;
    bool hasTreasureMap = false;
    bool hasTreasureKey = false;
};
void displayRiverQuestOptions() {
    cout << "River Quest Options:\n";
    cout << "1. Cross the river\n";
    cout << "2. Fight the dragon\n";
    cout << "3. Exit game\n";
}
void riverQuestQuest1(CharacterCreation& player) {

    cout << "You find yourself at the edge of a fast-flowing river with a dragon behind you.\n";

    while (player.health > 0) {
        int questOption;
        cout << "Choose an option (1-3):\n";
        displayRiverQuestOptions();
        cin >> questOption;

        switch (questOption) {

        case 1: {
            cout << "You chose to cross the river.\n";

            int riverEquipmentChoice;
            cout << "Choose your equipment for crossing the river (1-4):\n";
            cout << "1. Boat\n";
            cout << "2. Swim\n";
            cout << "3. Raft\n";
            cout << "4. Jet Ski\n";
            cin >> riverEquipmentChoice;

            cout << "Uh-oh! A shark is approaching you in the river!\n";

            int sharkAction;
            cout << "Choose your action to deal with the shark (1-3):\n";
            cout << "1. Fight the shark\n";
            cout << "2. Dive underwater\n";
            cout << "3. Climb onto a rock\n";
            cin >> sharkAction;

            if (sharkAction == 1) {
                cout << "You chose to fight the shark.\n";

                // Give the player a weapon
                int playerWeaponChoice;
                cout << "Choose your weapon to fight the shark (1-3):\n";
                cout << "1. Spear\n";
                cout << "2. Harpoon\n";
                cout << "3. Fists\n";
                cin >> playerWeaponChoice;

                int sharkStrength = rand() % 50 + 10;
                int playerStrength;

                switch (playerWeaponChoice) {
                case 1:
                    cout << "You fight the shark with a spear.\n";
                    playerStrength = rand() % 40 + 20;
                    break;
                case 2:
                    cout << "You use a harpoon to attack the shark.\n";
                    playerStrength = rand() % 35 + 25;
                    break;
                case 3:
                    cout << "You try to fight the shark with your fists.\n";
                    playerStrength = rand() % 30 + 30;
                    break;
                default:
                    cout << "Invalid weapon choice.\n";
                    return;
                }

                if (playerStrength > sharkStrength) {
                    cout << "You bravely fought the shark and managed to defeat it. Congratulations!\n";
                    player.experiencepoints += 30;
                    cout << "With the shark defeated, you make it to the other side of the river.\n";
                }
                else {
                    cout << "The shark was too strong for you. It bit you, and you lost some health.\n";
                    player.health -= 20;
                }
            }
            else if (sharkAction == 2) {
                cout << "You chose to dive underwater.\n";

                // Challenge: Underwater obstacles
                int underwaterChallenge = rand() % 3;

                if (underwaterChallenge == 0) {
                    cout << "You encounter a school of friendly fish. They guide you safely across the river.\n";
                    player.experiencepoints += 40;
                    cout << "You gained 40 experience points.\n";
                }
                else if (underwaterChallenge == 1) {
                    cout << "You face a strong underwater current but manage to navigate through it.\n";
                    player.experiencepoints += 35;
                    cout << "You gained 35 experience points.\n";
                }
                else {
                    // Randomly choose a riddle
                    int randomRiddle = rand() % 3;

                    if (randomRiddle == 0) {
                        cout << "A mysterious voice asks you: 'I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?'\n";
                    }
                    else if (randomRiddle == 1) {
                        cout << "The water spirit challenges you with a riddle: 'The more you take, the more you leave behind. What am I?'\n";
                    }
                    else {
                        cout << "A mermaid appears and poses a riddle: 'I have cities, but no houses. I have mountains, but no trees. I have water, but no fish. What am I?'\n";
                    }

                    string riddleAnswer;
                    cout << "Your answer: ";
                    cin.ignore();
                    getline(cin, riddleAnswer);

                    bool riddleCorrect = false;

                    // Check the answer based on the randomly chosen riddle
                    if (randomRiddle == 0 && riddleAnswer == "an echo") {
                        riddleCorrect = true;
                    }
                    else if (randomRiddle == 1 && riddleAnswer == "footsteps") {
                        riddleCorrect = true;
                    }
                    else if (randomRiddle == 2 && riddleAnswer == "a map") {
                        riddleCorrect = true;
                    }

                    if (riddleCorrect) {
                        cout << "Correct! You solved the riddle, and the mermaid allows you to pass. You gained 30 experience points.\n";
                        player.experiencepoints += 30;
                    }
                    else {
                        cout << "Incorrect! The water spirit creates a whirlpool, and you lose some health.\n";
                        player.health -= 15;
                    }
                }
            }
            else if (sharkAction == 3) {
                cout << "You chose to climb onto a rock.\n";

                // Additional adventure: An angel appears and gives you a map and key to a treasure!
                cout << "Suddenly, an angel appears before you!\n";
                cout << "The angel says, 'Brave adventurer, you have shown courage. Take this map and key to find a hidden treasure.'\n";
                player.hasTreasureMap = true;
                player.hasTreasureKey = true;

                player.experiencepoints += 35;
                cout << "You gained 35 experience points and received a treasure map and key.\n";
            }
            else {
                cout << "Invalid action. Despite the confusion, you successfully crossed the river.\n";
                player.experiencepoints += 25;
                cout << "You gained 25 experience points.\n";
            }

            break;
        }

        case 2: {
            cout << "You chose to fight the dragon.\n";
            cout << "As you approach the dragon, it surprisingly speaks: 'Hold, brave adventurer! Let us negotiate.'\n";
            cout << "The dragon offers a pact: share a valuable item with the dragon, and it will let you pass unharmed.\n";

            int negotiationChoice;
            cout << "Choose your action (1-2):\n";
            cout << "1. Negotiate and share a valuable item\n";
            cout << "2. Reject negotiation and fight the dragon\n";
            cout << "3. Exit game\n";
            cin >> negotiationChoice;

            if (negotiationChoice == 1) {
                // Implement negotiation logic
                bool negotiationSuccess = (rand() % 2 == 0); // 50% chance of negotiation success

                if (negotiationSuccess) {
                    cout << "Negotiation successful! The dragon appreciates your gesture and lets you pass safely.\n";
                    player.experiencepoints += 40;
                    cout << "You gained 40 experience points.\n";
                }
                else {
                    cout << "Negotiation failed! The dragon demands more, and you reluctantly part with a valuable item.\n";
                    player.health -= 10;
                    cout << "You lost 10 health in the process.\n";
                }
            }
            else if (negotiationChoice == 2) {
                // Proceed with the combat as before
                int dragonWeaponChoice;
                cout << "Choose your weapon to fight the dragon (1-5):\n";
                cout << "1. Sword\n";
                cout << "2. Bow and arrows\n";
                cout << "3. Magic staff\n";
                cout << "4. Fire-breathing potion\n";
                cout << "5. Lightning spear\n";
                cin >> dragonWeaponChoice;

                int playerDamage = 0;
                int dragonDamage = 0;

                switch (dragonWeaponChoice) {
                case 1:
                    cout << "You wield a sword against the dragon.\n";
                    playerDamage = rand() % 30 + 20;
                    dragonDamage = rand() % 40 + 10;
                    break;
                case 2:
                    cout << "You use a bow and arrows to attack the dragon.\n";
                    playerDamage = rand() % 25 + 15;
                    dragonDamage = rand() % 35 + 15;
                    break;
                case 3:
                    cout << "You wield a magic staff to cast spells on the dragon.\n";
                    playerDamage = rand() % 35 + 10;
                    dragonDamage = rand() % 30 + 20;
                    break;
                case 4:
                    cout << "You throw a fire-breathing potion at the dragon.\n";
                    playerDamage = rand() % 40 + 10;
                    dragonDamage = rand() % 25 + 15;
                    break;
                case 5:
                    cout << "You attack the dragon with a lightning spear.\n";
                    playerDamage = rand() % 45 + 5;
                    dragonDamage = rand() % 20 + 20;
                    break;
                default:
                    cout << "Invalid weapon choice.\n";
                    return;
                }

                cout << "Player's damage to the dragon: " << playerDamage << endl;
                cout << "Dragon's damage to the player: " << dragonDamage << endl;

                if (playerDamage > dragonDamage) {
                    cout << "Congratulations! You defeated the dragon.\n";
                    player.experiencepoints += 50;
                    cout << "You gained 50 experience points.\n";
                }
                else if (playerDamage < dragonDamage) {
                    cout << "Sorry! The dragon overpowered you. Better luck next time.\n";
                    player.health -= 30;
                    cout << "You lost 30 health.\n";
                }
                else {
                    cout << "The battle ends in a draw. Both you and the dragon are exhausted.\n";
                }
            }
            else if (negotiationChoice == 3) {
                cout << "You chose to exit the game. Thanks for playing!\n";
                cout << "Player's Health: " << player.health << "\n";
                cout << "Player's Experience Points: " << player.experiencepoints << "\n";
                return;
            }
            else {
                cout << "Invalid choice. The dragon sees it as an act of aggression and prepares for combat!\n";

            }

            break;
        }

        case 3: {
            cout << "You chose to exit the game. Thanks for playing!\n";
            cout << "Player's Health: " << player.health << "\n";
            cout << "Player's Experience Points: " << player.experiencepoints << "\n";
            return;
        }

        default:
            cout << "Invalid option. Please select a valid quest option.\n";
        }

        cout << "\nAdventure Summary:\n";
        cout << "Player's Health: " << player.health << "\n";
        cout << "Player's Experience Points: " << player.experiencepoints << "\n";
    }

    cout << "Game over! Your health has reached zero. Thanks for playing!\n";
}
//Quest 3
void wait(int sec) {
    Sleep(sec * 1000);
}

string getPlayerName() {
    string playerName;
    cout << "Welcome to the Mind Games Quest!\n";
    cout << "Please enter your name: ";
    cin >> playerName;
    return playerName;
}

bool playMemoryGame() {
    int x;
    int health = 10;
    int experiencepoints = 0;
    cout << "Choose your difficulty level \n 1.easy \n 2.medium \n 3.hard \n";
    cin >> x;
    switch (x) {
    case 1: {
        cout << "\nYou encounter a mystical door with ancient symbols.A Giant ugly bug is approaching you. \n";
        cout << "Guess the symbols before it catches you. \n";
        wait(2);
        system("cls");
        cout << "You only get 3 seconds\n";
        srand(time(0));
        string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string sequence = "";

        for (int i = 0; i < 5; ++i) {
            char symbol = symbols[rand() % symbols.size()];
            sequence += symbol;
            cout << symbol << " ";
        }

        cout << "\nHere you go!";

        wait(3);

        system("cls");

        string playerGuess;
        cout << "Enter the sequence of symbols: ";
        cin >> playerGuess;
        if (playerGuess == sequence) {
            cout << "Correct! The mystical door opens. You escape the giant bug. WOAH!!\n";
            health += 10;
            experiencepoints += 5;
            cout << "Congrats! Your health is increased to " << health << ".\n";
            cout << "Your experience points are increased to " << experiencepoints << ".\n";
            return true;
        }
        else {
            cout << "Incorrect! The mystical door remains closed. You are today's meal of the giant bug. BYE!!\n";
            health -= 10;
            experiencepoints -= 5;
            cout << "Pfft! Your health is decreased to " << health << ".\n";
            cout << "Your experience points are decreased to " << experiencepoints << ".\n";
            return false;
        }
        break;
    }
    case 2: {
        cout << "The hands are coming out of this room's walls.";
        cout << "\nThey will soon approach you";
        cout << "\nYou only get 5 seconds to memorize the sequence.\n";
        srand(time(0));
        string numbers = "1234567890";
        string sequence = "";

        for (int i = 0; i < 7; ++i) {
            char number = numbers[rand() % numbers.size()];
            sequence += number;
            cout << number << " ";
        }

        cout << "\nHere you go!";

        wait(5);

        system("cls");

        string playerGuess;
        cout << "Enter the sequence of numbers: ";
        cin >> playerGuess;

        if (playerGuess == sequence) {
            cout << "Great! You successfully avoided the hands. You can proceed further.\n";
            health += 15;
            experiencepoints += 10;
            cout << "Congrats! Your health is increased to " << health << ".\n";
            cout << "Your experience points are increased to " << experiencepoints << ".\n";
            return true;
        }
        else {
            cout << "Oops! The hands grabbed you. You'll have to try again.\n";
            health -= 15;
            experiencepoints -= 10;
            cout << "Pfft! Your health is decreased to " << health << ".\n";
            cout << "Your experience points are decreased to " << experiencepoints << ".\n";
            return false;
        }
        break;
    }
    case 3: {
        cout << "You find yourself in a mysterious room with shifting colors.";
        cout << "\nYou need to memorize the color sequence quickly.\n";
        cout << "You only get 7 seconds.\n";

        srand(time(0));
        string colors[] = { "Red", "Blue", "Green", "Yellow", "Purple", "Orange", "Pink" };
        string sequence = "";

        for (int i = 0; i < 9; ++i) {
            string color = colors[rand() % 7];
            sequence += color;
            cout << color << " ";
        }

        cout << "\nHere you go!";

        wait(7);

        system("cls");

        string playerGuess;
        cout << "Enter the sequence of colors (case-sensitive): ";
        cin >> playerGuess;

        if (playerGuess == sequence) {
            cout << "Congratulations! You passed the color challenge. The door ahead opens.\n";
            health += 20;
            experiencepoints += 25;
            cout << "Congrats! Your health is increased to " << health << ".\n";
            cout << "Your experience points are increased to " << experiencepoints << ".\n";
            return true;
        }
        else {
            cout << "Oops! Your vision is distorted. You'll need to try again.\n";
            health -= 20;
            experiencepoints -= 25;
            cout << "Pfft! Your health is decreased to " << health << ".\n";
            cout << "Your experience points are decreased to " << experiencepoints << ".\n";
            return false;
        }
        break;
    }
    default: {
        cout << "Invalid choice. Please choose a valid difficulty level.\n";
        return false;
    }
    }
}
//Quest 4
struct PlayerInformation
{
    string name;
    string gender;
    int Hp;
    int exp;
};

struct Monster
{
    int monsterHp;
    int monsterExp;
    string monsterName;
};

void animateText(const string& text, int delayMillis, bool increaseSize = false)
{
    for (char c : text)
    {
        cout << c;
        Sleep(delayMillis);
    }
}



void Moving(PlayerInformation& player, Monster& monster);
void createCharacter2(PlayerInformation& player)
{
    cout << "Enter your name: ";
    cin >> player.name;

    cout << "Your gender: ";
    cin >> player.gender;

    player.Hp = 100;
    player.exp = 0;

    for (int i = 0; i < 3; i++)
    {
        cout << "Creating Character" << string(i + 1, '.') << endl;
        Sleep(2000);
        system("cls");
    }
}

void displayCharacter2(const PlayerInformation& player)
{
    cout << "\nName: " << player.name << "\nSex: " << player.gender << "\nHealth: " << player.Hp << "\nExperience: " << player.exp << endl;
    Sleep(2000);
    system("cls");
}

Monster createMonsterCharacter()
{
    Monster monster;
    monster.monsterName = (rand() % 2 == 0) ? "Witch" : "Wizard";
    monster.monsterHp = 100;
    monster.monsterExp = 50; // Initialize monsterExp

    for (int i = 0; i < 3; i++)
    {
        cout << "Creating Monster Character" << string(i + 1, '.') << endl;
        Sleep(2000);
        system("cls");
    }
    return monster;
}

void displayMonster(const Monster& monster)
{
    cout << "\nName: " << monster.monsterName << "\nHealth: " << monster.monsterHp << "\nExperience: " << monster.monsterExp << endl;
    Sleep(2000);
    system("cls");
}

int inventoryofMonster()
{
    int a;

    cout << "Choose weapons from the inventory (1-8):\n 1. Silver Dagger\n 2. Sunlight-infused weapon\n 3. Eclipsing blade\n 4. Wooden stakes\n 5. Thorned chainsaw\n 6. Knife\n 7. Crossbow with wooden bolts\n 8. Mystic rune blade\n";

    cin >> a;

    if (a > 0 && a < 9)
    {
        cout << "You Chose: " << a << ". ";

        if (a == 1)
        {
            cout << "Silver Dagger";
        }
        else if (a == 2)
        {
            cout << "Sunlight-infused weapon";
        }
        else if (a == 3)
        {
            cout << "Eclipsing blade";
        }
        else if (a == 4)
        {
            cout << "Wooden stakes";
        }
        else if (a == 5)
        {
            cout << "Thorned chainsaw";
        }
        else if (a == 6)
        {
            cout << "Knife";
        }
        else if (a == 7)
        {
            cout << "Crossbow with wooden bolts";
        }
        else if (a == 8)
        {
            cout << "Mystic rune blade";
        }

        cout << endl;
    }
    else
    {
        cout << "Invalid choice. Please choose a number from 1 to 8." << endl;
    }

    return a;
}

void combat2(PlayerInformation& player, Monster& monster)
{
    int playerAttack;
    int playerDamage;
    int monsterAttack;

    while (player.Hp > 0 && monster.monsterHp > 0)
    {
        cout << "1. Attack\n 2. Block\n 3. RUN!\n";
        cin >> playerAttack;

        if (playerAttack == 1)
        {
            playerDamage = rand() % 20 + 10;
            cout << "Attacking----you did " << playerDamage << " Damage to the " << monster.monsterName << endl;

            monster.monsterHp -= playerDamage;

            if (monster.monsterHp > 0)
            {
                cout << "Monster is attacking---\n";

                monsterAttack = rand() % 15 + 5;
                player.Hp -= monsterAttack;

                cout << "You suffered " << monsterAttack << " Hp. Your current health: " << player.Hp << endl;

                if (player.Hp <= 0)
                {
                    player.Hp = 0;
                }

                // Add experience points based on damage dealt to the monster
                if (playerDamage >= 30)
                {
                    player.exp += 25;
                }
                else
                {
                    player.exp += 20;
                }

                cout << "You gained " << ((playerDamage >= 30) ? 25 : 20) << " experience points. Total experience: " << player.exp << endl;
            }
        }
        else if (playerAttack == 2)
        {
            cout << "Blocking\n";
            int i = rand() % 100 + 1;
            if (i >= 50)
            {
                cout << "You Blocked the incoming attack\n";
                player.Hp += player.exp * 10 / 2; // Healing based on experience points
                cout << "You have been Healed for " << player.exp * 10 / 2 << endl;

                if (player.Hp > 100)
                {
                    player.Hp = 100;
                }
            }
            else
            {
                cout << "You failed to block the savage attack\n";
                player.Hp -= monsterAttack;
                cout << "You were stabbed for " << monsterAttack << " current hp " << player.Hp << endl;
            }
        }
        else if (playerAttack == 3)
        {
            cout << "You try to Run\n";
            int x = rand() % 100 + 1;
            if (x >= 50)
            {
                animateText("HURRAH! You Successfully ran away leaving MONSTER behind, escaping the dark WOODS.\n", 50);
                break;
            }
            else
            {
                cout << "You failed to run away\n";
                cout << "Monster does a savage attack on you!\n";
                player.Hp -= monsterAttack + 10;
                cout << "You suffered " << monsterAttack + 10 << " Your current health is " << player.Hp << endl;
            }
        }
        else
        {
            cout << "Invalid Number\n";
        }
    }

    // Display results after the battle
    if (player.Hp <= 0)
    {
        cout << "You Died! \nYou were killed by " << monster.monsterName << endl;
    }
    else if (monster.monsterHp <= 0)
    {
        cout << "You Defeated " << monster.monsterName << "! You are rewarded with " << monster.monsterExp << " xp.\nWellDone!\n";
        player.exp += monster.monsterExp;
        cout << "You gained " << monster.monsterExp << " experience points. Total experience: " << player.exp << endl;
    }
}


void Moving(PlayerInformation& player, Monster& monster)
{
    int choice;
    cout << "1. Move Forward\n";
    cout << "2. Move Backwards\n";
    cin >> choice;
    int temp, tempBack;

    switch (choice)
    {
    case 1:
        temp = rand() % 100 + 1;
        cout << "You begin moving forward---\n";
        if (temp >= 50)
        {
            string tempName = (rand() % 2 == 0) ? "Witch" : "Wizard";
            cout << "A " << tempName << " ! Prepare to fight !\n";
            monster.monsterName = tempName;
            Sleep(1000);
            combat2(player, monster);
        }
        else
        {
            cout << "You find nothing of interest\n";
            Sleep(1000);
            displayCharacter2(player);
            Moving(player, monster);
        }
        break;

    case 2:
        tempBack = rand() % 100 + 1;
        cout << "You begin moving backwards---\n";
        if (tempBack >= 50)
        {
            string tempNameBack = (rand() % 2 == 0) ? "Witch" : "Wizard";
            cout << "A " << tempNameBack << " ! Prepare to fight !\n";
            monster.monsterName = tempNameBack;
            Sleep(1000);
            combat2(player, monster);
        }
        else
        {
            cout << "You find nothing of interest\n";
            Sleep(1000);
            displayCharacter2(player);
            Moving(player, monster);
        }
        break;

    default:
        cout << "Invalid Number\n";
        Sleep(500);
        break;
    }
}

void finalquest()
{
    srand(static_cast<unsigned int>(time(0)));

    PlayerInformation player;
    createCharacter2(player);
    displayCharacter2(player);

    Monster monster = createMonsterCharacter();
    displayMonster(monster);

    animateText("In the mystical realm, the brave adventurer, ", 50, true);
    animateText(player.name, 50, true);
    animateText(", armed with a ", 50, true);
    animateText("Silver Dagger", 50, true);
    animateText(", faces the menacing ", 50, true);
    animateText(monster.monsterName, 50, true);
    animateText(" in the Dark Woods. ", 50, true);
    animateText(player.name, 50, true);
    animateText(" must decide whether to attack, block, or escape during the intense battle. The outcome remains uncertain as the hero either triumphs, earning valuable experience points, or succumbs to the relentless attacks.", 50);

    Sleep(3000);
    system("cls");

    int weaponChoice = inventoryofMonster();
    Moving(player, monster);


}
void combat2(PlayerInformation& player, Monster& monster);

void createCharacter2(PlayerInformation& player);

void displayCharacter2(const PlayerInformation& player);

Monster createMonsterCharacter();

void displayMonster(const Monster& monster);

int inventoryofmonster();
void combat2(PlayerInformation& player, Monster& monster);
void Moving(Player& player, Monster& monster);
void finalquest();




int main() {
    srand(time(0));
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 13);

    cout << "Welcome to WeaponsWar\n";

    SetConsoleTextAttribute(h, 7);

    CharacterCreation player;

    // Character creation
    cout << "Loading...\n";

    SetConsoleTextAttribute(h, 11);
    cout << "Quest against mythical creatures\n";
    SetConsoleTextAttribute(h, 7);
    Sleep(2000);
    system("cls");

    do {
        int role;
        cout << "Select your Quest" << endl;
        cout << "1. YoshimitsuChallenge\n2.DragonAttack\n3.MindGameQuest \n4.Monster\n";
        cin >> role;

        switch (role) {
        case 1: {
            srand(time(0));

            Player player;
            createCharacter(player);
            displayCharacter(player);

            Yoshimitsu yoshimitsu = createYoshimitsuCharacter();
            displayYoshimitsu(yoshimitsu);

            int weaponChoice = inventory();

            combat(player, yoshimitsu);
            // No need to declare 'CharacterCreation player;' here

            break;
        }
        case 2:
        {

            cout << "Welcome to the Enhanced River Quest!\n";
            riverQuestQuest1(player);
            break;

        }
        case 3:
        {
            string playerName = getPlayerName();
            cout << "\nHello, " << playerName << "! Your quest begins...\n";
            wait(1);
            cout << "You are stuck in a 3 Rooms challenge with different creatures\n";
            cout << "The only way out is solving the riddles\n";
            wait(1);
            cout << "..LOADING..\n";
            wait(1);
            bool firstChallengePassed = playMemoryGame();

        }
        case 4:
        {
            finalquest();
        }
        default:
            cout << "Invalid option. Please select a valid quest.\n";
            break;
        }
        system("cls");
        Sleep(2000);
        // After each quest, provide options to continue, exit, or take a rest
        cout << "Options:\n";
        cout << "1. Continue to the next quest\n";
        cout << "2. Exit the game\n";
        cout << "3. Take a rest\n";
        int option;
        cin >> option;

        switch (option) {

        case 1:
            // Continue to the next quest
            break;
        case 2:
            // Exit the game
            cout << "Exiting the game. Goodbye!\n";
            return 0;
        case 3:
            // Take a rest
            cout << "You take a rest. Resting...\n";
            Sleep(2000); // Adjust the time as needed
            cout << "You feel refreshed and ready for the next quest!\n";
            break;
        default:
            cout << "Invalid option. Exiting the game.\n";
            return 0;
        }

    } while (true);

    return 0;
}
