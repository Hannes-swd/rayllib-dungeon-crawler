#include "raylib.h"
#include "LoadTexture.h"
#include <unordered_map>
#include <string>

std::unordered_map<std::string, Texture2D> textures;

void loadTextures() {

    //spieler
    textures["PlayerF"] = LoadTexture("resources/Player/PlayerF.png");
    textures["PlayerL"] = LoadTexture("resources/Player/PlayerL.png");
    textures["PlayerR"] = LoadTexture("resources/Player/PlayerR.png");
    textures["PlayerH"] = LoadTexture("resources/Player/PlayerH.png");


    //Tiles
    textures["test"] = LoadTexture("resources/Tiles/test.png");
    textures["Boden"] = LoadTexture("resources/Tiles/Boden.png");
    textures["Wasser"] = LoadTexture("resources/Tiles/Wasser.png");
    textures["Lava"] = LoadTexture("resources/Tiles/Lava.png");
    textures["Wand"] = LoadTexture("resources/Tiles/Wand.png");
    textures["kiste"] = LoadTexture("resources/Tiles/kiste.png");
    textures["Tür"] = LoadTexture("resources/Tiles/Tür.png");

    //Ui
    textures["Herz"] = LoadTexture("resources/Ui/Herz.png");
    textures["schwert"] = LoadTexture("resources/Ui/schwert.png");
    textures["Energie_1"] = LoadTexture("resources/Ui/Energie_1.png");//energie start
    textures["Energie_2"] = LoadTexture("resources/Ui/Energie_2.png");//energie Mitte
    textures["Energie_3"] = LoadTexture("resources/Ui/Energie_3.png"); //energie ende
    textures["Energie_4"] = LoadTexture("resources/Ui/Energie_4.png");//energie ende grau
    textures["Energie_5"] = LoadTexture("resources/Ui/Energie_5.png");//energie mitte grau
    textures["Energie_6"] = LoadTexture("resources/Ui/Energie_6.png");//energie start grau
    textures["Geld"] = LoadTexture("resources/Ui/Geld.png");
    textures["energie_orb"] = LoadTexture("resources/Ui/energie_orb.png");

    //gegner
    textures["Gegner"] = LoadTexture("resources/Gegner/Gegner.png");
    
    //andere
    textures["ETaste"] = LoadTexture("resources/Andere/ETaste.png");

    //maps
	textures["map1"] = LoadTexture("resources/Maps/map1.png");
    textures["map2"] = LoadTexture("resources/Maps/map2.png");
    textures["map3"] = LoadTexture("resources/Maps/map3.png");


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