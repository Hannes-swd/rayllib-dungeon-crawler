
#pragma once
#include<iostream>
void Drop(std::string Item, int anzahl, int x, int y);
void DrawDropItems();
void CollectDropItems();

typedef struct DropItem {
	std::string itemName;
	Vector2 position;
} DropItem;