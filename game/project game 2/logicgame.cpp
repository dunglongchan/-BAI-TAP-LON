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
            break;
        SDL_Delay(10);
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
bool check(string x, int y, char z) {
    if (z == x[y]) return true;
    else return false;
}
void start(SDL_Renderer* render) {
    SDL_RenderClear;
    SDL_Rect start, start1;
    start.x = 0, start.y = 0, start.w = 900, start.h = 600;
    start1.x = 0, start1.y = 0, start1.w = 900, start1.h = 600;
    SDL_RenderCopy(render, loadImage("start.png", render), &start, &start1);
    SDL_RenderPresent(render);
    SDL_Texture* tex = loadImage("back2.png", render);
    //SDL_DestroyTexture(tex);
}
bool cheker(SDL_Event e, string text, int dem) {
    int x = e.key.keysym.sym;
    if (x == int(text[dem])) return true;
    return false;
}
