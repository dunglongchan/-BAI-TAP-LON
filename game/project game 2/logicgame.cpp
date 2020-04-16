#include "logicgame.h"

using namespace std;

SDL_Texture* loadImage(std::string fileAnh, SDL_Renderer* render) {
    SDL_Surface* surf = IMG_Load(fileAnh.c_str());
    SDL_Texture* tex;
    tex = SDL_CreateTextureFromSurface(render, surf);
    return tex;
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_WaitEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}
string getText(){
    vector<string> wordList;
    ifstream file("aloalo.txt");
    if (file.is_open()) {
        string word;
        while (getline(file, word)) {
            wordList.push_back(word);
        }
        file.close();
    }
    if (wordList.size() > 0) {
        srand(time(0));
        int randomIndex = rand() % wordList.size();
        return wordList[randomIndex];
    }
    else return "";
}