#include "gameplay.h"

using namespace std;

bool kiemtrakitu(SDL_Event e, string text, int dem) 
{
    int x = e.key.keysym.sym;
    if (x == int(text[dem])) return true;
    return false;
}

string getText()
{
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

void drawtext(SDL_Renderer* renderer, string text,int size,int desX,int desY, SDL_Color fg,string fontname) {
    TTF_Font* font = NULL;
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;
    if (TTF_Init() < 0) SDL_Log("%s", TTF_GetError());
    font = TTF_OpenFont(fontname.c_str(), size);
    surface = TTF_RenderText_Solid(font, text.c_str(), fg);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect srcRest;
    srcRest.x = desX;
    srcRest.y = desY;
    srcRest.w = 0;
    srcRest.h = 0;
    TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);
    SDL_RenderCopy(renderer, texture, NULL, &srcRest);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}
void health(SDL_Renderer* renderer, int n)
{
    SDL_Rect src, des;
    src.x = 0, src.y = 0, src.w = 50, src.h = 50;
    des.x = 850, des.y = 0, des.w = 50, des.h = 50;
    SDL_Surface* surf = IMG_Load("heart.png");
    SDL_Texture* tex;
    tex = SDL_CreateTextureFromSurface(renderer, surf);
    for (int i = 0; i < n; i++) {
        SDL_RenderCopy(renderer,tex, &src, &des);
        des.x -= 50;
    }
    SDL_DestroyTexture(tex);
}
int gethighest(vector<int>a,int n)
{
    int max = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}
void police(SDL_Renderer* renderer,int n)
{
    SDL_Rect src, des;
    src.x = 0, src.y = 0, src.w = 80, src.h = 120;
    des.x = 650 , des.y = 350, des.w = 80, des.h = 120;
    switch (n)
    {
    case 1:
        {
            SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, IMG_Load("police2.png"));
            SDL_RenderCopy(renderer, tex, &src, &des);
            SDL_DestroyTexture(tex);
            break;
        }
    case 2:
    {
        SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, IMG_Load("police1.png"));
        SDL_RenderCopy(renderer, tex, &src, &des);
        SDL_DestroyTexture(tex);
        break;
    }
    case 3:
    {
        SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, IMG_Load("police3.png"));
        SDL_RenderCopy(renderer, tex, &src, &des);
        SDL_DestroyTexture(tex);
        break;
    }
    case 4:
    {
        SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, IMG_Load("police4.png"));
        SDL_RenderCopy(renderer, tex, &src, &des);
        SDL_DestroyTexture(tex);
        break;
    }
    case 5:
    {
        SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, IMG_Load("police5.png"));
        for (int i = 0; i < 3; i++) {
            SDL_RenderCopy(renderer, tex, &src, &des);
            des.x += 35;
            des.y += 35;
        }
        SDL_DestroyTexture(tex);
        break;
    }
    default:
        break;
    }
}
void backgrmusic()
{
    vector<string> soundlist;
    ifstream file("soundname.txt");
    if (file.is_open()) {
        string word;
        while (getline(file, word)) {
            soundlist.push_back(word);
        }
        file.close();
    }
    string name;
    if (soundlist.size() > 0) {
        srand(time(0));
        int randomIndex = rand() % soundlist.size();
        name= soundlist[randomIndex];
    }
    Mix_Music* backgrmusic = NULL;
    backgrmusic = Mix_LoadMUS(name.c_str());
    Mix_PlayMusic(backgrmusic, -1);
}
void ticktock() 
{
    Mix_Chunk* tiktok = NULL;
    tiktok= Mix_LoadWAV("ticktock.mp3");
    Mix_PlayChannel(-1, tiktok, 0,-1);
}

void firesound()
{
    Mix_Chunk* tiktok = NULL;
    tiktok = Mix_LoadWAV("fire.mp3");
    Mix_PlayChannel(-1, tiktok, 0);
}

void endgamesound()
{
    Mix_Music* tiktok = NULL;
    tiktok = Mix_LoadMUS("highscore.mp3");
    Mix_PlayMusic( tiktok, 0);
}

void endgamesound2()
{
    Mix_Music* tiktok = NULL;
    tiktok = Mix_LoadMUS("lose.mp3");
    Mix_PlayMusic(tiktok, 0);
}

void policesound()
{
    Mix_Chunk* tiktok = NULL;
    tiktok = Mix_LoadWAV("police.mp3");
    Mix_PlayChannel(-1, tiktok, 0);
}
void buff()
{
    Mix_Chunk* buff = NULL;
    buff = Mix_LoadWAV("buff.mp3");
    Mix_PlayChannel(-1, buff, 0);
}
void playagian()
{
    SDL_Event e;
    while (true) {
        if (SDL_WaitEvent(&e) != 0 && e.key.keysym.sym==115)
            break;
        SDL_Delay(10);
    }
}