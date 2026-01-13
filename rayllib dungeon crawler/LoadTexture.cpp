#include "raylib.h"
#include "LoadTexture.h"
#include <unordered_map>
#include <string>

std::unordered_map<std::string, Texture2D> textures;

void loadTextures() {
    textures["test"] = LoadTexture("resources/test.png");
    textures["Boden"] = LoadTexture("resources/Boden.png");
    textures["Wasser"] = LoadTexture("resources/Wasser.png");
    textures["Lava"] = LoadTexture("resources/Lava.png");
    textures["Wand"] = LoadTexture("resources/Wand.png");
    textures["Player"] = LoadTexture("resources/Player.png");
    textures["Herz"] = LoadTexture("resources/Herz.png");
	textures["Zaber"] = LoadTexture("resources/zaber.png");
	textures["Gegner"] = LoadTexture("resources/Gegner.png");
    textures["schwert"] = LoadTexture("resources/schwert.png");
    textures["Energie_1"] = LoadTexture("resources/Energie_1.png");
    textures["Energie_2"] = LoadTexture("resources/Energie_2.png");
    textures["Energie_3"] = LoadTexture("resources/Energie_3.png"); 
    textures["kiste"] = LoadTexture("resources/kiste.png");
    textures["energie_orb"] = LoadTexture("resources/energie_orb.png");
}

void unloadTextures() {
    for (auto& pair : textures) {
        UnloadTexture(pair.second);
    }
    textures.clear();
}

void DrawTexture(const std::string& name, float x, float y, float width, float height, Color tint) {
    if (textures.find(name) != textures.end()) {
        Texture2D tex = textures[name];
        Rectangle source = { 0, 0, (float)tex.width, (float)tex.height };
        Rectangle dest = { x, y, width, height };
        Vector2 origin = { 0, 0 };
        DrawTexturePro(tex, source, dest, origin, 0.0f, tint);
    }
}