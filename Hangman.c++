#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to jumble a word
string jumbleWord(const string& word) {
    string jumbled = word;
    random_shuffle(jumbled.begin(), jumbled.end());
    return jumbled;
}

// Function to display the hangman figure based on the number of wrong guesses
void displayHangman(int tries) {
    cout << "  -----" << endl;
    cout << "  |   |" << endl;
    if (tries >= 1) cout << "  O   |" << endl;
    else cout << "      |" << endl;
    if (tries >= 3) cout << " /|\\  |" << endl;
    else if (tries >= 2) cout << "  |   |" << endl;
    else cout << "      |" << endl;
    if (tries >= 5) cout << " / \\  |" << endl;
    else if (tries >= 4) cout << " /    |" << endl;
    else cout << "      |" << endl;
    cout << "      |" << endl;
    cout << "---------\n";
}

// Function to display the current state of the guessed word
void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            cout << word[i] << ' ';
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Function to check if a guessed letter is in the word
bool checkGuess(const string& word, char guess, vector<bool>& guessed) {
    bool found = false;
    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] == guess) {
            guessed[i] = true;
            found = true;
        }
    }
    return found;
}

// Function to get a random word from a specified category
string getRandomWord(const vector<string>& words) {
    return words[rand() % words.size()];
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Extended Categories of words
    vector<string> places = {
        "london", "paris", "mumbai", "sydney", "tokyo", "newyork", "berlin", "rome", "dubai", "moscow",
        "beijing", "osaka", "rio", "amsterdam", "vienna", "athens", "cairo", "sao", "lisbon", "prague",
        "budapest", "warsaw", "stockholm", "helsinki", "dublin", "edinburgh", "brussels", "zurich", "porto", "luxembourg",
        "monaco", "nice", "marseille", "milan", "florence", "barcelona", "valencia", "seville", "geneva", "zurich",
        "hamburg", "hamburg", "copenhagen", "oslo", "reykjavik", "jerusalem", "lagos", "nairobi", "kuala", "jakarta"
    };

    vector<string> objects = {
        "computer", "phone", "keyboard", "mouse", "monitor", "chair", "table", "pen", "book", "lamp",
        "notebook", "wallet", "headphones", "calculator", "remote", "flashlight", "bag", "camera", "phone", "printer",
        "scanner", "projector", "router", "charger", "disk", "harddrive", "modem", "speakers", "microphone", "webcam",
        "glasses", "watch", "bag", "umbrella", "calculator", "thermometer", "toaster", "microwave", "blender", "refrigerator",
        "stereo", "alarm", "tape", "thermostat", "monitor", "speaker", "telephone", "mousepad", "gps", "drone"
    };

    vector<string> animals = {
        "elephant", "giraffe", "tiger", "lion", "kangaroo", "zebra", "panda", "monkey", "wolf", "bear",
        "dolphin", "whale", "eagle", "hawk", "falcon", "parrot", "penguin", "shark", "octopus", "jellyfish",
        "rhinoceros", "hippopotamus", "giraffe", "koala", "sloth", "otter", "beaver", "bison", "buffalo", "hyena",
        "cheetah", "leopard", "jaguar", "cougar", "platypus", "squirrel", "rabbit", "deer", "moose", "camel",
        "wombat", "puma", "armadillo", "skunk", "hedgehog", "mole", "seal", "walrus", "coyote", "woodpecker"
    };

    vector<string> fruits = {
        "apple", "banana", "cherry", "orange", "mango", "grape", "pear", "peach", "plum", "kiwi",
        "pineapple", "strawberry", "blueberry", "blackberry", "raspberry", "pomegranate", "watermelon", "melon", "fig", "date",
        "apricot", "nectarine", "coconut", "papaya", "guava", "lychee", "dragonfruit", "passionfruit", "tangerine", "cantaloupe",
        "persimmon", "kumquat", "soursop", "starfruit", "jackfruit", "rhubarb", "quince", "olive", "custardapple", "honeydew",
        "grapefruit", "mangosteen", "chayote", "rhubarb", "acai", "gooseberry", "jasmine", "carambola", "rhubarb", "bloodorange"
    };

    vector<string> vegetables = {
        "carrot", "broccoli", "spinach", "onion", "tomato", "cucumber", "pepper", "lettuce", "corn", "potato",
        "cabbage", "cauliflower", "zucchini", "asparagus", "mushroom", "pumpkin", "squash", "beet", "radish", "celery",
        "artichoke", "brussels", "greenbean", "kale", "parsnip", "chard", "sweetpotato", "turnip", "leek", "yam",
        "jicama", "okra", "rhubarb", "napa", "chili", "tomatillo", "edamame", "fennel", "celeriac", "daikon",
        "seaweed", "nori", "dandelion", "basil", "rosemary", "thyme", "coriander", "sage", "tarragon", "marjoram"
    };

    vector<string> newCategory = {
        "guitar", "violin", "drums", "piano", "flute", "trumpet", "saxophone", "harp", "cello", "trombone",
        "banjo", "mandolin", "accordion", "clarinet", "oboe", "bassoon", "ukulele", "xylophone", "marimba", "sitar",
        "tambourine", "accordion", "bagpipes", "fiddle", "synthesizer", "organ", "conga", "bongo", "triangle", "maracas",
        "didgeridoo", "lute", "zither", "theremin", "horn", "melody", "timpani", "gong", "cymbals", "drumkit",
        "steelpan", "harmonica", "cowbell", "kazoo", "whistle", "castanets", "clavichord", "celesta", "saxophone", "recorder"
    };

    // Display category choices
    cout << "Choose a category:" << endl;
    cout << "1. Place" << endl;
    cout << "2. Object" << endl;
    cout << "3. Animal" << endl;
    cout << "4. Fruit" << endl;
    cout << "5. Vegetable" << endl;
    cout << "6. Music Instrument" << endl;

    int categoryChoice;
    cout << "Enter the number of your choice: ";
    cin >> categoryChoice;

    vector<string> chosenCategory;

    switch (categoryChoice) {
        case 1:
            chosenCategory = places;
            break;
        case 2:
            chosenCategory = objects;
            break;
        case 3:
            chosenCategory = animals;
            break;
        case 4:
            chosenCategory = fruits;
            break;
        case 5:
            chosenCategory = vegetables;
            break;
        case 6:
            chosenCategory = newCategory;
            break;
        default:
            cout << "Invalid choice. Exiting..." << endl;
            return 1;
    }

    // Randomly select a word from the chosen category
    string word = getRandomWord(chosenCategory);
    string jumbledWord = jumbleWord(word);

    vector<bool> guessed(word.length(), false);
    int maxTries = 6;
    int tries = 0;
    string guessedLetters;

    cout << "Your jumbled word: " << jumbledWord << endl;

    while (tries < maxTries) {
        cout << "\nCurrent word: ";
        displayWord(word, guessed);
        cout << "Guess a letter: ";
        
        char guess;
        cin >> guess;

        if (guessedLetters.find(guess) != string::npos) {
            cout << "You've already guessed that letter." << endl;
            continue;
        }

        guessedLetters += guess;

        if (checkGuess(word, guess, guessed)) {
            cout << "Good guess!" << endl;
        } else {
            cout << "Wrong guess!" << endl;
            tries++;
        }

        displayHangman(tries);

        bool allGuessed = all_of(guessed.begin(), guessed.end(), [](bool g) { return g; });
        if (allGuessed) {
            cout << "\nCongratulations! You've guessed the word: " << word << endl;
            break;
        }
    }

    if (tries == maxTries) {
        cout << "\nGame over! The word was: " << word << endl;
    }

    return 0;
}
