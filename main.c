#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char convert_to_uppercase(char character);
bool check_answer(char enteredAnswer[], char correctAnswer[]);

int main() {
    char questions[][50] = { "What is the largest planet in the solar system?", "What is the hottest planet?", "Which planet has the most moons?", "Is the Earth flat?" };
    char options[][4][25] = { {"Jupyter", "Saturn", "Uranus", "Neptune"}, {"Mercury", "Venus", "Earth", "Mars"}, {"Earth", "Mars", "Jupiter", "Saturn"}, {"Yes", "No", "Maybe", "Sometimes"} };
    char answers[][25] = { "Jupyter", "Venus", "Saturn", "No" };
    int score = 0;
    int possibleMaximumScore = sizeof(answers) / sizeof(answers[0]);

    char choice = '\0';

    int questionsCount = sizeof(questions) / sizeof(questions[0]);

    printf("*** QUIZ GAME ***\n\n");
    int i;
    for (i = 0; i < questionsCount; i++)
    {
        printf("%s\n\n", questions[i]);
        printf("A. %s\n", options[i][0]);
        printf("B. %s\n", options[i][1]);
        printf("C. %s\n", options[i][2]);
        printf("D. %s\n", options[i][3]);

        printf("\n\nEnter your choice: ");
        scanf(" %c", &choice);
        choice = convert_to_uppercase(choice);

        switch (choice)
        {
            case 'A':
                bool isCorrect = check_answer(options[i][0], answers[i]);
                if (isCorrect) {
                    score += 1;
                    printf("CORRECT!\n\n");
                } else {
                    printf("WRONG!\n\n");
                }
                break;
            case 'B':
                isCorrect = check_answer(options[i][1], answers[i]);
                if (isCorrect) {
                    score += 1;
                    printf("CORRECT!\n\n");
                } else {
                    printf("WRONG!\n\n");
                }
                break;
            case 'C':
                isCorrect = check_answer(options[i][2], answers[i]);
                if (isCorrect) {
                    score += 1;
                    printf("CORRECT!\n\n");
                } else {
                    printf("WRONG!\n\n");
                }
                break;
            case 'D':
                isCorrect = check_answer(options[i][3], answers[i]);
                if (isCorrect) {
                    score += 1;
                    printf("CORRECT!\n\n");
                } else {
                    printf("WRONG!\n\n");
                }
                break;
            
            default:
                perror("Invalid option. Please try to run the program again and ansnwer with the possible characters (A, B, C, D).");
                return 1;
                break;
        }
    }
    
    printf("Your score is %d out of %d\n", score, possibleMaximumScore);

    return 0;
}

char convert_to_uppercase(char character) {
    /* Check if the character is lowercase before converting */
    if (character >= 'a' && character <= 'z') {
        character = character - 32;
        return character;
    } else if(character >= 'A' && character <= 'Z') {
        return character;
    } else {
        perror("Enter a valid ASCII Character to convert to uppercase");
    }
}

bool check_answer(char enteredAnswer[], char correctAnswer[]) {
    return !strcmp(enteredAnswer, correctAnswer);
}